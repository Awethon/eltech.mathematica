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
	* Криворучко Никита 5305;
	* Сокращение дроби
	*/
	static bool INT_Q_B(const Rational&);
	/**
	* Тягунова Мария 5308;
	* Проверка на целое, если рациональное число является целым, то «да», иначе «нет»
	*/
	static Rational TRANS_Z_Q(const BigInt&);
	/**
	* Ефимова Юлия 5305;
	* Преобразование целого в дробное
	*/
	static BigInt TRANS_Q_Z(const Rational&);
	/**
	* Гусаков Виктор 5308;
	* Преобразование дробного в целое (если знаменатель равен 1)
	*/
	static Rational ADD_QQ_Q(const Rational&, const Rational&);
	/**
	* Репников Алексей 5308;
	* Сложение дробей
	*/
	static Rational SUB_QQ_Q(const Rational&, const Rational&);
	/**
	* Аксинин Александр 5308;
	* Вычитание дробей
	*/
	static Rational MUL_QQ_Q(const Rational&, const Rational&);
	/**
	* Ефимова Юлия 5305;
	* Умножение дробей
	*/
	static Rational DIV_QQ_Q(const Rational&, const Rational&);
	/**
	* Перепёлкина Ксения 5308;
	* Деление дробей (делитель отличен от нуля)
	*/

};
