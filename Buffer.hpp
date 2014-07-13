#ifndef BUFFER_HPP_INCLUDED
#define BUFFER_HPP_INCLUDED


class Buffer{
	uint64_t size;
	unique_ptr<uint8_t> buffer;

	uint64_t readPos, writePos;
public:

	Buffer(uint64_t size);
	Buffer(const Buffer &buffer);
	Buffer(Buffer &&buffer);

	void write(const void *data, uint64_t length);
	void write(istream &i, uint64_t length);
	void read(void *dst, uint64_t length);
	void read(ostream &o, uint64_t length);


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

	uint64_t getWriteSpace() const;
	uint64_t getReadSpace() const;

	void *get();
	const void *get() const;
	uint64_t getSize() const;
};



#endif // BUFFER_HPP_INCLUDED
