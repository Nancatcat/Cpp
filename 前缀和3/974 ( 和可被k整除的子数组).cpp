#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k)
    {
        unordered_map<int, int>hash;
        hash[0] = 1;
        int sum = 0, ret = 0;
        for (auto ch : nums)
        {
            sum += ch;
            int remainder = (sum % k + k) % k;
            if (hash.count(remainder))
                ret += hash[remainder];
            hash[remainder]++;
        }
        return ret;
    }
};