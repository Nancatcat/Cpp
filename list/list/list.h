#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<vector>
#include<list>
#include<stdio.h>
using namespace std;

namespace bit
{
	template <class T>
	//创建节点
	struct ListNode
	{
		ListNode<T>* _next;
		ListNode<T>* _prev;
		T _data;
		
		ListNode(const T& tmp = T())
			:_next = (nullptr)
			, _prev = (nullptr)
			, _data = (tmp)
		{}//初始化头节点
	};
	template <class T>
	class list
	{
		typedef ListNode<T> Node;//重命名节点结构体名字
	private:
		Node* _head;//创捷哨兵位
	public:
		list()//初始化哨兵位
		{
			_head = new Node;
			_head->next = _head;
			_head->prev = _head;
		}
		void push_back(const T& tmp)//尾插
		{
			Node* NewNode = new Node(x);//开辟新节点并赋值
			Node* tail = _head->prev;//保存尾节点
			
			tail->next = NewNode;//尾节点链接新节点
			NewNode->prev = tail;//新节点的尾节点链接尾节点
			NewNode->next = _head;//链接哨兵位
			_head->prev = NewNode;//相同
		}
	};

}