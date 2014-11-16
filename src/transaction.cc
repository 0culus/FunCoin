#include "transaction.h"

Transaction::Transaction(Fundoshi amount, Transaction* input) {
  this->amount = amount;
  this->input.insert(input);
  this->output = NULL;
  this->change = NULL;
}

void Transaction::addInput(Fundoshi amount, Transaction* input) {
  this->amount += amount;
  this->input.insert(input);
}

void Transaction::addOutput(Transaction *output, Transaction *change) {
  this->output = output;
  this->change = change;
}

Fundoshi Transaction::getUnspent() {
  if (output == NULL) {
    return amount;
  }

  return 0;
}
