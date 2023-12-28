#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

//����˼·
//��������˼��,���ù�ϣ���ԭ����Ͷ������,������Ԫ�ش���1�����ظ�,
//�����������������������,ֱ���ҵ����len
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
