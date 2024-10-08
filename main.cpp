#include <iostream>
#include "modAlphaCipher.h"
using namespace std;
void check(const string& Text, const string& key)
{ 
	
	string cipherText;
	string decryptedText;
	modAlphaCipher cipher(key);
	cipherText = cipher.encrypt(Text);
	decryptedText = cipher.decrypt(cipherText);
	std::cout << "Введите ключ: " << std::endl;
	cout << " " << key << endl;
	std::cout << "Ваш текст: " << std::endl;
	cout << Text << endl;
	std::cout << "Обработанный текст: " << std::endl;
	cout << cipherText << endl;
	cout << decryptedText << endl;
		if (Text == decryptedText)
	cout << "Ok\n";
		else cout << "Err\n";
}
int main(int argc, char **argv)
{ 
	check("ПРИВЕТ","SIMPLE");
	check("ПРИВЕТ","EXAMPLE");
	check("ПРИВЕТ","QWERTY");
return 0;
}
