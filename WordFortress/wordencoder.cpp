#ifdef _DEBUG
#  pragma comment ( lib, "cryptlibd" )
#else
#  pragma comment ( lib, "cryptlib" )
#endif

#include "wordencoder.h"
#include "cryptopp\modes.h"
#include "cryptopp\aes.h"

void WordEncoder::ENCRYPT(std::string& password, const std::string& key, std::string& salt)
{
	CryptoPP::AutoSeededRandomPool rnd;

	// add salt to password
	CryptoPP::SecByteBlock rndSalt(0x00, 32);
	rnd.GenerateBlock(rndSalt, rndSalt.size());
	salt = std::string((char*)rndSalt.data());
	password.append(salt);

	CryptoPP::byte hKey[CryptoPP::SHA256::DIGESTSIZE];
	CryptoPP::SecByteBlock iv(CryptoPP::AES::BLOCKSIZE);
	GENERATE_KEY_AND_IV(key, hKey, iv);

	CryptoPP::CFB_Mode<CryptoPP::AES>::Encryption cfbEncryption(hKey, CryptoPP::SHA256::DIGESTSIZE, iv);
	cfbEncryption.ProcessData((CryptoPP::byte*)password.data(), (CryptoPP::byte*)password.data(), password.size());
}

bool WordEncoder::DECRYPT(std::string& password, const std::string& key, const std::string& salt)
{
	CryptoPP::byte hKey[CryptoPP::SHA256::DIGESTSIZE];
	CryptoPP::SecByteBlock iv(CryptoPP::AES::BLOCKSIZE);
	GENERATE_KEY_AND_IV(key, hKey, iv);

	CryptoPP::CFB_Mode<CryptoPP::AES>::Decryption cfbDecryption(hKey, CryptoPP::SHA256::DIGESTSIZE, iv);
	cfbDecryption.ProcessData((CryptoPP::byte*)password.data(), (CryptoPP::byte*)password.data(), password.size());

	if (password.size() <= salt.size())
	{
#ifdef _DEBUG
		std::cout << "Decrypt failed. Password is too short." << std::endl;
#endif
		return false;
	}
	else
	{
		std::string retrievedSalt = password.substr(password.size() - salt.size(), salt.size());
		if (retrievedSalt != salt)
		{
#ifdef _DEBUG
			std::cout << "Decrypt failed. Retrieved salt is different." << std::endl;
#endif
			return false;
		}
		else
		{
			password = password.substr(0, password.size() - salt.size());

			return true;
		}
	}
}

void WordEncoder::GENERATE_KEY_AND_IV(const std::string& key, CryptoPP::byte hKey[], CryptoPP::SecByteBlock& iv)
{
	// hash key:
	CryptoPP::SHA256().CalculateDigest(hKey, (CryptoPP::byte*) key.data(), key.length());

	// generate IV from hashed key:
	CryptoPP::byte hhkey[CryptoPP::SHA224::DIGESTSIZE];
	CryptoPP::SHA224().CalculateDigest(hhkey, hKey, CryptoPP::SHA256::DIGESTSIZE);
	iv.Assign(hhkey, CryptoPP::AES::BLOCKSIZE);
}
