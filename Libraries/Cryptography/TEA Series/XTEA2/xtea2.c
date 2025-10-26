

#include "xtea2.h"


static uint32_t _rol(uint32_t base, uint8_t shift)
{
	shift &= 0x1F;
	return (base << shift) | (base >> (32 - shift));
}

static void _XTEA2_128bit_Block_Encrypt(void *_128bit_block, const void *key_128bit, uint8_t num_of_rounds)
{
	uint32_t vv;

	uint32_t v0 = ((uint32_t*)_128bit_block)[0];
	uint32_t v1 = ((uint32_t*)_128bit_block)[1] + ((uint32_t*)key_128bit)[0];
	uint32_t v2 = ((uint32_t*)_128bit_block)[2];
	uint32_t v3 = ((uint32_t*)_128bit_block)[3] + ((uint32_t*)key_128bit)[1];

	uint32_t sum = 0;

	for (uint8_t i = 0; i < num_of_rounds; ++i)
	{
		v0  += ((v1 << 4) ^ (v1 >> 5)) + (v3 ^ sum) + _rol(((uint32_t*)key_128bit)[sum & 3], v1);
		sum += 0x9E3779B9;
		v2  += ((v3 << 4) ^ (v3 >> 5)) + (v1 ^ sum) + _rol(((uint32_t*)key_128bit)[(sum >> 11) & 3], v3);
		
		vv = v0;
		v0 = v1;
		v1 = v2;
		v2 = v3;
		v3 = vv;
	}

	((uint32_t*)_128bit_block)[0] = v0 ^ ((uint32_t*)key_128bit)[2];
	((uint32_t*)_128bit_block)[1] = v1;
	((uint32_t*)_128bit_block)[2] = v2 ^ ((uint32_t*)key_128bit)[3];
	((uint32_t*)_128bit_block)[3] = v3;
}

static void _XTEA2_128bit_Block_Decrypt(void *_128bit_block, const void *key_128bit, uint8_t num_of_rounds)
{
	uint32_t vv;

	uint32_t v3 = ((uint32_t*)_128bit_block)[3];
	uint32_t v2 = ((uint32_t*)_128bit_block)[2] ^ ((uint32_t*)key_128bit)[3];
	uint32_t v1 = ((uint32_t*)_128bit_block)[1];
	uint32_t v0 = ((uint32_t*)_128bit_block)[0] ^ ((uint32_t*)key_128bit)[2];

	uint32_t sum = 0x9E3779B9 * num_of_rounds;

	for (uint8_t i = 0; i < num_of_rounds; ++i)
	{
		vv = v3;
		v3 = v2;
		v2 = v1;
		v1 = v0;
		v0 = vv;

		v2  -= ((v3 << 4) ^ (v3 >> 5)) + (v1 ^ sum) + _rol(((uint32_t*)key_128bit)[(sum >> 11) & 3], v3);
		sum -= 0x9E3779B9;
		v0  -= ((v1 << 4) ^ (v1 >> 5)) + (v3 ^ sum) + _rol(((uint32_t*)key_128bit)[sum & 3], v1);
	}

	((uint32_t*)_128bit_block)[0] = v0;
	((uint32_t*)_128bit_block)[1] = v1 - ((uint32_t*)key_128bit)[0];
	((uint32_t*)_128bit_block)[2] = v2;
	((uint32_t*)_128bit_block)[3] = v3 - ((uint32_t*)key_128bit)[1];
}

uint32_t XTEA2_Encrypt_ECB(void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds)
{
	uint32_t num_of_encrypted_bytes = 0;
	

	for (; num_of_encrypted_bytes < data_size; num_of_encrypted_bytes += 16)
	{
		_XTEA2_128bit_Block_Encrypt(data + num_of_encrypted_bytes, key_128bit, num_of_rounds);
	}

	return num_of_encrypted_bytes;
}

uint32_t XTEA2_Decrypt_ECB(void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds)
{
	uint32_t num_of_decrypted_bytes = 0;
	

	for (; num_of_decrypted_bytes < data_size; num_of_decrypted_bytes += 16)
	{
		_XTEA2_128bit_Block_Decrypt(data + num_of_decrypted_bytes, key_128bit, num_of_rounds);
	}

	return num_of_decrypted_bytes;
}

