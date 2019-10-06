#pragma once

namespace zdy {


template<class T>
class ListNode
{
	ListNode<T>* pPre;
	ListNode<T>* pNext;
	T m_val;

	ListNode(const T& val = T()):
		pPre(nullptr),
		pNext(nullptr),
		val(val)
	{

	}
};

template<class T>
class List
{
	ListNode<T>* m_head;

	void createHead()
	{
		m_head = new ListNode<T>;
		m_head->pNext = m_head->pPre = m_head;
	}

public:

	class iterator
	{
	public:
		ListNode<T>* m_pos;

		iterator(ListNode<T>* val = nullptr):
			m_pos(val)
		{

		}

		T& operator * () const
		{
			return m_pos->m_val;
		}

		T* operator -> () const
		{
			return &m_pos->m_val;
		}

		iterator operator ++ ()
		{
			m_pos = m_pos->pNext;
			return *this;
		}

		iterator operator ++ (int)
		{
			iterater tmp = *this;
			m_pos = m_pos->pNext;
			return tmp;
		}

		iterator operator -- ()
		{
			m_pos = m_pos->pPre;
			return *this;
		}

		iterator operator -- (int)
		{
			iterator tmp = *this;
			m_pos = m_pos->pPre;
			return tmp;
		}

		bool operator == (const iterator& i) const
		{
			return m_pos == i.m_pos;
		}

		bool operator != (const iterator& i) const
		{
			return m_pos != i.m_pos;
		}
	};

	list(T * start, T * finish)
	{
		createHead();

		insert(end(), start, finish);
	}

	iterator insert(iterator pos, const T& val)
	{
		ListNode<T>* cur = new ListNode<T>;
		ListNode<T>* nPos = pos.m_pos;

		cur->m_val = val;

		cur->pPre = nPos->pPre;
		nPos->pPre->pNext = cur;
		cur->pNext = nPos;
		nPos->pPre = cur;

		return cur;
	}

	iterator insert(iterator pos, T* start, T* finish)
	{
		T* tmp = start;

		while (tmp != finish)
		{
			pos = insert(pos, *start);
			tmp++;
		}
		return pos;
	}
	iterator insert(iterator pos, iterator start, iterator end)
	{
		//TODO
	}
	iterator end()
	{
		return m_head;
	}

};





}