#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int waysToStep(int n)
    {
        const int MOD = 1e9 + 7;
        if (n == 1 || n == 2) return n;
        if (n == 3) return 4;
        vector<int> nums(n + 1);
        nums[1] = 1, nums[2] = 2, nums[3] = 4;
        for (int i = 4; i <= n; i++)
        {
            nums[i] = ((nums[i - 1] + nums[i - 2]) % MOD + nums[i - 3]) % MOD;
        }
        return nums[n];
    }
};
//±³°üÓÅ»¯
class Solution {
public:
    int waysToStep(int n)
    {
        const int MOD = 1e9 + 7;
        if (n == 1 || n == 2) return n;
        if (n == 3) return 4;
        int a = 1, b = 2, c = 4;
        int sum = 0;
        for (int i = 4; i <= n; i++)
        {
            sum = ((a + b) % MOD + c) % MOD;
            a = b;
            b = c;
            c = sum;
        }
        return sum;
    }
};

