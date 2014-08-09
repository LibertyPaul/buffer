#include <iostream>
#include <memory>
#include <istream>
#include <ostream>

#include <random>

using namespace std;
#include "Buffer.hpp"

template<typename intType>
string dec2bin(const intType &n){
	size_t length = sizeof(intType) * 8;
	string res;
	for(size_t i = 0; i < length; ++i)
		if(n & 1 << (length - i - 1))
			res += "1";
		else
			res += "0";
	return res;
}


int main(){
	uint32_t size = 10;
	Buffer buffer(size);

	random_device rd;
	for(uint32_t i = 0; i < size; ++i)
		buffer.write<uint8_t>(0);

	buffer.setBit(true, 8);
	buffer.setBit(true, 18);
	buffer.setBit(true, 28);
	buffer.setBit(true, 38);
	buffer.setBit(true, 48);
	buffer.setBit(true, 79);

	for(uint32_t i = 0; i < size; ++i)
		cout << dec2bin<uint8_t>(buffer.get(i)) << endl;
}
