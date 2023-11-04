#pragma once

#include <cstdint>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

union U128
{
    u64 vec64u[2]; 
    u32 vec32u[4];
    u16 vec16u[8];
    u8  vec8u[16];
    u8  mat4x4[4][4];
};

static const u8 SBoxEnc[256] = {
    0x63U, 0x7cU, 0x77U, 0x7bU, 0xf2U, 0x6bU, 0x6fU, 0xc5U,
    0x30U, 0x01U, 0x67U, 0x2bU, 0xfeU, 0xd7U, 0xabU, 0x76U,
    0xcaU, 0x82U, 0xc9U, 0x7dU, 0xfaU, 0x59U, 0x47U, 0xf0U,
    0xadU, 0xd4U, 0xa2U, 0xafU, 0x9cU, 0xa4U, 0x72U, 0xc0U,
    0xb7U, 0xfdU, 0x93U, 0x26U, 0x36U, 0x3fU, 0xf7U, 0xccU,
    0x34U, 0xa5U, 0xe5U, 0xf1U, 0x71U, 0xd8U, 0x31U, 0x15U,
    0x04U, 0xc7U, 0x23U, 0xc3U, 0x18U, 0x96U, 0x05U, 0x9aU,
    0x07U, 0x12U, 0x80U, 0xe2U, 0xebU, 0x27U, 0xb2U, 0x75U,
    0x09U, 0x83U, 0x2cU, 0x1aU, 0x1bU, 0x6eU, 0x5aU, 0xa0U,
    0x52U, 0x3bU, 0xd6U, 0xb3U, 0x29U, 0xe3U, 0x2fU, 0x84U,
    0x53U, 0xd1U, 0x00U, 0xedU, 0x20U, 0xfcU, 0xb1U, 0x5bU,
    0x6aU, 0xcbU, 0xbeU, 0x39U, 0x4aU, 0x4cU, 0x58U, 0xcfU,
    0xd0U, 0xefU, 0xaaU, 0xfbU, 0x43U, 0x4dU, 0x33U, 0x85U,
    0x45U, 0xf9U, 0x02U, 0x7fU, 0x50U, 0x3cU, 0x9fU, 0xa8U,
    0x51U, 0xa3U, 0x40U, 0x8fU, 0x92U, 0x9dU, 0x38U, 0xf5U,
    0xbcU, 0xb6U, 0xdaU, 0x21U, 0x10U, 0xffU, 0xf3U, 0xd2U,
    0xcdU, 0x0cU, 0x13U, 0xecU, 0x5fU, 0x97U, 0x44U, 0x17U,
    0xc4U, 0xa7U, 0x7eU, 0x3dU, 0x64U, 0x5dU, 0x19U, 0x73U,
    0x60U, 0x81U, 0x4fU, 0xdcU, 0x22U, 0x2aU, 0x90U, 0x88U,
    0x46U, 0xeeU, 0xb8U, 0x14U, 0xdeU, 0x5eU, 0x0bU, 0xdbU,
    0xe0U, 0x32U, 0x3aU, 0x0aU, 0x49U, 0x06U, 0x24U, 0x5cU,
    0xc2U, 0xd3U, 0xacU, 0x62U, 0x91U, 0x95U, 0xe4U, 0x79U,
    0xe7U, 0xc8U, 0x37U, 0x6dU, 0x8dU, 0xd5U, 0x4eU, 0xa9U,
    0x6cU, 0x56U, 0xf4U, 0xeaU, 0x65U, 0x7aU, 0xaeU, 0x08U,
    0xbaU, 0x78U, 0x25U, 0x2eU, 0x1cU, 0xa6U, 0xb4U, 0xc6U,
    0xe8U, 0xddU, 0x74U, 0x1fU, 0x4bU, 0xbdU, 0x8bU, 0x8aU,
    0x70U, 0x3eU, 0xb5U, 0x66U, 0x48U, 0x03U, 0xf6U, 0x0eU,
    0x61U, 0x35U, 0x57U, 0xb9U, 0x86U, 0xc1U, 0x1dU, 0x9eU,
    0xe1U, 0xf8U, 0x98U, 0x11U, 0x69U, 0xd9U, 0x8eU, 0x94U,
    0x9bU, 0x1eU, 0x87U, 0xe9U, 0xceU, 0x55U, 0x28U, 0xdfU,
    0x8cU, 0xa1U, 0x89U, 0x0dU, 0xbfU, 0xe6U, 0x42U, 0x68U,
    0x41U, 0x99U, 0x2dU, 0x0fU, 0xb0U, 0x54U, 0xbbU, 0x16U
};

