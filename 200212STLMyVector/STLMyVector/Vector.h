#pragma once
#include <assert.h>

namespace dongyu
{
template <class T>
class Vector
{
private:
	T* start;
	T* finish;
	T* endofstorage;
	void Expand()
	{
		if (size() == capacity())
		{
			reserve(capacity() * 2 + 3);
		}
	}
public:
	typedef T* iterator;
	typedef const T* const_iterator;

	// �޲ι���
	Vector()
		:start(nullptr)
		,finish(nullptr)
		,endofstorage(nullptr)
	{

	}

	// ����n��val
	Vector(size_t n, const T& data = T())
	{
		start = new T[n];
		finish = start + n;
		endofstorage = finish;

		for (size_t i = 0; i < n; i++)
		{
			start[i] = data;
		}
	}

	// ��������
	Vector(const Vector<T>& v)
	{
		size_t n = v.size();
		start = new T[n];
		finish = start + n;
		endofstorage = finish;

		for (size_t i = 0; i < n; i++)
		{
			start[i] = v.start[i];
		}
	}

	 // ��������(������)
	 // ���ʹ��iterator�����������ᵼ�³�ʼ���ĵ���������[first,last)ֻ����Vector�ĵ�����
	 // ��������������������������[first,last]���������������ĵ�����, ��������
	template<class Iterator>
	Vector(Iterator first, Iterator last)
	{
		// ��[first, last)������Ԫ�صĸ���
		Iterator it = first;
		size_t n = 0;
		//distance(first, last, n);
		while (it != last)
		{
			n++;
			++it;
		}

		start = new T[n];
		finish = start;
		while (first != last)
		{
			*finish = *(Iterator)first;
			++first;
			++finish;
		}

		endofstorage = finish;
	}


	//Vector(int* first, int* last)
	//{
	//	// ��[first, last)������Ԫ�صĸ���
	//	int* it = first;
	//	size_t n = 0;
	//	//distance(first, last, n);
	//	while (it != last)
	//	{
	//		n++;
	//		++it;
	//	}

	//	start = new T[n];
	//	finish = start;
	//	while (first != last)
	//	{
	//		*finish = *first;
	//		++first;
	//		++finish;
	//	}

	//	endofstorage = finish;
	//}

	// ��ֵ������
	// Vector<T>& operator= (Vector<T> v)

	// ��������
	~Vector()
	{
		// ע��Ҫ�ж�
		if (start) 
		{
			delete[] start;
			start = finish = endofstorage = nullptr;
		}
	}

	iterator begin()
	{
		return start;
	}

	iterator end()
	{
		return finish;
	}

	/***********************************************/
	// capacity
	size_t size() const
	{
		return finish - start;
	}

	size_t capacity() const
	{
		return endofstorage - start;
	}

	bool empty()
	{
		return finish == start;
	}

	void resize(size_t newSize, const T& data = T())
	{
		size_t oldSize = size();
		if (newSize <= oldSize)
		{
			finish = start + newSize;
		}
		else
		{
			if (newSize > capacity())
			{
				reserve(newSize);
			}

			for (size_t i = oldSize; i < newSize; i++)
			{
				start[i] = data;
			}
			finish = start + newSize;
		}
	}

	void reserve(size_t newCapacity)
	{
		size_t oldCapacity = capacity();
		if (newCapacity > oldCapacity)
		{
			// �����¿ռ�
			T* newStart = new T[newCapacity];
			// ������Ԫ��
			size_t n = size();
			if (start)
			{
				for (size_t i = 0; i < n; i++)
				{
					newStart[i] = start[i];
				}

				delete[] start;
			}
			start = newStart;
			finish = start + n;
			endofstorage = start + newCapacity;
		}
	}
	/****************************************************/
	// access
	T& operator[](size_t index)
	{
		return start[index];
	}

	const T& operator[](size_t index) const
	{
		return start[index];
	}

	T& front()
	{
		return start[0];
	}

	const T& front() const
	{
		return start[0];
	}

	T& back()
	{
		return *(finish - 1);
	}

	const T& back() const 
	{
		return *(finish - 1);
	}

	/*******************************************/
	// modify
	void push_back(const T& data)
	{
		Expand();
		*finish = data;
		finish++;
	}

	void pop_back()
	{
		if (size())
		{
			finish--;
		}
		else
		{
			assert(0);
		}
	}

	iterator insert(iterator pos, const T& data)
	{
		Expand();
		iterator it = end();
		finish++;
		while (it != pos)
		{
			*it = *(it - 1);
			it--;
		}
		*pos = data;
		return pos;
	}

	iterator erase(iterator pos)
	{
		iterator it = pos;
		while (it + 1 != finish)
		{
			*it = *(it + 1);
			it++;
		}
		finish--;
		return pos;
	}

	void clear()
	{
		finish = start;
	}

	void swap(Vector<T>& v)
	{
		// ���ﲻ��ݹ����, ��������
		swap(start, v.start);
		swap(finish, v.finish);
		swap(endofstorage, v.endofstorage);
	}
};
}

using namespace std;
template<class T>
void PrintVector(dongyu::Vector<T>& v)
{
	// begin end
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void TestVector1()
{
	dongyu::Vector<int> v1;
	dongyu::Vector<int> v2(10, 5);
	PrintVector(v2);

	dongyu::Vector<int> v3(v2);
	PrintVector(v3);
	cout << v3.size() << endl;
	cout << v3.capacity() << endl;

	int array[] = { 1, 2, 3, 4, 5 };
	dongyu::Vector<int> v4(array, array + sizeof(array) / sizeof(array[0]));
	PrintVector(v4);

}


