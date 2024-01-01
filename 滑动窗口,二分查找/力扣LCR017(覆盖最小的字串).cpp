#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<string>
//����˼· ��������
//����t�ַ����ڵ��������,������ϣ��ӳ���ϵ
//������ϣ��2 ѭ�����ж�
// ������ char in = s[right]; hash2[in]++; ���if (hash2[in] == hash1[in]) count++; ����ӳ����ͬ,ӳ���ϵ++
//�ж� ֻ����������ȲŽ��г����ڲ���,�������ж�,������, �ж���̳��� ,�жϺ�++left,hash2ӳ���ϵ--
//�������--,ӦΪ���ܴ��ڶ���ظ��ַ�,�����ж�����Ϊwhileѭ��
//���ؽ��
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
