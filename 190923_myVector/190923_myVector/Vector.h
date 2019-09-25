#pragma once

namespace Michael
{
	template<class T>
	class Vector
	{
	public:
		typedef T* Iterator;
		typedef const T* ConstIterator;

		Iterator Begin() { return _start; }
		Iterator End() { return _finish; }

		ConstIterator CBegin() const { return _start; }
		ConstIterator CEnd() const { return _finish; }

		size_t Size() { return _finish - _start; }
		size_t Capacity() const { return _endOfStorage - _start; }

		Vector() :
			_start(nullptr),
			_finish(nullptr),
			_endOfStorage(nullptr)
		{

		}

		Vector(int n, const T& value = T()):
			_start(nullptr),
			_finish(nullptr),
			_endOfStorage(nullptr)
		{
			int i;
			Reserve(n);
			while (n--)
			{
				Push_back(value);
			}
		}

		template<class InputIterator>
		Vector(InputIterator first, InputIterator last)
		{
			Reserve(last - first);
			while (first != last)
			{
				Push_back(*first);
				first++;
			}
		}

		Vector(const Vector& v):
			_start(nullptr),
			_finish(nullptr),
			_endOfStorage(nullptr)
		{
			Iterator it = Begin();
			ConstIterator vit = v.Begin();

			while (vit != v.End())
			{
				(*it)++ = (*vit)++;
			}

			_finish = _start + v.Size();
			_endOfStorage = _start + v.Capacity();
		}

		Vector<T>& operator = (Vector<T> v)
		{
			Swap(v);
			return *this;
		}

		~Vector()
		{
			delete[] _start;
			_start = _endOfStorage = _finish = nullptr;
		}

		void Reserve(size_t n)
		{
			if (n > Capacity())
			{
				size_t size = Size;

				T* tmp = new T[n];

				if (_start)
				{
					for (int i = 0; i < size; i++)
					{
						tmp[i] = _start[i];
					}
				}
				_start = tmp;
				_finish = _start + size();
				_endOfStorage = _start + n;
			}
		}

		void Resize(size_t n, const T& value = T())
		{
			if (n < Size())
			{
				_finish = _start + n;
				return;
			}
			if (n > Capacity())
			{
				Resize(n);
			}

			Iterator it = _start;
			Iterator _finish = _start + n;
			//////////////////////////
			while (it != _finish)
			{
				*it = value;
				it++;
			}
		}

		void Swap(Vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endOfStorage, v._endOfStorage);
		}

		void Push_back(const T& x)
		{
			Insert(End(), x);
		}

		void Pop_back()
		{
			Erase(--End());
		}

		Iterator Insert(Iterator pos, const T& x) 
		{
			assert(pos <= _finish);

			// 空间不够先进行增容            
			if (_finish == _endOfStorage)            
			{                
				size_t size = Size();       
				size_t newCapacity = Capacity() == 0 ? 1 : Capacity() * 2;
				Reserve(newCapacity);
				// 如果发生了增容，需要重置pos       
				pos = _start + size;          
			}

			Iterator end = _finish - 1;    
			while (end >= pos) 
			{ 
				*(end + 1) = *end;     
				--end;
			}

			*pos = x;   
			++_finish; 
			return pos;
		}

		Iterator Erase(Iterator pos)      
		{              
			Iterator begin = pos + 1;   
			while (begin != _finish) 
			{              
				*(begin - 1) = *begin;   
				++begin;     
			}

			--_finish;
			return pos;
		}

		T& operator[](size_t pos) 
		{
			return _start[pos]; 
		}

	private:
		Iterator _start;
		Iterator _finish;
		Iterator _endOfStorage;
	};








}