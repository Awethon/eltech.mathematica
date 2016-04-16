#include "stdafx.h"
#include "BigInt.h"
#include <vector>

BigInt::BigInt() {
	N.resize(0);
	sign = 0;
}
BigInt::BigInt(bool _sign, string kek)
	: sign(_sign), N(kek) {
}

BigInt::BigInt(bool _sign, Natural hey_buddy)
	: sign(_sign), N(hey_buddy) {
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
		return 1;
	return 2;
}

BigInt BigInt::MUL_ZM_Z(BigInt a) {
	BigInt result((a.sign == 0) ? 1 : 0, a.N);
	return result;
};

//BigInt BigInt::MUL_ZZ_Z(BigInt a, BigInt b) {
//	
//	if (POZ_Z_D(a) == 0 || POZ_Z_D(b) == 0)
//	{
//		vector<int> tmpV(1);
//		BigInt result(0, tmpV);
//		return result;
//	}
//	if (POZ_Z_D(a) == POZ_Z_D(b))
//		return TRANS_N_Z(MUL_NN_N(ABS_Z_N(a), ABS_Z_N(b)));
//	else
//		return MUL_Z__Z(TRANS_N_Z((MUL_NN_N(ABS_Z_N(a), ABS_Z_N(b)))));
//}

Natural BigInt::TRANS_Z_N(BigInt a) {
	return a.N;
}

BigInt BigInt::TRANS_N_Z(Natural a) {
	BigInt b(0, a);
	return b;
}

BigInt BigInt::ADD_ZZ_Z(BigInt a, BigInt b) {
	if (POZ_Z_D(a) == 0 || POZ_Z_D(b) == 0) {
		BigInt result(0, "0");
		return result;
	}
	if (POZ_Z_D(a) == POZ_Z_D(b))
	{
		if (POZ_Z_D(a) == 1)
			return TRANS_N_Z(Natural::ADD_NN_N(ABS_Z_N(a), ABS_Z_N(b)));
		return MUL_ZM_Z(TRANS_N_Z((Natural::ADD_NN_N(ABS_Z_N(a), ABS_Z_N(b)))));
	}
	(b.sign == 0) ? b.sign = 1 : b.sign = 0;
	return SUB_ZZ_Z(a, b);
}

BigInt BigInt::SUB_ZZ_Z(BigInt x, BigInt y) {
	switch (POZ_Z_D(x) + POZ_Z_D(y)) {
	case 3: // ���� ���� �������������, � ������ �������������
		if (POZ_Z_D(x) == 2) // ���� ������ �������������
			return MUL_ZM_Z(TRANS_N_Z(Natural::ADD_NN_N(ABS_Z_N(x), ABS_Z_N(y))));
		else // ���� ������ ������������� 
			return TRANS_N_Z(Natural::ADD_NN_N(ABS_Z_N(x), ABS_Z_N(y)));
	case 0: //��� ����
	case 1: //���� 0 ������ ������������
	case 2: //��� ������������� ��� ���� ����, � ������ �������������
		if (POZ_Z_D(x) == 0 || POZ_Z_D(y) == 0) {//���� ���� ����� 0 ������ ������������� ��� ��� ����� 0
			if (POZ_Z_D(x) == 0) {//���� ������ ����� 0
				if (POZ_Z_D(y) == 0) //� ���� ����� ������ 0
					return y;
				//���� ������ ������ 0
				return (MUL_ZM_Z(y));
			}
			//���� ������ ����� 0
			return x;
		}
		// ���� ��� �������������
		if (Natural::COM_NN_D(ABS_Z_N(x), ABS_Z_N(y)) != 0) { // ���� �� ������ ��� �� �����
			if (Natural::COM_NN_D(ABS_Z_N(x), ABS_Z_N(y)) == 2) // ���� �� ������ ������ ������ �������
				return TRANS_N_Z(Natural::SUB_NN_N(ABS_Z_N(x), ABS_Z_N(y)));
			// ���� �� ������ ������ ������ �������
			return MUL_ZM_Z(TRANS_N_Z(Natural::SUB_NN_N(ABS_Z_N(y), ABS_Z_N(x))));
		}
		// ���� �� ������� �����, �� ���������� ����� 4 ����� ������
	case 4: // ���� ��� �������������
		if (Natural::COM_NN_D(ABS_Z_N(x), ABS_Z_N(y)) == 0) // ���� �� ������ ��� �����
			return TRANS_N_Z(Natural::SUB_NN_N(ABS_Z_N(x), ABS_Z_N(y)));
		// ���� �� ������ ��� �� �����
		if (Natural::COM_NN_D(ABS_Z_N(x), ABS_Z_N(y)) == 2) // ���� �� ������ ������ ������ �������
			return MUL_ZM_Z(TRANS_N_Z(Natural::SUB_NN_N(ABS_Z_N(x), ABS_Z_N(y))));
		// ���� �� ������ ������ ������ �������
		return TRANS_N_Z(Natural::SUB_NN_N(ABS_Z_N(y), ABS_Z_N(x)));
	}
}

BigInt BigInt::MUL_ZZ_Z(BigInt x, BigInt y) {
	BigInt z;
	if (POZ_Z_D(x) == 0)
		z = x;
	else if (POZ_Z_D(y) == 0)
		z = y;
	else if (((POZ_Z_D(x) == 2) && (POZ_Z_D(y) == 1)) || ((POZ_Z_D(x) == 1) && (POZ_Z_D(y) == 2)))
		z = MUL_ZM_Z(TRANS_N_Z(Natural::MUL_NN_N(ABS_Z_N(x), ABS_Z_N(y))));
	else
		z = TRANS_N_Z(Natural::MUL_NN_N(ABS_Z_N(x), ABS_Z_N(y)));

	return z;
}

BigInt BigInt::DIV_ZZ_Z(BigInt a, BigInt b) {
	if (POZ_Z_D(a) == 0 || POZ_Z_D(b) == 0) {
		BigInt result(0, "0");
		return result;
	}
	if (POZ_Z_D(a) == POZ_Z_D(b))
		return TRANS_N_Z(Natural::DIV_NN_N(ABS_Z_N(a), ABS_Z_N(b)));
	else
		return MUL_ZM_Z(TRANS_N_Z(Natural::DIV_NN_N(ABS_Z_N(a), ABS_Z_N(b))));
}

BigInt BigInt::MOD_ZZ_Z(BigInt a, BigInt b) {
	if (POZ_Z_D(a) == POZ_Z_D(b))
		return SUB_ZZ_Z(a, MUL_ZZ_Z(DIV_ZZ_Z(a, b), b));
	if (POZ_Z_D(a) == 2)
	{
		BigInt kek(0, TRANS_Z_N(b));
		return SUB_ZZ_Z(ADD_ZZ_Z(a, kek), MUL_ZZ_Z(DIV_ZZ_Z(a, b), b));
	}
	exit(-12);
}

//BigInt BigInt::MOD_ZZ_Z(BigInt a, BigInt b) {
//		BigInt remainder, private_d, inversion;
//		private_d = DIV_ZZ_Z(a, b);
//		inversion = MUL_ZM_Z(b);
//		private_d = MUL_ZZ_Z(private_d, inversion);
//		remainder = SUB_ZZ_Z(a, private_d);
//		return remainder;
//}
