#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

//解题思路
//从题意中我们知道了我们判断的数组一定是正整数数组,根据这个数组,我们能得出这几个特点
//1. 该数组一定是正整数,所以相加的数字一定是不断增加的,此时满足了单调性
//2.当我们确定了数组满足单调性,就可以定义双指针解题,left定位首元素,不断累加right所对应的元素
//  直至累加到与目标相等;保存长度
//3.最终结果-left+left的下一个数是否>=目标数,如果大于,更新len,如果小于,继续累加right
//  直到right结束 ,完成全部的遍历
// 疑惑点: 为什么没有全部遍历就能确定最终的结果一定正确呢
//原因如下,我们利用了单调性,当我们得出第一个结果并保存后,继续++right的结果一定是大于目标数的,所以
//我们++left,再让累加结果减去旧的left,更新了新的累加数,变相完成了筛选.所以结果必定正确
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int len = INT_MAX;//初始化len,进行比对3
        int sum = 0;
        int n = nums.size();
        for (int left = 0, right = 0; right < n; right++)
        {
            sum += nums[right];//累加
            while (sum >= target)
            {
                len = min(len, right - left + 1);//更新
                sum -= nums[left++];
            }
        }
        return len == INT_MAX ? 0 : len;//判断返回值是否为0
    }
};