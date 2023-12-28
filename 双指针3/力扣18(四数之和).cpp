#define  _CRT_SECURE_NO_WARNINGS


class Solution {
public:
    //解题思路 
    //根据三数之和的原理,我们可以准确定位到三个数字之和,将这个原理延申,既是
    //四数之和
    //首先Sort排序,定位最小值,设为i, 接着定位次小值,设为j
    //在双指针内开始枚举遍历,如果 left+right=target-a-j
    //此时,我们就到了四数之和,因为left+right+i+j 一定等于 traget 
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());//牌序,优化数组位置
        int n = nums.size();//定位范围
        vector<vector<int>> num;
        for (int i = 0; i < n;)//定位i
        {
            for (int j = i + 1; j < n;)//定位j
            {
                long long tmp = (long long)target - nums[i] - nums[j];//计算target-a-j
                int left = j + 1;//确定范围域
                int right = n - 1;
                while (left < right)
                {
                    
                    int sum = nums[left] + nums[right];//计算域内数字
                    if (sum > tmp) right--;//大于right--
                    else if (sum < tmp) left++;//小于left++
                    else
                    {
                        num.push_back({ nums[i],nums[j],nums[left++],nums[right--] });//插入数组
                        while (left < right && nums[left] == nums[left - 1]) left++;//如果重复,就执行++,优化时间
                        while (left < right && nums[right] == nums[right + 1]) right--;//同理
                    }
                }
                j++;
                while (j < n && nums[j] == nums[j - 1])//判断是否重复,重复j++
                    j++;
            }
            i++;
            while (i < n && nums[i] == nums[i - 1])//判断是否重复,重复i++
                i++;
        }
        return num;//返回结果
    }
};
