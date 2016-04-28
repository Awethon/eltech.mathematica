#include "stdafx.h"
#include <iostream>
#include "Rational.h"
#include <cvt/wstring>

Rational::Rational()
	: Z("0"), N("1") {
}

Rational::Rational(BigInt Z, Natural N)
	: Z(Z), N(N) {
}

Rational::Rational(bool sign, string str_Z, string str_N)
	: Z(sign, str_Z), N(str_N) {
}

Rational::Rational(string str) {
	int i = 0;
	bool sign;
	if (str[0] == '-') {
		i++;
		sign = 1;
	}
	size_t pos = str.find("/");
	string strZ = str.substr(i, pos - i);
	if (sign == 1) strZ = "-" + strZ;
	string strN = str.substr(pos + 1);
	Z = BigInt(strZ);
	N = Natural(strN);


}


unsigned int Rational::getSize_Z() const{
	return Z.getSize();
}

unsigned int Rational::getSize_N() const {
	return N.getSize();
}

unsigned Rational::getDigit_Z(unsigned rank) const {
	return Z.getDigit(rank);
}

unsigned Rational::getDigit_N(unsigned rank) const {
	return N.getDigit(rank);
}

bool Rational::getSign_Q() const{
	return Z.getSign();
}

Rational Rational::RED_Q_Q(const Rational &A) {
	BigInt Z = BigInt::DIV_ZZ_Z(A.Z, BigInt::TRANS_N_Z(Natural::GCF_NN_N(BigInt::TRANS_Z_N(A.Z), A.N)));
	Natural N = Natural::DIV_NN_N(A.N, Natural::GCF_NN_N(BigInt::TRANS_Z_N(A.Z), A.N));
	Rational result(Z, N);
	return result;
};

bool Rational::INT_Q_B(const Rational& a) {
	if (Natural::COM_NN_D(BigInt::ABS_Z_N(a.Z), a.N) == 2 || Natural::COM_NN_D(BigInt::ABS_Z_N(a.Z), a.N) == 0)
		if (!Natural::NZER_N_B(Natural::MOD_NN_N(BigInt::ABS_Z_N(a.Z), a.N))) {
			return true;
		}
	return false;
};

Rational Rational::TRANS_Z_Q(const BigInt &a) {
	Natural N("1");
	Rational Q(a, N);
	return Q;
};
BigInt Rational::TRANS_Q_Z(const Rational &a) {
	if (!(a.N.getDigit(0) == 1 && a.N.getSize() == 1)) {
		//› —≈œÿŒÕ
	}
	return a.Z;
};

Rational Rational::ADD_QQ_Q(const Rational &q1, const Rational &q2) {
	Rational add;
	add.N = Natural::LCM_NN_N(q1.N, q2.N);

	Rational q3;
	q3.Z = BigInt::TRANS_N_Z(add.N);
	q3.N = q1.N;

	Rational q4;
	q4.Z = BigInt::TRANS_N_Z(add.N);
	q4.N = q2.N;

	add.Z = BigInt::ADD_ZZ_Z(BigInt::MUL_ZZ_Z(q1.Z, TRANS_Q_Z(RED_Q_Q(q3))), BigInt::MUL_ZZ_Z(q2.Z, TRANS_Q_Z(RED_Q_Q(q4))));
	return RED_Q_Q(add);
};

Rational Rational::SUB_QQ_Q(const Rational &q1, const Rational &q2) {
	Rational sub;
	sub.N = Natural::LCM_NN_N(q1.N, q2.N);

	Rational q3;
	q3.Z = BigInt::TRANS_N_Z(sub.N);
	q3.N = q1.N;

	Rational q4;
	q4.Z = BigInt::TRANS_N_Z(sub.N);
	q4.N = q2.N;

	sub.Z = BigInt::SUB_ZZ_Z(BigInt::MUL_ZZ_Z(q1.Z, TRANS_Q_Z(RED_Q_Q(q3))), BigInt::MUL_ZZ_Z(q2.Z, TRANS_Q_Z(RED_Q_Q(q4))));
	return RED_Q_Q(sub);
};

Rational Rational::MUL_QQ_Q(const Rational &q1, const Rational &q2) {
	Rational result(BigInt::MUL_ZZ_Z(q1.Z, q2.Z), Natural::MUL_NN_N(q1.N, q2.N));
	return RED_Q_Q(result);
};

Rational Rational::DIV_QQ_Q(const Rational &a, const Rational &c) {
	if (a.Z.getSign() != c.Z.getSign()) {
		Rational result(BigInt::MUL_ZM_Z(BigInt::MUL_ZZ_Z(a.Z, BigInt::TRANS_N_Z(c.N))), Natural::MUL_NN_N(a.N, BigInt::TRANS_Z_N(c.Z)));
		return RED_Q_Q(result);
	}
	Rational result(BigInt::MUL_ZZ_Z(a.Z, BigInt::TRANS_N_Z(c.N)), Natural::MUL_NN_N(a.N, BigInt::TRANS_Z_N(c.Z)));
	return RED_Q_Q(result);
};
