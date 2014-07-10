#include <memory>
#include <istream>
#include <ostream>

#include <cstring>
#include <stdexcept>

using namespace std;
#include "Buffer.hpp"

Buffer::Buffer(uint64_t size): size(size), buffer(new uint8_t[size]), readPos(0), writePos(0){}

Buffer::Buffer(const Buffer &buffer): size(buffer.getSize()), buffer(new uint8_t[size]), readPos(0), writePos(0){
	memcpy(this->get(), buffer.get(), size);
}

Buffer::Buffer(Buffer &&buffer): size(buffer.getSize()), buffer(move(buffer.buffer)), readPos(0), writePos(0){}



void Buffer::dropPointers(){
	readPos = 0;
	writePos = 0;
}


void Buffer::write(const void *data, uint32_t length){
	if(getWriteSpace() < length)
		throw logic_error("Buffer overflow");

	memcpy(buffer.get() + writePos, data, length);
	writePos += length;
}

void Buffer::write(istream &i, uint32_t length){
	if(getWriteSpace() < length)
		throw logic_error("Buffer overflow");

	void *ptr = buffer.get() + writePos;
	i.read(reinterpret_cast<char *>(ptr), length);
	writePos += length;
}


uint32_t Buffer::getWriteSpace() const{
	return size - writePos;
}

uint32_t Buffer::getReadSpace() const{
	return size - readPos;
}

void Buffer::read(void *dst, uint32_t length){
	if(getReadSpace() < length)
		throw logic_error("Buffer reading overflow");

	memcpy(dst, buffer.get() + readPos, length);
	readPos += length;
}


void Buffer::read(ostream &o, uint32_t length){
	if(getReadSpace() < length)
		throw logic_error("Buffer reading overflow");

	void *ptr = buffer.get() + readPos;
	o.write(reinterpret_cast<char *>(ptr), length);
	readPos += length;
}


void *Buffer::get(){
	return buffer.get();
}

const void *Buffer::get() const{
	return buffer.get();
}

uint64_t Buffer::getSize() const{
	return size;
}
