#pragma once

#include <new>
#include <algorithm>
#include <stdexcept>
#include <memory.h>

template <typename T>
class CMyIterator : public std::iterator<std::input_iterator_tag, T>
{
	friend class CMyArray;
private:
	CMyIterator(T* p)
		:p(p)
	{}
public:
	CMyIterator(const CMyIterator &it)
		:p(it.p)
	{}

	T & GetData()
	{
		return *p;
	}
	const T & GetData() const
	{
		return *p;
	}
	bool operator!=(CMyIterator const& other) const
	{
		return p != other.p;
	}
	bool operator==(CMyIterator const& other) const
	{
		return p == other.p;
	}

	typename CMyIterator::reference operator*() const
	{
		return *p;
	}
	CMyIterator& operator++()
	{
		++p;
		return *this;
	}

private:
	T* p;
};

template <typename T>
class CMyArray
{
public:
	typedef CMyIterator<T> iterator;
	typedef CMyIterator<const T> const_iterator;

	CMyArray(std::initializer_list<T> values)
		: m_size(values.size())
		, m_array(new int(m_size()))
	{
		std::copy(values.begin(), values.end(), m_array.get());
	}

	CMyIterator::iterator begin()
	{
		return iterator(m_array.get());
	}
	CMyIterator::iterator end()
	{
		return iterator(m_array.get() + m_size);
	}

	CMyIterator::const_iterator begin() const
	{
		return const_iterator(m_array.get());
	}

	CMyIterator::const_iterator end() const
	{
		return const_iterator(m_array.get() + m_size);
	}
private:
	const size_t m_size;
	std::unique_ptr<T[]> m_array;
};