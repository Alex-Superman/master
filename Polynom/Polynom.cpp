#include "Polynom.h"

//конструкто по умолчанию
Polynom::Polynom()
{
	//инициализируем многочлен нулевой степенью
	_size = 1;
	_degree = _size-1;
	
	_degrees = new int[_size];
	_degrees[0] = 0;
	
	_coefficients = new double[_size];
	_coefficients[0] = 0;
}

//конструктор с параметрами
Polynom::Polynom(int degree, double* coefficients)
{
	if (degree < 0)
		throw exception("Неверная степень!");

	if (!coefficients)
		throw exception("Нулевой указатель!");

	//копируем параметры в поля класса
	_degree = degree;
	_size = _degree + 1;

	_degrees = new int[_size];
	_coefficients = new double[_size];
	for (int i = 0; i < _size; i++)
	{
		_degrees[i] = i;
		_coefficients[i] = coefficients[i];
	}
}

//конструктор копирования
Polynom::Polynom(const Polynom& polynom)
{
	//копируем поля входного объекта
	_degree = polynom._degree;
	_size = polynom._size;

	_degrees = new int[_size];
	_coefficients = new double[_size];
	for (int i = 0; i < _size; i++)
	{
		_degrees[i] = polynom._degrees[i];
		_coefficients[i] = polynom._coefficients[i];
	}
}

//оператор присваивания
Polynom& Polynom::operator=(const Polynom& polynom)
{
	//копируем поля входного объекта
	_degree = polynom._degree;
	_size = polynom._size;

	delete[] _coefficients;
	delete[] _degrees;

	_degrees = new int[_size];
	_coefficients = new double[_size];
	for (int i = 0; i < _size; i++)
	{
		_degrees[i] = polynom._degrees[i];
		_coefficients[i] = polynom._coefficients[i];
	}

	return *this;

}



//получение степени многочлена
int Polynom::getDegree()
{
	return _degree;
}



//изменение степеней многочлена вместе с массивом коэффициентов
void Polynom::setDegrees(int size, int* degrees, double* coefficients)
{
	//т.к. степени располагаются от нулевой до degree, то второй аргумент не используется

	//на вход не должны приходить нулевые указатели
	if (!coefficients)
		throw exception("Нулевой указатель!");

	//размер не может быть отрицательным
	if (size <= 0)
		throw exception("Неверный размер!");

	setDegree(size - 1);
	setCoefficients(coefficients);
}

//изменить степень многочлена
void Polynom::setDegree(int degree)
{
	if (degree < 0)
		throw exception("Неверная степень!");

	//создаем массив с новой величиной степени многочлена
	int newSize = degree + 1;
	double* newCoefficints = new double[newSize];
	int* newDegrees = new int[newSize];

	//если новое значение степени больше текущей
	if (degree >= _degree)
	{
		//то из старого массива коэффициентов переносим все коэффициенты
		for (int i = 0; i < _size; i++)
		{
			newCoefficints[i] = _coefficients[i];
			newDegrees[i] = i;
		}
		//освободившиеся ячейки заполняем нулями
		for (int i = _size; i < newSize; i++)
		{
			newCoefficints[i] = 0;
			newDegrees[i] = i;
		}
	}
	else
	{
		//то из старого массива коэффициентов переносим все коэффициенты
		for (int i = 0; i < newSize; i++)
		{
			newCoefficints[i] = _coefficients[i];
			newDegrees[i] = i;
		}
	}

	_degree = degree;
	_size = newSize;

	delete[] _coefficients;
	delete[] _degrees;

	_coefficients = newCoefficints;
	_degrees = newDegrees;
}


