typedef int INT32;
#include <cstdint>
#include <iostream>
class DESUtils
{
private:
    const uint8_t des_S[8][64] =
        {
            {0xe, 0x0, 0x4, 0xf, 0xd, 0x7, 0x1, 0x4, 0x2, 0xe, 0xf, 0x2, 0xb,
             0xd, 0x8, 0x1, 0x3, 0xa, 0xa, 0x6, 0x6, 0xc, 0xc, 0xb, 0x5, 0x9,
             0x9, 0x5, 0x0, 0x3, 0x7, 0x8, 0x4, 0xf, 0x1, 0xc, 0xe, 0x8, 0x8,
             0x2, 0xd, 0x4, 0x6, 0x9, 0x2, 0x1, 0xb, 0x7, 0xf, 0x5, 0xc, 0xb,
             0x9, 0x3, 0x7, 0xe, 0x3, 0xa, 0xa, 0x0, 0x5, 0x6, 0x0, 0xd},
            {0xf, 0x3, 0x1, 0xd, 0x8, 0x4, 0xe, 0x7, 0x6, 0xf, 0xb, 0x2, 0x3,
             0x8, 0x4, 0xf, 0x9, 0xc, 0x7, 0x0, 0x2, 0x1, 0xd, 0xa, 0xc, 0x6,
             0x0, 0x9, 0x5, 0xb, 0xa, 0x5, 0x0, 0xd, 0xe, 0x8, 0x7, 0xa, 0xb,
             0x1, 0xa, 0x3, 0x4, 0xf, 0xd, 0x4, 0x1, 0x2, 0x5, 0xb, 0x8, 0x6,
             0xc, 0x7, 0x6, 0xc, 0x9, 0x0, 0x3, 0x5, 0x2, 0xe, 0xf, 0x9},
            {0xa, 0xd, 0x0, 0x7, 0x9, 0x0, 0xe, 0x9, 0x6, 0x3, 0x3, 0x4, 0xf,
             0x6, 0x5, 0xa, 0x1, 0x2, 0xd, 0x8, 0xc, 0x5, 0x7, 0xe, 0xb, 0xc,
             0x4, 0xb, 0x2, 0xf, 0x8, 0x1, 0xd, 0x1, 0x6, 0xa, 0x4, 0xd, 0x9,
             0x0, 0x8, 0x6, 0xf, 0x9, 0x3, 0x8, 0x0, 0x7, 0xb, 0x4, 0x1, 0xf,
             0x2, 0xe, 0xc, 0x3, 0x5, 0xb, 0xa, 0x5, 0xe, 0x2, 0x7, 0xc},
            {0x7, 0xd, 0xd, 0x8, 0xe, 0xb, 0x3, 0x5, 0x0, 0x6, 0x6, 0xf, 0x9,
             0x0, 0xa, 0x3, 0x1, 0x4, 0x2, 0x7, 0x8, 0x2, 0x5, 0xc, 0xb, 0x1,
             0xc, 0xa, 0x4, 0xe, 0xf, 0x9, 0xa, 0x3, 0x6, 0xf, 0x9, 0x0, 0x0,
             0x6, 0xc, 0xa, 0xb, 0xa, 0x7, 0xd, 0xd, 0x8, 0xf, 0x9, 0x1, 0x4,
             0x3, 0x5, 0xe, 0xb, 0x5, 0xc, 0x2, 0x7, 0x8, 0x2, 0x4, 0xe},
            {0x2, 0xe, 0xc, 0xb, 0x4, 0x2, 0x1, 0xc, 0x7, 0x4, 0xa, 0x7, 0xb,
             0xd, 0x6, 0x1, 0x8, 0x5, 0x5, 0x0, 0x3, 0xf, 0xf, 0xa, 0xd, 0x3,
             0x0, 0x9, 0xe, 0x8, 0x9, 0x6, 0x4, 0xb, 0x2, 0x8, 0x1, 0xc, 0xb,
             0x7, 0xa, 0x1, 0xd, 0xe, 0x7, 0x2, 0x8, 0xd, 0xf, 0x6, 0x9, 0xf,
             0xc, 0x0, 0x5, 0x9, 0x6, 0xa, 0x3, 0x4, 0x0, 0x5, 0xe, 0x3},
            {0xc, 0xa, 0x1, 0xf, 0xa, 0x4, 0xf, 0x2, 0x9, 0x7, 0x2, 0xc, 0x6,
             0x9, 0x8, 0x5, 0x0, 0x6, 0xd, 0x1, 0x3, 0xd, 0x4, 0xe, 0xe, 0x0,
             0x7, 0xb, 0x5, 0x3, 0xb, 0x8, 0x9, 0x4, 0xe, 0x3, 0xf, 0x2, 0x5,
             0xc, 0x2, 0x9, 0x8, 0x5, 0xc, 0xf, 0x3, 0xa, 0x7, 0xb, 0x0, 0xe,
             0x4, 0x1, 0xa, 0x7, 0x1, 0x6, 0xd, 0x0, 0xb, 0x8, 0x6, 0xd},
            {0x4, 0xd, 0xb, 0x0, 0x2, 0xb, 0xe, 0x7, 0xf, 0x4, 0x0, 0x9, 0x8,
             0x1, 0xd, 0xa, 0x3, 0xe, 0xc, 0x3, 0x9, 0x5, 0x7, 0xc, 0x5, 0x2,
             0xa, 0xf, 0x6, 0x8, 0x1, 0x6, 0x1, 0x6, 0x4, 0xb, 0xb, 0xd, 0xd,
             0x8, 0xc, 0x1, 0x3, 0x4, 0x7, 0xa, 0xe, 0x7, 0xa, 0x9, 0xf, 0x5,
             0x6, 0x0, 0x8, 0xf, 0x0, 0xe, 0x5, 0x2, 0x9, 0x3, 0x2, 0xc},
            {0xd, 0x1, 0x2, 0xf, 0x8, 0xd, 0x4, 0x8, 0x6, 0xa, 0xf, 0x3, 0xb,
             0x7, 0x1, 0x4, 0xa, 0xc, 0x9, 0x5, 0x3, 0x6, 0xe, 0xb, 0x5, 0x0,
             0x0, 0xe, 0xc, 0x9, 0x7, 0x2, 0x7, 0x2, 0xb, 0x1, 0x4, 0xe, 0x1,
             0x7, 0x9, 0x4, 0xc, 0xa, 0xe, 0x8, 0x2, 0xd, 0x0, 0xf, 0x6, 0xc,
             0xa, 0x9, 0xd, 0x0, 0xf, 0x3, 0x3, 0x5, 0x5, 0x6, 0x8, 0xb}};
    // Generate Key for DES, using the first 56 bits of the input key
    INT32 genKey();
    INT32 permutationKey(uint32_t *key, int mode);
    INT32 rotateKey(uint32_t *key);

    // Formal DES Algorithm for 16 rounds
    INT32 initialPermutation(uint32_t *data);
    INT32 initialPermutationReverse(uint32_t *data);
    INT32 expansionBox(uint32_t *data);
    INT32 extractionBox(uint32_t *data);
    INT32 roundHandler(uint32_t *data, uint32_t *subKey, int mode);

public:
    // Constructor
    DESUtils();
    // Destructor
    ~DESUtils();
    // Encrypt the plaintext
    void encrypt(const char *plaintext, const char *key, char *ciphertext);
    // Decrypt the ciphertext
    void decrypt(const char *ciphertext, const char *key, char *plaintext);
};
