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
	/*
	Функция RED_Q_Q выполняет сокращение дроби
	На вход получает число А
	Объекту Z типа BigInt присваивается результат работы функции
	DIV_ZZ_Z - результат деления большего целого (числителя) на равное или меньшее целое (знаменателя) с остатком

	Параметры функции DIV_ZZ_Z - два целых числа: первое - числитель, второе - результаты функции TRANS_N_Z (параметры TRANS_N_Z - НОД числителя и знаменателя дроби)

	Объекту N типа Natural присваивается значение функции
	DIV_NN_N - деления знаменателя на результат функции
	GCF_NN_N - НОД функции TRANS_Z_N - числителя, преобразованного из целого в натуральное (без знака) и знаменателя
	Создается и возвращается объект result типа Rational - сокращенная дробь

	Автор: Тягунова Мария
	*/
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
		//ЭКСЕПШОН
	}
	return a.Z;
};

Rational Rational::ADD_QQ_Q(const Rational &q1, const Rational &q2) {
	Rational add;
	add.N = Natural::LCM_NN_N(q1.N, q2.N); // находим общий знаменатель и присваеваем его знаменателю результирующей дроби

	Rational q3; // создаём вспомогательную дробь, для вычисления дополнительного множителя первой дроби
	q3.Z = BigInt::TRANS_N_Z(add.N);
	q3.N = q1.N;

	Rational q4;  // создаём вспомогательную дробь, для вычисления дополнительного множителся второй дроби
	q4.Z = BigInt::TRANS_N_Z(add.N);
	q4.N = q2.N;

	//считаем числитель результирующей дроби
	add.Z = BigInt::ADD_ZZ_Z(BigInt::MUL_ZZ_Z(q1.Z, TRANS_Q_Z(RED_Q_Q(q3))), BigInt::MUL_ZZ_Z(q2.Z, TRANS_Q_Z(RED_Q_Q(q4))));
	return RED_Q_Q(add);
};

Rational Rational::SUB_QQ_Q(const Rational &q1, const Rational &q2) {
	Rational sub;
	sub.N = Natural::LCM_NN_N(q1.N, q2.N); // находим НОК двух дробей

	Rational q3;
	q3.Z = BigInt::TRANS_N_Z(sub.N); //преобразовываем натуральный НОК в целое число и записываем в q3
	q3.N = q1.N;					 //знаменатель q3 - это знаменатель q1

	Rational q4;
	q4.Z = BigInt::TRANS_N_Z(sub.N);	//преобразовываем натуральный НОК в целое число и записываем в q4
	q4.N = q2.N;						//знаменатель q4 - это знаменатель q2

	sub.Z = BigInt::SUB_ZZ_Z(BigInt::MUL_ZZ_Z(q1.Z, TRANS_Q_Z(RED_Q_Q(q3))), BigInt::MUL_ZZ_Z(q2.Z, TRANS_Q_Z(RED_Q_Q(q4))));
	//находим разность произведения целой части первой дроби и целой сокращенной q3
	//и произведения целой части второй дроби и целой сокращенной q4 
	return RED_Q_Q(sub);
};

Rational Rational::MUL_QQ_Q(const Rational &q1, const Rational &q2) {
	Rational result(BigInt::MUL_ZZ_Z(q1.Z, q2.Z), Natural::MUL_NN_N(q1.N, q2.N));
	return RED_Q_Q(result);
};

Rational Rational::DIV_QQ_Q(const Rational &a, const Rational &c) {
	if (a.Z.getSign() != c.Z.getSign()) { //сравниваем знаки числителей дробей a и c, если они различны, выполняем описанное в скобках
		Rational result(BigInt::MUL_ZM_Z(BigInt::MUL_ZZ_Z(a.Z, BigInt::TRANS_N_Z(c.N))), Natural::MUL_NN_N(a.N, BigInt::TRANS_Z_N(c.Z)));
		//модулем TRANS_N_Z преобразуем знаменатель дроби c в целое, затем с помощью MUL_ZZ_Z перемножаем числитель дроби a и знаменатель дроби c
		//модулем TRANS_Z_N преобразуем числитель дроби c в натуральное, затем с помощью MUL_NN_N перемножаем знаменатель дроби a и числитель дроби c
		//этими действиями мы как бы перевернули дробь c и перемножили её с a
		//чтобы вернуть знак минус новой дроби используем модуль MUL_ZM_Z
		return RED_Q_Q(result);
	}
	Rational result(BigInt::MUL_ZZ_Z(a.Z, BigInt::TRANS_N_Z(c.N)), Natural::MUL_NN_N(a.N, BigInt::TRANS_Z_N(c.Z)));
	//действия аналогичны, выше описанным, разница лишь в том, что дроби были одного знака, а значит не нужно ставить перед новой знак минус
	return RED_Q_Q(result); //сокращаем дробь и возвращем результат из модуля
};
