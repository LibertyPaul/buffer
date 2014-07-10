#include <iostream>
#include <memory>
#include <istream>
#include <ostream>

#include <random>

using namespace std;
#include "Buffer.hpp"


int main(){
	uint32_t size = 1024;
	Buffer buffer(size);

	random_device rd;
	for(uint32_t i = 0; i < size / sizeof(uint32_t); ++i)
		buffer.write<uint32_t>(rd());
}
