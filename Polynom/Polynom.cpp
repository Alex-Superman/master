#include "Polynom.h"

/*Лабораторная работа 1*/

//конструкто по умолчанию
Polynom::Polynom()
{
	//инициализируем многочлен нулевой степенью
	_degree = 0;
	
	//и помещаем в него только один элемент - самый первый и равный нулю
	_coefficients = new double[_degree + 1];
	_coefficients[0] = 0;
}

//конструктор с параметрами
Polynom::Polynom(int degree, double* coefficients)
{
	//размер массива должен быть на 1 больше, чем степень многочлена
	//т.к. степень многочлена - максимальная степень одночлена, входящего в многочлен
	//т.е. при степени 9 многочлен будет содержать 10 слагаемых - от 0 до 9 степени включительно

	if (degree < 0)
		throw exception("Negative degree of the polynom");

	if (!coefficients)
		throw exception("Array of coefficients equals to nullptr");

	//сохраняем степень из аргумента
	_degree = degree;

	//копируем все коэффициенты из входного массива в наш объект
	_coefficients = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		_coefficients[i] = coefficients[i];
}

//конструктор копирования
Polynom::Polynom(const Polynom& polynom)
{
	//создаем копию входного объекта

	//копируем степень полинома
	_degree = polynom._degree;

	//копируем все коэффициенты из входного объекта в наш объект
	_coefficients = new double[_degree + 1];
	for (int i = 0; i < _degree + 1; i++)
		this->_coefficients[i] = polynom._coefficients[i];
}

//деструктор
Polynom::~Polynom()
{
	delete[] _coefficients;
}



//геттеры - нужны для получения полей класса

//получение степени многочлена
int Polynom::getDegree()
{
	return _degree;
}

//получение массива коэффициентов
double* Polynom::getCoefficients()
{
	//копируем содержимое массива коэффициентов 
	double* coefficientsCopy = new double[_degree + 1];
	for (int i = 0; i < _degree + 1; i++)
		coefficientsCopy[i] = _coefficients[i];

	//возвращаем копию
	return coefficientsCopy;
}

//получение коэффициента при степени degree
double Polynom::getCoefficient(int degree)
{
	if ((degree < 0) || (degree > _degree))
		throw exception("Bad degree");

	return _coefficients[degree];
}



//сеттеры - методы, необходимые для установки полей класса

//изменить степень многочлена
void Polynom::setDegree(int degree)
{

	if (degree < 0)
		throw exception("Negative degree of the polynom");

	//создаем массив с новой величиной степени многочлена
	double* newCoefficints = new double[degree + 1];

	//если новое значение степени больше текущей
	if (degree >= _degree)
	{
		//при увеличении степени многочлена появившиеся коэффициенты равны нулю

		//то из старого массива коэффициентов переносим все коэффициенты
		for (int i = 0; i < _degree + 1; i++)
			newCoefficints[i] = _coefficients[i];
		//освободившиеся ячейки заполняем нулями
		for (int i = _degree + 1; i < degree + 1; i++)
			newCoefficints[i] = 0;
	}
	else
	{
		//при уменьшении степени многочлена старшие коэффициенты пропадают

		//иначе переносим все коэффициенты кроме последних
		for (int i = 0; i < degree + 1; i++)
			newCoefficints[i] = _coefficients[i];
	}

	//сохраняем новый массив коэффициентов и степень
	delete[] _coefficients;
	_coefficients = newCoefficints;
	_degree = degree;
}

//изменить коэффициенты многочлена
void Polynom::setCoefficients(double* coefficients)
{
	if (!coefficients)
		throw exception("Array of coefficients equals to nullptr");

	for (int i = 0; i < _degree + 1; i++)
		this->_coefficients[i] = coefficients[i];
}

//изменить коэффициент при степени degree
void Polynom::setCoefficient(double coefficient, int degree)
{
	if ((degree < 0) || (degree > _degree))
		throw exception("Bad degree");

	_coefficients[degree] = coefficient;
}



//вывод содержимого многочлена на экран
char * Polynom::toString()
{
	//создаем результирующую строку
	char* str = new char[1000];
	int k = 0;
	//пробегаемся по всем коэффициентам многочлена
	for (int i = 0; i <= _degree; i++)
	{
		//каждый коэффициент переводим в строку
		char* str_number = new char[100];
		_itoa_s(_coefficients[i], str_number, 100, 10);

		//строковое представление коэффициента переносим в результирующую строку
		for (int j = 0; j < strlen(str_number); j++)
			str[k++] = str_number[j];

		str[k++] = ' ';

		delete[] str_number;
	}
	str[k] = '\0';

	return str;
}