//сложение многочленов
Polynom Polynom::operator+(const Polynom& polynom)
{
	Polynom result;

	//если степень текущего многочлена больше степени входного объекта
	if (this->_degree >= polynom._degree)
	{
		//то ставим степень равную степени текущего объекта
		result.setDegree(this->_degree);

		//переносим все коэффициенты из текущего объекта
		for (int i = 0; i < _size; i++)
			result._coefficients[i] = this->_coefficients[i];

		//складываем соответствующие коэффициенты многочленов
		for (int i = 0; i < polynom._size; i++)
			result._coefficients[i] += polynom._coefficients[i];
	}
	else
	{
		//делаем все то же самое, что и в предыдущем случае, только текущий объект и входной поменялись местами
		result.setDegree(polynom._degree);

		for (int i = 0; i < polynom._size; i++)
			result._coefficients[i] = polynom._coefficients[i];

		for (int i = 0; i < _size; i++)
			result._coefficients[i] += this->_coefficients[i];
	}

	//возвращаем ссылку на результирующий объект для того, чтобы можно было составлять множественные выражения
	return result;
}

//вычитание многочленов
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

	//возвращаем ссылку на результирующий объект для того, чтобы можно было составлять множественные выражения
	return result;
}



//оператор инкремента (префиксная форма)
Polynom Polynom::operator++()
{
	setDegree(_degree + 1);

	return *this;
}

//оператор инкремента (постфиксная форма)
Polynom Polynom::operator++(int)
{
	//возвращать будем старую версию текущего объекта
	Polynom temp(*this);

	//увеличиваем степень на единицу
	setDegree(_degree + 1);

	return temp;
}

//оператор декремента (префиксная форма)
Polynom Polynom::operator--()
{
	//уменьшаем степень на единицу
	setDegree(_degree - 1);

	return *this;
}

//оператор декремента (постфиксная форма)
Polynom Polynom::operator--(int)
{
	//возвращать будем старую версию текущего объекта
	Polynom temp(*this);

	//уменьшаем степень на единицу
	setDegree(_degree - 1);

	return temp;
}


//чтение из бинарного файла
void Polynom::read(fstream& file)
{
	//проверяем, чтобы файл бал открыт
	if (!file.is_open())
		return;

	int size;
	double* coefficients;
	int temp;

	//считываем размер
	file.read((char*)&size, sizeof(int));

	if (size <= 0)
		throw exception("Неверный размер!");

	//считываем элементы в формате: коэффициент и степень (степень пропускаем и считываем ее в фиктивный элемент)
	//это сделано для того, чтобы обеспечить корректное чтение многочленов разных классов из одного и того же файла
	coefficients = new double[size];
	for (int i = 0; i < size; i++)
	{
		file.read((char*)&coefficients[i], sizeof(double));
		file.read((char*)&temp, sizeof(int));
	}

	//устанавливаем считанные значения
	setDegrees(size, nullptr, coefficients);
}

//функция вывода на экран - нужна для демонстрации полиморфизма
void Polynom::show()
{
	cout << "CLASS : Polynom" << endl;
	cout << (*this) << endl;
}

//чтение с обычного потока
istream& operator>>(istream& stream, Polynom& polynom)
{
	int size;
	double* coefficients;

	//считываем размер
	stream >> size;

	if (size < 0)
		throw exception("Неверная степень!");

	//считываем элементы в формате: коэффициент (степень установится автоматически)
	coefficients = new double[size];
	for (int i = 0; i < size; i++)
		stream >> coefficients[i];

	//устанавливаем степень и коэффициенты
	polynom.setDegrees(size, nullptr, coefficients);

	return stream;
}

//чтение с файлового потока
ifstream& operator>>(ifstream& file, Polynom& polynom)
{
	int size;
	double* coefficients;
	int temp;

	//считываем степень
	file >> size;

	if (size < 0)
		throw exception("Неверная степень!");

	//считываем элементы в формате: коэффициент (степень установится автоматически)
	coefficients = new double[size];
	for (int i = 0; i < size; i++)
	{
		file >> coefficients[i];
		file >> temp;
	}

	polynom.setDegrees(size, nullptr, coefficients);

	return file;
}
