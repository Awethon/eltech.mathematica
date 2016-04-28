// DM.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "Natural.h"
#include "Rational.h"
#include "Polynom.h"
#include "ctime"
#include <stdint.h>
#include <cstdlib>
//#include <primesieve.hpp>
#include "Crypto.h"

using namespace std;

void output(Natural out) {
	for (int i = out.getSize() - 1; i >= 0; i--) {
		std::cout << out.getDigit(i);
	}
	std::cout << '\n';
	system("pause");
}

void output(BigInt out) {
	if (out.getSign() == 1) {
		std::cout << '-';
	}
	for (int i = out.getSize() - 1; i >= 0; i--) {
		std::cout << out.getDigit(i);
	}
	std::cout << '\n';
	system("pause");
}

void output(Rational out) {
	if (out.getSign_Q() == 1) {
		std::cout << '-';
	}
	for (int i = out.getSize_Z() - 1; i >= 0; i--) {
		std::cout << out.getDigit_Z(i);
	}
	std::cout << '/';
	for (int i = out.getSize_N() - 1; i >= 0; i--) {
		std::cout << out.getDigit_N(i);
	}
	std::cout << '\n';
	system("pause");
}

void output(Polynom out) {
	for (int m = out.getexp(); m >= 0; m--) {
		std::cout << '(';
		if (out.getQ(m).getSign_Q() == 1) {
			std::cout << '-';
		}
		int i;
		for (i = out.getQ(m).getSize_Z() - 1; i >= 0; i--) {
			std::cout << out.getQ(m).getDigit_Z(i);
		}
		std::cout << '/';
		for (i = out.getQ(m).getSize_N() - 1; i >= 0; i--) {
			std::cout << out.getQ(m).getDigit_N(i);
		}
		std::cout << ')';
		if (m != 0) {
			std::cout << "x^" << m;
			std::cout << " + ";
		}
	}
	cout << '\n';
	system("pause");
}

