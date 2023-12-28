#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

//����˼·
//������������֪���������жϵ�����һ��������������,�����������,�����ܵó��⼸���ص�
//1. ������һ����������,������ӵ�����һ���ǲ������ӵ�,��ʱ�����˵�����
//2.������ȷ�����������㵥����,�Ϳ��Զ���˫ָ�����,left��λ��Ԫ��,�����ۼ�right����Ӧ��Ԫ��
//  ֱ���ۼӵ���Ŀ�����;���泤��
//3.���ս��-left+left����һ�����Ƿ�>=Ŀ����,�������,����len,���С��,�����ۼ�right
//  ֱ��right���� ,���ȫ���ı���
// �ɻ��: Ϊʲôû��ȫ����������ȷ�����յĽ��һ����ȷ��
//ԭ������,���������˵�����,�����ǵó���һ������������,����++right�Ľ��һ���Ǵ���Ŀ������,����
//����++left,�����ۼӽ����ȥ�ɵ�left,�������µ��ۼ���,���������ɸѡ.���Խ���ض���ȷ
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int len = INT_MAX;//��ʼ��len,���бȶ�3
        int sum = 0;
        int n = nums.size();
        for (int left = 0, right = 0; right < n; right++)
        {
            sum += nums[right];//�ۼ�
            while (sum >= target)
            {
                len = min(len, right - left + 1);//����
                sum -= nums[left++];
            }
        }
        return len == INT_MAX ? 0 : len;//�жϷ���ֵ�Ƿ�Ϊ0
    }
};