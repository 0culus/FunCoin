#include <beecrypt/dsa.h>
#include <iostream>

int main(void) {
  dldp_p parameters;
  randomGeneratorContext rng;

  dsaparamMake(&parameters, &rng, 512);

  std::cout << "Prime number:" << parameters.p << std::endl;
  std::cout << "Cofactor:" << parameters.q << std::endl;
  std::cout << "p = qr + 1:" << parameters.r << std::endl;
  std::cout << "Generator of Zp or Generator of G order q:" << parameters.g << std::endl;
  std::cout << "n = p-1 = qr:" << parameters.n << std::endl;
  return 0;
} 
