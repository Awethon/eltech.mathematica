#include "stdafx.h"
#include <iostream>
#include "Rational.h"

Rational::Rational()
	: Z("0"), N("1") {
}

Rational::Rational(BigInt Z, Natural N)
	: Z(Z), N(N) {
}

Rational::Rational(bool sign, string str_Z, string str_N)
	: Z(sign, str_Z), N(str_N) {
}

unsigned int Rational::getSize_Z() {
	return Z.getSize();
}

unsigned int Rational::getSize_N() {
	return N.getSize();
}

unsigned int Rational::getDigit_Z(int rank) {
	return Z.getDigit(rank);
}

unsigned int Rational::getDigit_N(int rank) {
	return N.getDigit(rank);
}

bool Rational::getSign_Q() {
	return Z.getSign();
}

Rational Rational::RED_Q_Q(Rational A) {
	BigInt Z = BigInt::DIV_ZZ_Z(A.Z, BigInt::TRANS_N_Z(Natural::GCF_NN_N(BigInt::TRANS_Z_N(A.Z), A.N)));
	Natural N = Natural::DIV_NN_N(A.N, Natural::GCF_NN_N(BigInt::TRANS_Z_N(A.Z), A.N));
	Rational result(Z, N);
	return result;
};

bool Rational::INT_Q_B(Rational a) {
	if (Natural::COM_NN_D(BigInt::ABS_Z_N(a.Z), a.N) == 2 || Natural::COM_NN_D(BigInt::ABS_Z_N(a.Z), a.N) == 0)
		if (!Natural::NZER_N_B(Natural::MOD_NN_N(BigInt::ABS_Z_N(a.Z), a.N)))
			return true;
	return false;
};
Rational Rational::TRANS_Z_Q(BigInt a) {
	Natural N("1");
	Rational Q(a, N);
	return Q;
};
BigInt Rational::TRANS_Q_Z(Rational a) {
	if (!(a.N.getDigit(0) == 1 && a.N.getSize() == 1)) {
		//› —≈œÿŒÕ
	}
	return a.Z;
};

Rational Rational::ADD_QQ_Q(Rational q1, Rational q2) {
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

Rational Rational::SUB_QQ_Q(Rational q1, Rational q2) {
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

Rational Rational::MUL_QQ_Q(Rational q1, Rational q2) {
	Rational result(BigInt::MUL_ZZ_Z(q1.Z, q2.Z), Natural::MUL_NN_N(q1.N, q2.N));
	return RED_Q_Q(result);
};

Rational Rational::DIV_QQ_Q(Rational a, Rational c) {
	if (a.Z.getSign() != c.Z.getSign()) {
		Rational result(BigInt::MUL_ZM_Z(BigInt::MUL_ZZ_Z(a.Z, BigInt::TRANS_N_Z(c.N))), Natural::MUL_NN_N(a.N, BigInt::TRANS_Z_N(c.Z)));
		return RED_Q_Q(result);
	}
	Rational result(BigInt::MUL_ZZ_Z(a.Z, BigInt::TRANS_N_Z(c.N)), Natural::MUL_NN_N(a.N, BigInt::TRANS_Z_N(c.Z)));
	return RED_Q_Q(result);
};
