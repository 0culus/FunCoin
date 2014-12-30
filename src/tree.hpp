/**
 * tree.hpp
 * a basic fake merkle tree implemented for FunCoin
 * Sean D. Turner
 *
 */

#pragma once

#define DEBUG 1

#include <memory>
#include <iomanip>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

#ifdef DEBUG
  #include <boost/type_index.hpp>
#endif

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
    BasicTreeNode(const BasicTreeNode& other) = default;
    ~BasicTreeNode() = default;
    
    //! getter and setter for hash
    std::string getHash();
    
    //! getter and setter for payload
    decltype(auto) getPayload();
    
    //template<typename T>
    void setPayload(const T& payload);
    
    //! getter and setter for left child
    decltype(auto) getLeftChild();
    
    void setLeftChild(const BasicTreeNode& node);
    
    //! getter and setter for right child
    decltype(auto) getRightChild();
    
    void setRightChild(const BasicTreeNode& node);

    void addTransaction();
  };
  
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

}

