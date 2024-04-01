#define  _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
class Solution {
public:
    struct kvCom
    {
        bool operator()(const pair<string, int>& key1, const pair<string, int>& key2) const
        {
            return key1.second > key2.second;//�º�������ж�����,����val�ж�(first,second)
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        map<string, int>countmap;//map��������
        for (auto& ch : words)
            countmap[ch]++;

        vector<pair<string, int>> ret(countmap.begin(), countmap.end());//ʹ��pair����
        stable_sort(ret.begin(), ret.end(), kvCom());//�ȶ�����,��֤���ݲ�����ֻ���(�ֵ���)

        vector<string> v;
        auto it = ret.begin();
        while (k--)
        {
            v.push_back(it->first);//����
            it++;
        }
        return v;
    }
};