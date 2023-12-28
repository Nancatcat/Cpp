#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

//解题思路
//滑动窗口思想,利用哈希表的原理创建投射数组,数组内元素大于1代表重复,
//进行清零操作继续遍历即可,直至找到最大len
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int hash[128] = { 0 };
        int n = s.size();
        int left = 0, right = 0;
        int len = 0;
        while (right < n)
        {
            hash[s[right]]++;
            while (hash[s[right]] > 1)
            {
                hash[s[left++]]--;
            }
            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};
