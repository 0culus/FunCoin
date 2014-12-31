/**
 * tree.cc
 * Implementation of our pseudo-merkle-tree for FunCoin
 *
 *
 */

#include "tree.hpp"

using namespace tree;

#ifdef DEBUG
  using boost::typeindex::type_id_with_cvr;
#endif

int main(void) {
  std::vector<std::string> transactions = { "alice-sends-bob-5-funcoin",
                                  "trent-sends-alice-2-funcoin",
                                  "bob-sends-alice-10-funcoin",
                                  "trent-sends-bob-3-funcoin" };
  
  // create root node
  decltype(auto) MerkleRoot = new BasicTreeNode<std::string>();
  std::cout << "MerkleRoot's type =    "
  << type_id_with_cvr<decltype(MerkleRoot)>().pretty_name();
  
  auto str = transactions[0];
  
  decltype(auto) t1 = std::make_unique<std::string>(str);
  std::cout << "t1's type =    "
  << type_id_with_cvr<decltype(t1)>().pretty_name();
  
  MerkleRoot->setPayload(*t1);
  
  auto MerkleRootRvalue = std::move(MerkleRoot);
  
  decltype(auto) MerkleRootPtr = std::make_unique<BasicTreeNode<std::string>>(*MerkleRootRvalue);
  std::cout << "MerkleRootPtr's type =    "
  << type_id_with_cvr<decltype(MerkleRootPtr)>().pretty_name();
  
  
  return 0;
}