/**
 * blockchain.hpp
 * 
 * A simple hacky "blockchain" in order to demonstrate
 * FunCoin
 * Sean Turner
 * TODO: finish this
 */

#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

namespace Fakeblockchain {
  
  //! a fake block just for demonstrating concepts
  //! does not worry about hashes of previous blocks
  //! just stores transactions
  public class block {
  private:
    //std::string _previousBlockHash;
    std::vector<std::string> _transactions;
    std::string _fakeMerkleRoot;
    
    void _concatMerkleRoot(const std::string& transaction) {
      
    }
    
  public:
    block();
    block(const block& other);
    ~block();
    
    //std::string GetPreviousBlockHash() {
    //  return this->_previousBlockHash;
    //}
    
    //! add a transaction to the list of transactions
    void AddTransaction(const std::string& transaction) {
      this->_transactions.push_back(transaction);
    }
    
    bool ValidateTransaction(const std::string& transaction) {
      
    }
  };
  
}