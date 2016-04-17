#pragma once
#include "Natural.h"
class Polynom;

class BigInt {
	bool sign;
	Natural N;
public:
	BigInt();

	BigInt(bool _sign, string kek);

	BigInt(bool _sign, Natural hey_buddy);

	bool getSign() const;

	unsigned short getDigit(unsigned int rank);

	int getSize();

	static Natural ABS_Z_N(BigInt);
	static int POZ_Z_D(BigInt x);
	int COM_ZZ_D(BigInt, BigInt);
	static BigInt MUL_ZM_Z(BigInt);// на -1
	static Natural TRANS_Z_N(BigInt);
	static BigInt TRANS_N_Z(Natural);
	static BigInt ADD_ZZ_Z(BigInt, BigInt);
	static BigInt SUB_ZZ_Z(BigInt, BigInt);
	static BigInt MUL_ZZ_Z(BigInt, BigInt);
	static BigInt DIV_ZZ_Z(BigInt, BigInt);
	static BigInt MOD_ZZ_Z(BigInt, BigInt);
};
