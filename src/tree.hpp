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
    BasicTreeNode(const BasicTreeNode& other);
    BasicTreeNode(BasicTreeNode&& other);
    ~BasicTreeNode() = default;
    
    BasicTreeNode operator=(BasicTreeNode&& other);
    
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
  
  //! copy ctor
  template<typename T>
  BasicTreeNode<T>::BasicTreeNode(const BasicTreeNode& other) {
    auto tmp = other;
    this->payload = std::make_unique<T>(tmp.payload);
    this->left = std::make_unique<T>(tmp.left);
    this->right = std::make_unique<T>(tmp.right);
  }
  
  //! move ctor
  template<typename T>
  BasicTreeNode<T>::BasicTreeNode(BasicTreeNode&& other)
  : payload{other->payload},
  left{other->left},
  right{other->right} {
    other->payload = nullptr;
    other->left = nullptr;
    other->right = nullptr;
  }
  
  //! move assignment operator
  template<typename T>
  BasicTreeNode<T>& operator=(BasicTreeNode<T>&& other) {
    if (this != other) {
      if (this->payload != nullptr) this->payload = nullptr;
      
      this->payload = std::move(other.payload);
      this->left = std::move(other.left);
      this->right = std:move(other.right);
    }
    
    return *this;
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

