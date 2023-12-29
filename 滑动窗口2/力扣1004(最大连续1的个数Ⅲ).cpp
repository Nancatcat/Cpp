class Solution {
public:
    int longestOnes(vector<int>& nums, int k)
    {
        int len = 0, zero = 0;
        int n = nums.size();
        for (int left = 0, right = 0; right < n; right++)
        {
            if (nums[right] == 0) zero++;
            while (zero > k)
            {
                if (nums[left++] == 0) zero--;
            }
            len = max(len, right - left + 1);
        }
        return len;
    }
};