static const u8 SBoxDec[256] = {
    0x52U, 0x09U, 0x6aU, 0xd5U, 0x30U, 0x36U, 0xa5U, 0x38U,
    0xbfU, 0x40U, 0xa3U, 0x9eU, 0x81U, 0xf3U, 0xd7U, 0xfbU,
    0x7cU, 0xe3U, 0x39U, 0x82U, 0x9bU, 0x2fU, 0xffU, 0x87U,
    0x34U, 0x8eU, 0x43U, 0x44U, 0xc4U, 0xdeU, 0xe9U, 0xcbU,
    0x54U, 0x7bU, 0x94U, 0x32U, 0xa6U, 0xc2U, 0x23U, 0x3dU,
    0xeeU, 0x4cU, 0x95U, 0x0bU, 0x42U, 0xfaU, 0xc3U, 0x4eU,
    0x08U, 0x2eU, 0xa1U, 0x66U, 0x28U, 0xd9U, 0x24U, 0xb2U,
    0x76U, 0x5bU, 0xa2U, 0x49U, 0x6dU, 0x8bU, 0xd1U, 0x25U,
    0x72U, 0xf8U, 0xf6U, 0x64U, 0x86U, 0x68U, 0x98U, 0x16U,
    0xd4U, 0xa4U, 0x5cU, 0xccU, 0x5dU, 0x65U, 0xb6U, 0x92U,
    0x6cU, 0x70U, 0x48U, 0x50U, 0xfdU, 0xedU, 0xb9U, 0xdaU,
    0x5eU, 0x15U, 0x46U, 0x57U, 0xa7U, 0x8dU, 0x9dU, 0x84U,
    0x90U, 0xd8U, 0xabU, 0x00U, 0x8cU, 0xbcU, 0xd3U, 0x0aU,
    0xf7U, 0xe4U, 0x58U, 0x05U, 0xb8U, 0xb3U, 0x45U, 0x06U,
    0xd0U, 0x2cU, 0x1eU, 0x8fU, 0xcaU, 0x3fU, 0x0fU, 0x02U,
    0xc1U, 0xafU, 0xbdU, 0x03U, 0x01U, 0x13U, 0x8aU, 0x6bU,
    0x3aU, 0x91U, 0x11U, 0x41U, 0x4fU, 0x67U, 0xdcU, 0xeaU,
    0x97U, 0xf2U, 0xcfU, 0xceU, 0xf0U, 0xb4U, 0xe6U, 0x73U,
    0x96U, 0xacU, 0x74U, 0x22U, 0xe7U, 0xadU, 0x35U, 0x85U,
    0xe2U, 0xf9U, 0x37U, 0xe8U, 0x1cU, 0x75U, 0xdfU, 0x6eU,
    0x47U, 0xf1U, 0x1aU, 0x71U, 0x1dU, 0x29U, 0xc5U, 0x89U,
    0x6fU, 0xb7U, 0x62U, 0x0eU, 0xaaU, 0x18U, 0xbeU, 0x1bU,
    0xfcU, 0x56U, 0x3eU, 0x4bU, 0xc6U, 0xd2U, 0x79U, 0x20U,
    0x9aU, 0xdbU, 0xc0U, 0xfeU, 0x78U, 0xcdU, 0x5aU, 0xf4U,
    0x1fU, 0xddU, 0xa8U, 0x33U, 0x88U, 0x07U, 0xc7U, 0x31U,
    0xb1U, 0x12U, 0x10U, 0x59U, 0x27U, 0x80U, 0xecU, 0x5fU,
    0x60U, 0x51U, 0x7fU, 0xa9U, 0x19U, 0xb5U, 0x4aU, 0x0dU,
    0x2dU, 0xe5U, 0x7aU, 0x9fU, 0x93U, 0xc9U, 0x9cU, 0xefU,
    0xa0U, 0xe0U, 0x3bU, 0x4dU, 0xaeU, 0x2aU, 0xf5U, 0xb0U,
    0xc8U, 0xebU, 0xbbU, 0x3cU, 0x83U, 0x53U, 0x99U, 0x61U,
    0x17U, 0x2bU, 0x04U, 0x7eU, 0xbaU, 0x77U, 0xd6U, 0x26U,
    0xe1U, 0x69U, 0x14U, 0x63U, 0x55U, 0x21U, 0x0cU, 0x7dU,
};

