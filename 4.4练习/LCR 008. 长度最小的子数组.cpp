#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int len = INT_MAX;//��ʼ������
        long long  sum = 0;//target�Ƚϵ�λ
        int left = 0, right = 0, n = nums.size();
        while (right < n)
        {
            sum += (long long)nums[right];//�봰��
            while (sum >= target)//������ڵ���target,��������������
            {
                len = min((right - left + 1), len);,//���³���
                sum -= nums[left];//����left����
                left++;
            }

            right++;
        }
        return len == INT_MAX ? 0 : len;//���len���ȱ��ֳ�ʼ��,����û����������������,����0
    }
};