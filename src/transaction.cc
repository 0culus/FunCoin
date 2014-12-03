#include "transaction.hpp"

Transaction::Transaction(Fundoshi amount, Transaction* input, std::string signature) {
  this->amount = amount;
  this->input.push_back(input);
  this->output = NULL;
  this->change = NULL;
  this->signature = signature;
}

void Transaction::addInput(Fundoshi amount, Transaction* input) {
  this->amount += amount;
  this->input.push_back(input);
}

void Transaction::addOutput(Transaction* output, Transaction* change) {
  this->output = output;
  this->change = change;
}

Fundoshi Transaction::getUnspent() {
  if (output == NULL) {
    return amount;
  }
  
  return 0;
}

std::string Transaction::getSignature()
{
  return signature;
}

std::vector<Transaction*> Transaction::getInputs()
{
  return input;
}