static const u8 GLookupE[256] = 
{
    0x01U, 0x03U, 0x05U, 0x0fU, 0x11U, 0x33U, 0x55U, 0xffU, 
    0x1aU, 0x2eU, 0x72U, 0x96U, 0xa1U, 0xf8U, 0x13U, 0x35U,
    0x5fU, 0xe1U, 0x38U, 0x48U, 0xd8U, 0x73U, 0x95U, 0xa4U,
    0xf7U, 0x02U, 0x06U, 0x0aU, 0x1eU, 0x22U, 0x66U, 0xaaU,
    0xe5U, 0x34U, 0x5cU, 0xe4U, 0x37U, 0x59U, 0xebU, 0x26U,
    0x6aU, 0xbeU, 0xd9U, 0x70U, 0x90U, 0xabU, 0xe6U, 0x31U,
    0x53U, 0xf5U, 0x04U, 0x0cU, 0x14U, 0x3cU, 0x44U, 0xccU, 
    0x4fU, 0xd1U, 0x68U, 0xb8U, 0xd3U, 0x6eU, 0xb2U, 0xcdU,
    0x4cU, 0xd4U, 0x67U, 0xa9U, 0xe0U, 0x3bU, 0x4dU, 0xd7U,
    0x62U, 0xa6U, 0xf1U, 0x08U, 0x18U, 0x28U, 0x78U, 0x88U,
    0x83U, 0x9eU, 0xb9U, 0xd0U, 0x6bU, 0xbdU, 0xdcU, 0x7fU, 
    0x81U, 0x98U, 0xb3U, 0xceU, 0x49U, 0xdbU, 0x76U, 0x9aU,
    0xb5U, 0xc4U, 0x57U, 0xf9U, 0x10U, 0x30U, 0x50U, 0xf0U, 
    0x0bU, 0x1dU, 0x27U, 0x69U, 0xbbU, 0xd6U, 0x61U, 0xa3U,
    0xfeU, 0x19U, 0x2bU, 0x7dU, 0x87U, 0x92U, 0xadU, 0xecU, 
    0x2fU, 0x71U, 0x93U, 0xaeU, 0xe9U, 0x20U, 0x60U, 0xa0U,
    0xfbU, 0x16U, 0x3aU, 0x4eU, 0xd2U, 0x6dU, 0xb7U, 0xc2U, 
    0x5dU, 0xe7U, 0x32U, 0x56U, 0xfaU, 0x15U, 0x3fU, 0x41U,
    0xc3U, 0x5eU, 0xe2U, 0x3dU, 0x47U, 0xc9U, 0x40U, 0xc0U, 
    0x5bU, 0xedU, 0x2cU, 0x74U, 0x9cU, 0xbfU, 0xdaU, 0x75U,
    0x9fU, 0xbaU, 0xd5U, 0x64U, 0xacU, 0xefU, 0x2aU, 0x7eU, 
    0x82U, 0x9dU, 0xbcU, 0xdfU, 0x7aU, 0x8eU, 0x89U, 0x80U,
    0x9bU, 0xb6U, 0xc1U, 0x58U, 0xe8U, 0x23U, 0x65U, 0xafU, 
    0xeaU, 0x25U, 0x6fU, 0xb1U, 0xc8U, 0x43U, 0xc5U, 0x54U,
    0xfcU, 0x1fU, 0x21U, 0x63U, 0xa5U, 0xf4U, 0x07U, 0x09U, 
    0x1bU, 0x2dU, 0x77U, 0x99U, 0xb0U, 0xcbU, 0x46U, 0xcaU,
    0x45U, 0xcfU, 0x4aU, 0xdeU, 0x79U, 0x8bU, 0x86U, 0x91U, 
    0xa8U, 0xe3U, 0x3eU, 0x42U, 0xc6U, 0x51U, 0xf3U, 0x0eU,
    0x12U, 0x36U, 0x5aU, 0xeeU, 0x29U, 0x7bU, 0x8dU, 0x8cU,
    0x8fU, 0x8aU, 0x85U, 0x94U, 0xa7U, 0xf2U, 0x0dU, 0x17U,
    0x39U, 0x4bU, 0xddU, 0x7cU, 0x84U, 0x97U, 0xa2U, 0xfdU, 
    0x1cU, 0x24U, 0x6cU, 0xb4U, 0xc7U, 0x52U, 0xf6U, 0x01U
};