void naturalmenu() {
	unsigned x = 1;
	string temp1, temp2;
	Natural tmpN1, tmpN2;
	int num;
	while (x != 0) {
		puts(" 1 - ��������� ����������� �����: 2 - ���� ������ ������ ���� ����� �������, 0, ���� �����, 1 �����.");
		puts(" 2 - �������� �� ����: ���� ����� �� ����� ����, �� ��� ����� ����");
		puts(" 3 - ���������� 1 � ������������ �����");
		puts(" 4 - �������� ����������� �����");
		puts(" 5 - ��������� �� ������� �������� ������������ ����� ������� �������� ��� �������");
		puts(" 6 - ��������� ������������ ����� �� �����");
		puts(" 7 - ��������� ������������ ����� �� 10^k");
		puts(" 8 - ��������� ����������� �����");
		puts(" 9 - ��������� �� ������������ ������� ������������, ����������� �� ����� ��� ������ � ��������������� �����������");
		puts("10 - ���������� ������ ����� ������� �������� ������������ �� �������, ����������� �� 10^k, ��� k - ����� ������� ���� ����� (����� ��������� � ����)");
		puts("11 - ������� �� ������� �������� ������������ ����� �� ������� ��� ������ ����������� � �������� (�������� ������� �� ����)");
		puts("12 - ������� �� ������� �������� ������������ ����� �� ������� ��� ������ ����������� � �������� (�������� ������� �� ����)");
		puts("13 - ��� ����������� �����");
		puts("14 - ��� ����������� �����");
		puts("������� ����� ����: ");
		cin >> x;
		switch (x) {
		case 1:
			puts("��������� ����������� �����: 2 - ���� ������ ������ ���� ����� �������, 0, ���� �����, 1 �����.");
			cin >> temp1 >> temp2;
			tmpN1 = Natural(temp1);
			tmpN2 = Natural(temp2);
			std::cout << Natural::COM_NN_D(tmpN1, tmpN2);
			break;
		case 2:
			puts("�������� �� ����: ���� ����� �� ����� ����, �� ��� ����� ����");
			cin >> temp1;
			tmpN1 = Natural(temp1);
			std::cout << Natural::NZER_N_B(tmpN1);
			break;
		case 3:
			puts("���������� 1 � ������������ �����");
			cin >> temp1;
			tmpN1 = Natural(temp1);
			output(Natural::ADD_1N_N(tmpN1));
			break;
		case 4:
			puts("�������� ����������� �����");
			cin >> temp1 >> temp2;
			tmpN1 = Natural(temp1);
			tmpN2 = Natural(temp2);
			output(Natural::ADD_NN_N(tmpN1, tmpN2));
			break;
		case 5:
			puts("��������� �� ������� �������� ������������ ����� ������� �������� ��� �������");
			cin >> temp1 >> temp2;
			tmpN1 = Natural(temp1);
			tmpN2 = Natural(temp2);
			output(Natural::SUB_NN_N(tmpN1, tmpN2));
			break;
		case 6:
			puts("��������� ������������ ����� �� �����");
			cin >> temp1 >> num;
			tmpN1 = Natural(temp1);
			output(Natural::MUL_ND_N(tmpN1, num));
			break;
		case 7:
			puts("��������� ������������ ����� �� 10^k");
			cin >> temp1 >> num;
			tmpN1 = Natural(temp1);
			output(Natural::MUL_ND_N(tmpN1, num));
			break;
		case 8:
			puts("��������� ����������� �����");
			cin >> temp1 >> temp2;
			tmpN1 = Natural(temp1);
			tmpN2 = Natural(temp2);
			output(Natural::MUL_NN_N(tmpN1, tmpN2));
			break;
		case 9:
			puts("��������� �� ������������ ������� ������������, ����������� �� ����� ��� ������ � ��������������� �����������");
			cin >> temp1 >> temp2 >> num;
			tmpN1 = Natural(temp1);
			tmpN2 = Natural(temp2);
			output(Natural::SUB_NDN_N(tmpN1, num, tmpN2));
			break;
		case 10:
			puts("���������� ������ ����� ������� �������� ������������ �� �������, ����������� �� 10^k, ��� k - ����� ������� ���� ����� (����� ��������� � ����)");
			cin >> temp1 >> temp2;
			tmpN1 = Natural(temp1);
			tmpN2 = Natural(temp2);
			output(Natural::DIV_NN_Dk(tmpN1, tmpN2));
			break;
		case 11:
			puts("������� �� ������� �������� ������������ ����� �� ������� ��� ������ ����������� � �������� (�������� ������� �� ����)");
			cin >> temp1 >> temp2;
			tmpN1 = Natural(temp1);
			tmpN2 = Natural(temp2);
			output(Natural::DIV_NN_N(tmpN1, tmpN2));
			break;
		case 12:
			puts("������� �� ������� �������� ������������ ����� �� ������� ��� ������ ����������� � �������� (�������� ������� �� ����)");
			cin >> temp1 >> temp2;
			tmpN1 = Natural(temp1);
			tmpN2 = Natural(temp2);
			output(Natural::MOD_NN_N(tmpN1, tmpN2));
			break;
		case 13:
			puts("��� ����������� �����");
			cin >> temp1 >> temp2;
			tmpN1 = Natural(temp1);
			tmpN2 = Natural(temp2);
			output(Natural::GCF_NN_N(tmpN1, tmpN2));
			break;
		case 14:
			puts("��� ����������� �����");
			cin >> temp1 >> temp2;
			tmpN1 = Natural(temp1);
			tmpN2 = Natural(temp2);
			output(Natural::LCM_NN_N(tmpN1, tmpN2));
			break;
		}
	}
}

