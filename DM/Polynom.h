#pragma once
#include "Rational.h"

class Polynom {
	unsigned int n;
	vector<Rational> v_Q;
public:
	Polynom();
	Polynom(unsigned int pow);
	Polynom(unsigned int pow, const vector<Rational>& _v_Q);
	Polynom(unsigned pow, string input);
	//void swap(Polynom & other)
	//{
	//	std::swap(v_Q, other.v_Q);
	//	std::swap(n, other.n);
	//}

	//Polynom & operator = (Polynom other) // ѕримечание: аргумент передаетс€ по значению!
	//{
	//	swap(other);
	//	return *this;
	//}

	unsigned int getexp();
	Rational getQ(int rank);

	static Polynom ADD_PP_P(Polynom p1, Polynom p2);
	static Polynom SUB_PP_P(Polynom f, Polynom g);
	static Polynom MUL_PQ_P(Polynom, Rational);
	static Polynom MUL_Pxk_P(Polynom a, int k);
	static Rational LED_P_Q(Polynom);
	static unsigned DEG_P_N(Polynom P);
	static Rational FAC_P_Q(Polynom);
	static Polynom MUL_PP_P(Polynom a, Polynom b);
	static Polynom DIV_PP_P(Polynom, Polynom);
	static Polynom MOD_PP_P(Polynom f, Polynom g);
	static Polynom GCF_PP_P(Polynom, Polynom);
	static Polynom DER_P_P(Polynom a);
	static Polynom NMR_P_P(Polynom);

};
