#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        unordered_map<int, int> dp;
        int sum = 0, ret = 0;
        dp[0] = 1;
        for (auto ch : nums)
        {
            sum += ch;
            if (dp.count(sum - k)) ret += dp[sum - k];
            dp[sum]++;
        }
        return ret;
    }
};
