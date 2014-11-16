#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <openssl/sha.h>
#include <set>

/*The smallest FunCoin unit*/
using Fundoshi = unsigned long;

class Transaction 
{
  /*amount in Satoshi*/
  Fundoshi amount;
  std::set<Transaction*> input;
  Transaction* output;
  Transaction* change;

  Transaction(Fundoshi amount, Transaction* input);
  void addInput(Fundoshi amount, Transaction* input);
  void addOutput(Transaction *output, Transaction *change);
  /**
   * Returns the unspent funcoin. If the ouput
   * is not null, returns -1
   * @return unspent function if output = null, -1 otherwise
   */
  Fundoshi getUnspent();
  
  friend std::ostream &operator<<(std::ostream &output,
                                  const Transaction &T) {
    output << "Amount: " << T.amount << std::endl;
    return output;
  }
  
};
