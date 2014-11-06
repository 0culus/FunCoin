#include <beecrypt/dsa.h>
#include <beecrypt/sha256.h>
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

  sha256Param sp;
  byte result = 0;
  sp.data[0] = 100;
  sp.data[1] = 20;
  sha256Process(&sp);
  sha256Digest(&sp, &result);
  std::cout << result << std::endl;
  return 0;
} 
