
#include "rtea128bitkey.h"


static void _RTEA128BitKey_64bit_Block_Encrypt(void *_64bit_block, const void *key_128bit)
{
	uint32_t* a = &(((uint32_t*)_64bit_block)[0]);
	uint32_t* b = &(((uint32_t*)_64bit_block)[1]);

	for (int8_t i = 0; i < 48; ++i)
	{
		*a += *b + ((*b << 6) ^ (*b >> 8)) + ((uint32_t*)key_128bit)[i & 0b11] + i;

		++i;

		*b += *a + ((*a << 6) ^ (*a >> 8)) + ((uint32_t*)key_128bit)[i & 0b11] + i;
	}
}

static void _RTEA128BitKey_64bit_Block_Decrypt(void *_64bit_block, const void *key_128bit)
{
	uint32_t* a = &(((uint32_t*)_64bit_block)[0]);
	uint32_t* b = &(((uint32_t*)_64bit_block)[1]);

	for (int8_t i = 47; i >= 0; --i)
	{
		*b -= *a + ((*a << 6) ^ (*a >> 8)) + ((uint32_t*)key_128bit)[i & 0b11] + i;

		--i;

		*a -= *b + ((*b << 6) ^ (*b >> 8)) + ((uint32_t*)key_128bit)[i & 0b11] + i;
	}
}



uint32_t RTEA128BitKey_Encrypt_ECB(void *data, const uint32_t data_size, const void *key_128bit)
{
	uint32_t num_of_encrypted_bytes = 0;
	

	for (; num_of_encrypted_bytes < data_size; num_of_encrypted_bytes += 8)
	{
		_RTEA128BitKey_64bit_Block_Encrypt((uint8_t*)data + num_of_encrypted_bytes, key_128bit);
	}

	return num_of_encrypted_bytes;
}


uint32_t RTEA128BitKey_Decrypt_ECB(void *data, const uint32_t data_size, const void *key_128bit)
{
	uint32_t num_of_decrypted_bytes = 0;
	

	for (; num_of_decrypted_bytes < data_size; num_of_decrypted_bytes += 8)
	{
		_RTEA128BitKey_64bit_Block_Decrypt((uint8_t*)data + num_of_decrypted_bytes, key_128bit);
	}

	return num_of_decrypted_bytes;
}


uint32_t RTEA128BitKey_Encrypt_CBC(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_128bit)
{
	uint8_t *vector = (uint8_t*)init_vector_64bit;

	uint32_t num_of_encrypted_bytes = 0;
	

	for (; num_of_encrypted_bytes < data_size; num_of_encrypted_bytes += 8)
	{
		for (uint8_t i = 0; i < 8; ++i)
		{
			(((uint8_t*)data) + num_of_encrypted_bytes)[i] ^= vector[i];
		}

		_RTEA128BitKey_64bit_Block_Encrypt((uint8_t*)data + num_of_encrypted_bytes, key_128bit);

		for (uint8_t i = 0; i < 8; ++i)
		{
			vector[i] = (((uint8_t*)data) + num_of_encrypted_bytes)[i];
		}
	}

	return num_of_encrypted_bytes;
}


uint32_t RTEA128BitKey_Decrypt_CBC(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_128bit)
{
	uint8_t *vector_1 = (uint8_t*)init_vector_64bit;
	
	uint8_t vector_2[8];

	uint32_t num_of_decrypted_bytes = 0;
	

	for (; num_of_decrypted_bytes < data_size; num_of_decrypted_bytes += 8)
	{
		for (uint8_t i = 0; i < 8; ++i)
		{
			vector_2[i] = (((uint8_t*)data) + num_of_decrypted_bytes)[i];
		}

		_RTEA128BitKey_64bit_Block_Decrypt((uint8_t*)data + num_of_decrypted_bytes, key_128bit);

		for (uint8_t i = 0; i < 8; ++i)
		{
			(((uint8_t*)data) + num_of_decrypted_bytes)[i] ^= vector_1[i];

			vector_1[i] ^= vector_2[i];
			vector_2[i] ^= vector_1[i];
			vector_1[i] ^= vector_2[i];
		}
	}

	return num_of_decrypted_bytes;
}


