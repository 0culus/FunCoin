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
#include <openssl/sha.h>

namespace blockchain {
    typedef uint8_t byte;
    constexpr size_t size = 32;
    
    class block {
    protected:
        std::unique_ptr<byte[size]> _hash;
        int _magic = 0xD9B4BEF9;
        int _blocksize;
        
        
        static_assert(sizeof(_hash) == 32, "Hash array must be exactly 256 bits");
        
    };
    
    class blockheader {
    public:
        std::unique_ptr<byte[size]> hash_previous_block;
        std::unique_ptr<byte[size]> hash_current_block;
        time_point timestamp;
    };
}
