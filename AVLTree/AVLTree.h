#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

template<class key, class val>

struct AVLTreeNode
{
	AVLTreeNode<key, val>* _left;
	AVLTreeNode<key, val>* _right;
	AVLTreeNode<key, val>* _parent;
	int _bf;
	pari<key, val> _kv;

	AVLTreeNode(const pair<key, val>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
		, _kv(kv)
	{}
};

template<class key, class val>
class AVLTree
{
	typedef AVLTreeNode<key, val> Node;
	bool Insert(const pair<key, val>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->kv.first < kv.first)
			{
				parern = cur;
				cur = cur->_right;
			}
			else if (cur->kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}

		}
		cur = new Node(kv);
		if (parent->kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;
		while (parent)
		{
			if (cur == parent->left)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}
			if (parent->_bf == 0)
				break;

			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);
				}
				else
				{
					RotateRL(parent);
				}
				break;
			}
			else
			{
				assert("AVLTree.Insert(false)");
			}
		}

		return true;
	}
	void RotateL(Node* parent)
	{
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;

		parent->_right = SubRL;
		if (SubRL)
			SubRL->_parent = parent;
		SubR->_left = parent;
		Node* pparent = parent->_parent;
		parent->_parent = SubR;

		if (parent == _root)
		{
			_root = SubL;
			SubL->_parent = nullptr;
		}
		else 
		{
			if (pparent->_left == parent)
				pparent->_left = SubR;
			else
				pparent->_right = SubR;
			SubR->_parent = pparent;		
		}
		parent->_bf = 0;
		SubR->_bf = 0;

	}
	void RotateR(Node* parent)
	{
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;

		parent->_left = SubLR;
		if (SubLR)
			SubLR->_parent = parent;
		SubL->_right = parent;
		Node* pparent = parent->_parent;
		parent->_parent = SubL;
		if (parent == _root)
		{
			_root = SubL;
			SubL->_parent = nullptr;
		}
		else
		{
			if (pparent->_left == parent)
				pparent->_left = SubR;
			else
				pparent->_right = SubR;
			SubR->_parent = pparent;
		}
		parent->_bf = 0;
		SubL->_bf = 0;
	}
	void RotateLR(Node* parent)
	{
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;
		int bf = SubL->_bf;
		RotateL(parent->_left);
		RotateR(parent);

		if (bf == -1)
		{
			subLR->_bf = 0;
			subL->_bf = 0;
			parent->_bf = 1;
		}
		else if (bf == 1)
		{
			subLR->_bf = 0;
			subL->_bf = -1;
			parent->_bf = 0;
		}
		else if (bf == 0)
		{
			subLR->_bf = 0;
			subL->_bf = 0;
			parent->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}
pubilc:
	Node* _root = nullptr;
};