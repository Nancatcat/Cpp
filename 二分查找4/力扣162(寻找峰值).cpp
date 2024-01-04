#define  _CRT_SECURE_NO_WARNINGS

class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {

        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = (right - left) / 2 + left;
            if (nums[mid] > nums[mid + 1]) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = (right - left) / 2 + left;
            if (nums[mid] < nums[mid + 1]) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};