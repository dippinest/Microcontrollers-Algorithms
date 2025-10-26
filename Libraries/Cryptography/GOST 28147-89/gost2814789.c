
#include "gost2814789.h"


// S-блок 4-х битной замены. Поскольку он не стандартизирован, вы можете
// изменить его значения на свои. Данные значения я взял из примера в статье
// в Википедии про данный алгоритм
// -------------------------------------------------------------------------------
// S-block is a 4-bit replacement block. Since it is not standardized,
// you can change its values to your own. I took these values from an
// example in a Wikipedia article about this algorithm.
static const uint8_t STable[8][16] =
{
	{0xF, 0xC, 0x2, 0xA, 0x6, 0x4, 0x5, 0x0, 0x7, 0x9, 0xE, 0xD, 0x1, 0xB, 0x8, 0x3},
	{0xB, 0x6, 0x3, 0x4, 0xC, 0xF, 0xE, 0x2, 0x7, 0xD, 0x8, 0x0, 0x5, 0xA, 0x9, 0x1},
	{0x1, 0xC, 0xB, 0x0, 0xF, 0xE, 0x6, 0x5, 0xA, 0xD, 0x4, 0x8, 0x9, 0x3, 0x7, 0x2},
	{0x1, 0x5, 0xE, 0xC, 0xA, 0x7, 0x0, 0xD, 0x6, 0x2, 0xB, 0x4, 0x9, 0x3, 0xF, 0x8},
	{0x0, 0xC, 0x8, 0x9, 0xD, 0x2, 0xA, 0xB, 0x7, 0x3, 0x6, 0x5, 0x4, 0xE, 0xF, 0x1},
	{0x8, 0x0, 0xF, 0x3, 0x2, 0x5, 0xE, 0xB, 0x1, 0xA, 0x4, 0x7, 0xC, 0x9, 0xD, 0x6},
	{0x3, 0x0, 0x6, 0xF, 0x1, 0xE, 0x9, 0x2, 0xD, 0x8, 0xC, 0x4, 0xB, 0xA, 0x5, 0x7},
	{0x1, 0xA, 0x6, 0x8, 0xF, 0xB, 0x0, 0x4, 0xC, 0x3, 0x5, 0x9, 0x7, 0xD, 0x2, 0xE},
};


static uint32_t _GOST2814789_F(uint32_t input_value)
{
	uint32_t output_value = 0;

	for (uint8_t i = 0; i < 8; ++i)
	{
		uint8_t _4bit_value = input_value & 0b1111;

		output_value |= ((uint32_t)((STable[i][_4bit_value]) & 0b1111) << (i * 4));

		input_value >>= 4;
	}

	return output_value;
}


static void _GOST2814789_64bit_Block_Encrypt(void *_64bit_block, const void *key_256bit)
{
	uint32_t L = ((uint32_t*)_64bit_block)[0];
	uint32_t R = ((uint32_t*)_64bit_block)[1];

	uint32_t K, F;

	for (uint8_t i = 0; i < 32; ++i)
	{
		if (i < 24)
		{
			K = ((uint32_t*)key_256bit)[i % 8];
		}
		else
		{
			K = ((uint32_t*)key_256bit)[31 - i];
		}

		F = ROTL(_GOST2814789_F(R + K), 11, uint32_t);

		L ^= F;

		L ^= R;
		R ^= L;
		L ^= R;
	}

	L ^= R;
	R ^= L;
	L ^= R;

	((uint32_t*)_64bit_block)[0] = L;
	((uint32_t*)_64bit_block)[1] = R;
}


static void _GOST2814789_64bit_Block_Decrypt(void *_64bit_block, const void *key_256bit)
{
	uint32_t L = ((uint32_t*)_64bit_block)[0];
	uint32_t R = ((uint32_t*)_64bit_block)[1];

	uint32_t K, F;

	uint8_t subkey_index = 7;


	for (uint8_t i = 0; i < 32; ++i)
	{
		if (i < 8)
		{
			K = ((uint32_t*)key_256bit)[i];
		}
		else
		{
			K = ((uint32_t*)key_256bit)[subkey_index];

			if (subkey_index == 0)
			{
				subkey_index = 7;
			}
			else
			{
				--subkey_index;
			}
		}

		F = ROTL(_GOST2814789_F(R + K), 11, uint32_t);

		L ^= F;

		L ^= R;
		R ^= L;
		L ^= R;
	}

	L ^= R;
	R ^= L;
	L ^= R;

	((uint32_t*)_64bit_block)[0] = L;
	((uint32_t*)_64bit_block)[1] = R;
}


uint32_t GOST2814789_Encrypt_ECB(void* data, const uint32_t data_size, const void* key_256bit)
{
	uint32_t num_of_encrypted_bytes = 0;
	

	for (; num_of_encrypted_bytes < data_size; num_of_encrypted_bytes += 8)
	{
		_GOST2814789_64bit_Block_Encrypt((uint8_t*)data + num_of_encrypted_bytes, key_256bit);
	}

	return num_of_encrypted_bytes;
}


