class Solution {
public:
    vector<int> missingTwo(vector<int>& nums)
    {
        int tmp = 0;
        for (auto x : nums) tmp ^= x;
        for (int i = 1; i <= nums.size() + 2; i++)
        {
            tmp ^= i;
        }
        int diff = 0;
        while (1)
        {
            if (((tmp >> diff) & 1) == 1) break;
            else diff++;
        }
        int a = 0, b = 0;
        for (auto ch : nums)
        {
            if (((ch >> diff) & 1) == 1) a ^= ch;
            else b ^= ch;
        }
        for (int i = 1; i <= nums.size() + 2; i++)
        {
            if (((i >> diff) & 1) == 1) a ^= i;
            else b ^= i;
        }
        return { a,b };
    }
};