#pragma once
#include <stdint.h>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

class Crypto
{
	unsigned long long d;
	unsigned long m;
	unsigned e;
public:
	Crypto();
	Crypto(uint64_t, uint64_t);

	/**
	* Половинкин Алексей 5308;
	*/
	vector<uint64_t> encrypt(string);
	string decrypt(vector<uint64_t>);
	string hack(vector<uint64_t> encrypt);
	vector<uint64_t> sign(string str);
	
	unsigned get_e();
	unsigned long get_m();
};

