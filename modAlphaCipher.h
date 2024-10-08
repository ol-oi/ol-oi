#pragma once
#include <vector>
#include <string>
#include <map>
class modAlphaCipher
{
private:
std::string numAlpha =
	"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; //алфавит по порядку
	std::map <char,int> alphaNum; //ассоциативный массив "номер по символу"
	std::vector <int> key; //ключ
	std::vector<int> convert(const std::string& s); //преобразование строка-вектор
	std::string convert(const std::vector<int>& v); //преобразование вектор-строка
public:
	modAlphaCipher() = delete; 
	modAlphaCipher(const std::string& skey); 
	std::string encrypt(const std::string& open_text); 
	std::string decrypt(const std::string& cipher_text);
};

modAlphaCipher::modAlphaCipher(const std::string& skey)
{ 
	for (unsigned i = 0; i<numAlpha.size(); i++) {
alphaNum[numAlpha[i]] = i;
}
key = convert(skey);
}

std::string modAlphaCipher::encrypt(const std::string& open_text)
{ std::vector<int> work = convert(open_text);
for(unsigned i=0; i < work.size(); i++) {
work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
}
return convert(work);
}

std::string modAlphaCipher::decrypt(const std::string& cipher_text)
{ std::vector<int> work = convert(cipher_text);
for(unsigned i=0; i < work.size(); i++) {
work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();
}
return convert(work);
}

inline std::vector<int> modAlphaCipher::convert(const std::string& s)
{ std::vector<int> result;
for(auto c:s) {
result.push_back(alphaNum[c]);
}
return result;
}
inline std::string modAlphaCipher::convert(const std::vector<int>& v)
{ std::string result;
for(auto i:v) {
result.push_back(numAlpha[i]);
}
return result;
}



