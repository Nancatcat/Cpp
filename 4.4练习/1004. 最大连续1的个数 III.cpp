#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int longestOnes(vector<int>& nums, int k)
    {
        int len = 0, zero = 0;
        int n = nums.size();
        for (int left = 0, right = 0; right < n; right++)//滑动窗口
        {
            if (nums[right] == 0) zero++;//如果为零,计数器加加
            while (zero > k)//当计数器大于k,更新数据
            {
                if (nums[left++] == 0) zero--;//更新left,直至left定位到zero计数器的合法位置
            }
            len = max(len, right - left + 1);//更新数据
        }
        return len;
    }
};