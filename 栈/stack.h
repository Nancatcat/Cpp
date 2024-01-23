#pragma once
#include<iostream>
#include<vector>
#include<list>
#include<deque>

using namespace std;

namespace bit
{
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		void push(const T& tmp)
		{
			_con.push_back(tmp);
		}

		void pop()
		{
			_con.pop_back();
		}
		
		const T& top()
		{
			return _con.back();
		}

		bool empry()
		{
			return _con.empty();
		}


		size_t size()
		{
			return _con.size();
		}
	private:

		Container _con;
	};
}
