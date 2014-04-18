#include <iostream>
using namespace std;

class BloomFilter {
	public:
		void add(int i);
		int in_set(int i);
		BloomFilter();
		~BloomFilter();
	private:
		unsigned long bit_vector: 32;
};

void test(BloomFilter f, int i);

