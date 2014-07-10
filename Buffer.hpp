#ifndef BUFFER_HPP_INCLUDED
#define BUFFER_HPP_INCLUDED


class Buffer{
	uint64_t size;
	unique_ptr<uint8_t> buffer;

	uint32_t readPos, writePos;
public:

	Buffer(uint64_t size);
	Buffer(const Buffer &buffer);
	Buffer(Buffer &&buffer);

	void write(const void *data, uint32_t length);
	void write(istream &i, uint32_t length);
	void read(void *dst, uint32_t length);
	void read(ostream &o, uint32_t length);


	template<typename T>
	void write(const T &t){
		write(&t, sizeof(T));
	}

	template<typename T>
	T read(){
		T t;
		read(&t, sizeof(t));
		return t;
	}


	void dropPointers();

	uint32_t getWriteSpace() const;
	uint32_t getReadSpace() const;

	void *get();
	const void *get() const;
	uint64_t getSize() const;
};



#endif // BUFFER_HPP_INCLUDED
