#include "aes.h" 
#include "openssl/evp.h"
#include "openssl/err.h"
#include "openssl/conf.h"
#include "cstdio"

#define OPENSSL_API_COMPAT 0x10100000L

void printBytesDec(u8* bytes)
{
    printf("[");
    for(int i = 0; i < 16; i++)
    {
        if(i == 8)
            printf(" %u \n ", *bytes++);
        else
            printf(" %u ", *bytes++);
    }
    printf("]\n");
}

void openssl_handleErrors(void)
{
    ERR_print_errors_fp(stderr);
    abort();
}

void openssl_aes128(unsigned char *plaintext, int plaintext_len, unsigned char *key,
                    unsigned char *ciphertext)
{
    EVP_CIPHER_CTX *ctx;

    int len;

    int ciphertext_len;

    /* Create and initialise the context */
    if(!(ctx = EVP_CIPHER_CTX_new()))
        openssl_handleErrors();

    /*
     * Initialise the encryption operation. IMPORTANT - ensure you use a key
     * and IV size appropriate for your cipher
     * In this example we are using 256 bit AES (i.e. a 256 bit key). The
     * IV size for *most* modes is the same as the block size. For AES this
     * is 128 bits
     */
    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_128_ecb(), NULL, key, nullptr))
        openssl_handleErrors();

    /*
     * Provide the message to be encrypted, and obtain the encrypted output.
     * EVP_EncryptUpdate can be called multiple times if necessary
     */
    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        openssl_handleErrors();
    ciphertext_len = len;

    /*
     * Finalise the encryption. Further ciphertext bytes may be written at
     * this stage.
     */
    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
        openssl_handleErrors();
    ciphertext_len += len;

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);
}
int main()
{
    U128 key{};
    for(int i =0; i< 16; i++)
        key.vec8u[i] = i; 
    
    U128 plaintext{};
    for(int i = 0; i < 16; i++)
        plaintext.vec8u[i] = i*2;
    
    U128 ciphertext{};

    aes128(&plaintext, &ciphertext, &key);

    printf("plaintext bytes: \n");
    printBytesDec(plaintext.vec8u);
     
    printf("\nmy ciphertext: \n");
    printBytesDec(ciphertext.vec8u);

    u8 openssl_ciphertext[44]{};
    openssl_aes128((unsigned char *)&plaintext, 128, 
                   (unsigned char *)&key,
                   (unsigned char *)&openssl_ciphertext);

    printf("\nopenssl ciphertext: \n");
    printBytesDec(openssl_ciphertext);
}
