#pragma once
#include <string>
#include "transaction.hpp"

class User
{
public:
  std::string name;

  using Namepair = std::pair<std::string, std::string>;

  User(std::string name);
  
  /**
   * Dissects a simple FunCoin signature and returns the two
   * parties involved. A signature such as:
   * "Alice gives Bob"
   * Will dissect to the pair ("Alice", "Bob").
   *
   * @param signature, the signature to dissect
   * @return the pair containing the parties involved
   */
  Namepair dissectSignature(std::string signature);

  /**
   * Inspects a local transaction for validity by following the chain
   * and ensuring that every signature makes a logical connection.
   *
   * @param t, the transaction to inspect
   * @return whether or not the transaction checked out
   */
  bool inspectLocalTransaction(Transaction* t);

  /**
   * Inspects a local transaction for validity by following the chain
   * and ensuring that every signature makes a logical connection.
   * This function call must include the pair of parties involved in
   * the previous transaction.
   *
   * @param t, the transaction to inspect
   * @param previous_parties, the parties involved in the previous transaction
   * @return whether or not the transaction checked out
   */
  bool inspectLocalTransaction(Transaction* t, Namepair previous_parties);
};
