#pragma once
#include "stdafx.h"

class CMyString
{
public:
	// конструктор по умолчанию
	CMyString();

	// конструктор, инициализирующий строку данными строки
	// с завершающим нулевым символом
	CMyString(const char * pString);

	// конструктор, инициализирующий строку данными из 
	// символьного массива заданной длины
	CMyString(const char * pString, size_t length);

	// конструктор копирования
	CMyString(CMyString const& other);

	// перемещающий конструктор (для компиляторов, совместимых с C++11)
	//  реализуется совместно с перемещающим оператором присваивания 
	CMyString(CMyString && other);

	// конструктор, инициализирующий строку данными из 
	// строки стандартной библиотеки C++
	CMyString(std::string const& stlString);

	// деструктор класса - освобождает память, занимаемую символами строки
	~CMyString();

	// возвращает длину строки (без учета завершающего нулевого символа)
	size_t GetLength()const;

	// возвращает указатель на массив символов строки.
	// В конце массива обязательно должен быть завершающий нулевой символ
	// даже если строка пустая 
	const char* GetStringData()const;

	// возвращает подстроку с заданной позиции длиной не больше length символов
	CMyString const SubString(size_t start, size_t length = SIZE_MAX)const;

	// очистка строки (строка становится снова нулевой длины)
	void Clear();

	// operators
	CMyString & operator =(const CMyString & str);
	CMyString & operator +=(const CMyString & str);
	const char & operator[](size_t index) const;
private:
	size_t m_length = 0;
	char* m_string;
};

CMyString operator +(CMyString const &str1, CMyString const &str2);
CMyString operator +(std::string const &str1, CMyString const &str2);
CMyString operator +(const char* str1, CMyString const &str2);

bool operator ==(const CMyString &str1, const CMyString &str2);
bool operator !=(const CMyString &str1, const CMyString &str2);
bool operator <(const CMyString &str1, const CMyString &str2);
bool operator >(const CMyString &str1, const CMyString &str2);
bool operator <=(const CMyString &str1, const CMyString &str2);
bool operator >=(const CMyString &str1, const CMyString &str2);

std::ostream & operator <<(std::ostream & strm, CMyString const & string);
std::istream & operator >> (std::istream & strm, CMyString & string);