#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int ret = -1;
        while (left <= right)
        {
            //int mid = (left + right) / 2;
            int mid = (right - left) / 2 + left;
            // 推荐计算中心点公式
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return ret;
    }
};