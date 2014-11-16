/**
 * tree.hpp
 * a basic fake merkle tree implemented for FunCoin
 * Sean D. Turner
 *
 */

#pragma once

#include <memory>
#include <iomanip>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

namespace tree {

  template<typename T>
  class BasicTreeNode {
  private:
    //! will be null for nonleaf nodes
    std::unique_ptr<T> payload;

    std::unique_ptr<BasicTreeNode<T>> left;
    std::unique_ptr<BasicTreeNode<T>> right;

  public:
    BasicTreeNode();
    BasicTreeNode(const BasicTreeNode& other);
    ~BasicTreeNode();
    
    //! getter and setter for hash
    std::string getHash();
    
    //! getter and setter for payload
    std::unique_ptr<T> getPayload();
    
    //template<typename T>
    void setPayload(const T& payload);
    
    //! getter and setter for left child
    std::unique_ptr<BasicTreeNode<T>> getLeftChild();
    
    void setLeftChild(const BasicTreeNode& node);
    
    //! getter and setter for right child
    std::unique_ptr<BasicTreeNode<T>> getRightChild();
    
    void setRightChild(const BasicTreeNode& node);

    void addTransaction();
  };

}

