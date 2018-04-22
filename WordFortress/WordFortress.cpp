#include "WordFortress.h"
#ifdef _DEBUG
#  pragma comment ( lib, "cryptlibd" )
#else
#  pragma comment ( lib, "cryptlib" )
#endif

int main()
{
	AutoSeededRandomPool rnd;

	SecByteBlock key(0x00, 32);
	rnd.GenerateBlock(key, key.size());

	// Generate a random IV
	SecByteBlock iv(AES::BLOCKSIZE);
	rnd.GenerateBlock(iv, iv.size());

	byte plainText[] = "Hello! How are you.";
	size_t messageLen = std::strlen((char*)plainText) + 1;

	//////////////////////////////////////////////////////////////////////////
	// Encrypt

	std::cout << "Text: " << plainText << std::endl;
	std::cout << "Key: " << key << std::endl;
	std::cout << "IV: " << iv << std::endl;

	CFB_Mode<AES>::Encryption cfbEncryption(key, key.size(), iv);
	cfbEncryption.ProcessData(plainText, plainText, messageLen);

	std::cout << "Encrypted Text: " << plainText << std::endl;

	//////////////////////////////////////////////////////////////////////////
	// Decrypt

	CFB_Mode<AES>::Decryption cfbDecryption(key, key.size(), iv);
	cfbDecryption.ProcessData(plainText, plainText, messageLen);

	std::cout << "Decrypted Text: " << plainText << std::endl;

	int i = 0;
	std::cin >> i;
	return 0;
}
