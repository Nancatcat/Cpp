#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>

using namespace std;


//��Ϊ��ǰ�������Ḳ������,�����������Ҫ�Ӻ���ǰ��ֵ
class Solution {
public:
    void duplicateZeros(vector<int>& arr)
    {
        int cur = 0, desc = -1;//����ָ��,��ǰ������,ȷ��cur����λ��
        int n = arr.size();
        while (cur < n) {
            if (arr[cur]) {
                desc++;
            }
            else {
                desc += 2;
            }
            if (desc >= n - 1)//���desc==n���ߴ���n,֤��Խ��.������ֹѭ��
                break;
            cur++;
        }


        if (desc == n)//descֻ�е�����Ľ��
        {
            arr[n - 1] = 0;//������д
            cur--; desc -= 2;//����ָ��
        }
        while (cur >= 0)//����ѭ��,���curΪ1��������
        {
            if (arr[cur])
                arr[desc--] = arr[cur--];
            else//���Ϊ��,desc��ֵ0,cur������
            {
                arr[desc--] = 0;
                arr[desc--] = 0;
                cur--;
            }
        }

    }
};