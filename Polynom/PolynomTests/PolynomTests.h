#pragma once

#include "../Polynom.h"

/*Лабораторная работа 1*/

//тестирование для getter'ов не сделано, т.к. там примитивный код

//тест для конструктора по умолчанию
void defaultConstructorTest();

//тест для конструктора с параметрами
void parametrConstructorTest();

//тест для конструктора копирования
void copyConstructorTest();

//тест для сеттера степени
void setDegreeTest();

//тест для сеттера коэффициентов
void setCoefficientsTest();

//тест для сеттера одного коэффициента
void setCoefficientTest();

//тест для метода вычисления многочлена
void computeTest();

/*Лабораторная работа 2*/

//тест оператора +
void addOperatorTest();

//тест оператора -
void subOperatorTest();

//тест оператора ++ (префикс)
void prefixIncrementOperatorTest();

//тест оператора ++ (постфикс)
void postfixIncrementOperatorTest();

//тест оператора -- (префикс)
void prefixDecrementOperatorTest();

//тест оператора -- (постфикс)
void postfixDecrementOperatorTest();

//тест оператора ()
void functionOperatorTest();

//тест оператора []
void indexOperatorTest();

//тест оператора =
void assignmentOperatorTest();

/*Лабораторная работа 3*/

//тест ввода-вывода в бинарный файл
void binaryInputOutputTest();

//тест ввода-вывода в текстовый файл
void fileInputOutputTest();