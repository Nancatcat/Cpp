#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int longestOnes(vector<int>& nums, int k)
    {
        int len = 0, zero = 0;
        int n = nums.size();
        for (int left = 0, right = 0; right < n; right++)//��������
        {
            if (nums[right] == 0) zero++;//���Ϊ��,�������Ӽ�
            while (zero > k)//������������k,��������
            {
                if (nums[left++] == 0) zero--;//����left,ֱ��left��λ��zero�������ĺϷ�λ��
            }
            len = max(len, right - left + 1);//��������
        }
        return len;
    }
};