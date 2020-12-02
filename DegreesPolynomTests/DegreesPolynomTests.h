
#include "../DegreesPolynom/DegreesPolynom.h"

class DegreesPolynomTests
{
public:

	//тестирование конструктора по умолчанию
	void defaultConstructor();

	//тестирование конструктора с параметрами
	void parametrConstructor();

	//тестирование конструктора копирования
	void copyConstructor();

	//тестирование оператора присваивания
	void assignmentOperator();



	//тест метода изменения степеней
	void setDegrees();

	//тест метода изменения коэффициентов
	void setCoefficients();



	//тест оператора ()
	void functionOperator();



	//тест оператора сложения
	void sumOperator();

	//тест оператора вычитания
	void subOperator();



	//тест операторов ввода-вывода для текстовых файлов
	void fileOperators();

	//тест операторов ввода-вывода для бинарных файлов
	void binaryOperators();

};