//вычислить значение многочлена
double Polynom::compute(double x)
{
	double polynomValue = 0, singleTermValue = 1;
	for (int i = 0; i < _degree + 1; i++)
	{
		polynomValue += singleTermValue * _coefficients[i];

		singleTermValue *= x;
	}

	return polynomValue;
}

/*Лабораторная работа 2*/

//оператор сложения
Polynom Polynom::operator+(const Polynom& polynom)
{
	Polynom result;

	//если степень текущего многочлена больше степени входного объекта
	if (this->_degree >= polynom._degree)
	{
		//то ставим степень равную степени текущего объекта
		result.setDegree(this->_degree);

		//переносим все коэффициенты из текущего объекта
		for (int i = 0; i < this->_degree + 1; i++)
			result._coefficients[i] = this->_coefficients[i];

		//складываем соответствующие коэффициенты многочленов
		for (int i = 0; i < polynom._degree + 1; i++)
			result._coefficients[i] += polynom._coefficients[i];
	}
	else
	{
		//делаем все то же самое, что и в предыдущем случае, только текущий объект и входной поменялись местами
		result.setDegree(polynom._degree);

		for (int i = 0; i < polynom._degree + 1; i++)
			result._coefficients[i] = polynom._coefficients[i];

		for (int i = 0; i < this->_degree + 1; i++)
			result._coefficients[i] += this->_coefficients[i];
	}

	//возвращаем результирующий объект для того, чтобы можно было составлять множественные выражения
	return result;
}

//оператор вычитания
Polynom Polynom::operator-(const Polynom& polynom)
{
	Polynom result;

	//если степень текущего многочлена больше степени входного объекта
	if (this->_degree >= polynom._degree)
	{
		//то ставим степень равную степени текущего объекта
		result.setDegree(this->_degree);

		//переносим все коэффициенты из текущего объекта
		for (int i = 0; i < this->_degree + 1; i++)
			result._coefficients[i] = this->_coefficients[i];

		//вычитаем соответствующие коэффициенты многочленов
		for (int i = 0; i < polynom._degree + 1; i++)
			result._coefficients[i] -= polynom._coefficients[i];
	}
	else
	{
		//делаем все то же самое, что и в предыдущем случае, только текущий объект и входной поменялись местами
		result.setDegree(polynom._degree);

		for (int i = 0; i < polynom._degree + 1; i++)
			result._coefficients[i] = -polynom._coefficients[i];

		for (int i = 0; i < this->_degree + 1; i++)
			result._coefficients[i] += this->_coefficients[i];
	}

	//возвращаем результирующий объект для того, чтобы можно было составлять множественные выражения
	return result;
}

//оператор инкремента (префиксная форма)
Polynom operator++(Polynom& polynom)
{
	polynom.setDegree(polynom._degree + 1);

	return polynom;
}

//оператор инкремента (постфиксная форма)
Polynom operator++(Polynom& polynom, int)
{
	//возвращать будем старую версию текущего объекта
	Polynom temp(polynom);

	//увеличиваем степень на единицу
	polynom.setDegree(polynom._degree + 1);

	return temp;
}

//оператор декремента (префиксная форма)
Polynom operator--(Polynom& polynom)
{
	//уменьшаем степень на единицу
	polynom.setDegree(polynom._degree - 1);

	return polynom;
}

//оператор декремента (постфиксная форма)
Polynom operator--(Polynom& polynom, int)
{
	//возвращать будем старую версию текущего объекта
	Polynom temp(polynom);

	//уменьшаем степень на единицу
	polynom.setDegree(polynom._degree - 1);

	return temp;
}

//оператор для вычисления многочлена как функции
double Polynom::operator()(double x)
{
	//возвращаем вычисленное значение полинома от х
	return compute(x);
}

//оператор индексирования
double& Polynom::operator[](int degree)
{
	if ((degree < 0) || (degree > _degree))
		throw exception("Bad index");

	//возвращаем коэффициент при степени degree
	return _coefficients[degree];
}

//оператор присваивания
Polynom& Polynom::operator=(const Polynom& polynom)
{
	delete[] _coefficients;

	//копируем содержимое входного объекта в текущий
	_degree = polynom._degree;
	_coefficients = new double[_degree + 1];
	for (int i = 0; i < _degree + 1; i++)
		_coefficients[i] = polynom._coefficients[i];

	return *this;

}

