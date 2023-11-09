#pragma once

#include <cstdint>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef unsigned uint;

union U128
{
    u64 vec64u[2]; 
    u32 vec32u[4];
    u16 vec16u[8];
    u8  vec8u[16];
    u8  mat4x4[4][4];
};

//regular aes128 functions
void aes128(U128* in, U128* out, U128* key);
void aes128Inv(U128* in, U128* out, U128* key);

void aes128_ecb_enc(U128* in, U128* out, uint sizeBytes, U128* key);
void aes128_ecb_dec(U128* in, U128* out, uint sizeBytes, U128* key);

void aes128_ctr_enc(U128* in, U128* out, u64 nonce, uint sizeBytes, U128* key);

//aes128 that allows a custom number of rounds
void aes128(U128* in, U128* out, U128* key, uint rounds);
void aes128Inv(U128* in, U128* out, U128* key, uint rounds);

void aes128_ecb_enc(U128* in, U128* out, uint sizeBytes, U128* key, uint rounds);
void aes128_ecb_dec(U128* in, U128* out, uint sizeBytes, U128* key, uint rounds);

void aes128_ctr_enc(U128* in, U128* out, u64 nonce, uint sizeBytes, U128* key, uint rounds);
