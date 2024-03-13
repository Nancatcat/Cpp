#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>


using namespace std;

template<class K>

struct BinarySearTree
{
    typedef BinarySearTree<K> Node;

    Node* _left;
    Node* _right;
    K _key;


    BinarySearTree(const K& key)
        :_left(nullptr)
        , _right(nullptr)
        , _key(key)
    {

    }
};


template<class K>
//class BinarySearTree  

class BSTree
{
    typedef BinarySearTree<K> Node;
public:
    bool Insert(const K& key)
    {
        if (_root == nullptr)
        {
            _root = new Node(key);
            return true;
        }
        Node* parent = nullptr;
        Node* cur = _root;
        while (cur)
        {
            if (cur->_key > key)
            {
                parent = cur;
                cur = cur->_left;
            }
            else if (cur->_key < key)
            {
                parent = cur;
                cur = cur->_right;
            }
            else
            {
                return false;
            }
        }

        cur = new Node(key);
        if (parent->_key > key)
        {
            parent->_left = cur;
        }
        else
        {
            parent->_right = cur;
        }

        return true;

    }
    bool Erase(const K& key)
    {
        Node* parent = nullptr;
        Node* cur = _root;
        while (cur)
        {
            if (cur->_key < key)
            {
                parent = cur;
                cur = cur->_right;
            }
            else if (cur->_key > key)
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                if (cur->_left == nullptr)
                {
                    if (cur == _root)
                    {
                        _root = cur->_right;
                    }
                    else
                    {
                        if (cur == parent->_right)
                        {
                            parent->_right = cur->_right;
                        }
                        else
                        {
                            parent->_left = cur->_right;
                        }
                        
                    }
                    delete cur;
                    return true;
                }
                else if (cur->_right == nullptr)
                {
                    if (cur == _root)
                    {
                        _root = cur->_left;
                    }
                    else
                    {
                        if (cur == parent->_left)
                        {
                            parent->_left = cur->_left;
                        }
                        else
                        {
                            parent->_right = cur->_left;
                        }
                    }
                    delete cur;
                    return true;
                }
                else
                {
                    Node* rightparentMin = cur;
                    Node* rightMin = cur->_right;
                    while (rightMin->_left)
                    {
                        rightparentMin = rightMin;
                        rightMin = rightMin->_left;
                    }
                    cur->_key = rightMin->_key;

                    if (rightMin == rightparentMin->_left)
                    {
                        rightparentMin->_left = rightMin->_right;
                    }
                    else
                    {
                        rightparentMin->_right = rightMin->_right;
                    }

                    delete rightMin;
                    return true;
                }
            }
        }
        return false;
    }
    bool Find(const K& key)
    {
        Node* cur = _root;

        while (cur)
        {
            if (cur->_key > key)
            {
                cur = cur->_left;
            }
            else if (cur->_key < key)
            {
                cur = cur->_right;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
    void InOrder()
    {
        _InOrder(_root);
        cout << endl;
    }


    // digunbanben

    bool InsertR(const K& key)
    {
        _InsertR(_root, key);
    }

    bool _FindR(const K& key)
    {
        _FindR(_root, key);
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
private:
    void _InsertR(Node*& root, const K& key)
    {
        if (root == nullptr)
        {
            root = new Node(key);
            return true;
        }
        if (root->_left < key)
        {
            _InsertR(root->_right, key);
        }
        else if (root->_left > key)
        {
            _InsertR(root->_left, key);
        }
        else
        {
            return false;
        }
    }
    void _FindR(Node* root, const K& key)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (root->_key < key)
        {
            _FindR(root, key);
        }
        else if (root->_key > key)
        {
            _FindR(root, key);
        }
        else
        {
            return true;
        }
    }
    void _EraseR(Node*& root, const K& key)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (root->_key < key)
        {
            _EraseR(root->_right, key);
        }
        else if (root->_key > key)
        {
            _EraseR(root->_left, key);
        }
        else
        {
            Node* del = root;
            if (root->_left == nullptr)
            {
                root = root->_right;
            }
            else if (root->_right == nullptr)
            {
                root = root->_left;
            }
            else
            {
                Node* rightMin = root->_right;
                while (rightMin->_left)
                {
                    rightMin = rightMin->_left;
                }

                swap(root->_key, rightMin->_key);
                return _EraseR(root->_right, key);

            }
            delete del;
            return true;
        }
    }
    void _InOrder(Node* root)
    {
        if (root == nullptr)
        {
            return;
        }
        _InOrder(root->_left);
        cout << root->_key << " ";
        _InOrder(root->_right);

    }
    Node* _root = nullptr;
};


