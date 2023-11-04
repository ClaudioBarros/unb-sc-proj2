#include "aes.h"

#include <cstring>
#include <cassert>

u32 GetKeyOffset(u32* key, unsigned offset, unsigned keySizeBytes)
{
    assert(offset < (keySizeBytes-1)/4);
    return *(key+offset);
}

u32 subWord(u32 in)
{
    u8* inByte = (u8*) &in;
    u32 out = 0;
    u8* outByte = (u8*) &out;
    *outByte = SBoxEnc[*(inByte)];
    *(outByte + 1) = SBoxEnc[*(inByte+1)];
    *(outByte + 2) = SBoxEnc[*(inByte+2)];
    *(outByte + 3) = SBoxEnc[*(inByte+3)]; 

    return *((u32*) outByte);
}

u32 rotWord(u32 in)
{
    u8* inByte = (u8*) &in;
    u32 out = 0;
    u8* outByte = (u8*) &out;
    *outByte = *(inByte+1);
    *(outByte + 1) = *(inByte + 2);
    *(outByte + 2) = *(inByte + 3);
    *(outByte + 3) = *(inByte);

    return *((u32*) outByte);
}

void expandKey(u32* keyIn, u32* keyOut) 
{
    unsigned keyInSize= 16; //in bytes
    unsigned keyOutSize = 172; //in bytes
    for(unsigned i = 0; i < 44; i++)
    {
        if(i < 4)
        {
            *(keyOut+i) = GetKeyOffset(keyIn, i, keyInSize);
            continue;
        }
        
        if(i%4 == 0)
        {
            if(i==4)
            {
                *(keyOut+i) = 
                    subWord(rotWord(GetKeyOffset(keyOut, i-1, keyOutSize))) ^ 
                    RconLUT[i/4 - 1] ^ 
                    GetKeyOffset(keyOut, i-4, keyOutSize);
            }
            else
            {
                *(keyOut+i) = 
                    subWord(rotWord(GetKeyOffset(keyOut, i-4, keyOutSize))) ^ 
                    RconLUT[i/4 - 1] ^ 
                    GetKeyOffset(keyOut, i-4, keyOutSize);
            }
            continue;
        }

        else
        {
            *(keyOut+i) = GetKeyOffset(keyOut, i-1, keyOutSize) ^
                          GetKeyOffset(keyOut, i-4, keyOutSize);
        }
    }

}

void addRoundKey(U128* state, U128* key) 
{
    state->vec64u[1] = state->vec64u[1] ^ key->vec64u[1];
    state->vec64u[0] = state->vec64u[0] ^ key->vec64u[0];
}

void subBytes(U128* state)
{
    for(int i = 0; i < 16; i++)
        state->vec8u[i] = SBoxEnc[state->vec8u[i]]; 
}

void shiftRows(U128* state)
{
    u8 r0[4] = {state->vec8u[0], state->vec8u[4],state->vec8u[8],  state->vec8u[12]};
    u8 r1[4] = {state->vec8u[1], state->vec8u[5],state->vec8u[9],  state->vec8u[13]};
    u8 r2[4] = {state->vec8u[2], state->vec8u[6],state->vec8u[10], state->vec8u[14]};
    u8 r3[4] = {state->vec8u[3], state->vec8u[7],state->vec8u[11], state->vec8u[15]};

    //shift r1 1 position to the right
    u8 tmp[4]{};
    tmp[0] = r1[3];
    tmp[1] = r1[0];
    tmp[2] = r1[1];
    tmp[3] = r1[2];
    memcpy(r1, tmp, sizeof(u8) * 4);

    //shift r2 2 positions to the right
    tmp[0] = r2[2];
    tmp[1] = r2[3];
    tmp[2] = r2[0];
    tmp[3] = r2[1];
    memcpy(r2, tmp, sizeof(u8) * 4);

    //shift r3 3 positions to the right
    tmp[0] = r3[1];
    tmp[1] = r3[2];
    tmp[2] = r3[3];
    tmp[3] = r3[0];
    memcpy(r3, tmp, sizeof(u8) * 4);

    for(int i = 0; i < 16; i+=4)
    {
        state->vec8u[i] = r0[i/4];
        state->vec8u[i+1] = r1[i/4];
        state->vec8u[i+2] = r2[i/4];
        state->vec8u[i+3] = r3[i/4];
    }
}

u8 GMul(u8 a, u8 b)
{
    if(a == 1 || b == 1) 
        return (a*b);
    else
        return GLookupE[GLookupF[a] + GLookupF[b]]; 
}

u8 GDotProduct(u8* vecA, u8* vecB)
{
     return GMul(vecA[0], vecB[0]) ^ 
            GMul(vecA[1], vecB[1]) ^
            GMul(vecA[2], vecB[2]) ^
            GMul(vecA[3], vecB[3]);
}

void mixColumns(U128* state)
{

    u8 m[4][4]= { 2, 3, 1, 1,
                  1, 2, 3, 1,
                  1, 1, 2, 3,
                  3, 1, 1, 3 };

    u8 r0[4] = {state->vec8u[0], state->vec8u[4],state->vec8u[8],  state->vec8u[12]};
    u8 r1[4] = {state->vec8u[1], state->vec8u[5],state->vec8u[9],  state->vec8u[13]};
    u8 r2[4] = {state->vec8u[2], state->vec8u[6],state->vec8u[10], state->vec8u[14]};
    u8 r3[4] = {state->vec8u[3], state->vec8u[7],state->vec8u[11], state->vec8u[15]};

    for(int i = 0; i < 4; i++)
    {
        state->mat4x4[i][0] = GDotProduct(&state->mat4x4[i][0], &m[i][0]);
        state->mat4x4[i][1] = GDotProduct(&state->mat4x4[i][0], &m[i][1]);
        state->mat4x4[i][2] = GDotProduct(&state->mat4x4[i][0], &m[i][2]);
        state->mat4x4[i][3] = GDotProduct(&state->mat4x4[i][0], &m[i][3]);
    }
}

void aes128(U128* in, U128* out, U128* key)
{
    U128 expKey[11]{};
    expandKey(key->vec32u, expKey->vec32u);

    U128 state = *in;

    unsigned keyIndex = 0;
    //initial round:
    addRoundKey(&state, &expKey[keyIndex++]);

    //intermediate rounds:
    for(int i = 0; i < 10; i++)
    {
        subBytes(&state);
        shiftRows(&state);
        if(i < 9)
            mixColumns(&state);
        addRoundKey(&state, &expKey[keyIndex++]);
    }

    *out = state;
}



