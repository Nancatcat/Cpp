#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    //解题思路 ,三角新的最小两边之和如果大于第三边
    //则构成三角形,根据该定律,sort出最大值和最小值
    //三角形的总个数 = right-left
    //right--计算下一数的三角形个数即可
    int triangleNumber(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());//排序
        int sum = 0;
        for (int i = nums.size() - 1; i >= 2; i--)//定位最大值,开始遍历
        {
            int left = 0;//定位到最小数
            int right = i - 1;//定位到最大数的前一个
            while (left < right)//循环该数据内的三角形总个数
            {
                if (nums[left] + nums[right] > nums[i])//如果成立相加
                {
                    sum += right - left;
                    right--;
                }
                else//不成立改变最小值,继续判定
                    left++;
            }
        }
        return sum;
    }
};