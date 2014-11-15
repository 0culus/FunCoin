#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <openssl/sha.h>

class Transaction 
{
  /*amount in Satoshi*/
  unsigned long amount;
  std::set<Transaction&> input;
  
}
