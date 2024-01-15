class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int ret = 0;
        for (int i = 0; i < 32; i++)//位数循环
        {
            int sum = 0;
            for (auto ch : nums)//取每一个数的第i位相加
                if (((ch >> i) & 1) == 1)//如果是1sum++
                    sum++;
            sum %= 3;//得数为i位置正确的数
            if (sum == 1) ret |= 1 << i;//修改ret第i位
        }
        return ret;
    }
};