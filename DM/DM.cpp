// DM.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "Natural.h"
#include "Rational.h"
#include "Polynom.h"
#include "ctime"
#include <stdint.h>
#include <cstdlib>
//#include <primesieve.hpp>
#include "Crypto.h"

using namespace std;

void output(Natural out) {
	for (int i = out.getSize() - 1; i >= 0; i--) {
		std::cout << out.getDigit(i);
	}
	std::cout << '\n';
}

void output(BigInt out) {
	if (out.getSign() == 1) {
		std::cout << '-';
	}
	for (int i = out.getSize() - 1; i >= 0; i--) {
		std::cout << out.getDigit(i);
	}
	std::cout << '\n';
}

void output(Rational out) {
	if (out.getSign_Q() == 1) {
		std::cout << '-';
	}
	for (int i = out.getSize_Z() - 1; i >= 0; i--) {
		std::cout << out.getDigit_Z(i);
	}
	std::cout << '/';
	for (int i = out.getSize_N() - 1; i >= 0; i--) {
		std::cout << out.getDigit_N(i);
	}
	std::cout << '\n';
}

void output(Polynom out) {
	for (int m = out.getexp(); m >= 0; m--) {
		std::cout << '(';
		if (out.getQ(m).getSign_Q() == 1) {
			std::cout << '-';
		}
		int i;
		for (i = out.getQ(m).getSize_Z() - 1; i >= 0; i--) {
			std::cout << out.getQ(m).getDigit_Z(i);
		}
		std::cout << '/';
		for (i = out.getQ(m).getSize_N() - 1; i >= 0; i--) {
			std::cout << out.getQ(m).getDigit_N(i);
		}
		std::cout << ')';
		if (m != 0) {
			std::cout << "x^" << m;
			std::cout << " + ";
		}
	}
	}
int main(int argc, char *argv[])
{
	unsigned int start_time = clock();
	//uint64_t n = 10;
	//if (argv[1])
	//	n = std::atol(argv[1]);

	//uint64_t nth_prime = primesieve::parallel_nth_prime(n);
	//std::cout << n << "th prime = " << nth_prime << std::endl;

	Crypto lol(102539, 102547);
	vector<uint64_t> kek = lol.encrypt("LIFE");
	string heh = lol.decrypt(kek);
	cout << heh;
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << search_time << '\n';
	system("pause");
	return 0;
}