uint32_t RTEA128BitKey_Encrypt_PCBC(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_128bit)
{
	uint8_t *vector_1 = (uint8_t*)init_vector_64bit;
	
	uint8_t vector_2[8];

	uint32_t num_of_encrypted_bytes = 0;
	

	for (; num_of_encrypted_bytes < data_size; num_of_encrypted_bytes += 8)
	{
		for (uint8_t i = 0; i < 8; ++i)
		{
			vector_2[i] = (((uint8_t*)data) + num_of_encrypted_bytes)[i];
			(((uint8_t*)data) + num_of_encrypted_bytes)[i] ^= vector_1[i];
		}

		_RTEA128BitKey_64bit_Block_Encrypt((uint8_t*)data + num_of_encrypted_bytes, key_128bit);

		for (uint8_t i = 0; i < 8; ++i)
		{
			vector_1[i] = (((uint8_t*)data) + num_of_encrypted_bytes)[i] ^ vector_2[i];
		}
	}

	return num_of_encrypted_bytes;
}


uint32_t RTEA128BitKey_Decrypt_PCBC(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_128bit)
{
	uint8_t *vector_1 = (uint8_t*)init_vector_64bit;
	
	uint8_t vector_2[8];

	uint32_t num_of_decrypted_bytes = 0;
	

	for (; num_of_decrypted_bytes < data_size; num_of_decrypted_bytes += 8)
	{
		for (uint8_t i = 0; i < 8; ++i)
		{
			vector_2[i] = (((uint8_t*)data) + num_of_decrypted_bytes)[i];
		}

		_RTEA128BitKey_64bit_Block_Decrypt((uint8_t*)data + num_of_decrypted_bytes, key_128bit);

		for (uint8_t i = 0; i < 8; ++i)
		{
			(((uint8_t*)data) + num_of_decrypted_bytes)[i] ^= vector_1[i];
			vector_1[i] = (((uint8_t*)data) + num_of_decrypted_bytes)[i] ^ vector_2[i];
		}
	}

	return num_of_decrypted_bytes;
}


uint32_t RTEA128BitKey_Encrypt_CFB(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_128bit)
{
	uint8_t *vector = (uint8_t*)init_vector_64bit;

	uint32_t num_of_encrypted_bytes = 0;
	

	for (; num_of_encrypted_bytes < data_size; num_of_encrypted_bytes += 8)
	{
		_RTEA128BitKey_64bit_Block_Encrypt(vector, key_128bit);

		for (uint8_t i = 0; i < 8; ++i)
		{
			(((uint8_t*)data) + num_of_encrypted_bytes)[i] ^= vector[i];
			vector[i] = (((uint8_t*)data) + num_of_encrypted_bytes)[i];
		}
	}

	return num_of_encrypted_bytes;
}


uint32_t RTEA128BitKey_Decrypt_CFB(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_128bit)
{
	uint8_t *vector_1 = (uint8_t*)init_vector_64bit;
	
	uint8_t vector_2[8];

	uint32_t num_of_decrypted_bytes = 0;
	

	for (; num_of_decrypted_bytes < data_size; num_of_decrypted_bytes += 8)
	{
		for (uint8_t i = 0; i < 8; ++i)
		{
			vector_2[i] = (((uint8_t*)data) + num_of_decrypted_bytes)[i];
		}

		_RTEA128BitKey_64bit_Block_Encrypt(vector_1, key_128bit);

		for (uint8_t i = 0; i < 8; ++i)
		{
			(((uint8_t*)data) + num_of_decrypted_bytes)[i] ^= vector_1[i];

			vector_1[i] ^= vector_2[i];
			vector_2[i] ^= vector_1[i];
			vector_1[i] ^= vector_2[i];
		}
	}

	return num_of_decrypted_bytes;
}


uint32_t RTEA128BitKey_Encrypt_OFB(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_128bit)
{
	uint8_t *vector = (uint8_t*)init_vector_64bit;

	uint32_t num_of_encrypted_bytes = 0;
	

	for (; num_of_encrypted_bytes < data_size; num_of_encrypted_bytes += 8)
	{
		_RTEA128BitKey_64bit_Block_Encrypt(vector, key_128bit);

		for (uint8_t i = 0; i < 8; ++i)
		{
			(((uint8_t*)data) + num_of_encrypted_bytes)[i] ^= vector[i];
		}
	}

	return num_of_encrypted_bytes;
}


uint32_t RTEA128BitKey_Decrypt_OFB(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_128bit)
{
	return RTEA128BitKey_Encrypt_OFB(init_vector_64bit, data, data_size, key_128bit);
}


