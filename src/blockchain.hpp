/**
 * blockchain.hpp
 * Part of FunCoin, the CSE441 Fall 2014 semester project
 *
 * This file specifies the namespace and classes for the blockchain
 *
 */

#pragma once

#include <string>
#include <memory>
#include <chrono>
#include <cstdint>
#include <openssl/sha.h>
#include <openssl/engine.h>
#include "c_redblack.hpp"

using namespace rbm;

namespace blockchain {
    
    typedef uint8_t byte;
    constexpr size_t size = 32;
    
    //! a block in the blockchain
    class block {
    protected:
        blockheader _header;
        constexpr int _magic = 0xD9B4BEF9; // just like bitcoin!
        int _blocksize;
        
    public:
        block();
        
        //prevent copying of blocks
        block(const block&) = delete;
        ~block();
    };
    
    //! encapsulate the blockheader
    class blockheader {
    protected:
        std::unique_ptr<unsigned char[SHA256_DIGEST_LENGTH]> _hash_previous_block;
        std::unique_ptr<unsigned char[SHA256_DIGEST_LENGTH]> _hash_current_block;
        time_point _timestamp;
        uint32_t _nonce;
        
    public:
        blockheader();
        blockheader(std::unique_ptr<unsigned char[]> hash_previous,
                    std::unique_ptr<unsigned char[]> hash_current,
                    time_point timestamp,
                    uint32_t nonce) {
            
            static_assert(sizeof(hash_previous) == SHA256_DIGEST_LENGTH,
                          "Previous block hash must be 256 bits");
            static_assert(sizeof(hash_current) == SHA256_DIGEST_LENGTH,
                          "Current block hash must be 256 bits");
            static_assert(std::is_same<decltype(nonce), uint32_t>::value,
                          "Nonce must be uint32_t");
            
            this._hash_previous_block = hash_previous;
            this._hash_current_block = hash_current;
            this._timestamp = timestamp;
            this._nonce = nonce;
        }
        
        //prevent copying of blockheaders
        blockheader(const blockheader&) = delete;
        ~blockheader();
    };
    
    //! merkle tree using the left leaning redblack tree
    //! https://github.com/amiller/redblackmerkle
    class merkle {
        
    };
    
}
