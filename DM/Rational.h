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
	Rational(string);

	unsigned getSize_Z() const;
	unsigned getSize_N() const;
	unsigned getDigit_Z(unsigned) const;
	unsigned getDigit_N(unsigned) const;
	bool getSign_Q() const;

	static Rational RED_Q_Q(const Rational&);
	/**
	* ���������� ������ 5305;
	* ���������� �����
	*/
	static bool INT_Q_B(const Rational&);
	/**
	* �������� ����� 5308;
	* �������� �� �����, ���� ������������ ����� �������� �����, �� ���, ����� ����
	*/
	static Rational TRANS_Z_Q(const BigInt&);
	/**
	* ������� ���� 5305;
	* �������������� ������ � �������
	*/
	static BigInt TRANS_Q_Z(const Rational&);
	/**
	* ������� ������ 5308;
	* �������������� �������� � ����� (���� ����������� ����� 1)
	*/
	static Rational ADD_QQ_Q(const Rational&, const Rational&);
	/**
	* �������� ������� 5308;
	* �������� ������
	*/
	static Rational SUB_QQ_Q(const Rational&, const Rational&);
	/**
	* ������� ��������� 5308;
	* ��������� ������
	*/
	static Rational MUL_QQ_Q(const Rational&, const Rational&);
	/**
	* ������� ���� 5305;
	* ��������� ������
	*/
	static Rational DIV_QQ_Q(const Rational&, const Rational&);
	/**
	* ���������� ������ 5308;
	* ������� ������ (�������� ������� �� ����)
	*/

};
