#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
   
	vector<int>twoSum(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;
		int sum = 0;
		while (left < right)
		{
			if (nums[left] + nums[right] > target)
			{
				right--;
			}
			else if (nums[left] + nums[right] < target)
			{
				left++;
			}
			else
				return { nums[left],nums[right] };
		}
		return { -1,-1 };
	}
};