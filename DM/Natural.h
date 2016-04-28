#pragma once
#include <vector>
using namespace std;

class Natural {
protected:
	vector<int8_t> v_N;
	unsigned long long vsize;
public:
	Natural();
	Natural(string);

	unsigned short getDigit(unsigned long long) const;
	unsigned long long getSize() const;

	void resize(unsigned long long);

	static int COM_NN_D(const Natural&, const Natural&);     
	/**
     * ������ ��������� 5305; 
     * ��������� ����������� �����
     * return 2, ���� ������ ������;
     *        1, ���� ������;
     *        0, ���� �����.
     */
	static bool NZER_N_B(const Natural&);
	/**
	* �������� ������� 5308;
	* �������� �� ����: ���� ����� �� ����� ����, �� ��� ����� ����
	*/
	static Natural ADD_1N_N(Natural);
	/**
	* ������ ��������� 5305;
	* ���������� 1 � ������������ �����
	*/
	static Natural ADD_NN_N(Natural, Natural);
	/**
	* �������� ���� 5308;
	* �������� ����������� �����
	*/
	static Natural SUB_NN_N(Natural, Natural);
	/**
	* ����������� ������ 5305;
	* ��������� �� ������� �������� ������������ ����� ������� �������� ��� �������
	*/
	static Natural MUL_ND_N(const Natural&, int);
	/**
	* ����� ���� 5308;
	* ��������� ������������ ����� �� �����
	*/
	static Natural MUL_Nk_N(const Natural&, int);
	/**
	* ������� ����� 5305;
	* ��������� ������������ ����� �� 10^k
	*/
	static Natural MUL_NN_N(const Natural&, const Natural&);
	/**
	* ���������� ���������� 5308;
	* ��������� ����������� �����
	*/
	static Natural SUB_NDN_N(const Natural&, int, const Natural&);
	/**
	* ��������� ��������� 5308;
	*/
	static Natural DIV_NN_Dk(const Natural&, const Natural&);
	/**
	* ����� ������ 5308;
	* ���������� ������ ����� ������� �������� ������������ �� �������, ����������� �� 10^k, ��� k - ����� ������� ���� ����� (����� ��������� � ����)
	*/
	static Natural DIV_NN_N(const Natural&, const Natural&);
	/**
	* ������� ������ 5305;
	* ������� �� ������� �������� ������������ ����� �� ������� ��� ������ ����������� � �������� (�������� ������� �� ����)
	*/
	static Natural MOD_NN_N(const Natural&, const Natural&);
	/**
	* ��������� ������ 5308;
	* ������� �� ������� �������� ������������ ����� �� ������� ��� ������ ����������� � �������� (�������� ������� �� ����)
	*/
	static Natural GCF_NN_N(Natural, Natural);
	/**
	* ������ ������ 5305;
	* ��� ����������� �����
	*/
	static Natural LCM_NN_N(const Natural&, const Natural&);
	/**
	* ���������� ������ 5305;
	* ��� ����������� �����
	*/
};
