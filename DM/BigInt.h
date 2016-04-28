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
	* Болгова  Анна 5305;
	* Абсолютная величина числа, результат - натуральное
	*/
	static int POZ_Z_D(const BigInt &x);
	/**
	* Бураченко Александр 5308;
	* Определение положительности числа (2 - положительное, 0 — равное нулю, 1 - отрицательное)
	*/
	static int COM_ZZ_D(const BigInt&, const BigInt&);
	/**
	* Алексей Половинкин 5308;
	* Сравнение целых чисел (свой модуль)
	*/
	static BigInt MUL_ZM_Z(const BigInt&);
	/**
	* Бакиев Александр 5305;
	* Умножение целого на (-1)
	*/
	static Natural TRANS_Z_N(const BigInt&);
	/**
	* Болгова Анна 5305;
	* Преобразование целого неотрицательного в натуральное
	*/
	static BigInt TRANS_N_Z(const Natural&);
	/**
	* Бабенко Евгений 5308;
	* Преобразование натурального в целое
	*/
	static BigInt ADD_ZZ_Z(const BigInt&, const BigInt&);
	/**
	* Васильев Никита 5305;
	* Сложение целых чисел
	*/
	static BigInt SUB_ZZ_Z(const BigInt&, const BigInt&);
	/**
	* Рябов Владислав 5308;
	* Вычитание целых чисел
	*/
	static BigInt MUL_ZZ_Z(const BigInt&, const BigInt&);
	/**
	* Акатов Фрол 5308;
	* Умножение целых чисел
	*/
	static BigInt DIV_ZZ_Z(const BigInt&, const BigInt&);
	/**
	* Заяев Сергей 5308;
	* Частное от деления большего целого числа на меньшее или равное натуральное с остатком (делитель отличен от нуля)
	*/
	static BigInt MOD_ZZ_Z(const BigInt&, const BigInt&);
	/**
	* Салыкин Владимир 5305;
	* Остаток от деления большего целого числа на мешьнее
	*/
};
