#include "stdafx.h"
#include "MyString.h"

CMyString::CMyString()
	: m_string(new char[1])
{
	m_string[0] = '\0';
}

CMyString::CMyString(const char * pString)
	: m_length(std::strlen(pString) + 1)
	, m_string(new char[m_length])
{
	memcpy(m_string, pString, m_length);
	m_string[m_length - 1] = '\0';
	--m_length;
}

CMyString::CMyString(const char * pString, size_t length)
	: m_length(length + 1)
	, m_string(new char[m_length])
{
	memcpy(m_string, pString, m_length);
	m_string[m_length - 1] = '\0';
	--m_length;
}

CMyString::CMyString(CMyString const & other)
	: m_length(other.m_length + 1)
	, m_string(new char[m_length])
{
	memcpy(m_string, other.m_string, m_length);
	m_string[m_length - 1] = '\0';
	--m_length;
}

CMyString::CMyString(CMyString && other)
	: m_length(other.m_length)
	, m_string(other.m_string)
{
	other.m_string = nullptr;
	other.m_length = 0;
}


CMyString::CMyString(std::string const & stlString)
	: m_length(stlString.size() + 1)
	, m_string(new char[m_length])
{
	memcpy(m_string, stlString.c_str(), m_length);
	m_string[m_length - 1] = '\0';
	--m_length;
}

CMyString::~CMyString()
{
	delete[] m_string;
	m_string = nullptr;
}

size_t CMyString::GetLength() const
{
	return m_length;
}

const char * CMyString::GetStringData() const
{
	return m_string;
}

CMyString const CMyString::SubString(size_t start, size_t length) const
{
	if (start < m_length && length < m_length && m_length > 0 && start < length)
	{
		return CMyString(&m_string[start], length);
	}
	return nullptr;
}

void CMyString::Clear()
{
	delete[] m_string;
	m_string = new char[1];
	m_string[0] = '\0';
	m_length = 0;
}

CMyString & CMyString::operator=(const CMyString & str)
{
	Clear();
	m_length = str.GetLength() + 1;
	m_string = new char[m_length + 1];
	memcpy(m_string, str.m_string, m_length);
	m_string[m_length - 1] = '\0';
	--m_length;
	return *this;
}

CMyString & CMyString::operator+=(const CMyString & str)
{
	*this = *this + str;
	return *this;
}

const char & CMyString::operator[](size_t index) const
{
	char empty = '\0';
	return (index >= 0 && index < m_length) ? m_string[index] : empty;
}

CMyString operator+(CMyString const & str1, CMyString const & str2)
{
	char * localStr;
	localStr = new char[str1.GetLength() + str2.GetLength() + 1];
	for (size_t i = 0; i < str1.GetLength(); i++)
	{
		localStr[i] = str1[i];
	}
	for (size_t i = str1.GetLength(), j = 0;
		i <= str1.GetLength() + str2.GetLength(); ++i, ++j)
	{
		localStr[i] = str2[j];
	}
	return CMyString(localStr);
}

CMyString operator+(std::string const & str1, CMyString const & str2)
{
	char * localStr;
	localStr = new char[str1.length() + str2.GetLength() + 2];
	for (size_t i = 0; i < str1.length(); ++i)
	{
		localStr[i] = str1[i];
	}
	for (size_t i = str1.length(), j = 0;
		i <= str1.length() + str2.GetLength(); ++i, ++j)
	{
		localStr[i] = str2[j];
	}
	return CMyString(localStr);
}

CMyString operator+(const char * str1, CMyString const & str2)
{
	return (CMyString(str1) + str2);
}

bool operator==(const CMyString & str1, const CMyString & str2)
{
	return !(str1 != str2);
}

bool operator!=(const CMyString & str1, const CMyString & str2)
{
	if (str1.GetLength() == str2.GetLength())
	{
		return false;
	}
	return (memcmp(str1.GetStringData()
		, str2.GetStringData()
		, static_cast<size_t>(fmaxl(str1.GetLength(), str2.GetLength()))));
}

bool operator<(const CMyString & str1, const CMyString & str2)
{
	if (str1.GetLength() > str2.GetLength())
	{
		return false;
	}
	return (memcmp(str1.GetStringData()
		, str2.GetStringData()
		, static_cast<size_t>(fmaxl(str1.GetLength(), str2.GetLength()))) == -1);
}

bool operator>(const CMyString & str1, const CMyString & str2)
{
	if (str1.GetLength() < str2.GetLength())
	{
		return false;
	}
	return (memcmp(str1.GetStringData()
		, str2.GetStringData()
		, static_cast<size_t>(fmaxl(str1.GetLength(), str2.GetLength()))) == 1);
}

bool operator<=(const CMyString & str1, const CMyString & str2)
{
	return ((str1 == str2) || (str1 < str2));
}

bool operator>=(const CMyString & str1, const CMyString & str2)
{
	return ((str1 == str2) || (str1 > str2));
}

std::ostream & operator<<(std::ostream & strm, CMyString const & string)
{
	strm << string.GetStringData();
	return strm;
}

std::istream & operator >> (std::istream & strm, CMyString & string)
{
	char tmp[2048];
	strm.getline(tmp, sizeof(tmp));
	string = CMyString(tmp);
	return strm;
}
