#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    //ˮͰԭ��,ľͰ��ˮ������Сֵ����
    // �����ֵȷ�����,��ʼ����ö��
    //��λָ��,�ж���С������������
    //1,�߶Ȳ���,��ȼ���, ˮ������
    //2.�߶ȼ���,��ȼ���,ˮ������
    //�ɴ˵ó�,����ָ��ָ�����Сֵ,��������,ָ���ƶ�,��������,������Сֵ
    //ֱ��������ɵó����ʵ�ֵ
    int maxArea(vector<int>& height)
    {
        size_t  left = 0;
        size_t right = height.size() - 1;//����ָ��
        int Max = 0;
        while (left < right)//left����С��right,��==��֤��û��ˮ
        {
            int v = (right - left) * min(height[right], height[left]);//���㱾�α�������ֵ
            Max = max(v, Max);//�Ƚϴ�С
            if (height[right] > height[left])//���rightָ���ֵ����left,��++left,��������
            {
                left++;
            }
            else//�෴
            {
                right--;
            }
        }
        return Max;//�������ֵ
    }
};