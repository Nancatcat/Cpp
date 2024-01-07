#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> former(n, 1), after(n, 1), num(n);
        for (size_t i = 1; i < n; i++)
            former[i] = former[i - 1] * nums[i - 1];
        for (size_t i = n - 2; i < n; i--)
            after[i] = after[i + 1] * nums[i + 1];

        for (size_t i = 0; i < n; i++)
            num[i] = after[i] * former[i];
        return num;
    }
};