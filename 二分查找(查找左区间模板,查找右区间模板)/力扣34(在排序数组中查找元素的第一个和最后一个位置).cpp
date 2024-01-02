#define  _CRT_SECURE_NO_WARNINGS
//解题思路 二分左端点查找与二分右端点查找
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        if (nums.size() == 0) return { -1,-1 };
        int left = 0, right = nums.size() - 1, begin = -1;

        while (left < right)
        {
            int mid = (right - left) / 2 + left;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if (nums[left] != target) return { -1,-1 };
        begin = left;
        right = nums.size() - 1;
        while (left < right)
        {
            int mid = (right - left + 1) / 2 + left;
            if (nums[mid] <= target) left = mid;
            else right = mid - 1;
        }
        return { begin,right };
    }
};