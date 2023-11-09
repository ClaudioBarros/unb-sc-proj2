#include "tests.h"
#include "aes.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <cstring>

void writePPM(std::string filename, 
              std::string header,
              std::vector<U128> &imgData,
              uint numBytes)
{
    std::ofstream out(filename, std::ios::binary);

    u8* ptrBytes = &imgData[0].vec8u[0];
    for(uint i = 0; i < numBytes; i++)
    {
        if(i < header.size())
        {
            out << header[i];
            continue;
        }
        out << ptrBytes[i];
    }
}

void selfieTest()
{
    std::string filename = "test_pic.ppm";
    std::ifstream inFile(filename, std::ios_base::binary);

    inFile.seekg(0, std::ios_base::end);
    size_t length = inFile.tellg();
    inFile.seekg(0, std::ios_base::beg);

    std::vector<u8> buffer;
    buffer.reserve(length);

    std::copy( std::istreambuf_iterator<char>(inFile),
               std::istreambuf_iterator<char>(),
               std::back_inserter(buffer) );
    
    u64 nonce = rand();

    uint numBlocks = length/16 + length%16;

    const char* keystr = "2b7e151628aed2a6abf7158809cf4f3c";
    U128 key{}; 
    for(int i = 0; i < 16; i++)
        key.vec8u[i] = (u8) keystr[i];

    std::vector<U128> pic(numBlocks, {0});
    memcpy(pic[0].vec8u, &buffer[0], sizeof(u8) * buffer.size());

    std::string ppmFileHeader = "P6\n684 684\n255\n";
    std::vector<U128> outPic(numBlocks, {0});

    // 1 round
    uint numRounds = 1;
    aes128_ctr_enc(&pic[0], &outPic[0], nonce, length, &key, numRounds);
    writePPM("img_1round.ppm", ppmFileHeader, outPic, buffer.size());
    
    // 5 rounds 
    numRounds = 5;
    aes128_ctr_enc(&pic[0], &outPic[0], nonce, length, &key, numRounds);
    writePPM("img_5rounds.ppm", ppmFileHeader, outPic, buffer.size());

    // 9 rounds
    numRounds = 9;
    aes128_ctr_enc(&pic[0], &outPic[0], nonce, length, &key, numRounds);
    writePPM("img_9rounds.ppm", ppmFileHeader, outPic, buffer.size());

    // 13 rounds
    numRounds = 13;
    aes128_ctr_enc(&pic[0], &outPic[0], nonce, length, &key, numRounds);
    writePPM("img_13rounds.ppm", ppmFileHeader, outPic,buffer.size());
}

void runAllTests()
{
    
}