uint32_t GOST2814789_Decrypt_ECB(void* data, const uint32_t data_size, const void* key_256bit)
{
	uint32_t num_of_encrypted_bytes = 0;
	

	for (; num_of_encrypted_bytes < data_size; num_of_encrypted_bytes += 8)
	{
		_GOST2814789_64bit_Block_Decrypt((uint8_t*)data + num_of_encrypted_bytes, key_256bit);
	}

	return num_of_encrypted_bytes;
}


uint32_t GOST2814789_Encrypt_CBC(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_256bit)
{
	uint8_t *vector = (uint8_t*)init_vector_64bit;

	uint32_t num_of_encrypted_bytes = 0;
	

	for (; num_of_encrypted_bytes < data_size; num_of_encrypted_bytes += 8)
	{
		for (uint8_t i = 0; i < 8; ++i)
		{
			(((uint8_t*)data) + num_of_encrypted_bytes)[i] ^= vector[i];
		}

		_GOST2814789_64bit_Block_Encrypt((uint8_t*)data + num_of_encrypted_bytes, key_256bit);

		for (uint8_t i = 0; i < 8; ++i)
		{
			vector[i] = (((uint8_t*)data) + num_of_encrypted_bytes)[i];
		}
	}

	return num_of_encrypted_bytes;
}


uint32_t GOST2814789_Decrypt_CBC(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_256bit)
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

		_GOST2814789_64bit_Block_Decrypt((uint8_t*)data + num_of_decrypted_bytes, key_256bit);

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


uint32_t GOST2814789_Encrypt_PCBC(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_256bit)
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

		_GOST2814789_64bit_Block_Encrypt((uint8_t*)data + num_of_encrypted_bytes, key_256bit);

		for (uint8_t i = 0; i < 8; ++i)
		{
			vector_1[i] = (((uint8_t*)data) + num_of_encrypted_bytes)[i] ^ vector_2[i];
		}
	}

	return num_of_encrypted_bytes;
}


uint32_t GOST2814789_Decrypt_PCBC(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_256bit)
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

		_GOST2814789_64bit_Block_Decrypt((uint8_t*)data + num_of_decrypted_bytes, key_256bit);

		for (uint8_t i = 0; i < 8; ++i)
		{
			(((uint8_t*)data) + num_of_decrypted_bytes)[i] ^= vector_1[i];
			vector_1[i] = (((uint8_t*)data) + num_of_decrypted_bytes)[i] ^ vector_2[i];
		}
	}

	return num_of_decrypted_bytes;
}


uint32_t GOST2814789_Encrypt_CFB(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_256bit)
{
	uint8_t *vector = (uint8_t*)init_vector_64bit;

	uint32_t num_of_encrypted_bytes = 0;
	

	for (; num_of_encrypted_bytes < data_size; num_of_encrypted_bytes += 8)
	{
		_GOST2814789_64bit_Block_Encrypt(vector, key_256bit);

		for (uint8_t i = 0; i < 8; ++i)
		{
			(((uint8_t*)data) + num_of_encrypted_bytes)[i] ^= vector[i];
			vector[i] = (((uint8_t*)data) + num_of_encrypted_bytes)[i];
		}
	}

	return num_of_encrypted_bytes;
}


uint32_t GOST2814789_Decrypt_CFB(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_256bit)
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

		_GOST2814789_64bit_Block_Encrypt(vector_1, key_256bit);

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


uint32_t GOST2814789_Encrypt_OFB(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_256bit)
{
	uint8_t *vector = (uint8_t*)init_vector_64bit;

	uint32_t num_of_encrypted_bytes = 0;
	

	for (; num_of_encrypted_bytes < data_size; num_of_encrypted_bytes += 8)
	{
		_GOST2814789_64bit_Block_Encrypt(vector, key_256bit);

		for (uint8_t i = 0; i < 8; ++i)
		{
			(((uint8_t*)data) + num_of_encrypted_bytes)[i] ^= vector[i];
		}
	}

	return num_of_encrypted_bytes;
}


uint32_t GOST2814789_Decrypt_OFB(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_256bit)
{
	return GOST2814789_Encrypt_OFB(init_vector_64bit, data, data_size, key_256bit);
}


// ===============================================================================


void *GOST2814789_CTR(void *init_vector_64bit, void *_64bit_block, const void *key_256bit)
{
	uint32_t *_32bit_vector_left_path  = &(((uint32_t*)init_vector_64bit)[0]);
	uint32_t *_32bit_vector_right_path = &(((uint32_t*)init_vector_64bit)[1]);
	
	
	_GOST2814789_64bit_Block_Encrypt(_64bit_block, key_256bit);
	
	
	++(*_32bit_vector_right_path);
	
	if (*_32bit_vector_right_path == 0)
	{
		++(*_32bit_vector_left_path);
	}

	return _64bit_block;
}






