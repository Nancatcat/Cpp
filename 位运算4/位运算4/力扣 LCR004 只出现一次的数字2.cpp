class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int ret = 0;
        for (int i = 0; i < 32; i++)//λ��ѭ��
        {
            int sum = 0;
            for (auto ch : nums)//ȡÿһ�����ĵ�iλ���
                if (((ch >> i) & 1) == 1)//�����1sum++
                    sum++;
            sum %= 3;//����Ϊiλ����ȷ����
            if (sum == 1) ret |= 1 << i;//�޸�ret��iλ
        }
        return ret;
    }
};