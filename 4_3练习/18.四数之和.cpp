#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)//与三数之和相同解题思路
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> num;
        for (int i = 0; i < n;)
        {
            for (int j = i + 1; j < n;)
            {
                long long tmp = (long long)target - nums[i] - nums[j];//不同点,因为int数据会超出数据范围,所以扩大范围
                int left = j + 1;
                int right = n - 1;
                while (left < right)
                {
                    tmp = abs(tmp);
                    int sum = nums[left] + nums[right];
                    if (sum > tmp) right--;
                    else if (sum < tmp) left++;
                    else
                    {
                        num.push_back({ nums[i],nums[j],nums[left++],nums[right--] });//关键点,循环数据范围要保持稳定不越界
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    }
                }
                j++;
                while (j < n && nums[j] == nums[j - 1])
                    j++;
            }
            i++;
            while (i < n && nums[i] == nums[i - 1])
                i++;
        }
        return num;
    }
};