void integermenu() {
	unsigned x = 1;
	string temp1, temp2;
	BigInt tmpN1, tmpN2;
	int num;
	while (x != 0) {
		puts(" 1 - ���������� �������� �����, ��������� - �����������");
		puts(" 2 - ����������� ��������������� ����� (2 - �������������, 0 � ������ ����, 2 1 - �������������)");
		puts(" 3 - ��������� ������ �� (-1)");
		puts(" 6 - �������� ����� �����");
		puts(" 7 - ��������� ����� �����");
		puts(" 8 - ��������� ����� �����");
		puts(" 9 - ������� �� ������� �������� ������ ����� �� ������� ��� ������ ����������� � �������� (�������� ������� �� ����)");
		puts("10 - ������� �� ������� �������� ������ ����� �� ������� ��� ������ ����������� � �������� (�������� ������� �� ����)");
		puts("������� ����� ����: ");
		cin >> x;
		switch (x) {
		case 1:
			puts("���������� �������� �����, ��������� - �����������");
			cin >> temp1;
			tmpN1 = BigInt(temp1);
			output(BigInt::ABS_Z_N(tmpN1));
			break;
		case 2:
			puts("����������� ��������������� ����� (2 - �������������, 0 � ������ ����, 2 1 - �������������)");
			cin >> temp1;
			tmpN1 = BigInt(temp1);
			std::cout << BigInt::POZ_Z_D(tmpN1);
			break;
		case 3:
			puts("��������� ������ �� (-1)");
			cin >> temp1;
			tmpN1 = BigInt(temp1);
			output(BigInt::MUL_ZM_Z(tmpN1));
			break;
		case 6:
			puts("�������� ����� �����");
			cin >> temp1 >> temp2;
			tmpN1 = BigInt(temp1);
			tmpN2 = BigInt(temp2);
			output(BigInt::ADD_ZZ_Z(tmpN1, tmpN2));
			break;
		case 7:
			puts("��������� ����� �����");
			cin >> temp1 >> temp2;
			tmpN1 = BigInt(temp1);
			tmpN2 = BigInt(temp2);
			output(BigInt::SUB_ZZ_Z(tmpN1, tmpN2));
			break;
		case 8:
			puts("��������� ����� �����");
			cin >> temp1 >> temp2;
			tmpN1 = BigInt(temp1);
			tmpN2 = BigInt(temp2);
			output(BigInt::MUL_ZZ_Z(tmpN1, tmpN2));
			break;
		case 9:
			puts("������� �� ������� �������� ������ ����� �� ������� ��� ������ ����������� � �������� (�������� ������� �� ����)");
			cin >> temp1 >> temp2;
			tmpN1 = BigInt(temp1);
			tmpN2 = BigInt(temp2);
			output(BigInt::DIV_ZZ_Z(tmpN1, tmpN2));
			break;
		case 10:
			puts("������� �� ������� �������� ������ ����� �� ������� ��� ������ ����������� � �������� (�������� ������� �� ����)");
			cin >> temp1 >> temp2;
			tmpN1 = BigInt(temp1);
			tmpN2 = BigInt(temp2);
			output(BigInt::MOD_ZZ_Z(tmpN1, tmpN2));
			break;
		}
	}
}

void rationalmenu() {
	unsigned x = 1;
	string temp1, temp2;
	Rational tmpN1, tmpN2;
	int num;
	while (x != 0) {
		puts("1 - ���������� �����");
		puts("2 - �������� �� �����, ���� ������������ ����� �������� �����, �� ���, ����� ����");
		puts("3 - �������������� ������ � �������");
		puts("4 - �������������� �������� � ����� (���� ����������� ����� 1)");
		puts("5 - �������� ������");
		puts("6 - ��������� ������");
		puts("7 - ��������� ������");
		puts("8 - ������� ������ (�������� ������� �� ����)");
		puts("������� ����� ����: ");
		cin >> x;
		switch (x) {
		case 1:
			puts("���������� �����");
			cin >> temp1;
			tmpN1 = Rational(temp1);
			output(Rational::RED_Q_Q(tmpN1));
			break;
		case 2:
			puts("�������� �� �����, ���� ������������ ����� �������� �����, �� ���, ����� ����");
			cin >> temp1;
			tmpN1 = Rational(temp1);
			std::cout << Rational::INT_Q_B(tmpN1);
			break;
		case 5:
			puts("�������� ������");
			cin >> temp1 >> temp2;
			tmpN1 = Rational(temp1);
			tmpN2 = Rational(temp2);
			output(Rational::ADD_QQ_Q(tmpN1, tmpN2));
		case 6:
			puts("��������� ������");
			cin >> temp1 >> temp2;
			tmpN1 = Rational(temp1);
			tmpN2 = Rational(temp2);
			output(Rational::SUB_QQ_Q(tmpN1, tmpN2));
		case 7:
			puts("��������� ������");
			cin >> temp1 >> temp2;
			tmpN1 = Rational(temp1);
			tmpN2 = Rational(temp2);
			output(Rational::MUL_QQ_Q(tmpN1, tmpN2));
		case 8:
			puts("������� ������ (�������� ������� �� ����)");
			cin >> temp1 >> temp2;
			tmpN1 = Rational(temp1);
			tmpN2 = Rational(temp2);
			output(Rational::DIV_QQ_Q(tmpN1, tmpN2));
		}
	}
}

