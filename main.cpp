#include <iostream>
#include <string>
#include <openssl/aes.h>

std::string encryptAES(const std::string& plaintext, const std::string& key) {
    std::string encryptedText;

    // Initialize the AES encryption context
    AES_KEY aesKey;
    AES_set_encrypt_key(reinterpret_cast<const unsigned char*>(key.c_str()), key.length() * 8, &aesKey);

    // Allocate memory for the output buffer
    encryptedText.resize(plaintext.size());

    // Encrypt the plaintext using AES
    AES_encrypt(reinterpret_cast<const unsigned char*>(plaintext.c_str()),
                reinterpret_cast<unsigned char*>(&encryptedText[0]), &aesKey);

    return encryptedText;
}

std::string decryptAES(const std::string& ciphertext, const std::string& key) {
    std::string decryptedText;

    // Initialize the AES decryption context
    AES_KEY aesKey;
    AES_set_decrypt_key(reinterpret_cast<const unsigned char*>(key.c_str()), key.length() * 8, &aesKey);

    // Allocate memory for the output buffer
    decryptedText.resize(ciphertext.size());

    // Decrypt the ciphertext using AES
    AES_decrypt(reinterpret_cast<const unsigned char*>(ciphertext.c_str()),
                reinterpret_cast<unsigned char*>(&decryptedText[0]), &aesKey);

    return decryptedText;
}

int main() {
    std::string plaintext = "Hello, World!";
    std::string key = "mySecretKey12345";

    std::string encryptedText = encryptAES(plaintext, key);
    std::cout << "Encrypted text: " << encryptedText << std::endl;

    std::string decryptedText = decryptAES(encryptedText, key);
    std::cout << "Decrypted text: " << decryptedText << std::endl;

    return 0;
}
