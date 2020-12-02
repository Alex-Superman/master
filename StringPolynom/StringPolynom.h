#pragma once

#include "../DegreesPolynom/DegreesPolynom.h"

//многочлен со строкой
class StringPolynom : public DegreesPolynom
{
public:

	/*
	Конструктор по умолчанию
	создает многочлен нулевой степени с коэффицинтом ноль
	*/
	StringPolynom();

	/*
	Конструктор с параметрами
	создает многочлен размера size со степенями degrees и коэффициентами coefficients
	также, массив степеней сортируется по возрастанию
	args:
		size - размер многочлена
		degrees - массив степеней
		coeff - массив коэффициентов
	Исключения:
		если встречен нулевой указатель
		если размер меньше или равен нулю
		если массив степеней содержит отрицательные степени или совпадающие степени
	*/
	StringPolynom(int size, int* degrees, double* coefficients);

	/*
	Конструктор копирования
	создает копию входного многочлена
	args:
		polynom - копируемый объект
	*/
	StringPolynom(const StringPolynom& polynom);

	/*
	Оператор присваивания
	создает копию входного многочлена
	args:
		polynom - копируемый объект
	*/
	StringPolynom& operator=(const StringPolynom& polynom);

	//виртуальный деструктор - уничтожает "свою" часть объекта
	virtual ~StringPolynom();



	/*
	получение строки
	return:
		копия строки _str
	*/
	char* getStr();



	/*
	сеттер для степеней
	устанавливает многочлену размер size, степени degrees и коэффициенты coefficients
	также, массив степеней сортируется по возрастанию
	args:
		size - размер многочлена
		degrees - массив степеней
		coefficients - массив коэффициентов
	Исключения:
		если встречен нулевой указатель
		если размер меньше или равен нулю
		если массив степеней содержит отрицательные степени или совпадающие степени
	*/
	virtual void setDegrees(int size, int* degrees, double* coefficients) override;

	/*
	сеттер для коэффициентов
	устанавливает многочлену коэффициенты coefficients
	args:
		coefficients - массив коэффициентов
	Исключения:
		если встречен нулевой указатель
	*/
	virtual void setCoefficients(double* coefficients) override;



	/*
	Оператор сложения
	args:
		polynom - слагаемый полином
	return:
		полином - результат сложения многочленов
	*/
	StringPolynom operator+(const StringPolynom& polynom);

	/*
	Оператор вычитания
	args:
		polynom - вычитаемый полином
	return:
		полином - результат вычитания многочленов
	*/
	StringPolynom operator-(const StringPolynom& polynom);



	//операторы вывода аналогичны операторам вывода для многочлена с коэффициентами

	/*
	Оператор чтения с обычного потока
	считывает многочлен с обычного потока
	args:
		stream - поток чтения
		polynom - считываемый многочлен
	return:
		ссылка на поток ввода
	Исключения:
		если размер меньше или равен нулю
		если массив степеней содержит отрицательные степени или совпадающие степени
	*/
	friend istream& operator>>(istream& stream, StringPolynom& polynom);

	/*
	Оператор чтения с файлового потока
	считывает многочлен с файлового потока
	args:
		stream - поток чтения
		polynom - считываемый многочлен
	return:
		ссылка на поток ввода
	Исключения:
		если размер меньше или равен нулю
		если массив степеней содержит отрицательные степени или совпадающие степени
	*/
	friend ifstream& operator>>(ifstream& stream, StringPolynom& polynom);

	/*
	чтения из бинарного файла
	args:
		file - бинарный файл
	Исключения:
		если file не открыт
		если размер меньше или равен нулю
		если массив степеней содержит отрицательные степени или совпадающие степени
	*/
	virtual void read(fstream& file) override;

protected:

	/*
	метод обновления строки
	переписывает _str
	*/
	void rewriteStr();

	//строка с многочленом
	char* _str;
};

