#pragma once
#include <stdint.h>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

class Crypto
{
	unsigned long long d;
	unsigned long long m;
	unsigned e;
public:
	Crypto(uint64_t, uint64_t);

	vector<uint64_t> encrypt(string);
	string decrypt(vector<uint64_t>);
	//uint64_t
};

