#pragma once

#include <string>

#include "cryptopp\osrng.h"

static class WordEncoder
{
public:
	static void ENCRYPT(std::string& password, const std::string& key, std::string& salt);
	static bool DECRYPT(std::string& password, const std::string& key, const std::string& salt);

private:
	static void GENERATE_KEY_AND_IV(const std::string& key, CryptoPP::byte hKey[], CryptoPP::SecByteBlock& iv);
};
