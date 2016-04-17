#include "stdafx.h"
#include "BigInt.h"
#include <vector>

BigInt::BigInt() {
	N.resize(0);
	sign = 0;
}

//BigInt::BigInt(bool _sign, string kek)
//	: sign(_sign), N(kek) {
//}

BigInt::BigInt(string strZ) {
	if (strZ[0] == '-') {
		sign = 1;
		N = Natural(strZ.substr(1));
	} else {
		sign = 0;
		N = Natural(strZ);
	}
}

BigInt::BigInt(bool sign, Natural N)
	: sign(sign), N(N) {
}

bool BigInt::getSign() const {
	return sign;
}

unsigned short BigInt::getDigit(unsigned int rank) {
	return N.getDigit(rank);
}

int BigInt::getSize() {
	return N.getSize();
}

Natural BigInt::ABS_Z_N(BigInt a) {
	return a.N;
}

int BigInt::POZ_Z_D(BigInt x) {
	if (x.N.getDigit(0) == 0 && x.N.getSize() == 1)
		return 0;
	if (x.sign == 0)
		return 2;
	return 1;
}

int BigInt::COM_ZZ_D(BigInt a, BigInt b) {
	if (POZ_Z_D(a) == POZ_Z_D(b))
		return Natural::COM_NN_D(a.N, b.N);
	return POZ_Z_D(a) == 2 ? 2 : 1;
}

BigInt BigInt::MUL_ZM_Z(BigInt a) {
	BigInt result((a.sign == 0) ? 1 : 0, a.N);
	return result;
};

BigInt BigInt::MUL_ZZ_Z(BigInt a, BigInt b) {

	if (POZ_Z_D(a) == 0 || POZ_Z_D(b) == 0) {
		BigInt result("0");
		return result;
	}
	if (POZ_Z_D(a) == POZ_Z_D(b))
		return TRANS_N_Z(Natural::MUL_NN_N(ABS_Z_N(a), ABS_Z_N(b)));
	return MUL_ZM_Z(TRANS_N_Z((Natural::MUL_NN_N(ABS_Z_N(a), ABS_Z_N(b)))));
}

Natural BigInt::TRANS_Z_N(BigInt a) {
	return a.N;
}

BigInt BigInt::TRANS_N_Z(Natural a) {
	BigInt b(0, a);
	return b;
}

BigInt BigInt::ADD_ZZ_Z(BigInt a, BigInt b) {
	if (POZ_Z_D(a) == POZ_Z_D(b)) {
		BigInt result(a.getSign(), Natural::ADD_NN_N(a.N, b.N));
		return result;
	}
	if (COM_ZZ_D(a, b) == 2) {
		BigInt result(a.getSign(), Natural::SUB_NN_N(a.N, b.N));
		return result;
	}
	if (COM_ZZ_D(a, b) == 1) {
		BigInt result(b.getSign(), Natural::SUB_NN_N(b.N, a.N));
		return result;
	}
	BigInt result("0");
	return result;
}

BigInt BigInt::SUB_ZZ_Z(BigInt a, BigInt b) {
	if (POZ_Z_D(a) != POZ_Z_D(b)) {
		BigInt result(a.sign, Natural::ADD_NN_N(ABS_Z_N(a), ABS_Z_N(b)));
		return result;
	}
	if (COM_ZZ_D(a, b) == 2) {
		BigInt result(a.sign, Natural::SUB_NN_N(ABS_Z_N(a), ABS_Z_N(b)));
		return result;
	}
	if (COM_ZZ_D(a, b) == 1) {
		BigInt result(b.getSign(), Natural::SUB_NN_N(ABS_Z_N(b), ABS_Z_N(a)));
		return result;
	}
	BigInt result("0");
	return result;
}

BigInt BigInt::DIV_ZZ_Z(BigInt a, BigInt b) {
	if (POZ_Z_D(a) == 0 || POZ_Z_D(b) == 0) {
		BigInt result("0");
		return result;
	}
	if (POZ_Z_D(a) == POZ_Z_D(b))
		return TRANS_N_Z(Natural::DIV_NN_N(ABS_Z_N(a), ABS_Z_N(b)));
	return MUL_ZM_Z(TRANS_N_Z(Natural::DIV_NN_N(ABS_Z_N(a), ABS_Z_N(b))));
}

BigInt BigInt::MOD_ZZ_Z(BigInt a, BigInt b) {
	if (POZ_Z_D(a) == POZ_Z_D(b))
		return SUB_ZZ_Z(a, MUL_ZZ_Z(DIV_ZZ_Z(a, b), b));
	return SUB_ZZ_Z(ADD_ZZ_Z(a, b), MUL_ZZ_Z(DIV_ZZ_Z(TRANS_N_Z(a.N), b), b));
}
