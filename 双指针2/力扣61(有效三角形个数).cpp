#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    //����˼· ,�����µ���С����֮��������ڵ�����
    //�򹹳�������,���ݸö���,sort�����ֵ����Сֵ
    //�����ε��ܸ��� = right-left
    //right--������һ���������θ�������
    int triangleNumber(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());//����
        int sum = 0;
        for (int i = nums.size() - 1; i >= 2; i--)//��λ���ֵ,��ʼ����
        {
            int left = 0;//��λ����С��
            int right = i - 1;//��λ���������ǰһ��
            while (left < right)//ѭ���������ڵ��������ܸ���
            {
                if (nums[left] + nums[right] > nums[i])//����������
                {
                    sum += right - left;
                    right--;
                }
                else//�������ı���Сֵ,�����ж�
                    left++;
            }
        }
        return sum;
    }
};