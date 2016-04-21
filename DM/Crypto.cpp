#include "stdafx.h"
#include "Crypto.h"
#include <iostream>

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

uint64_t modpow_expsqr(uint64_t x, uint64_t e, uint32_t M)
{
	uint64_t B = x;
	uint64_t P = 1;

	while (e != 0)
	{
		if ((e & 1) == 1)
		{
			P = (P * B) % M;
		}
		B = (B * B) % M;
		e >>= 1;
	}

	return P;
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

string Crypto::hack(vector<uint64_t> encrypt) {
	string crypt;
	crypt.resize(encrypt.size());
	int j = 1;
	uint64_t CC = encrypt[0];
	while (modpow_expsqr(CC, e, m) != encrypt[0]) {
		CC = modpow_expsqr(CC, e, m);
		j++;
		cout << j << '\n';
	}

	for (int i = 0; i < crypt.length(); i++)
	{
		CC = encrypt[i];
		for (int k = 1; k < j; k++) {
			CC = modpow_expsqr(CC, e, m);
		}
		crypt[i] = CC;
	}
	return crypt;
}

vector<uint64_t> Crypto::sign(string str) {
	vector<uint64_t> crypt;
	crypt.resize(str.length());
	for (int i = 0; i < str.length(); i++) {
		crypt[i] = modpow_expsqr(str[i], d, m);
	}
	return crypt;
}

unsigned Crypto::get_e() {
	return e;
}

unsigned long Crypto::get_m() {
	return m;
}
