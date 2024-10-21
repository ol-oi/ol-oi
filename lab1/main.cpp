#include <iostream>
#include "encrypt.cpp"
#include "decrypt.cpp"

int main() {
    std::string text;
    int columns;

    std::cout << "Введите текст для шифрования: ";
    std::getline(std::cin, text);
    
    std::cout << "Введите количество столбцов: ";
    std::cin >> columns;

    std::string encrypted_text = encrypt(text, columns);
    std::cout << "Зашифрованный текст: " << encrypted_text << std::endl;

    std::string decrypted_text = decrypt(encrypted_text, columns);
    std::cout << "Расшифрованный текст: " << decrypted_text << std::endl;

    return 0;
}
