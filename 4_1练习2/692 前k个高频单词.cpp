#define  _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
class Solution {
public:
    struct kvCom
    {
        bool operator()(const pair<string, int>& key1, const pair<string, int>& key2) const
        {
            return key1.second > key2.second;//仿函数求改判断条件,按照val判断(first,second)
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        map<string, int>countmap;//map插入数据
        for (auto& ch : words)
            countmap[ch]++;

        vector<pair<string, int>> ret(countmap.begin(), countmap.end());//使用pair插入
        stable_sort(ret.begin(), ret.end(), kvCom());//稳定排序,保证数据不会出现混乱(字典序)

        vector<string> v;
        auto it = ret.begin();
        while (k--)
        {
            v.push_back(it->first);//插入
            it++;
        }
        return v;
    }
};