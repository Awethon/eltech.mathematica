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
     * Бакиев Александр 5305; 
     * Сравнение натуральных чисел
     * return 2, если первое больше;
     *        1, если меньше;
     *        0, если равно.
     */
	static bool NZER_N_B(const Natural&);
	/**
	* Яковлева Наталья 5308;
	* Проверка на ноль: если число не равно нулю, то «да» иначе «нет»
	*/
	static Natural ADD_1N_N(Natural);
	/**
	* Бакиев Александр 5305;
	* Добавление 1 к натуральному числу
	*/
	static Natural ADD_NN_N(Natural, Natural);
	/**
	* Гребенюк Артём 5308;
	* Сложение натуральных чисел
	*/
	static Natural SUB_NN_N(Natural, Natural);
	/**
	* Игнатовский Андрей 5305;
	* Вычитание из первого большего натурального числа второго меньшего или равного
	*/
	static Natural MUL_ND_N(const Natural&, int);
	/**
	* Эмдин Марк 5308;
	* Умножение натурального числа на цифру
	*/
	static Natural MUL_Nk_N(const Natural&, int);
	/**
	* Баталов Антон 5305;
	* Умножение натурального числа на 10^k
	*/
	static Natural MUL_NN_N(const Natural&, const Natural&);
	/**
	* Коростелев Константин 5308;
	* Умножение натуральных чисел
	*/
	static Natural SUB_NDN_N(const Natural&, int, const Natural&);
	/**
	* Цаллагова Маргарита 5308;
	*/
	static Natural DIV_NN_Dk(const Natural&, const Natural&);
	/**
	* Павел Бухтик 5308;
	* Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k, где k - номер позиции этой цифры (номер считается с нуля)
	*/
	static Natural DIV_NN_N(const Natural&, const Natural&);
	/**
	* Сертхир Стефан 5305;
	* Частное от деления большего натурального числа на меньшее или равное натуральное с остатком (делитель отличен от нуля)
	*/
	static Natural MOD_NN_N(const Natural&, const Natural&);
	/**
	* Касатиков Сергей 5308;
	* Остаток от деления большего натурального числа на меньшее или равное натуральное с остатком (делитель отличен от нуля)
	*/
	static Natural GCF_NN_N(Natural, Natural);
	/**
	* Егоров Андрей 5305;
	* НОД натуральных чисел
	*/
	static Natural LCM_NN_N(const Natural&, const Natural&);
	/**
	* Самойленко Даниил 5305;
	* НОК натуральных чисел
	*/
};
