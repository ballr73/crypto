#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <openssl/aes.h>

void encryptFile(const std::string& inputFile, const std::string& outputFile, const std::string& key) {
    // Initialize the AES encryption context
    AES_KEY aesKey;
    AES_set_encrypt_key(reinterpret_cast<const unsigned char*>(key.c_str()), key.length() * 8, &aesKey);

    std::ifstream inputFileStream(inputFile, std::ios::binary);
    std::ofstream outputFileStream(outputFile, std::ios::binary);

    if (inputFileStream && outputFileStream) {
        // Read and encrypt the file contents in blocks
        unsigned char inputBuffer[AES_BLOCK_SIZE];
        unsigned char outputBuffer[AES_BLOCK_SIZE];

        while (inputFileStream.read(reinterpret_cast<char*>(inputBuffer), AES_BLOCK_SIZE)) {
            AES_encrypt(inputBuffer, outputBuffer, &aesKey);
            outputFileStream.write(reinterpret_cast<const char*>(outputBuffer), AES_BLOCK_SIZE);
        }

        // Process any remaining bytes
        size_t bytesRead = inputFileStream.gcount();
        if (bytesRead > 0) {
            memset(inputBuffer + bytesRead, 0, AES_BLOCK_SIZE - bytesRead);
            AES_encrypt(inputBuffer, outputBuffer, &aesKey);
            outputFileStream.write(reinterpret_cast<const char*>(outputBuffer), AES_BLOCK_SIZE);
        }

        std::cout << "Encryption completed. Encrypted file: " << outputFile << std::endl;
    } else {
        std::cerr << "Error opening file!" << std::endl;
    }

    inputFileStream.close();
    outputFileStream.close();
}

void decryptFile(const std::string& inputFile, const std::string& outputFile, const std::string& key) {
    // Initialize the AES decryption context
    AES_KEY aesKey;
    AES_set_decrypt_key(reinterpret_cast<const unsigned char*>(key.c_str()), key.length() * 8, &aesKey);

    std::ifstream inputFileStream(inputFile, std::ios::binary);
    std::ofstream outputFileStream(outputFile, std::ios::binary);

    if (inputFileStream && outputFileStream) {
        // Read and decrypt the file contents in blocks
        unsigned char inputBuffer[AES_BLOCK_SIZE];
        unsigned char outputBuffer[AES_BLOCK_SIZE];

        while (inputFileStream.read(reinterpret_cast<char*>(inputBuffer), AES_BLOCK_SIZE)) {
            AES_decrypt(inputBuffer, outputBuffer, &aesKey);
            outputFileStream.write(reinterpret_cast<const char*>(outputBuffer), AES_BLOCK_SIZE);
        }

        std::streamsize bytesRead = inputFileStream.gcount();
        if (bytesRead > 0) {
            outputFileStream.write(reinterpret_cast<const char*>(outputBuffer), bytesRead);
        }

        std::cout << "Decryption completed. Decrypted file: " << outputFile << std::endl;
    } else {
        std::cerr << "Error opening file!" << std::endl;
    }

    inputFileStream.close();
    outputFileStream.close();
}

int main(int argc, char* argv[]) {
    if (argc != 6) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file> <key> <-e/-d>" << std::endl;
        return 1;
    }

    std::string inputFile = argv[1];
    std::string outputFile = argv[2];
    std::string key = argv[3];
    std::string action = argv[4];

    if (action == "-e") {
        // Encrypt the input file
        encryptFile(inputFile, outputFile, key);
    } else if (action == "-d") {
        // Decrypt the input file
        decryptFile(inputFile, outputFile, key);
    } else {
        std::cerr << "Invalid action specified. Use -e for encryption or -d for decryption." << std::endl;
        return 1;
    }

    return 0;
}
