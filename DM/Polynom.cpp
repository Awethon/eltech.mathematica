#include "stdafx.h"
#include <iostream>
#include "Polynom.h"

Polynom::Polynom()
	: n(0) {
	Rational Q(0, "0", "1");
	v_Q.push_back(Q);
}

Polynom::Polynom(unsigned int pow)
	: n(pow) {
	v_Q.resize(pow + 1);
}

Polynom::Polynom(unsigned int pow, const vector<Rational>& _v_Q)
	: n(pow), v_Q(_v_Q) {
}

Polynom::Polynom(unsigned pow, string input)
	: n(pow) {
	v_Q.resize(pow + 1);
	int k = pow;
	bool tmp_sign = false;
	bool isN = false;
	string tmp_Z, tmp_N;

	for (int i = 0; i < input.length(); i++) {
		switch (input[i]) {
		case '-':
		{
			tmp_sign = true;
			break;
		}
		case '/':
		{
			BigInt Z(tmp_sign, tmp_Z);
			v_Q[k].Z = Z;
			tmp_Z.clear();
			isN = true;
			tmp_sign = false;
			break;
		}
		case ' ':
		{
			Natural N(tmp_N);
			v_Q[k].N = N;
			tmp_N.clear();
			isN = false;
			k--;
			break;
		}
		default:
		{
			if (isN == false)
				tmp_Z.push_back(input[i]);
			else
				tmp_N.push_back(input[i]);
			break;
		}
		}
				
	}
	Natural N(tmp_N);
	v_Q[k].N = N;
}

unsigned int Polynom::getexp() {
	return n;
}

Rational Polynom::getQ(int rank) {
	return v_Q[rank];
}

Polynom Polynom::ADD_PP_P(Polynom p1, Polynom p2) {
	Polynom result(p1.n > p2.n ? p1.n : p2.n);
	unsigned lesser_p = p1.n > p2.n ? p2.n : p1.n;
	for (int i = result.n; i >= lesser_p; i--) {
		result.v_Q[i] = (p1.n > p2.n ? p1 : p2).getQ(i);
	}
	for (int i = 0; i <= lesser_p; i++) {
		result.v_Q[i] = Rational::RED_Q_Q(Rational::ADD_QQ_Q(p1.v_Q[i], p2.v_Q[i]));
	}
	return result;
}

Polynom Polynom::SUB_PP_P(Polynom f, Polynom g) {
	Polynom p(f.n > g.n ? f.n : g.n);
	int i;
	for (i = 0 , p.n = 0; (i < f.n || i < g.n); i++ , p.n++)
		p.v_Q[i] = Rational::SUB_QQ_Q(f.v_Q[i], g.v_Q[i]);
	return p;
};

Polynom Polynom::MUL_PQ_P(Polynom A, Rational Q) {
	for (int i = 0; i < A.n; i++) {
		A.v_Q[i] = Rational::MUL_QQ_Q(A.v_Q[i], Q);
	}
	return A;
};

Polynom Polynom::MUL_Pxk_P(Polynom a, unsigned int k) {
	int i;
	Polynom result(a.n + k);
	// Длина массива коэффициентов увеличивается на k
	for (i = a.n + k; i >= k; i--) {
		result.v_Q[i] = a.v_Q[i - k]; // Значения в массиве коэффициентов сдвигаются к старшим степеням
	}
	return result;
};

Rational Polynom::LED_P_Q(Polynom p) {
	return p.v_Q[p.n];
};

unsigned Polynom::DEG_P_N(Polynom P) {
	return P.n;
};

//Rational Polynom::FAC_P_Q(Polynom p) {
//	int i;
//	Natural NOD, NOK;
//	// Предполагается, что степень многочлена больше 1
//	for (i = 0;i < p.n; i++) // Вычисление НОДа числителей коэффицентов
//	{
//		if (i == 0)
//			NOD = BigInt::ABS_Z_N(p.v_Q[0].Z);
//		else
//			NOD = Natural::GCF_NN_N(NOD, BigInt::ABS_Z_N(p.v_Q[i].Z));
//	}
//
//	for (i = 0; i < p.n; i++) // Вычисление НОKа числителей коэффицентов
//	{
//		if (i == 0)
//			NOK = TRANS_Z_N(ABS_Z_N(polinom.factor[0].denominator));
//		else
//			NOK = LCM_NN_N(TRANS_Z_N(ABS_Z_N(NOK)), TRANS_Z_N(ABS_Z_N(polinom.factor[i].denomerator)));
//	}
//};

Polynom Polynom::MUL_PP_P(Polynom a, Polynom b) {
	Polynom result(a.n + b.n), temp;
	for (int i = 0; i <= result.n; i++) {
		temp = MUL_PQ_P(a, b.v_Q[i]);
		temp = MUL_Pxk_P(temp, i);
		result = ADD_PP_P(result, temp);
	}
	return result;
};

//Polynom Polynom::DIV_PP_P(Polynom A, Polynom B) {
//
//};

//Polynom Polynom::MOD_PP_P(Polynom f, Polynom g) {
//	return SUB_PP_P(f, MUL_PP_P(g, DIV_PP_P(f, g)));
//};

//Polynom Polynom::GCF_PP_P(Polynom p1, Polynom p2) {
//	while ((DEG_P_N(p1) != 0 && BigInt::POZ_Z_D(p1.v_Q[0].Z) != 0) || (DEG_P_N(p2) != 0 && BigInt::POZ_Z_D(p2.v_Q[0].Z) != 0)) {
//		if (DEG_P_N(p1) >= DEG_P_N(p2))
//			p1 = MOD_PP_P(p1, p2);
//		else
//			p2 = MOD_PP_P(p2, p1);
//	}
//	if (DEG_P_N(p1) != 0 || BigInt::POZ_Z_D(p2.v_Q[0].Z) != 0)
//		return p1;
//	return p2;
//};

Polynom Polynom::DER_P_P(Polynom a) {
	Polynom C(a.n);
	int i;
	for (i = 0; i < a.n; i++) {
		C.v_Q[i] = a.v_Q[i + 1];
		C.v_Q[i].Z = a.v_Q[i + 1].Z.getSign() == 0 ? BigInt::TRANS_N_Z(Natural::MUL_ND_N(BigInt::TRANS_Z_N(C.v_Q[i].Z), i + 1)) : BigInt::MUL_ZM_Z(BigInt::TRANS_N_Z(Natural::MUL_ND_N(BigInt::TRANS_Z_N(C.v_Q[i].Z), i + 1))); // Умножение числителя коэффициента на степень рассматриваемого слагаемого многочлена.
		C.v_Q[i] = Rational::RED_Q_Q(C.v_Q[i]); // Сокращение дроби (если это возможно)
	}
	return C;
};

//Polynom Polynom::NMR_P_P(Polynom) {
//	return DIV_PP_P(pNum, GFC_PP_P(pNum, DER_P_P(pNum)));
//};