uint32_t XTEA2_Encrypt_CBC(void *init_vector_128bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds)
{
	uint8_t *vector = (uint8_t*)init_vector_128bit;

	uint32_t num_of_encrypted_bytes = 0;
	

	for (; num_of_encrypted_bytes < data_size; num_of_encrypted_bytes += 16)
	{
		for (uint8_t i = 0; i < 16; ++i)
		{
			(((uint8_t*)data) + num_of_encrypted_bytes)[i] ^= vector[i];
		}

		_XTEA2_128bit_Block_Encrypt(data + num_of_encrypted_bytes, key_128bit, num_of_rounds);

		for (uint8_t i = 0; i < 16; ++i)
		{
			vector[i] = (((uint8_t*)data) + num_of_encrypted_bytes)[i];
		}
	}

	return num_of_encrypted_bytes;
}

uint32_t XTEA2_Decrypt_CBC(void *init_vector_128bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds)
{
	uint8_t *vector_1 = (uint8_t*)init_vector_128bit;
	
	uint8_t vector_2[16];

	uint32_t num_of_decrypted_bytes = 0;
	

	for (; num_of_decrypted_bytes < data_size; num_of_decrypted_bytes += 16)
	{
		for (uint8_t i = 0; i < 16; ++i)
		{
			vector_2[i] = (((uint8_t*)data) + num_of_decrypted_bytes)[i];
		}

		_XTEA2_128bit_Block_Decrypt(data + num_of_decrypted_bytes, key_128bit, num_of_rounds);

		for (uint8_t i = 0; i < 16; ++i)
		{
			(((uint8_t*)data) + num_of_decrypted_bytes)[i] ^= vector_1[i];

			vector_1[i] ^= vector_2[i];
			vector_2[i] ^= vector_1[i];
			vector_1[i] ^= vector_2[i];
		}
	}

	return num_of_decrypted_bytes;
}

uint32_t XTEA2_Encrypt_PCBC(void *init_vector_128bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds)
{
	uint8_t *vector_1 = (uint8_t*)init_vector_128bit;
	
	uint8_t vector_2[16];

	uint32_t num_of_encrypted_bytes = 0;
	

	for (; num_of_encrypted_bytes < data_size; num_of_encrypted_bytes += 16)
	{
		for (uint8_t i = 0; i < 16; ++i)
		{
			vector_2[i] = (((uint8_t*)data) + num_of_encrypted_bytes)[i];
			(((uint8_t*)data) + num_of_encrypted_bytes)[i] ^= vector_1[i];
		}

		_XTEA2_128bit_Block_Encrypt(data + num_of_encrypted_bytes, key_128bit, num_of_rounds);

		for (uint8_t i = 0; i < 16; ++i)
		{
			vector_1[i] = (((uint8_t*)data) + num_of_encrypted_bytes)[i] ^ vector_2[i];
		}
	}

	return num_of_encrypted_bytes;
}

uint32_t XTEA2_Decrypt_PCBC(void *init_vector_128bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds)
{
	uint8_t *vector_1 = (uint8_t*)init_vector_128bit;
	
	uint8_t vector_2[16];

	uint32_t num_of_decrypted_bytes = 0;
	

	for (; num_of_decrypted_bytes < data_size; num_of_decrypted_bytes += 16)
	{
		for (uint8_t i = 0; i < 16; ++i)
		{
			vector_2[i] = (((uint8_t*)data) + num_of_decrypted_bytes)[i];
		}

		_XTEA2_128bit_Block_Decrypt(data + num_of_decrypted_bytes, key_128bit, num_of_rounds);

		for (uint8_t i = 0; i < 16; ++i)
		{
			(((uint8_t*)data) + num_of_decrypted_bytes)[i] ^= vector_1[i];
			vector_1[i] = (((uint8_t*)data) + num_of_decrypted_bytes)[i] ^ vector_2[i];
		}
	}

	return num_of_decrypted_bytes;
}

uint32_t XTEA2_Encrypt_CFB(void *init_vector_128bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds)
{
	uint8_t *vector = (uint8_t*)init_vector_128bit;

	uint32_t num_of_encrypted_bytes = 0;
	

	for (; num_of_encrypted_bytes < data_size; num_of_encrypted_bytes += 16)
	{
		_XTEA2_128bit_Block_Encrypt(vector, key_128bit, num_of_rounds);

		for (uint8_t i = 0; i < 16; ++i)
		{
			(((uint8_t*)data) + num_of_encrypted_bytes)[i] ^= vector[i];
			vector[i] = (((uint8_t*)data) + num_of_encrypted_bytes)[i];
		}
	}

	return num_of_encrypted_bytes;
}

