#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> num;//创建返回数组
        sort(nums.begin(), nums.end());//排序,如果乱序无法利用单调性
        int n = nums.size();//指针移动范围
        for (int i = 0; i < n;) //定位i,判断i后的区域内数据
        {
            if (nums[i] > 0)//因为是递增关系,如果i大于零,代表没有相加为零的数字.优化循环
                break;
            int left = i + 1;//指针初始化
            int right = n - 1;
            int fnums = -nums[i];//取i位置的相反数,后续判断相加是否为零
            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum > fnums) {//大于缩小右指针
                    right--;
                }
                else if (sum < fnums) {
                    left++;//相反
                }
                else {
                    num.push_back({ nums[left], nums[right], nums[i] });//相等插入
                    left++, right--;//更新判断
                    while (left < right && nums[left - 1] == nums[left])//如果相同继续更新,直至不同
                        left++;
                    while (left < right && nums[right] == nums[right + 1])//同上一条
                        right--;
                }
            }
            i++;
            while (i + 1 < n && nums[i] == nums[i - 1])//判断i自增后是否和上一个数据相等,相等继续递增,直至不能
                i++;
        }
        return num;//返回结果数组
    }
};
