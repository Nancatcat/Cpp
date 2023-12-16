#include <iostream>
#include<string>
using namespace std;
#include"string.h"

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
		typedef const char* const_iterator;
		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const
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
		/*string(const string&s)
		{
		    _str = new char[s._capacity+1];
		    strcpy(_str,s.str);
		    _size = s._size;
		    _capacity = s._capacity;
		}*/
		string(const string&s)//ÏÖ´úÐ´·¨
		{
		    string tmp(s._str);
		    swap(tmp);
		}
		/*string& operator=(const string& s)
		{
            if(this!= &s)
            {
                char* tmp = new char[s._capacity+1];
                strcpy(tmp,s._str);
                delete[]_str;

                _str = tmp;
                _capacity = s._capacity;
                _size = s._size;
            }
            return *this;
		}*/
		string& operator=(string s)
		{
		    swap(s);
		    return *this;
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
		void reserve(size_t n)
		{
		    if(n>_capacity)
            {
                char *tmp = new char[n+1];
                strcpy(tmp,_str);
                delete[]_str;
                _str = tmp;
                _capacity = n;
            }
		}
		void push_back(char ch)
		{
		    if(_size==_capacity)
            {
               size_t newcapacity = _capacity == 0?4:_capacity*2;
               reserve(newcapacity);
            }
            _str[_size] = ch;
            _size++;
            _str[_size] = '\0';
		}
		void append(const char* str)
		{
		    size_t len = strlen(str);
		    if(_size+len>=_cpapcity)
            {
                reserve(_size+len);
            }
            strcpy(_str+_size,str);
            _size = _size+len;
		}
		string& operator+=(char ch)
		{
		    push_back(ch);
		    return *this;
		}
		string& operator+=(char* str)
		{
		    append(str);
		    return *this;
		}
		void insert(size_t pos,char ch)
		{
		    assert(pos<=_capacity);
		    if (_size==_capacity)
            {
                int newcapacity = _capacity==0?4:_capacity*2;
                reserve(newcapacity);
            }
            /*int end = _size;
            while(end>=(int)pos)
            {
                -str[end+1] = _str[end];
                --end;
            }*/
            size_t end = _size+1;
            while(end>pos)
            {
                _str[end] = _str[end-1];
                --end;
            }
            _str[pos] = ch;
            _size++;
		}
		void insert(size_t pos,const char* str)
		{
		    assert(pos<=_size);
		    size_t len = strlen(str);
		    if(_size+len>_capacity)
            {

                reserve(_size+len);
            }
            size_t end = _size+len;
            while(end>pos)
            {
                _str[end] = _str[end-len];
                --end;
            }
            strncpy(_str+pos,str,len);
            _size+=len;
		}
		void swap(string& s)
		{
		    std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}
		size_t find(char ch,size_t pos=0)
		{
		    for (int i = 0;i<_size;i++)
            {
                if(_str[i]==ch)
                {
                    return i;
                }
            }
            return npos;
		}
		size_t find(const char* str,size_t pos = 0)
		{
		    const char* ptr = strstr(_str+pos,str);
		    if(ptr == nullptr)
            {
                return npos;
            }
            else
            {
                return ptr-_str;
            }
		}
		string substr(size_t pos = 0,size_t len = npos)
		{

		}
		~string()
		{
			delete[]_str;
			_capacity = _size = 0;
			_str = nullptr;
		}
	private:
		size_t _size = 0;
		char* _str = nullptr;
		size_t _capacity = 0;
	 	const static size_t npos = -1;
	};
	//const size_t bit::npos = -1;
}
