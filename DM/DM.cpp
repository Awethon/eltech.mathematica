// DM.cpp: определяет точку входа для консольного приложения.
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
		puts(" 1 - Сравнение натуральных чисел: 2 - если первое больше либо равно второму, 0, если равно, 1 иначе.");
		puts(" 2 - Проверка на ноль: если число не равно нулю, то «да» иначе «нет»");
		puts(" 3 - Добавление 1 к натуральному числу");
		puts(" 4 - Сложение натуральных чисел");
		puts(" 5 - Вычитание из первого большего натурального числа второго меньшего или равного");
		puts(" 6 - Умножение натурального числа на цифру");
		puts(" 7 - Умножение натурального числа на 10^k");
		puts(" 8 - Умножение натуральных чисел");
		puts(" 9 - Вычитание из натурального другого натурального, умноженного на цифру для случая с неотрицательным результатом");
		puts("10 - Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k, где k - номер позиции этой цифры (номер считается с нуля)");
		puts("11 - Частное от деления большего натурального числа на меньшее или равное натуральное с остатком (делитель отличен от нуля)");
		puts("12 - Остаток от деления большего натурального числа на меньшее или равное натуральное с остатком (делитель отличен от нуля)");
		puts("13 - НОД натуральных чисел");
		puts("14 - НОК натуральных чисел");
		puts("Введите номер меню: ");
		cin >> x;
		switch (x) {
		case 1:
			puts("Сравнение натуральных чисел: 2 - если первое больше либо равно второму, 0, если равно, 1 иначе.");
			cin >> temp1 >> temp2;
			tmpN1 = Natural(temp1);
			tmpN2 = Natural(temp2);
			std::cout << Natural::COM_NN_D(tmpN1, tmpN2);
			break;
		case 2:
			puts("Проверка на ноль: если число не равно нулю, то «да» иначе «нет»");
			cin >> temp1;
			tmpN1 = Natural(temp1);
			std::cout << Natural::NZER_N_B(tmpN1);
			break;
		case 3:
			puts("Добавление 1 к натуральному числу");
			cin >> temp1;
			tmpN1 = Natural(temp1);
			output(Natural::ADD_1N_N(tmpN1));
			break;
		case 4:
			puts("Сложение натуральных чисел");
			cin >> temp1 >> temp2;
			tmpN1 = Natural(temp1);
			tmpN2 = Natural(temp2);
			output(Natural::ADD_NN_N(tmpN1, tmpN2));
			break;
		case 5:
			puts("Вычитание из первого большего натурального числа второго меньшего или равного");
			cin >> temp1 >> temp2;
			tmpN1 = Natural(temp1);
			tmpN2 = Natural(temp2);
			output(Natural::SUB_NN_N(tmpN1, tmpN2));
			break;
		case 6:
			puts("Умножение натурального числа на цифру");
			cin >> temp1 >> num;
			tmpN1 = Natural(temp1);
			output(Natural::MUL_ND_N(tmpN1, num));
			break;
		case 7:
			puts("Умножение натурального числа на 10^k");
			cin >> temp1 >> num;
			tmpN1 = Natural(temp1);
			output(Natural::MUL_ND_N(tmpN1, num));
			break;
		case 8:
			puts("Умножение натуральных чисел");
			cin >> temp1 >> temp2;
			tmpN1 = Natural(temp1);
			tmpN2 = Natural(temp2);
			output(Natural::MUL_NN_N(tmpN1, tmpN2));
			break;
		case 9:
			puts("Вычитание из натурального другого натурального, умноженного на цифру для случая с неотрицательным результатом");
			cin >> temp1 >> temp2 >> num;
			tmpN1 = Natural(temp1);
			tmpN2 = Natural(temp2);
			output(Natural::SUB_NDN_N(tmpN1, num, tmpN2));
			break;
		case 10:
			puts("Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k, где k - номер позиции этой цифры (номер считается с нуля)");
			cin >> temp1 >> temp2;
			tmpN1 = Natural(temp1);
			tmpN2 = Natural(temp2);
			output(Natural::DIV_NN_Dk(tmpN1, tmpN2));
			break;
		case 11:
			puts("Частное от деления большего натурального числа на меньшее или равное натуральное с остатком (делитель отличен от нуля)");
			cin >> temp1 >> temp2;
			tmpN1 = Natural(temp1);
			tmpN2 = Natural(temp2);
			output(Natural::DIV_NN_N(tmpN1, tmpN2));
			break;
		case 12:
			puts("Остаток от деления большего натурального числа на меньшее или равное натуральное с остатком (делитель отличен от нуля)");
			cin >> temp1 >> temp2;
			tmpN1 = Natural(temp1);
			tmpN2 = Natural(temp2);
			output(Natural::MOD_NN_N(tmpN1, tmpN2));
			break;
		case 13:
			puts("НОД натуральных чисел");
			cin >> temp1 >> temp2;
			tmpN1 = Natural(temp1);
			tmpN2 = Natural(temp2);
			output(Natural::GCF_NN_N(tmpN1, tmpN2));
			break;
		case 14:
			puts("НОК натуральных чисел");
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
		puts(" 1 - Абсолютная величина числа, результат - натуральное");
		puts(" 2 - Определение положительности числа (2 - положительное, 0 — равное нулю, 2 1 - отрицательное)");
		puts(" 3 - Умножение целого на (-1)");
		puts(" 6 - Сложение целых чисел");
		puts(" 7 - Вычитание целых чисел");
		puts(" 8 - Умножение целых чисел");
		puts(" 9 - Частное от деления большего целого числа на меньшее или равное натуральное с остатком (делитель отличен от нуля)");
		puts("10 - Остаток от деления большего целого числа на меньшее или равное натуральное с остатком (делитель отличен от нуля)");
		puts("Введите номер меню: ");
		cin >> x;
		switch (x) {
		case 1:
			puts("Абсолютная величина числа, результат - натуральное");
			cin >> temp1;
			tmpN1 = BigInt(temp1);
			output(BigInt::ABS_Z_N(tmpN1));
			break;
		case 2:
			puts("Определение положительности числа (2 - положительное, 0 — равное нулю, 2 1 - отрицательное)");
			cin >> temp1;
			tmpN1 = BigInt(temp1);
			std::cout << BigInt::POZ_Z_D(tmpN1);
			break;
		case 3:
			puts("Умножение целого на (-1)");
			cin >> temp1;
			tmpN1 = BigInt(temp1);
			output(BigInt::MUL_ZM_Z(tmpN1));
			break;
		case 6:
			puts("Сложение целых чисел");
			cin >> temp1 >> temp2;
			tmpN1 = BigInt(temp1);
			tmpN2 = BigInt(temp2);
			output(BigInt::ADD_ZZ_Z(tmpN1, tmpN2));
			break;
		case 7:
			puts("Вычитание целых чисел");
			cin >> temp1 >> temp2;
			tmpN1 = BigInt(temp1);
			tmpN2 = BigInt(temp2);
			output(BigInt::SUB_ZZ_Z(tmpN1, tmpN2));
			break;
		case 8:
			puts("Умножение целых чисел");
			cin >> temp1 >> temp2;
			tmpN1 = BigInt(temp1);
			tmpN2 = BigInt(temp2);
			output(BigInt::MUL_ZZ_Z(tmpN1, tmpN2));
			break;
		case 9:
			puts("Частное от деления большего целого числа на меньшее или равное натуральное с остатком (делитель отличен от нуля)");
			cin >> temp1 >> temp2;
			tmpN1 = BigInt(temp1);
			tmpN2 = BigInt(temp2);
			output(BigInt::DIV_ZZ_Z(tmpN1, tmpN2));
			break;
		case 10:
			puts("Остаток от деления большего целого числа на меньшее или равное натуральное с остатком (делитель отличен от нуля)");
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
		puts("1 - Сокращение дроби");
		puts("2 - Проверка на целое, если рациональное число является целым, то «да», иначе «нет»");
		puts("3 - Преобразование целого в дробное");
		puts("4 - Преобразование дробного в целое (если знаменатель равен 1)");
		puts("5 - Сложение дробей");
		puts("6 - Вычитание дробей");
		puts("7 - Умножение дробей");
		puts("8 - Деление дробей (делитель отличен от нуля)");
		puts("Введите номер меню: ");
		cin >> x;
		switch (x) {
		case 1:
			puts("Сокращение дроби");
			cin >> temp1;
			tmpN1 = Rational(temp1);
			output(Rational::RED_Q_Q(tmpN1));
			break;
		case 2:
			puts("Проверка на целое, если рациональное число является целым, то «да», иначе «нет»");
			cin >> temp1;
			tmpN1 = Rational(temp1);
			std::cout << Rational::INT_Q_B(tmpN1);
			break;
		case 5:
			puts("Сложение дробей");
			cin >> temp1 >> temp2;
			tmpN1 = Rational(temp1);
			tmpN2 = Rational(temp2);
			output(Rational::ADD_QQ_Q(tmpN1, tmpN2));
		case 6:
			puts("Вычитание дробей");
			cin >> temp1 >> temp2;
			tmpN1 = Rational(temp1);
			tmpN2 = Rational(temp2);
			output(Rational::SUB_QQ_Q(tmpN1, tmpN2));
		case 7:
			puts("Умножение дробей");
			cin >> temp1 >> temp2;
			tmpN1 = Rational(temp1);
			tmpN2 = Rational(temp2);
			output(Rational::MUL_QQ_Q(tmpN1, tmpN2));
		case 8:
			puts("Деление дробей (делитель отличен от нуля)");
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
		puts(" 1 - Сложение многочленов");
		puts(" 2 - Вычитание многочленов");
		puts(" 3 - Умножение многочлена на рациональное число");
		puts(" 4 - Умножение многочлена на x^k");
		puts(" 5 - Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей");
		puts(" 6 - Умножение многочленов");
		puts(" 7 - Частное от деления многочлена на многочлен при делении с остатком");
		puts(" 8 - Остаток от деления многочлена на многочлен при делении с остатком");
		puts(" 9 - НОД многочленов");
		puts("10 - Производная многочлена");
		puts("11 - Преобразование многочлена — кратные корни в простые");
		puts("Введите номер меню: ");
		cin >> x;
		switch (x) {
		case 1:
			puts("Сложение многочленов");
			cin >> d1 >> temp1 >> d2 >> temp2;
			tmpN1 = Polynom(d1, temp1);
			tmpN2 = Polynom(d2, temp2);
			output(Polynom::ADD_PP_P(tmpN1, tmpN2));
		case 2:
			puts("Вычитание многочленов");
			cin >> d1 >> temp1 >> d2 >> temp2;
			tmpN1 = Polynom(d1, temp1);
			tmpN2 = Polynom(d2, temp2);
			output(Polynom::SUB_PP_P(tmpN1, tmpN2));
		case 3:
			puts("Умножение многочлена на рациональное число");
			cin >> d1 >> temp1 >> temp2;
			tmpN1 = Polynom(d1, temp1);
			Q = Rational(temp2);
			output(Polynom::MUL_PQ_P(tmpN1, Q));
		case 4:
			puts("Умножение многочлена на x^k");
			cin >> d1 >> temp1 >> num;
			tmpN1 = Polynom(d1, temp1);
			output(Polynom::MUL_Pxk_P(tmpN1, num));
		case 7:
			puts("Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей");
			cin >> d1 >> temp1;
			tmpN1 = Polynom(d1, temp1);
			output(Polynom::FAC_P_Q(tmpN1));
		case 8:
			puts("Умножение многочленов");
			cin >> d1 >> temp1 >> d2 >> temp2;
			tmpN1 = Polynom(d1, temp1);
			tmpN2 = Polynom(d2, temp2);
			output(Polynom::MUL_PP_P(tmpN1, tmpN2));
		case 9:
			puts("Частное от деления многочлена на многочлен при делении с остатком");
			cin >> d1 >> temp1 >> d2 >> temp2;
			tmpN1 = Polynom(d1, temp1);
			tmpN2 = Polynom(d2, temp2);
			output(Polynom::DIV_PP_P(tmpN1, tmpN2));
		case 10:
			puts("Остаток от деления многочлена на многочлен при делении с остатком");
			cin >> d1 >> temp1 >> d2 >> temp2;
			tmpN1 = Polynom(d1, temp1);
			tmpN2 = Polynom(d2, temp2);
			output(Polynom::MOD_PP_P(tmpN1, tmpN2));
		case 11:
			puts("НОД многочленов");
			cin >> d1 >> temp1 >> d2 >> temp2;
			tmpN1 = Polynom(d1, temp1);
			tmpN2 = Polynom(d2, temp2);
			output(Polynom::GCF_PP_P(tmpN1, tmpN2));
		case 12:
			puts("Производная многочлена");
			cin >> d1 >> temp1;
			tmpN1 = Polynom(d1, temp1);
			output(Polynom::DER_P_P(tmpN1));
		case 13:
			puts("Преобразование многочлена — кратные корни в простые");
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
			puts("Введите два простых числа");
			unsigned p, q;
			cin >> p >> q;
			C = Crypto(p, q);
			cout << "e = " << C.get_e() << " m = " << C.get_m() << '\n';
			break;
		case 2:
			puts("Шифровка сообщения");
			puts("Введите сообщение");
			cin >> temp1;
			enc.resize(temp1.length());
			enc = C.encrypt(temp1);
			for (int i = 0; i < temp1.length(); i++) {
				cout << enc[i] << ' ';
			}
			cout << '\n';
			break;
		case 3:
			puts("Расшифровка сообщения");
			puts("1 - если взять из предыдущего 0 - если ввести своё");
			cin >> num;
			if (num == 1) {
				cout << C.decrypt(enc) << '\n';
			}
			if (num == 0) {
				puts("Длина сообщения:");
				cin >> num;
				enc2.resize(num);
				for (int i = 0; i < num; i++) {
					cin >> enc2[i];
				}
				cout << '\n' << C.decrypt(enc2) << '\n';
			}
			break;
		case 4:
			puts("Хакнуть сообщение");
			start_time = clock();
			cout << C.hack(enc) << '\n';
			end_time = clock();
			search_time = end_time - start_time;
			cout << "Времени прошло: " << search_time << " ms\n";
			break;
		case 5:
			puts("Подписать сообщение");
			puts("Введите сообщение");
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
