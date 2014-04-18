#include "bloom_filter.h"

BloomFilter::BloomFilter() {
	cout << "constructor" << endl;
	bit_vector = 0;
}

BloomFilter::~BloomFilter() {
	cout << "destructor" << endl;
}

void BloomFilter::add(int i) {
	cout << "adding " << i << endl;
	bit_vector |= i;
}

int BloomFilter::in_set(int i) {
	return bit_vector & i;
}

void test(BloomFilter f, int i) {
	if (f.in_set(i)) {
		cout << i << " might be in the set." << endl;
	}
	else {
		cout << i << " is definitely not in the set." << endl;
	}
}

int main() {
	BloomFilter f;

	f.add(1);
	f.add(12);
	f.add(13);
	f.add(12345);
	f.add(99);

	test(f, 12);
	test(f, 2);
	test(f, 12346);
	test(f, 0);
	test(f, 3);
	test(f, 99);
	test(f, 32768);

	return 0;
}
