#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<string>
//解题思路 滑动窗口
//计算t字符串内的种类个数,创建哈希表映射关系
//创建哈希表2 循环内判断
// 进窗口 char in = s[right]; hash2[in]++; 如果if (hash2[in] == hash1[in]) count++; 代表映射相同,映射关系++
//判断 只有种类数相等才进行出窗口操作,所以先判断,如果相等, 判断最短长度 ,判断后++left,hash2映射关系--
//种类计数--,应为可能存在多个重复字符,所以判断条件为while循环
//返回结果
class Solution {
public:
    string minWindow(string s, string t)
    {
        int hash1[128] = { 0 };
        int begin = -1;
        int len = 0;
        for (auto ch : t)
        {
            if (hash1[ch]++ == 0) len++;
        }
        int ret = INT_MAX;
        int hash2[128] = { 0 };
        for (int left = 0, right = 0, count = 0; right < s.size(); right++)
        {
            char in = s[right];
            hash2[in]++;
            if (hash2[in] == hash1[in]) count++;
            while (count == len)
            {
                if (right - left + 1 < ret)
                {
                    ret = right - left + 1;
                    begin = left;
                }
                char out = s[left];
                left++;
                if (hash2[out]-- == hash1[out]) count--;

            }

        }
        if (begin == -1) return  "";
        else return s.substr(begin, ret);

    }
};