void polynommenu() {
	unsigned x = 1;
	string temp1, temp2;
	Polynom tmpN1, tmpN2;
	Rational Q;
	int d1, d2;
	int num;
	while (x != 0) {
		puts(" 1 - �������� �����������");
		puts(" 2 - ��������� �����������");
		puts(" 3 - ��������� ���������� �� ������������ �����");
		puts(" 4 - ��������� ���������� �� x^k");
		puts(" 5 - ��������� �� ���������� ��� ������������ ������������� � ��� ����������");
		puts(" 6 - ��������� �����������");
		puts(" 7 - ������� �� ������� ���������� �� ��������� ��� ������� � ��������");
		puts(" 8 - ������� �� ������� ���������� �� ��������� ��� ������� � ��������");
		puts(" 9 - ��� �����������");
		puts("10 - ����������� ����������");
		puts("11 - �������������� ���������� � ������� ����� � �������");
		puts("������� ����� ����: ");
		cin >> x;
		switch (x) {
		case 1:
			puts("�������� �����������");
			cin >> d1 >> temp1 >> d2 >> temp2;
			tmpN1 = Polynom(d1, temp1);
			tmpN2 = Polynom(d2, temp2);
			output(Polynom::ADD_PP_P(tmpN1, tmpN2));
		case 2:
			puts("��������� �����������");
			cin >> d1 >> temp1 >> d2 >> temp2;
			tmpN1 = Polynom(d1, temp1);
			tmpN2 = Polynom(d2, temp2);
			output(Polynom::SUB_PP_P(tmpN1, tmpN2));
		case 3:
			puts("��������� ���������� �� ������������ �����");
			cin >> d1 >> temp1 >> temp2;
			tmpN1 = Polynom(d1, temp1);
			Q = Rational(temp2);
			output(Polynom::MUL_PQ_P(tmpN1, Q));
		case 4:
			puts("��������� ���������� �� x^k");
			cin >> d1 >> temp1 >> num;
			tmpN1 = Polynom(d1, temp1);
			output(Polynom::MUL_Pxk_P(tmpN1, num));
		case 7:
			puts("��������� �� ���������� ��� ������������ ������������� � ��� ����������");
			cin >> d1 >> temp1;
			tmpN1 = Polynom(d1, temp1);
			output(Polynom::FAC_P_Q(tmpN1));
		case 8:
			puts("��������� �����������");
			cin >> d1 >> temp1 >> d2 >> temp2;
			tmpN1 = Polynom(d1, temp1);
			tmpN2 = Polynom(d2, temp2);
			output(Polynom::MUL_PP_P(tmpN1, tmpN2));
		case 9:
			puts("������� �� ������� ���������� �� ��������� ��� ������� � ��������");
			cin >> d1 >> temp1 >> d2 >> temp2;
			tmpN1 = Polynom(d1, temp1);
			tmpN2 = Polynom(d2, temp2);
			output(Polynom::DIV_PP_P(tmpN1, tmpN2));
		case 10:
			puts("������� �� ������� ���������� �� ��������� ��� ������� � ��������");
			cin >> d1 >> temp1 >> d2 >> temp2;
			tmpN1 = Polynom(d1, temp1);
			tmpN2 = Polynom(d2, temp2);
			output(Polynom::MOD_PP_P(tmpN1, tmpN2));
		case 11:
			puts("��� �����������");
			cin >> d1 >> temp1 >> d2 >> temp2;
			tmpN1 = Polynom(d1, temp1);
			tmpN2 = Polynom(d2, temp2);
			output(Polynom::GCF_PP_P(tmpN1, tmpN2));
		case 12:
			puts("����������� ����������");
			cin >> d1 >> temp1;
			tmpN1 = Polynom(d1, temp1);
			output(Polynom::DER_P_P(tmpN1));
		case 13:
			puts("�������������� ���������� � ������� ����� � �������");
			cin >> d1 >> temp1;
			tmpN1 = Polynom(d1, temp1);
			output(Polynom::NMR_P_P(tmpN1));
		}
	}
}

