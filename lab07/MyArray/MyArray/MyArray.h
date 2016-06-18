#pragma once
#include <new>
#include <algorithm>
#include <stdexcept>

////
////template <typename T>
////class CMyIterator : public std::iterator<std::input_iterator_tag, T>
////{
////	friend class CMyArray;
////private:
////	CMyIterator(T* p)
////		:p(p)
////	{}
////public:
////	CMyIterator(const CMyIterator &it)
////		:p(it.p)
////	{}
////
////	T & GetData()
////	{
////		return *p;
////	}
////	const T & GetData() const
////	{
////		return *p;
////	}
////	bool operator!=(CMyIterator const& other) const
////	{
////		return p != other.p;
////	}
////	bool operator==(CMyIterator const& other) const
////	{
////		return p == other.p;
////	}
////
////	typename CMyIterator::reference operator*() const
////	{
////		return *p;
////	}
////	CMyIterator& operator++()
////	{
////		++p;
////		return *this;
////	}
////
////private:
////	T* p;
////};


template <typename T>
class CMyArray
{
public:/*
	typedef CMyIterator<int> myIterator;
	typedef CMyIterator<const int> const_myIterator;

	myIterator::iterator begin()
	{
		return iterator(m_array.get());
	}
	myIterator::iterator end()
	{
		return iterator(m_array.get() + m_size_it);
	}

	myIterator::const_iterator begin() const
	{
		return const_iterator(m_array.get());
	}

	myIterator::const_iterator end() const
	{
		return const_iterator(m_array.get() + m_size_it);
	}*/

	CMyArray() = default;
	CMyArray(CMyArray<T> && arr) :
		m_size(arr.m_size)
	{
		m_array.swap(arr.m_array);
	}
	CMyArray(const CMyArray<T> & arr) :
		m_size(arr.m_size),
		m_array(std::make_unique<T[]>(arr.m_size))
	{
		auto pSrcBegin = arr.m_array.get();
		std::copy(pSrcBegin, pSrcBegin + arr.m_size, m_array.begin());
	}

	CMyArray(std::initializer_list<T> values) :
		m_size(values.size()),
		m_array(std::make_unique<T[]>(m_size))
	{
		// TODO: std::copy
		size_t i = 0;
		for (auto it : values)
		{
			m_array[i] = it;
			++i;
		}
	}
	CMyArray(size_t size)
	{
		Resize(size);
	}
	CMyArray(size_t size, T item)
	{
		Resize(size, item);
	}

	size_t GetSize()const
	{
		return m_size;
	}

	// TODO: add basic exception safety
	// TODO: call copy constructor for elements
	void Append(const T & item)
	{
		++m_size;
		std::unique_ptr<T[]> buffer;
		m_array.swap(buffer);
		m_array = std::make_unique<T[]>(m_size);
		memcpy(m_array.get(), buffer.get(), (m_size - 1) * sizeof(T));
		m_array[m_size - 1] = item;
	}

	void Clear()
	{
		m_size = 0;
		m_array.reset();
	}

	// TODO: add basic exception safety
	// TODO: call copy constructor for elements
	void Resize(size_t size)
	{
		// TODO: unsigned type no need "x < 0" check
		if (size < 0)
		{
			throw std::out_of_range("size_not_in_range");
		}
		if (m_size > size)
		{
			m_size = size;
			return;
		}
		std::unique_ptr<T[]> buffer;
		m_array.swap(buffer);
		m_array = std::make_unique<T[]>(size);
		memcpy(m_array.get(), buffer.get(), (m_size) * sizeof(T));
		for (size_t i = m_size; i < size; ++i)
		{
			m_array[i] = T();
		}
		m_size = size;
	}
	// TODO: reduce code duplication using `T item = T()`
	void Resize(size_t size, T item)
	{
		if (size < 0)
		{
			throw std::out_of_range("size_not_in_range");
		}
		if (m_size > size)
		{
			m_size = size;
			return;
		}
		std::unique_ptr<T[]> buffer;
		m_array.swap(buffer);
		m_array = std::make_unique<T[]>(size);
		memcpy(m_array.get(), buffer.get(), (m_size) * sizeof(T));
		for (size_t i = m_size; i < size; ++i)
		{
			m_array[i] = item;
		}
		m_size = size;
	}
	T & operator[](size_t index)
	{
		// TODO: index cannot be less than 0
		if (index < 0 || index >= m_size)
		{
			throw std::out_of_range("index_not_in_range");
		}
		return m_array[index];
	}

	// TODO: call copy ctor on elements
	CMyArray<T> & operator=(const CMyArray<T> & arr)
	{	
		Clear();
		Resize(arr.GetSize());
		memcpy(m_array.get(), arr.m_array.get(), m_size * sizeof(m_size));
		return *this;
	}
	// TODO: use std::copy if possible
	CMyArray<T> & operator=(std::initializer_list<T> values)
	{
		Clear();
		Resize(values.size());
		size_t i = 0;
		for (auto it : values)
		{
			m_array[i] = it;
			++i;
		}
		return *this;
	}


private:
	size_t m_size = 0;
	const size_t m_size_it = 0;
	std::unique_ptr<T[]> m_array;
};