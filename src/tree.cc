/**
 * tree.cc
 * Implementation of our pseudo-merkle-tree for FunCoin
 *
 *
 */

#include "tree.hpp"

using namespace tree;

//! make sure payload is null for a new node
template<typename T>
BasicTreeNode<T>::BasicTreeNode() {
  this->payload = nullptr;
}

template<typename T>
std::string BasicTreeNode<T>::getHash() {
  
  //! cases:
  // node is a leaf, so hash is the transaction
  if (!left && !right) {
    std::stringstream s;
    s << this->payload;
    return s.str();
  }
  
  // node is not a leaf, but left child exists
  // so we concatenate the existing hash with
  // itself
  else if (left && !right) {
    return this->left.getHash() + this->left.getHash();
  }
  
  // node is not a leaf, but right child exists
  else if (!left && right) {
    return this->right.getHash() + this->right.getHash();
  }
  
  // node is not a leaf, but has both children
  else {
    return this->left.getHash() + this->right.getHash();
  }
}

template<typename T>
decltype(auto) BasicTreeNode<T>::getPayload() {
  return this->payload;
}

template<typename T>
void BasicTreeNode<T>::setPayload(const T& payload) {
  this->payload = std::make_unique<T>(payload);
}

template<typename T>
decltype(auto) BasicTreeNode<T>::getLeftChild() {
  return this->left;
}

template<typename T>
void BasicTreeNode<T>::setLeftChild(const BasicTreeNode& node) {
  this->left = node;
}

template<typename T>
decltype(auto) BasicTreeNode<T>::getRightChild() {
  return this->right;
}

template<typename T>
void BasicTreeNode<T>::setRightChild(const BasicTreeNode& node) {
  this->right = node;
}

int main(void) {
  auto t1 = "alice-sends-bob-5-funcoin";
  auto t2 = "trent-sends-alice-2-funcoin";
  auto t3 = "bob-sends-alice-10-funcoin";
  auto t4 = "trent-sends-bob-3-funcoin";
  
  // create root node
  decltype(auto) MerkleRoot = new BasicTreeNode<std::string>();
  MerkleRoot->setPayload(t1);
  
  decltype(auto) MerkleRootPtr = std::make_unique<BasicTreeNode<std::string>>(MerkleRoot);
  
  return 0;
}