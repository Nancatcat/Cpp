#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int size = cost.size();
        vector<int>nums(size + 1);
        for (int i = 2; i <= size; i++)
        {
            nums[i] = min((cost[i - 1] + nums[i - 1]), (cost[i - 2] + nums[i - 2]));
        }
        int i = nums.size() - 1;
        return nums[size];
    }
    //从后向前推
    class Solution {
    public:
        int minCostClimbingStairs(vector<int>& cost)
        {
            int n = cost.size();
            vector<int> nums(n);
            nums[n - 1] = cost[n - 1], nums[n - 2] = cost[n - 2];
            for (int i = n - 3; i >= 0; i--)
            {
                nums[i] = cost[i] + min(nums[i + 1], nums[i + 2]);
            }
            return min(nums[0], nums[1]);
        }
    };