#include "stdafx.h"
#include "Crypto.h"
#include <iostream>

//uint32_t modpow_expsqr(uint32_t b, uint32_t X, uint64_t M)
//{
//	uint64_t B = b;
//	uint64_t P = 1;
//
//	while (X != 0)
//	{
//		if ((X & 1) == 1)
//		{
//			P = (P * B) % M;
//		}
//		B = (B * B) % M;
//		X >>= 1;
//	}
//
//	return (uint32_t)P;
//}

uint64_t gcd(uint64_t a, uint64_t b) {
	return b ? gcd(b, a % b) : a;
}

void extended_euclid(uint64_t a, uint64_t b, uint64_t *x, uint64_t *y, uint64_t *d)
{
	uint64_t q, r, x1, x2, y1, y2;
	if (b == 0) {
		*d = a, *x = 1, *y = 0;
		return;
	}

	x2 = 1, x1 = 0, y2 = 0, y1 = 1;
	while (b > 0) {
		q = a / b, r = a - q * b;
		*x = x2 - q * x1, *y = y2 - q * y1;
		a = b, b = r;
		x2 = x1, x1 = *x, y2 = y1, y1 = *y;
	}

	*d = a, *x = x2, *y = y2;
}

uint64_t inverse(uint64_t a, uint64_t n)
{
	uint64_t d, x, y;
	extended_euclid(a, n, &x, &y, &d);
	if (d == 1) {
		while (x < 0) {
			x += n;
		}
		return x;
	}
	return 0;
}

uint64_t modpow_expsqr(uint64_t x, uint64_t e, uint64_t M)
{
	uint64_t r = 1;
	while (e > 0)
	{
		if ((e % 2) == 1)
		{
			r = (r * x) % M;
		}
		e /= 2;
		x = (x * x) % M;
	}
	return r;
}

Crypto::Crypto(uint64_t p, uint64_t q)
	:m(p*q)
{
	srand(time(NULL));
	uint64_t euler_f = (p - 1)*(q - 1);
	do {
		e = rand() % (rand() % 150 + 1) + 100;
	} while (gcd(euler_f, e) != 1);
	d = inverse(e, euler_f);
}

vector<uint64_t> Crypto::encrypt(string str) {
	vector<uint64_t> crypt;
	crypt.resize(str.length());	
	for (int i = 0; i < str.length(); i++) {
		crypt[i] = modpow_expsqr(str[i], e, m);
	} 
	return crypt;
}

string Crypto::decrypt(vector<uint64_t> encrypt) {
	string crypt;
	crypt.resize(encrypt.size());
	for (int i = 0; i < encrypt.size(); i++) {
		crypt[i] = modpow_expsqr(encrypt[i], d, m);
	}
	return crypt;
}