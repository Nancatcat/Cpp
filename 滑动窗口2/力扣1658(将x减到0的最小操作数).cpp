#define  _CRT_SECURE_NO_WARNINGS


//解题思路,滑动窗口
class Solution {
public:
    int minOperations(vector<int>& nums, int x)
    {
        int sum = 0;
        int n = nums.size();
        for (int a : nums) sum += a;
        int target = sum - x;
        int len = -1;
        int tmp = 0;
        if (target < 0) return len;
        for (int left = 0, right = 0; right < n; right++)
        {
            tmp += nums[right];
            while (tmp > target) tmp -= nums[left++];
            if (tmp == target)
                len = max(len, right - left + 1);
        }
        if (len == -1)
            return len;
        else
            return n - len;
    }



};