#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        int num = 0;
        for (auto ch : nums)
        {
            num ^= ch;
        }
        int ans1 = 0, ans2 = 0;
        int flag = (num == INT_MIN ? num : num & (-num));
        for (auto ch : nums)
        {
            if (ch & flag) ans1 ^= ch;
            else ans2 ^= ch;
        }
        return { ans1,ans2 };
    }
};