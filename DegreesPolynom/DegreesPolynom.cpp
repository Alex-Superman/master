#include "DegreesPolynom.h"

#include <exception>
#include <cmath>


//проверить, может ли массив быть массивом коэффициентов
bool DegreesPolynom::isArrayOfDegrees(int size, int* degrees)
{
	//проверяем каждый элемент массива степеней
	for (int i = 0; i < size; i++)
	{
		//в массиве не должно быть отрицательных степеней
		if (degrees[i] < 0)
			return false;

		//проверяем в массиве наличие одинаковых степеней
		for (int j = 0; j < size; j++)
		{
			if (i == j)
				continue;

			//в массиве не должно быть дублирующихся степеней
			if (degrees[i] == degrees[j])
				return false;
		}
	}

	return true;
}

//сортировка массива степеней в порядке возрастания
void DegreesPolynom::sort(int size, int* degrees, double * coefficients)
{
	//сортировка выбором

	//для каждого элемента массива
	for (int i = 0; i < size; i++) 
	{
		//ищем минимальный среди следующих элементов
		int minIndex = i;
		for (int j = i + 1; j < size; j++)
			if (degrees[j] < degrees[minIndex])
				minIndex = j;

		//меняем текущий элемент и минимальный
		int swap = degrees[minIndex];
		degrees[minIndex] = degrees[i];
		degrees[i] = swap;

		//также, меняем соответствующие коэффициенты
		double swap2 = coefficients[minIndex];
		coefficients[minIndex] = coefficients[i];
		coefficients[i] = swap2;
	}
}


//конструктор по умолчанию
DegreesPolynom::DegreesPolynom()
{
	//создаем полином из одного коэффициента 0
	_size = 1;
	
	_degrees = new int[_size];
	_degrees[0] = 0;
	
	_coefficients = new double[_size];
	_coefficients[0] = 0;
}

//конструктор с параметрами
DegreesPolynom::DegreesPolynom(int size, int* degrees, double* coefficients)
{
	_degrees = nullptr;
	_coefficients = nullptr;

	//устанавливаем нужные параметры
	setDegrees(size, degrees, coefficients);
}

//конструктор копирования
DegreesPolynom::DegreesPolynom(const DegreesPolynom& polynom)
{
	//копируем все параметры входного объекта
	_size = polynom._size;

	_coefficients = new double[_size];
	for (int i = 0; i < _size; i++)
		_coefficients[i] = polynom._coefficients[i];

	_degrees = new int[_size];
	for (int i = 0; i < _size; i++)
		_degrees[i] = polynom._degrees[i];
}

//оператор присваивания
DegreesPolynom& DegreesPolynom::operator=(const DegreesPolynom& Obj)
{
	delete[] _degrees;
	delete[] _coefficients;

	//копируем все поля входного объекта
	_size = Obj._size;

	_coefficients = new double[_size];
	for (int i = 0; i < _size; i++)
		_coefficients[i] = Obj._coefficients[i];

	_degrees = new int[_size];
	for (int i = 0; i < _size; i++)
		_degrees[i] = Obj._degrees[i];

	return *this;
}

//деструктор
DegreesPolynom::~DegreesPolynom()
{
	delete[] _coefficients;
	delete[] _degrees;
}


//получение размера многочлена
int DegreesPolynom::getSize()
{
	return _size;
}

//получение массива степеней
int* DegreesPolynom::getDegrees()
{
	int * copyDegrees = new int[_size];
	for (int i = 0; i < _size; i++)
		copyDegrees[i] = _degrees[i];

	return copyDegrees;
}

//получение степени по индексу
int DegreesPolynom::getDegree(int index)
{
	if ((index < 0) || (index >= _size))
		throw exception("bad index");

	return _degrees[index];
}

//получение массива коэффициентов
double* DegreesPolynom::getCoefficients()
{
	double* copyCoeff = new double[_size];
	for (int i = 0; i < _size; i++)
		copyCoeff[i] = _coefficients[i];

	return copyCoeff;
}


//изменение многочлена
void DegreesPolynom::setDegrees(int size, int* degrees, double* coefficients)
{

	//на вход не должны приходить нулевые указатели
	if (!coefficients)
		throw exception("nullptr");

	if (!degrees)
		throw exception("nullptr");

	//размер не может быть отрицательным
	if (size <= 0)
		throw exception("bad size");

	//массив должен соответствовать требованиям
	if (!isArrayOfDegrees(size, degrees))
		throw exception("bad array of degrees");

	delete[] _degrees;
	delete[] _coefficients;

	//копируем данные в текущий объект
	_size = size;

	_degrees = new int[_size];
	for (int i = 0; i < _size; i++)
		_degrees[i] = degrees[i];

	_coefficients = new double[_size];
	for (int i = 0; i < _size; i++)
		_coefficients[i] = coefficients[i];

	sort(_size, _degrees, _coefficients);
}

