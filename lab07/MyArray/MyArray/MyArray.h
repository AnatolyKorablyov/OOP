#pragma once

#include <new>
#include <algorithm>
#include <stdexcept>

template <typename T>
class CMyArray
{
public:
	CMyArray() = default;
	CMyArray(size_t size)
	{
		if (size > 0)
		{
			m_size = size;
			m_array = std::make_unique<T[]>(m_size);
			for (size_t i = m_size; i < size; ++i)
			{
				m_array[i] = T();
			}
		}
		else
		{
			throw std::out_of_range("negative_size");
		}
	}
	CMyArray(size_t size, const T & value)
	{
		if (size > 0)
		{
			m_size = size;
			m_array = std::make_unique<T[]>(m_size);
			for (size_t i = m_size; i < size; ++i)
			{
				m_array[i] = value;
			}
		}
		else
		{
			throw std::out_of_range("negative_size");
		}
	}
	CMyArray(const CMyArray& arr)
	{
		m_size = arr.GetSize();
		m_array(m_size);
		memcpy(m_array.get(), arr.m_array.get(), m_size * sizeof(m_size));
	}
	CMyArray<T>::CMyArray(CMyArray<T> && arr) :
		m_size(arr.m_size)
	{
		m_array.swap(arr.m_array);
	}
	CMyArray<T>::CMyArray(std::initializer_list<T> values) :
		m_size(values.size()),
		m_array(std::make_unique<T[]>(m_size))
	{
		size_t i = 0;
		for (auto it : values)
		{
			m_array[i] = it;
			++i;
		}
	}
	size_t GetSize()const
	{
		return m_size;
	}
	void CMyArray<T>::PushBack(const T & item)
	{
		++m_size;
		std::unique_ptr<T[]> buffer;
		m_array.swap(buffer);
		m_array = std::make_unique<T[]>(m_size);
		memcpy(m_array.get(), buffer.get(), (m_size - 1) * sizeof(T));
		m_array[m_size - 1] = item;
	}

	void CMyArray<T>::Clear()
	{
		m_size = 0;
		m_array.reset();
	}
	void CMyArray<T>::Resize(size_t size, T item)
	{
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
	T & CMyArray<T>::operator[](size_t index)
	{
		if (index < 0 || index >= m_size)
		{
			throw std::out_of_range("incorrect index");
		}
		return m_array[index];
	}

	T & CMyArray<T>::operator=(const CMyArray & arr)
	{
		m_size = arr.GetSize();
		memcpy(m_array.get(), arr.m_array.get(), m_size * sizeof(m_size));
	}

private:
	size_t m_size = 0;
	std::unique_ptr<T[]> m_array;
};