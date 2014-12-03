#include <openssl/dsa.h>
#include <openssl/engine.h>
#include <iostream>

/*
SYNOPSIS of the DSA library

 #include <openssl/dsa.h>
 #include <openssl/engine.h>
 DSA *  DSA_new(void);
 void   DSA_free(DSA *dsa);
 int    DSA_size(const DSA *dsa);
 DSA *  DSA_generate_parameters(int bits, unsigned char *seed,
                int seed_len, int *counter_ret, unsigned long *h_ret,
                void (*callback)(int, int, void *), void *cb_arg);
 DH *   DSA_dup_DH(const DSA *r);
 int    DSA_generate_key(DSA *dsa);
 int    DSA_sign(int dummy, const unsigned char *dgst, int len,
                unsigned char *sigret, unsigned int *siglen, DSA *dsa);
 int    DSA_sign_setup(DSA *dsa, BN_CTX *ctx, BIGNUM **kinvp,
                BIGNUM **rp);
 int    DSA_verify(int dummy, const unsigned char *dgst, int len,
                const unsigned char *sigbuf, int siglen, DSA *dsa);
 void DSA_set_default_method(const DSA_METHOD *meth);
 const DSA_METHOD *DSA_get_default_method(void);
 int DSA_set_method(DSA *dsa, const DSA_METHOD *meth);
 DSA *DSA_new_method(ENGINE *engine);
 const DSA_METHOD *DSA_OpenSSL(void);
 int DSA_get_ex_new_index(long argl, char *argp, int (*new_func)(),
             int (*dup_func)(), void (*free_func)());
 int DSA_set_ex_data(DSA *d, int idx, char *arg);
 char *DSA_get_ex_data(DSA *d, int idx);
 DSA_SIG *DSA_SIG_new(void);
 void   DSA_SIG_free(DSA_SIG *a);
 int    i2d_DSA_SIG(const DSA_SIG *a, unsigned char **pp);
 DSA_SIG *d2i_DSA_SIG(DSA_SIG **v, unsigned char **pp, long length);
 DSA_SIG *DSA_do_sign(const unsigned char *dgst, int dlen, DSA *dsa);
 int    DSA_do_verify(const unsigned char *dgst, int dgst_len,
             DSA_SIG *sig, DSA *dsa);
 DSA *  d2i_DSAPublicKey(DSA **a, unsigned char **pp, long length);
 DSA *  d2i_DSAPrivateKey(DSA **a, unsigned char **pp, long length);
 DSA *  d2i_DSAparams(DSA **a, unsigned char **pp, long length);
 int    i2d_DSAPublicKey(const DSA *a, unsigned char **pp);
 int    i2d_DSAPrivateKey(const DSA *a, unsigned char **pp);
 int    i2d_DSAparams(const DSA *a,unsigned char **pp);
 int    DSAparams_print(BIO *bp, const DSA *x);
 int    DSAparams_print_fp(FILE *fp, const DSA *x);
 int    DSA_print(BIO *bp, const DSA *x, int off);
int    DSA_print_fp(FILE *bp, const DSA *x, int off);

SHA Synopsis
#include <openssl/sha.h>
 unsigned char *SHA1(const unsigned char *d, unsigned long n,
                  unsigned char *md);
 int SHA1_Init(SHA_CTX *c);
 int SHA1_Update(SHA_CTX *c, const void *data,
                  unsigned long len);
 int SHA1_Final(unsigned char *md, SHA_CTX *c);

*/
int main(void) {
  DSA* dsa = DSA_new();

  if (!DSA_generate_parameters_ex(dsa, 1024, (const unsigned char *) "fuckit", 6, NULL, NULL, NULL)) {
    std::cerr << "DSA Parameter Generation failed!" << std::endl;
  }

  if (!DSA_generate_key(dsa)) {
    std::cerr << "DSA Key Generation failed!" << std::endl;
  }

  std::cout << "Public key: " << dsa->pub_key << std::endl;
  std::cout << "Private key: " << dsa->priv_key << std::endl;

  unsigned char *ret = (unsigned char *) malloc(sizeof(unsigned char) * DSA_size(dsa));
  unsigned int length;
  const unsigned char *digest = (unsigned char *) "Hello world";


  if (!DSA_sign(42, digest, 11, ret, &length, dsa)) {
    std::cerr << "DSA Signing failed!" << std::endl;
  }
 
  std::cout << (DSA_verify(42, digest, 11, ret, length, dsa)==1?"Valid":"Invalid") << std::endl;

  DSA_free(dsa);
  return 0;
} 
