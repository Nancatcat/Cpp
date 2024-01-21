#pragma once

namespace bit
{
	template <class T>
	struct ListNode
	{
		ListNode<T>* _next;
		ListNode<T>* _prev;
		T _data;

		ListNode(const T& tmp = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _data(tmp)
		{}

	};
	template <class T, class Ref,class Ptr>
	struct _list_iterator
	{
		typedef ListNode<T> Node;
		typedef _list_iterator<T , Ref, Ptr> self;
		Node* _node;

		_list_iterator(Node* node)
			:_node(node)
		{}

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		self& operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;
			return *this;
		}
		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		self& operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;
			return *this;
		}
		Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator->()
		{
			return &_node->_data;
		}
		bool operator!=(const self& s)
		{
			return _node != s._node;
		}
		bool operator==(const self& s)
		{
			return _node == s._node;
		}
	};
	template <class T>
	class list
	{
		typedef ListNode<T> Node;
		
	public:
		typedef _list_iterator<T,T&,T*> iterator;
		typedef _list_iterator<T,const T&,const T*> const_iterator;
		iterator begin()
		{
			return _head->_next;
		}
		iterator end()
		{
			return _head;
		}
		const_iterator begin()const
		{
			return _head->_next;
		}
		const_iterator end()const
		{
			return _head;
		}
		list()
		{
			emptyinit();
		}
		list(list<T>& it)
		{
	 		emptyinit();

			for (auto& ch : it)
			{
				push_back(ch);
			}
		}
		list<T>& operator=(list<T> it)
		{
			swap(it);
			return *this;
		}
		void swap(list<T>& tmp)
		{
			std::swap(_head, tmp._heap);

		}
		void emptyinit()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

		}
		void push_back(const T& tmp)
		{
			/*Node* newnode = new Node(tmp);
			Node* tail = _head->_prev;

			_head->_prev = newnode;
			newnode->_next = _head;
			newnode->_prev = tail;
			tail->_next = newnode;*/
			insert(end(), tmp);
		}
		void push_front(const T& tmp)
		{
			insert(begin(), tmp);
		}
		void pop_back(const T& tmp)
		{
			erase(--end());
		}
		void pop_front(const T& tmp)
		{
			erase(begin());
		}
		
		iterator insert(iterator pos, const T& tmp)
		{
			Node* cur = pos._node;
			Node* newnode = new Node(tmp);
			Node* prev = cur->_prev;

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			
			return newnode;
		}
		iterator erase(iterator pos)
		{
			assert(pos != end());
			Node* cur = pos._node;

			Node* prev = cur->_prev;
			Node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;

			delete cur;


			return next;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}
		~list()
		{
			clear();

			delete _head;
			_head = nullptr;
		}
		
	private:
		Node* _head;
	};
	void text1()
	{
		list<int> s1;
		s1.push_back(1);
		s1.push_back(2);
		s1.push_back(3);
		s1.push_back(4);
		s1.push_back(5);
		list<int>::iterator it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

	}
	void text2()
	{
		list<int> s1;
		s1.push_back(1);
		s1.push_back(2);
		s1.push_back(3);
		s1.push_back(4);
		s1.push_back(5);
		list<int>::iterator it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
	void text3()
	{
		list<int> s1;

		s1.push_back(1);
		s1.push_back(2);
		s1.push_back(3);
		s1.push_back(4);
		s1.push_back(5);
		list<int>::iterator it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
		s1.pop_back(5);
		s1.pop_front(1);
		 it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
	void print_list(const list<int>& s1)
	{
		
		list<int>::const_iterator it =  s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
		for (auto e : s1)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	
	
}