//изменение массива коэффициентов
void DegreesPolynom::setCoefficients(double* coefficients)
{
	if (!coefficients)
		throw exception("nullptr");

	for (int i = 0; i < _size; i++)
		_coefficients[i] = coefficients[i];
}



//оператор вычисления функции
double DegreesPolynom::operator()(double x)
{
	double sum = 0;

	for (int i = 0; i < _size; i++)
		sum += pow(x, _degrees[i]) * _coefficients[i];

	return sum;
}

//оператор индексирования
double& DegreesPolynom::operator[](int index)
{
	if ((index < 0) || (index >= _size))
		throw exception("bad index");

	return _coefficients[index];
}



//оператор сложения
DegreesPolynom DegreesPolynom::operator+(const DegreesPolynom& obj)
{
	//подсчитываем количество уникальных степеней
	int resultSize = _size + obj._size;
	for (int i = 0; i < _size; i++)
		for (int j = 0; j < obj._size; j++)
			//если встречены совпадающие элементы
			if (_degrees[i] == obj._degrees[j])
				resultSize--;

	int* resultDegrees = new int[resultSize];

	int i = 0, j = 0, k = 0;
	//добавляем в результирующий массив степеней несовпадающие элементы (чтобы не было двух одинаковых степеней в массиве)
	while ((i < _size) && (j < obj._size)) 
		if (_degrees[i] < obj._degrees[j])
			resultDegrees[k++] = _degrees[i++];
		else 
			if (_degrees[i] > obj._degrees[j])
				resultDegrees[k++] = obj._degrees[j++];
			else 
			{
				resultDegrees[k++] = _degrees[i++];
				j++;
			}
	while (i < _size)
		resultDegrees[k++] = _degrees[i++];
	while (j < obj._size)
		resultDegrees[k++] = obj._degrees[j++];

	//формируем массив коэффициентов
	double* resultCoeffs = new double[resultSize];
	for (int o = 0; o < resultSize; o++)
		resultCoeffs[o] = 0;
	
	//добавляем в сумму коэффициенты из первого многочлена
	for (int o = 0; o < _size;o++)
		for (int s = 0; s < resultSize; s++)
			if (_degrees[o] == resultDegrees[s])
				resultCoeffs[s] += _coefficients[o];

	//добавляем в сумму коэффициенты из второго многочлена
	for (int o = 0; o < obj._size; o++)
		for (int s = 0; s < resultSize; s++)
			if (obj._degrees[o] == resultDegrees[s])
				resultCoeffs[s] += obj._coefficients[o];

	//возвращаем результирующий объект
	return DegreesPolynom(resultSize,resultDegrees,resultCoeffs);
}

//оператор сложения
DegreesPolynom DegreesPolynom::operator-(const DegreesPolynom& obj)
{
	//подсчитываем количество уникальных элементов
	int resultSize = _size + obj._size;
	for (int i = 0; i < _size; i++)
		for (int j = 0; j < obj._size; j++)
			//если встречены совпадающие элементы
			if (_degrees[i] == obj._degrees[j])
				resultSize--;

	int* resultDegrees = new int[resultSize];

	int i = 0, j = 0, k = 0;
	//добавляем в результирующий массив степеней несовпадающие элементы (чтобы не было двух одинаковых степеней в массиве)
	while ((i < _size) && (j < obj._size))
		if (_degrees[i] < obj._degrees[j])
			resultDegrees[k++] = _degrees[i++];
		else
			if (_degrees[i] > obj._degrees[j])
				resultDegrees[k++] = obj._degrees[j++];
			else
			{
				resultDegrees[k++] = _degrees[i++];
				j++;
			}

	while (i < _size)
		resultDegrees[k++] = _degrees[i++];

	while (j < obj._size)
		resultDegrees[k++] = obj._degrees[j++];

	//формируем массив коэффициентов
	double* resultCoeffs = new double[resultSize];
	for (int o = 0; o < resultSize; o++)
		resultCoeffs[o] = 0;

	//добавляем в сумму коэффициенты из первого многочлена
	for (int o = 0; o < _size; o++)
		for (int s = 0; s < resultSize; s++)
			if (_degrees[o] == resultDegrees[s])
				resultCoeffs[s] += _coefficients[o];

	//добавляем в сумму коэффициенты из второго многочлена
	for (int o = 0; o < obj._size; o++)
		for (int s = 0; s < resultSize; s++)
			if (obj._degrees[o] == resultDegrees[s])
				resultCoeffs[s] -= obj._coefficients[o];

	//возвращаем результирующий объект
	return DegreesPolynom(resultSize, resultDegrees, resultCoeffs);
}


