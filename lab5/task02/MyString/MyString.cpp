#include "stdafx.h"
#include "MyString.h"

CMyString::CMyString()
	: m_string(new char[1])
{
	m_string[0] = '\0';
}

CMyString::CMyString(const char * pString)
	: m_length(std::strlen(pString))
	, m_string(new char[m_length])
{
	memcpy(m_string, pString, m_length);
	m_string[m_length - 1] = '\0';
}

CMyString::CMyString(const char * pString, size_t length)
	: m_length(length)
	, m_string(new char[m_length])
{
	memcpy(m_string, pString, m_length);
}

CMyString::CMyString(CMyString const & other)
	: m_length(other.m_length)
	, m_string(new char[m_length])
{
	memcpy(m_string, other.m_string, m_length);
	m_string[m_length - 1] = '\0';
}

CMyString::CMyString(CMyString && other)
	: m_length(other.m_length)
	, m_string(other.m_string)
{
	other.m_string = nullptr;
	other.m_length = 0;
}


CMyString::CMyString(std::string const & stlString)
	: m_length(stlString.size())
	, m_string(new char[m_length])
{
	memcpy(m_string, stlString.c_str(), m_length);
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
