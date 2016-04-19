// DM.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Natural.h"
#include "Rational.h"
#include "Polynom.h"
#include "ctime"
#include <iostream>
#include <stdint.h>
#include <iostream>
#include <cstdlib>
#include <primesieve.hpp>

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
	uint64_t n = 1000000;
	if (argv[1])
		n = std::atol(argv[1]);

	uint64_t nth_prime = primesieve::nth_prime(n);
	std::cout << n << "th prime = " << nth_prime << std::endl;
	system("pause");
	return 0;
}

//int main() {
//	Rational result;
//	system("pause");
//	return 0;
//}
