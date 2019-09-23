#include <iostream>
#include <cstdlib>

using namespace std;

template <class T> 
class SeqList
{
	T* m_data;
	size_t m_size;
	size_t m_capacity;

	void checkCapacity();

public:
	SeqList(size_t size = 0, size_t capacity = 10) :
		m_data(new T[capacity]),
		m_size(size),
		m_capacity(capacity)
	{
		
	}
	void push_back(const T &src);
	void pop_back();
	int size();
	~SeqList();
	T& const operator[](int i)
	{
		return m_data[i];
	}
};

template <class T>
void SeqList<T>::checkCapacity()
{
	if (m_size == m_capacity)
	{
		m_capacity *= 2;
		m_data = (T*)realloc(m_data, sizeof(T) * m_capacity);
	}
}

template <class T>
void SeqList<T>::push_back(const T &src)
{
	checkCapacity();

	m_data[m_size] = src;
	m_size++;
}

template <class T>
void SeqList<T>::pop_back()
{
	if (m_size > 0)
	{
		m_size--;
	}
}

template <class T>
int SeqList<T>::size()
{
	return m_size;
}

template <class T>
SeqList<T>::~SeqList()
{
	if (m_data)
	{
		delete[] m_data;
	}
	m_size = m_capacity = 0;
}


int main()
{
	SeqList<int> s1(5);


	for (int i = 0; i < s1.size(); i++)
	{
		s1[i] = i + 1;
	}
	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << endl;
	}

	system("pause");
	return 0;
}