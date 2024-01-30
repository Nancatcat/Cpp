#pragma once
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
namespace bit 
{
	template<class T>
	class less
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};

}
namespace bit
{
	template<class T>
	class greater
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};

}
namespace bit
{
	template<class T, class Container = vector<T>, class Compare = less<T>>
	class priority_queue
	{

	public:

		void push(T& tmp)
		{
			return _com.push.back(tmp);
		}
		void pop()
		{
			return _com.pop();
		}

		const T& top()
		{
			return _com.top();
		}

		size_t size()
		{
			return _com.size();
		}

		bool empty()
		{
			return _com.empty();
		}
	private:
		Container _com

	};
}