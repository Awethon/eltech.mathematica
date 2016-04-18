// DM.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Natural.h"
#include "Rational.h"
#include "Polynom.h"
#include "ctime"
#include <iostream>

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

int main() {
	Rational result;
	{
		unsigned int start_time = clock();
		Rational kek(0, "358094385937765785", "25");
		for (int i = 0; i < 20; i++) {
			result = Rational::RED_Q_Q(kek);
			output(result);
		}
		unsigned int end_time = clock(); // конечное время
		unsigned int search_time = end_time - start_time; // искомое время
		cout << '\n' << search_time << '\n';
	}
	{
		unsigned int start_time = clock();
		Rational lol(0, "3580967385", "25");
		for (int i = 0; i < 20; i++) {
			result = Rational::RED_Q_Q(lol);
			output(result);
		}
		unsigned int end_time = clock(); // конечное время
		unsigned int search_time = end_time - start_time; // искомое время
		cout << '\n' << search_time << '\n';
	}
	system("pause");
	return 0;
}