uint32_t XTEA2_Decrypt_CFB(void *init_vector_128bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds)
{
	uint8_t *vector_1 = (uint8_t*)init_vector_128bit;
	
	uint8_t vector_2[16];

	uint32_t num_of_decrypted_bytes = 0;
	

	for (; num_of_decrypted_bytes < data_size; num_of_decrypted_bytes += 16)
	{
		for (uint8_t i = 0; i < 16; ++i)
		{
			vector_2[i] = (((uint8_t*)data) + num_of_decrypted_bytes)[i];
		}

		_XTEA2_128bit_Block_Encrypt(vector_1, key_128bit, num_of_rounds);

		for (uint8_t i = 0; i < 16; ++i)
		{
			(((uint8_t*)data) + num_of_decrypted_bytes)[i] ^= vector_1[i];

			vector_1[i] ^= vector_2[i];
			vector_2[i] ^= vector_1[i];
			vector_1[i] ^= vector_2[i];
		}
	}

	return num_of_decrypted_bytes;
}

uint32_t XTEA2_Encrypt_OFB(void *init_vector_128bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds)
{
	uint8_t *vector = (uint8_t*)init_vector_128bit;

	uint32_t num_of_encrypted_bytes = 0;
	

	for (; num_of_encrypted_bytes < data_size; num_of_encrypted_bytes += 16)
	{
		_XTEA2_128bit_Block_Encrypt(vector, key_128bit, num_of_rounds);

		for (uint8_t i = 0; i < 16; ++i)
		{
			(((uint8_t*)data) + num_of_encrypted_bytes)[i] ^= vector[i];
		}
	}

	return num_of_encrypted_bytes;
}

uint32_t XTEA2_Decrypt_OFB(void *init_vector_128bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds)
{
	return XTEA2_Encrypt_OFB(init_vector_128bit, data, data_size, key_128bit, num_of_rounds);
}


// ===============================================================================


void *XTEA2_Encrypt_CTR(void *init_vector_128bit, void *_128bit_block, const void *key_128bit, uint8_t num_of_rounds)
{
	uint32_t *_32bit_vector_left2_path  = &(((uint32_t*)init_vector_128bit)[0]);
	uint32_t *_32bit_vector_left1_path  = &(((uint32_t*)init_vector_128bit)[1]);
	uint32_t *_32bit_vector_right2_path = &(((uint32_t*)init_vector_128bit)[2]);
	uint32_t *_32bit_vector_right1_path = &(((uint32_t*)init_vector_128bit)[3]);
	
	
	_XTEA2_128bit_Block_Encrypt(_128bit_block, key_128bit, num_of_rounds);
	
	
	//
	// В данной реализации счётчик на основе
	// инициализирующего вектора инкрементируется полностью
	//
	// ===============================================================================
	//
	// In this implementation, the counter is fully
	// incremented based on the initializing vector
	//
	++(*_32bit_vector_right1_path);
	
	if (*_32bit_vector_right1_path == 0)
	{
		++(*_32bit_vector_right2_path);
	}
	
	if (*_32bit_vector_right2_path == 0)
	{
		++(*_32bit_vector_left1_path);
	}
	
	if (*_32bit_vector_left1_path == 0)
	{
		++(*_32bit_vector_left2_path);
	}

	return _128bit_block;
}

void *XTEA2_Decrypt_CTR(void *init_vector_128bit, void *_128bit_block, const void *key_128bit, uint8_t num_of_rounds)
{
	uint32_t *_32bit_vector_left2_path  = &(((uint32_t*)init_vector_128bit)[0]);
	uint32_t *_32bit_vector_left1_path  = &(((uint32_t*)init_vector_128bit)[1]);
	uint32_t *_32bit_vector_right2_path = &(((uint32_t*)init_vector_128bit)[2]);
	uint32_t *_32bit_vector_right1_path = &(((uint32_t*)init_vector_128bit)[3]);
	
	
	_XTEA2_128bit_Block_Decrypt(_128bit_block, key_128bit, num_of_rounds);
	
	
	//
	// В данной реализации счётчик на основе
	// инициализирующего вектора инкрементируется полностью
	//
	// ===============================================================================
	//
	// In this implementation, the counter is fully
	// incremented based on the initializing vector
	//
	++(*_32bit_vector_right1_path);
	
	if (*_32bit_vector_right1_path == 0)
	{
		++(*_32bit_vector_right2_path);
	}
	
	if (*_32bit_vector_right2_path == 0)
	{
		++(*_32bit_vector_left1_path);
	}
	
	if (*_32bit_vector_left1_path == 0)
	{
		++(*_32bit_vector_left2_path);
	}

	return _128bit_block;
}








