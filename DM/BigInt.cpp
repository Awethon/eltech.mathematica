#include "stdafx.h"
#include "BigInt.h"
#include <vector>

BigInt::BigInt() {
	N.resize(0);
	sign = 0;
}

BigInt::BigInt(string strZ) {
	if (strZ[0] == '-') {
		sign = 1;
		N = Natural(strZ.substr(1));
	} else {
		sign = 0;
		N = Natural(strZ);
	}
}

BigInt::BigInt(bool sign, Natural N)
	: sign(sign), N(N) {
}

bool BigInt::getSign() const {
	return sign;
}

unsigned short BigInt::getDigit(unsigned long long rank) const {
	return N.getDigit(rank);
}

int BigInt::getSize() const {
	return N.getSize();
}

Natural BigInt::ABS_Z_N(const BigInt &a) {
	return a.N;
}

int BigInt::POZ_Z_D(const BigInt &x) {
	if (x.N.getDigit(0) == 0 && x.N.getSize() == 1)
		return 0;
	if (x.sign == 0)
		return 2;
	return 1;
}

int BigInt::COM_ZZ_D(const BigInt& a, const BigInt& b) {
	if (POZ_Z_D(a) == POZ_Z_D(b))
		return Natural::COM_NN_D(a.N, b.N);
	return POZ_Z_D(a) == 2 ? 2 : 1;
}

BigInt BigInt::MUL_ZM_Z(const BigInt &a) {
	BigInt result((a.sign == 0) ? 1 : 0, a.N);
	return result;
};

BigInt BigInt::MUL_ZZ_Z(const BigInt &a, const BigInt &b) {

	if (POZ_Z_D(a) == 0 || POZ_Z_D(b) == 0) {
		BigInt result("0");
		return result;
	}
	if (POZ_Z_D(a) == POZ_Z_D(b))
		return TRANS_N_Z(Natural::MUL_NN_N(ABS_Z_N(a), ABS_Z_N(b)));
	return MUL_ZM_Z(TRANS_N_Z((Natural::MUL_NN_N(ABS_Z_N(a), ABS_Z_N(b)))));
}

Natural BigInt::TRANS_Z_N(const BigInt &a) {
	return a.N;
}

BigInt BigInt::TRANS_N_Z(const Natural &a) {
	BigInt b(0, a);
	return b;
}

BigInt BigInt::ADD_ZZ_Z(const BigInt &a, const BigInt &b) {
	if (POZ_Z_D(a) == POZ_Z_D(b)) {
		BigInt result(a.getSign(), Natural::ADD_NN_N(a.N, b.N));
		return result;
	}
	if (Natural::COM_NN_D(TRANS_Z_N(a), TRANS_Z_N(b)) == 2) {
		BigInt result(a.getSign(), Natural::SUB_NN_N(a.N, b.N));
		return result;
	}
	if (Natural::COM_NN_D(TRANS_Z_N(a), TRANS_Z_N(b)) == 1) {
		BigInt result(b.getSign(), Natural::SUB_NN_N(b.N, a.N));
		return result;
	}
	BigInt result("0");
	return result;
	// если у складываемых чисел одинаковые знаки, то результату присваивается знак числа a и значение суммы a и b
	// если a > b и знаки a и b разные, то знак результата берётся у числа a, а значение результата - разность a и b
	// если a < b и знаки a и b разные, то знак результата берётся у числа b, а значение результата - разность b и a
}

BigInt BigInt::SUB_ZZ_Z(const BigInt &a, const BigInt &b) {
	if (POZ_Z_D(a) != POZ_Z_D(b)) {
		BigInt result(a.sign, Natural::ADD_NN_N(ABS_Z_N(a), ABS_Z_N(b)));
		return result;
	}
	if (Natural::COM_NN_D(TRANS_Z_N(a), TRANS_Z_N(b)) == 2) {
		BigInt result(a.sign, Natural::SUB_NN_N(ABS_Z_N(a), ABS_Z_N(b)));
		return result;
	}
	if (Natural::COM_NN_D(TRANS_Z_N(a), TRANS_Z_N(b)) == 1) {
		BigInt result(b.getSign(), Natural::SUB_NN_N(ABS_Z_N(b), ABS_Z_N(a)));
		return result;
	}
	BigInt result("0");
	return result;
	/*
	Функция SUB_ZZ_Z занимается вычитанием целых чисел
	В качестве параметров - два целых числа a и b
	Если знак числа a и знак числа b различны, то создается и возвращается объект result типа BigInt, у которой два поля:
	1 - знак числа a, 2 - результат функции ADD_NN_N - сложение двух натуральных чисел, или параметров, параметры -
	функции ABS_Z_N, которая возвращает натуральное число
	Если результат функции COM_NN_D ( сравнение натуральных чисел) равен 2 - первый параметр больше второго по абсолютной величине
	(в качестве параметров - результаты функций TRANS_Z_N - объект типа Natural), то создается и возвращается  объект result типа BigInt, у которой два поля:
	1 - знак числа а, 2 - результат работы функции SUB_NN_N - разность первого (большего) и второго (меньшего или равного) параметров,
	- параметры которой функции ABS_Z_N, которая возвращает натуральное число
	Если результат функции COM_NN_D ( сравнение натуральных чисел) равен 1 - первое число меньше второго по абсолютной величине
	(в качестве параметров - результаты функций TRANS_Z_N - объект типа Natural), то создается и возвращается стурктура result типа BigInt, у которой два поля:
	1 - знак числа b, 2 - результат работы функции SUB_NN_N - разность первого (большего) и второго (меньшего или равного) параметров,
	- параметры которой функции ABS_Z_N, которая возвращает натуральное число
	Если ни одно из условий не сработало, то числа а и b равны, создается и возвращается стуктура result - остаток, равен нулю

	Автор: Тягунова Мария
	*/
}

BigInt BigInt::DIV_ZZ_Z(const BigInt &a, const BigInt &b) {
	if (POZ_Z_D(a) == 0 || POZ_Z_D(b) == 0) {
		BigInt result("0");
		return result;
	}
	if (POZ_Z_D(a) == POZ_Z_D(b))
		return TRANS_N_Z(Natural::DIV_NN_N(ABS_Z_N(a), ABS_Z_N(b)));
	return MUL_ZM_Z(TRANS_N_Z(Natural::DIV_NN_N(ABS_Z_N(a), ABS_Z_N(b))));
}

BigInt BigInt::MOD_ZZ_Z(const BigInt &a, const BigInt &b) {
	if (POZ_Z_D(a) == POZ_Z_D(b))
		return SUB_ZZ_Z(a, MUL_ZZ_Z(DIV_ZZ_Z(a, b), b));
	//если знаки равны, то модулем DIV_ZZ_Z находим частное от деления a и b, затем с помощью MUL_ZZ_Z 
	//умножаем это частное на b, потом с помощью SUB_ZZ_Z вычитаем из значения a, полученное на предыдущем шаге
	//таким образом мы получили остаток от деления a на b
	return ADD_ZZ_Z(ADD_ZZ_Z(a, b), MUL_ZZ_Z(DIV_ZZ_Z(TRANS_N_Z(a.N), b), b));
	//с помощью TRANS_N_Z переводим беззнаковую чась числа a в целое, 
	//повторяем действия с модулями DIV_ZZ_Z и MUL_ZZ_Z из предыдущего условия
	//с помощью ADD_ZZ_Z складываем исходные значения a и b, а с помощью SUB_ZZ_Z 
	//вычитаем предыдущее значение и полученное на позапрошлом шаге
	//Автор комментариев: Перепёлкина Ксения
}
