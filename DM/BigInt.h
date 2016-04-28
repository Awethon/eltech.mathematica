#pragma once
#include "Natural.h"
class Polynom;

class BigInt {
	bool sign;
	Natural N;
public:
	BigInt();
	BigInt(string strZ);
	BigInt(bool _sign, Natural N);

	bool getSign() const;
	unsigned short getDigit(unsigned long long rank) const;
	int getSize() const;

	static Natural ABS_Z_N(const BigInt&);
	/**
	* �������  ���� 5305;
	* ���������� �������� �����, ��������� - �����������
	*/
	static int POZ_Z_D(const BigInt &x);
	/**
	* ��������� ��������� 5308;
	* ����������� ��������������� ����� (2 - �������������, 0 � ������ ����, 1 - �������������)
	*/
	static int COM_ZZ_D(const BigInt&, const BigInt&);
	/**
	* ������� ���������� 5308;
	* ��������� ����� ����� (���� ������)
	*/
	static BigInt MUL_ZM_Z(const BigInt&);
	/**
	* ������ ��������� 5305;
	* ��������� ������ �� (-1)
	*/
	static Natural TRANS_Z_N(const BigInt&);
	/**
	* ������� ���� 5305;
	* �������������� ������ ���������������� � �����������
	*/
	static BigInt TRANS_N_Z(const Natural&);
	/**
	* ������� ������� 5308;
	* �������������� ������������ � �����
	*/
	static BigInt ADD_ZZ_Z(const BigInt&, const BigInt&);
	/**
	* �������� ������ 5305;
	* �������� ����� �����
	*/
	static BigInt SUB_ZZ_Z(const BigInt&, const BigInt&);
	/**
	* ����� ��������� 5308;
	* ��������� ����� �����
	*/
	static BigInt MUL_ZZ_Z(const BigInt&, const BigInt&);
	/**
	* ������ ���� 5308;
	* ��������� ����� �����
	*/
	static BigInt DIV_ZZ_Z(const BigInt&, const BigInt&);
	/**
	* ����� ������ 5308;
	* ������� �� ������� �������� ������ ����� �� ������� ��� ������ ����������� � �������� (�������� ������� �� ����)
	*/
	static BigInt MOD_ZZ_Z(const BigInt&, const BigInt&);
	/**
	* ������� �������� 5305;
	* ������� �� ������� �������� ������ ����� �� �������
	*/
};
