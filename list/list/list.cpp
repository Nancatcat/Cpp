#define _CRT_SECURE_NO_WARNINGS
#include"list.h"

//namespace bit
//{
//	template <class T>
//	void list<T>:: push_back(const T& tmp)//尾插
//	{
//		Node* NewNode = new Node(x);//开辟新节点并赋值
//		Node* tail = _head->prev;//保存尾节点
//
//		tail->next = NewNode;//尾节点链接新节点
//		NewNode->prev = tail;//新节点的尾节点链接尾节点
//		NewNode->next = _head;//链接哨兵位
//		_head->prev = NewNode;//相同
//	}
//}
// 