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

	unsigned int getexp();
	Rational getQ(int rank);

	static Polynom ADD_PP_P(Polynom p1, Polynom p2);
	/**
	* �������� ������� 5308;
	* �������� �����������
	*/
	static Polynom SUB_PP_P(Polynom f, Polynom g);
	/**
	* ������ ���� 5308;
	* ��������� �����������
	*/
	static Polynom MUL_PQ_P(Polynom, Rational);
	/**
	* ������� ���� 5305;
	* ��������� ���������� �� ������������ �����
	*/
	static Polynom MUL_Pxk_P(Polynom a, int k);
	/**
	* �������� ���� 5308;
	* ��������� ���������� �� x^k
	*/
	static Rational LED_P_Q(Polynom);
	/**
	* ������� ����� 5305;
	* ������� ����������� ����������
	*/
	static unsigned DEG_P_N(Polynom P);
	/**
	* ����� ������ 5308;
	* ������� ����������
	*/
	static Rational FAC_P_Q(Polynom);
	/**
	* ���������� ������� 5305;
	* ��������� �� ���������� ��� ������������ ������������� � ��� ����������
	*/
	static Polynom MUL_PP_P(Polynom a, Polynom b);
	/**
	* �������� ������� 5308;
	* ��������� �����������
	*/
	static Polynom DIV_PP_P(Polynom, Polynom);
	/**
	* ������ ������ 5305;
	* ������� �� ������� ���������� �� ��������� ��� ������� � ��������
	*/
	static Polynom MOD_PP_P(Polynom f, Polynom g);
	/**
	* ������ ���� 5308;
	* ������� �� ������� ���������� �� ���������
	*/
	static Polynom GCF_PP_P(Polynom, Polynom);
	/**
	* ������ ����� 5305;
	* ��� ���������
	*/
	static Polynom DER_P_P(Polynom a);
	/**
	* �������� ���� 5308;
	* ����������� ����������
	*/
	static Polynom NMR_P_P(Polynom);
	/**
	* ����������� ������ 5305;
	* �������������� ���������� - ������� ����� � �������
	*/

};