static const u8 GLookupF[256] =
{
    0x00U, 0x00U, 0x19U, 0x01U, 0x32U, 0x02U, 0x1aU, 0xc6U, 
    0x4bU, 0xc7U, 0x1bU, 0x68U, 0x33U, 0xeeU, 0xdfU, 0x03U,
    0x64U, 0x04U, 0xe0U, 0x0eU, 0x34U, 0x8dU, 0x81U, 0xefU, 
    0x4cU, 0x71U, 0x08U, 0xc8U, 0xf8U, 0x69U, 0x1cU, 0xc1U,
    0x7dU, 0xc2U, 0x1dU, 0xb5U, 0xf9U, 0xb9U, 0x27U, 0x6aU,
    0x4dU, 0xe4U, 0xa6U, 0x72U, 0x9aU, 0xc9U, 0x09U, 0x78U,
    0x65U, 0x2fU, 0x8aU, 0x05U, 0x21U, 0x0fU, 0xe1U, 0x24U,
    0x12U, 0xf0U, 0x82U, 0x45U, 0x35U, 0x93U, 0xdaU, 0x8eU,
    0x96U, 0x8fU, 0xdbU, 0xbdU, 0x36U, 0xd0U, 0xceU, 0x94U,
    0x13U, 0x5cU, 0xd2U, 0xf1U, 0x40U, 0x46U, 0x83U, 0x38U,
    0x66U, 0xddU, 0xfdU, 0x30U, 0xbfU, 0x06U, 0x8bU, 0x62U,
    0xb3U, 0x25U, 0xe2U, 0x98U, 0x22U, 0x88U, 0x91U, 0x10U,
    0x7eU, 0x6eU, 0x48U, 0xc3U, 0xa3U, 0xb6U, 0x1eU, 0x42U,
    0x3aU, 0x6bU, 0x28U, 0x54U, 0xfaU, 0x85U, 0x3dU, 0xbaU,
    0x2bU, 0x79U, 0x0aU, 0x15U, 0x9bU, 0x9fU, 0x5eU, 0xcaU, 
    0x4eU, 0xd4U, 0xacU, 0xe5U, 0xf3U, 0x73U, 0xa7U, 0x57U,
    0xafU, 0x58U, 0xa8U, 0x50U, 0xf4U, 0xeaU, 0xd6U, 0x74U,
    0x4fU, 0xaeU, 0xe9U, 0xd5U, 0xe7U, 0xe6U, 0xadU, 0xe8U,
    0x2cU, 0xd7U, 0x75U, 0x7aU, 0xebU, 0x16U, 0x0bU, 0xf5U, 
    0x59U, 0xcbU, 0x5fU, 0xb0U, 0x9cU, 0xa9U, 0x51U, 0xa0U,
    0x7fU, 0x0cU, 0xf6U, 0x6fU, 0x17U, 0xc4U, 0x49U, 0xecU, 
    0xd8U, 0x43U, 0x1fU, 0x2dU, 0xa4U, 0x76U, 0x7bU, 0xb7U,
    0xccU, 0xbbU, 0x3eU, 0x5aU, 0xfbU, 0x60U, 0xb1U, 0x86U,
    0x3bU, 0x52U, 0xa1U, 0x6cU, 0xaaU, 0x55U, 0x29U, 0x9dU,
    0x97U, 0xb2U, 0x87U, 0x90U, 0x61U, 0xbeU, 0xdcU, 0xfcU, 
    0xbcU, 0x95U, 0xcfU, 0xcdU, 0x37U, 0x3fU, 0x5bU, 0xd1U,
    0x53U, 0x39U, 0x84U, 0x3cU, 0x41U, 0xa2U, 0x6dU, 0x47U, 
    0x14U, 0x2aU, 0x9eU, 0x5dU, 0x56U, 0xf2U, 0xd3U, 0xabU,
    0x44U, 0x11U, 0x92U, 0xd9U, 0x23U, 0x20U, 0x2eU, 0x89U,
    0xb4U, 0x7cU, 0xb8U, 0x26U, 0x77U, 0x99U, 0xe3U, 0xa5U,
    0x67U, 0x4aU, 0xedU, 0xdeU, 0xc5U, 0x31U, 0xfeU, 0x18U,
    0x0dU, 0x63U, 0x8cU, 0x80U, 0xc0U, 0xf7U, 0x70U, 0x07U
};

static const u32 RconLUT[15] = 
{
    0x01000000U, 0x02000000U, 0x04000000U, 0x08000000U,
    0x10000000U, 0x20000000U, 0x40000000U, 0x80000000U,
    0x1B000000U, 0x36000000U, 0x6C000000U, 0xD8000000U,
    0xAB000000U, 0x4D000000U, 0x9A000000U
};

void aes128(U128* in, U128* out, U128* key);
