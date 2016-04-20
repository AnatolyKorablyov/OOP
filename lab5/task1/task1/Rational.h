#pragma once
#include <map>

class CRational
{
public:
	//  онструирует рациональное число, равное нулю (0/1)
	CRational();

	//  онструирует рациональное число, равное value (value/1)
	CRational(int value);

	//  онструирует рациональное число, равное numerator/denominator
	// –ациональное число должно хранитьс€ в нормализованном виде:
	//	знаменатель положительный (числитель может быть отрицательным)
	//	числитель и знаменатель не имеют общиз делителей (6/8 => 3/4 и т.п.)
	// ≈сли знаменатель равен нулю, должно сконструироватьс€ рациональное число, равное нулю
	CRational(int numerator, int denominator);

	// ¬озвращает числитель
	int GetNumerator() const;

	// ¬озвращает знаменатель (натуральное число)
	int GetDenominator() const;

	// ¬озвращает отношение числител€ и знаменател€ в виде числа double
	double ToDouble() const;

	CRational const operator-() const;
	CRational const operator+() const;

	// task 4 +=
	CRational & operator +=(const CRational & secNumber);
	// task 5 -=
	CRational & operator -=(const CRational & secNumber);

	// task 8 *=
	CRational & operator *=(const CRational & secNumber);
	// task 9 /=
	CRational & operator /=(const CRational & secNumber);

private:
	int m_numerator;
	int m_denominator;

	// Ќормализует рациональное число
	void Normalize();


};

unsigned GCD(unsigned a, unsigned b);

// task 2 binary +
CRational const operator +(const CRational & firstNumber, const CRational & secNumber);

// task 3 binary -
CRational const operator -(const CRational & firstNumber, const CRational & secNumber);

// task 6 *
CRational const operator *(const CRational & firstNumber, const CRational & secNumber);

// task 7 /
CRational const operator /(const CRational & firstNumber, const CRational & secNumber);

// task 10 == and !=
bool const operator ==(const CRational & firstNumber, const CRational & secNumber);
bool const operator !=(const CRational & firstNumber, const CRational & secNumber);

// task 11 <, <=, >, >=
bool const operator <(const CRational & firstNumber, const CRational & secNumber);
bool const operator <=(const CRational & firstNumber, const CRational & secNumber);
bool const operator >(const CRational & firstNumber, const CRational & secNumber);
bool const operator >=(const CRational & firstNumber, const CRational & secNumber);