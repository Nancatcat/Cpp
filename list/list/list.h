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
	//�����ڵ�
	struct ListNode
	{
		ListNode<T>* _next;
		ListNode<T>* _prev;
		T _data;
		
		ListNode(const T& tmp = T())
			:_next = (nullptr)
			, _prev = (nullptr)
			, _data = (tmp)
		{}//��ʼ��ͷ�ڵ�
	};
	template <class T>
	class list
	{
		typedef ListNode<T> Node;//�������ڵ�ṹ������
	private:
		Node* _head;//�����ڱ�λ
	public:
		list()//��ʼ���ڱ�λ
		{
			_head = new Node;
			_head->next = _head;
			_head->prev = _head;
		}
		void push_back(const T& tmp)//β��
		{
			Node* NewNode = new Node(x);//�����½ڵ㲢��ֵ
			Node* tail = _head->prev;//����β�ڵ�
			
			tail->next = NewNode;//β�ڵ������½ڵ�
			NewNode->prev = tail;//�½ڵ��β�ڵ�����β�ڵ�
			NewNode->next = _head;//�����ڱ�λ
			_head->prev = NewNode;//��ͬ
		}
	};

}