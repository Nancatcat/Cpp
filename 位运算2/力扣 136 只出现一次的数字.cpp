#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int num = 0;
        for (auto ch : nums)
        {
            num ^= ch;
        }
        return num;
    }
};