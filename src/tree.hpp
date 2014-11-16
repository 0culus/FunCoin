/**
 * tree.hpp
 * a basic fake merkle tree implemented for FunCoin
 * Sean D. Turner
 *
 */

#include <memory>
#include <iomanip>
#include <vector>

namespace tree {

  template<typename T>
  class BasicTreeNode {
  private:
    
    //! hash of left node concat hash of right node
    std::unique_ptr<std::string> _hash;
    
    //! will be null for nonleaf nodes
    std::unique_ptr<T> _payload;

    std::unique_ptr<BasicTreeNode> _left;
    std::unique_ptr<BasicTreeNode> _right;

  public:
    BasicTreeNode();
    BasicTreeNode(const BasicTreeNode& other);
    ~BasicTreeNode();
    
    //! getter and setter for hash
    std::string getHash();
    
    //! getter and setter for payload
    template<typename T>
    std::unique_ptr<T> getPayload();
    
    template<typename T>
    void setPayload(const T& payload);
    
    //! getter and setter for left child
    template<typename T>
    std::unique_ptr<T> getLeftChild();
    
    template<typename T>
    void setLeftChild(const BasicTreeNode& node);
    
    //! getter and setter for right child
    template<typename T>
    std::unique_ptr<T> getRightChild();
    
    template<typename T>
    void setRightChild(const BasicTreeNode& node);

    void addTransaction();
  };

}

