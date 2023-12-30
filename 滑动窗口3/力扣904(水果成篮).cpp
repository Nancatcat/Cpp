#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int totalFruit(vector<int>& f)
    {
        int hash[1000001] = { 0 };
        int n = f.size();
        int count = 0;
        int len = 0;
        for (int left = 0, right = 0; right < n; right++)
        {
            if (hash[f[right]] == 0) count++;
            hash[f[right]]++;
            while (count > 2)
            {
                hash[f[left]]--;
                if (hash[f[left]] == 0)
                    count--;
                    left++;
            }
            len = max(len, right - left + 1);
        }
        return len;
    }
};