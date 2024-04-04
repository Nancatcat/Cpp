#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int len = INT_MAX;//初始化长度
        long long  sum = 0;//target比较单位
        int left = 0, right = 0, n = nums.size();
        while (right < n)
        {
            sum += (long long)nums[right];//入窗口
            while (sum >= target)//如果大于等于target,子数组条件满足
            {
                len = min((right - left + 1), len);,//更新长度
                sum -= nums[left];//更新left数据
                left++;
            }

            right++;
        }
        return len == INT_MAX ? 0 : len;//如果len长度保持初始化,代表没有子数组满足条件,返回0
    }
};