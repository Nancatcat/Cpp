#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    //[1,3,0,0,123,42,12,2,3]
    void moveZeroes(vector<int>& nums)
    {
        for (int dest = -1, cur = 0; cur < nums.size(); cur++)
        {
            if (nums[cur] != 0)//当cur不等于0时,将desc++与cur交换,使得desc位置的0不断后移,如同推箱子

            {
                dest++;
                swap(nums[cur], nums[dest]);
            }
        }
    }