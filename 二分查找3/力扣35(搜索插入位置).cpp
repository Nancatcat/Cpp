#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = (right - left) / 2 + left;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if (nums[left] < target) return left + 1;
        return left;
    }
};