//вывод в обычный поток
ostream& operator<<(ostream& stream, const DegreesPolynom& obj)
{
	//выводим многочлен в поток
	for (int i = 0; i < obj._size - 1; i++)
		stream << obj._coefficients[i] << "*x^" << obj._degrees[i] << " + ";

	stream << obj._coefficients[obj._size - 1] << "*x^" << obj._degrees[obj._size - 1];

	return stream;
}

//вывод в файловый поток
ofstream& operator<<(ofstream& stream, const DegreesPolynom& obj)
{
	//выводим в файловый поток размер, а потом каждый элемент многочлена в формате: коэффициент и степень
	stream << obj._size << " ";

	for (int i = 0; i < obj._size; i++)
		stream << obj._coefficients[i] << " " << obj._degrees[i] << " ";

	return stream;
}

//чтение с обычного потока
istream& operator>>(istream& stream, DegreesPolynom& obj)
{
	int size;
	double* coeff;
	int* degrees;

	//считываем размер
	stream >> size;

	if (size <= 0)
		throw exception("bad size");

	//считываем элементы в формате: коэффициент и степень
	coeff = new double[size];
	degrees = new int[size];
	for (int i = 0; i < size; i++)
	{
		stream >> coeff[i];
		stream >> degrees[i];
	}

	//устанавливаем считанные значения
	obj.setDegrees(size, degrees, coeff);

	return stream;
}

//чтение с файлового потока
ifstream& operator>>(ifstream& stream, DegreesPolynom& obj)
{
	int size;
	double* coeff;
	int* degrees;

	//считываем размер
	stream >> size;

	if (size <= 0)
		throw exception("bad size");

	//считываем элементы в формате: коэффициент и степень
	coeff = new double[size];
	degrees = new int[size];
	for (int i = 0; i < size; i++)
	{
		stream >> coeff[i];
		stream >> degrees[i];
	}

	//устанавливаем считанные значения
	obj.setDegrees(size, degrees, coeff);

	return stream;
}

//запись в бинарный файл
void DegreesPolynom::write(fstream& file)
{
	//проверяем, чтобы файл был открыт
	if (!file.is_open())
		return;

	//выводим в бинарный файл размер, а потом каждый элемент многочлена в формате: коэффициент и степень
	file.write((char*)&_size, sizeof(int));
	for (int i = 0; i < _size; i++)
	{
		file.write((char*)&_coefficients[i], sizeof(double));
		file.write((char*)&_degrees[i], sizeof(int));
	}
}

//чтение из бинарного файла
void DegreesPolynom::read(fstream& file)
{
	//проверяем, чтобы файл бал открыт
	if (!file.is_open())
		return;

	int size;
	double* coeff;
	int* degrees;
	
	//считываем размер
	file.read((char*)&size, sizeof(int));

	if (size <= 0)
		throw exception("bad size");

	//считываем элементы в формате: коэффициент и степень
	coeff = new double[size];
	degrees = new int[size];
	for (int i = 0; i < size; i++)
	{
		file.read((char*)&coeff[i], sizeof(double));
		file.read((char*)&degrees[i], sizeof(int));
	}

	//устанавливаем считанные значения
	setDegrees(size, degrees, coeff);
}



//оператор сравнения "равно"
bool DegreesPolynom::operator==(const DegreesPolynom& polynom)
{
	//если размеры не совпадают
	if (_size != polynom._size)
		return false;

	//если не совпадают коэффициенты или степени
	for (int i = 0; i < _size; i++)
		if ((_degrees[i] != polynom._degrees[i]) || (_coefficients[i] != polynom._coefficients[i]))
			return false;

	return true;
}

//функция вывода на экран - нужна для демонстрации полиморфизма
void DegreesPolynom::show()
{
	cout << "CLASS : DegreesPolynom" << endl;
	cout << (*this) << endl;
}
