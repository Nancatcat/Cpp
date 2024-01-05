#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int findMin(vector<int>& nums)
    {

        int left = 0, right = nums.size() - 1;
        int x = nums[right];
        while (left < right)
        {
            int mid = (right - left) / 2 + left;
            if (nums[mid] > x)  left = mid + 1;
            else right = mid;
        }

        return nums[left];
    }

};
