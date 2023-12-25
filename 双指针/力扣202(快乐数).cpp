#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int bitSum(int n)//����ÿһλ��ƽ���ͺ���
    {
        int sum = 0;
        while (n)
        {
            int t = n % 10;
            sum += t * t;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n)
    {
        int fast = bitSum(n);//��Ϊ�ǿ���ָ��,�ж���������fast!=slow,�������޷�ѭ��
        //���Ը�ֵfastΪslow����һ������,����Ϊ�ڻ���һ��������,���Բ�����ѭ��
        int slow = n;
        while (slow != fast)
        {
            slow = bitSum(slow);//ģ����ָ����һ��������
            fast = bitSum(bitSum(fast));//ģ���ָ��������������
        }
        return slow == 1;//���Ϊ1Ϊtrue,��Ϊ1Ϊfalst;
    }
};