#define  _CRT_SECURE_NO_WARNINGS
#pragma once

#include<assert.h>



namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char [_capacity + 1];


			strcpy(_str, str);
		}
		
		~string()
		{
			delete[]_str;
			_capacity = _size = 0;
			_str = nullptr;
		}

		const char* c_str() const
		{
			return _str;
		}

		size_t size() const
		{
			return _size;
		}

		char& operator[](size_t pos)
		{
			assert(pos <= _size);
			return _str[pos];
		}
		const char& operator[](size_t pos) const
		{
			assert(pos <= _size);
			return _str[pos];
		}
	private:
		size_t _size;
		char* _str;
		size_t _capacity;
	 	//const static const size_t npos;
	};
	const size_t bit::npos = -1;
}