void cryptomenu() {
	unsigned x = 1;
	string temp1, temp2;
	Crypto C;
	vector<uint64_t> enc;
	vector<uint64_t> enc2;
	unsigned start_time, end_time, search_time;
	int num;
	while (x != 0) {
		cin >> x;
		switch (x) {
		case 1:
			puts("������� ��� ������� �����");
			unsigned p, q;
			cin >> p >> q;
			C = Crypto(p, q);
			cout << "e = " << C.get_e() << " m = " << C.get_m() << '\n';
			break;
		case 2:
			puts("�������� ���������");
			puts("������� ���������");
			cin >> temp1;
			enc.resize(temp1.length());
			enc = C.encrypt(temp1);
			for (int i = 0; i < temp1.length(); i++) {
				cout << enc[i] << ' ';
			}
			cout << '\n';
			break;
		case 3:
			puts("����������� ���������");
			puts("1 - ���� ����� �� ����������� 0 - ���� ������ ���");
			cin >> num;
			if (num == 1) {
				cout << C.decrypt(enc) << '\n';
			}
			if (num == 0) {
				puts("����� ���������:");
				cin >> num;
				enc2.resize(num);
				for (int i = 0; i < num; i++) {
					cin >> enc2[i];
				}
				cout << '\n' << C.decrypt(enc2) << '\n';
			}
			break;
		case 4:
			puts("������� ���������");
			start_time = clock();
			cout << C.hack(enc) << '\n';
			end_time = clock();
			search_time = end_time - start_time;
			cout << "������� ������: " << search_time << " ms\n";
			break;
		case 5:
			puts("��������� ���������");
			puts("������� ���������");
			cin >> temp1;
			enc2.resize(temp1.length());
			enc2 = C.sign(temp1);
			for (int i = 0; i < temp1.length(); i++) {
				cin >> enc2[i];
			}
			cout << "\ne = " << C.get_e() << "m = " << C.get_m() << '\n';
			break;
		}
	}
}
int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Russian");
	unsigned int start_time = clock();
	//uint64_t n = 10;
	//if (argv[1])
	//	n = std::atol(argv[1]);

	//uint64_t nth_prime = primesieve::parallel_nth_prime(n);
	//std::cout << n << "th prime = " << nth_prime << std::endl;
	//prime numbers  < 18315

	//Crypto lol(18311, 18313);
	//vector<uint64_t> kek = lol.encrypt("LIFE");
	//string heh = lol.hack(kek);
	//cout << heh;

	unsigned x = 1;
	while (x != 0) {
		cin >> x;
		switch (x) {
		case 1:
			naturalmenu();
			break;
		case 2:
			integermenu();
			break;
		case 3:
			rationalmenu();
			break;
		case 4:
			polynommenu();
			break;
		case 5:
			cryptomenu();
			break;
		}
	}
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << search_time << '\n';
	system("pause");
	return 0;
}
