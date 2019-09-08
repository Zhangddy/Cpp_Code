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
	SeqList(size_t capacity = 10) :
		m_data(new T[capacity]),
		m_size(0),
		m_capacity(capacity)
	{

	}
	void push_back(const T &src);
	void pop_back();
	int size();
	~SeqList();
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
	SeqList<int> s1;
	s1.push_back(3);
	s1.push_back(2);
	s1.push_back(1);
	s1.push_back(5);
	s1.pop_back();

	cout << s1.size() << endl;
	system("pause");
	return 0;
}