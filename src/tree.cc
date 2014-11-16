/**
 * tree.cc
 * Implementation of our pseudo-merkle-tree for FunCoin
 *
 *
 */

#include "tree.h"

//! make sure payload is null for a new node
tree::BasicTreeNode() {
  this->payload = NULL;
}

std::string tree::getHash() {
  
  //! cases:
  // node is a leaf
  if (!left && !right) {
    std::stringstream s;
    s << this->payload;
    return s.str();
  }
  
  // node is not a leaf, but left child exists
  else if (left && !right) {
    return this->left.getHash() + "";
  }
  
  // node is not a leaf, but right child exists
  else if (!left && right) {
    return "" + this->right.getHash();
  }
  
  // node is not a leaf, so hash is concat of left and right children
  else {
    return this->left.getHash() + this->right.getHash();
  }
}

std::unique_ptr<T> tree::getPayload() {
  return this->payload;
}

void tree:setPayload(const T& payload) {
  this->payload = payload;
}

std::unique_ptr<T> tree::getLeftChild() {
  return this->left;
}

void tree::setLeftChild(const BasicTreeNode& node) {
  this->left = node;
}

std::unique_ptr<T> tree::getRightChild() {
  return this->right;
}

void tree::setRightChild(const BasicTreeNode& node) {
  this->right = node;
}