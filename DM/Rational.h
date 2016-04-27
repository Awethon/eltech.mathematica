#pragma once
#include "BigInt.h"
#include "Natural.h"

class Polynom;

class Rational {
	friend class Polynom;

	BigInt Z;
	Natural N;
public:
	Rational();
	Rational(BigInt, Natural);
	Rational(bool _sign, string str_Z, string str_N);

	unsigned getSize_Z() const;
	unsigned getSize_N() const;
	unsigned getDigit_Z(unsigned) const;
	unsigned getDigit_N(unsigned) const;
	bool getSign_Q() const;

	static Rational RED_Q_Q(const Rational&);
	static bool INT_Q_B(const Rational&);
	static Rational TRANS_Z_Q(const BigInt&);
	static BigInt TRANS_Q_Z(const Rational&);
	static Rational ADD_QQ_Q(const Rational&, const Rational&);
	static Rational SUB_QQ_Q(const Rational&, const Rational&);
	static Rational MUL_QQ_Q(const Rational&, const Rational&);
	static Rational DIV_QQ_Q(const Rational&, const Rational&);

};
