#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void duplicateZeros(vector<int>& arr)
    {
        int cur = 0, desc = -1, n = arr.size();
        while (cur < n)//�ж�cur,descλ��
        {
            if (arr[cur])//cur!=0 descǰ��һ��
                desc++;
            else//cur==0 descǰ������
                desc += 2;
            if (desc >= n - 1) break;//desc�����߽� ����ѭ��
            cur++;//����
        }
        if (desc == n)//���desc == n, ֤��cur���� ,�޸�����
        {
            arr[desc - 1] = 0;
            desc -= 2;
            cur--;
        }
        while (cur >= 0)//�����ƶ�
        {
            if (arr[cur])//�������㸳ֵһ��
                arr[desc--] = arr[cur--];
            else//�����㸳ֵ����
            {
                arr[desc--] = 0;
                arr[desc--] = 0;
                cur--;
            }
        }
    }
};