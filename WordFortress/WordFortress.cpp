#include "WordFortress.h"
#ifdef _DEBUG
#  pragma comment ( lib, "cryptlibd" )
#else
#  pragma comment ( lib, "cryptlib" )
#endif

std::string string_to_hex(const std::string& input)
{
	static const char* const lut = "0123456789ABCDEF";
	size_t len = input.length();

	std::string output;
	output.reserve(2 * len);
	for (size_t i = 0; i < len; ++i)
	{
		const unsigned char c = input[i];
		output.push_back(lut[c >> 4]);
		output.push_back(lut[c & 15]);
	}
	return output;
}

wxIMPLEMENT_APP(WordFortress);

bool WordFortress::OnInit()
{
	if (!wxApp::OnInit())
		return false;

	mainGui = new WordFortressMainGui(NULL, wxID_ANY);
	ConnectViewWithLogic();
	mainGui->Show();

	return true;
}

//int main()
//{
//	CryptoPP::AutoSeededRandomPool rnd;
//
//	CryptoPP::SecByteBlock key(0x00, 32);
//	rnd.GenerateBlock(key, key.size());
//
//	std::string testString = "Lord_Tpol";
//	CryptoPP::byte* pbData = (CryptoPP::byte*) testString.data();
//	CryptoPP::byte rKey[CryptoPP::SHA512::DIGESTSIZE];
//
//	CryptoPP::SHA256().CalculateDigest(rKey, pbData, testString.length());
//	std::cout << "Random key from String \"" << testString << "\": " << string_to_hex(std::string((char*) rKey, CryptoPP::SHA512::DIGESTSIZE)) << std::endl;
//	std::cout << "As String: " << (char*)rKey << std::endl;
//
//	// Generate a random IV
//	CryptoPP::SecByteBlock iv(CryptoPP::AES::BLOCKSIZE);
//	rnd.GenerateBlock(iv, iv.size());
//
//	CryptoPP::byte plainText[] = "123456";
//	size_t messageLen = std::strlen((char*)plainText) + 1;
//
//	//////////////////////////////////////////////////////////////////////////
//	// Encrypt
//
//	std::cout << "Text: " << plainText << std::endl;
//	std::cout << "Key: " << string_to_hex(std::string((char*)key.BytePtr(), CryptoPP::SHA256::DIGESTSIZE)) << std::endl;
//	std::cout << "IV: " << string_to_hex(std::string((char*)iv.BytePtr(), CryptoPP::SHA256::DIGESTSIZE)) << std::endl;
//
//	CryptoPP::CFB_Mode<CryptoPP::AES>::Encryption cfbEncryption(rKey, key.size(), (CryptoPP::byte*)"Lord_Tpol");
//	cfbEncryption.ProcessData(plainText, plainText, messageLen);
//
//	std::cout << "Encrypted Text: " << plainText << std::endl;
//
//	//////////////////////////////////////////////////////////////////////////
//	// Decrypt
//
//	CryptoPP::CFB_Mode<CryptoPP::AES>::Decryption cfbDecryption(rKey, key.size(), (CryptoPP::byte*)"Lord_Tpol");
//	cfbDecryption.ProcessData(plainText, plainText, messageLen);
//
//	std::cout << "Decrypted Text: " << plainText << std::endl;
//
//	WordFortressMainGui gui(NULL);
//	gui.Show();
//
//	int i = 0;
//	std::cin >> i;
//	return 0;
//}

void WordFortress::ConnectViewWithLogic()
{

}
