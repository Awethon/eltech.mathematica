#pragma once
#include "BigInt.h"
#include "Natural.h"

class Polynom;

class Rational {
	BigInt Z;
	Natural N;
public:
	Rational();

	Rational(BigInt, Natural);

	Rational(bool _sign, string str_Z, string str_N);

	friend Polynom;

	unsigned int getSize_Z();

	unsigned int getSize_N();

	unsigned getDigit_Z(unsigned);

	unsigned getDigit_N(unsigned);

	bool getSign_Q();

	static Rational RED_Q_Q(Rational);

	static bool INT_Q_B(Rational);

	static Rational TRANS_Z_Q(BigInt);

	static BigInt TRANS_Q_Z(Rational);

	static Rational ADD_QQ_Q(Rational, Rational);

	static Rational SUB_QQ_Q(Rational, Rational);

	static Rational MUL_QQ_Q(Rational, Rational);

	static Rational DIV_QQ_Q(Rational, Rational);

};
