#define  _CRT_SECURE_NO_WARNINGS

//Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

#include<bits/stdc++.h>
class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        map<Node*, Node*>mp;
        Node* copyhead = nullptr, * copytail = nullptr;
        Node* cur = head;
        while (cur)
        {
            if (copyhead == nullptr)
                copyhead = copytail = new Node(cur->val);
            else
            {
                copytail->next = new Node(cur->val);
                copytail = copytail->next;
            }
            mp[cur] = copytail;
            cur = cur->next;
            cout << mp[cur] << endl;
        }
        cur = head;
        Node* copy = copyhead;
        while (cur)
        {
            if (cur->random == nullptr)
                copy->random = nullptr;
            else
                copy->random = mp[cur->random];
            cur = cur->next;
            copy = copy->next;

        }
        return copyhead;
    }
};