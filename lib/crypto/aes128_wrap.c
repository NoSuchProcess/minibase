#include <string.h>
#include <endian.h>

#include "aes128.h"

/* Ref. RFC 3394 Advanced Encryption Standard (AES) Key Wrap Algorithm */

static uint64_t wrapmask(int n)
{
#ifdef BIGENDIAN
	return n;
#else
	return ((uint64_t)htonl(n) << 32);
#endif
}

void aes128_wrap(uint8_t key[16], void* buf, int len)
{
	struct aes128 ae;

	int n = len / 8 - 1;
	uint64_t* R = buf;
	uint8_t B[16];
	int i, j;

	aes128_init(&ae, key);

	for(j = 0; j <= 5; j++)
		for(i = 1; i <= n; i++) {
			memcpy(B + 0, &R[0], 8);
			memcpy(B + 8, &R[i], 8);

			aes128_encrypt(&ae, B);

			memcpy(&R[0], B + 0, 8);
			memcpy(&R[i], B + 8, 8);

			R[0] ^= wrapmask(n*j + i);
		}

	aes128_fini(&ae);
}
