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
	* Репников Алексей 5308;
	* Сложение многочленов
	*/
	static Polynom SUB_PP_P(Polynom f, Polynom g);
	/**
	* Акатов Фрол 5308;
	* Вычитание многочленов
	*/
	static Polynom MUL_PQ_P(Polynom, Rational);
	/**
	* Болгова Анна 5305;
	* Умножение многочлена на рациональное число
	*/
	static Polynom MUL_Pxk_P(Polynom a, int k);
	/**
	* Михайлов Иван 5308;
	* Умножение многочлена на x^k
	*/
	static Rational LED_P_Q(Polynom);
	/**
	* Баталов Антон 5305;
	* Старший коэффициент многочлена
	*/
	static unsigned DEG_P_N(Polynom P);
	/**
	* Заяев Сергей 5308;
	* Степень многочлена
	*/
	static Rational FAC_P_Q(Polynom);
	/**
	* Сыроветник Дмитрий 5305;
	* Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей
	*/
	static Polynom MUL_PP_P(Polynom a, Polynom b);
	/**
	* Соловьёв Евгений 5308;
	* Умножение многочленов
	*/
	static Polynom DIV_PP_P(Polynom, Polynom);
	/**
	* Петров Михаил 5305;
	* Частное от деления многочлена на многочлен при делении с остатком
	*/
	static Polynom MOD_PP_P(Polynom f, Polynom g);
	/**
	* Акатов Фрол 5308;
	* Остаток от деления многочлена на многочлен
	*/
	static Polynom GCF_PP_P(Polynom, Polynom);
	/**
	* Правда Роман 5305;
	* НОД полиномов
	*/
	static Polynom DER_P_P(Polynom a);
	/**
	* Михайлов Иван 5308;
	* Производная многочлена
	*/
	static Polynom NMR_P_P(Polynom);
	/**
	* Игнатовский Андрей 5305;
	* Преобразование многочлена - кратные корни в простые
	*/

};
