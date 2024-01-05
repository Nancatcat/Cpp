#define  _CRT_SECURE_NO_WARNINGS
#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int num(vector<int>& nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = (right - left) / 2 + left;
            if (nums[mid] == mid) left = mid + 1;
            else right = mid;
        }
        return nums[left] == left ? left + 1 : left;
    }

};
