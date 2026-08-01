
#include "simplehash.h"


uint32_t SimpleHash_FNV(void *data, uint32_t data_size)
{
	#define FNV_32_PRIME 0x01000193
	

	uint32_t hval = 0x811C9DC5;

	for (uint32_t i = 0; i < data_size; ++i)
	{
		hval ^= ((uint8_t*)data)[i];
		hval *= FNV_32_PRIME;
	}

	return hval;
}


uint32_t SimpleHash_Jenkins(void *data, uint32_t data_size)
{
	uint32_t hash = 0;

	for (uint32_t i = 0; i < data_size; ++i)
	{
		hash += ((uint8_t*)data)[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}

	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);

	return hash;
}

uint32_t SimpleHash_PJWHash(void *data, uint32_t data_size)
{
	uint32_t hash = 0;
	uint32_t test = 0;
	
	for (uint32_t i = 0; i < data_size; ++i)
	{
		hash = (hash << 4) + *((uint8_t*)data);
		
		if ((test = hash & 0xf0000000) != 0)
		{
			hash = ((hash ^ (test >> 24)) & (0xfffffff));
		}
	}
	
	return hash;
}


