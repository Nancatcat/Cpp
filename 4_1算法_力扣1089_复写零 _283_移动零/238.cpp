#define  _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

class Solution {
public:

    void moveZeroes(vector<int>& nums)
    {
        for (int dest = -1, cur = 0; cur < nums.size(); cur++)
        {
            if (nums[cur] != 0)//�����㽻��,��֤����curǰ
            {
                dest++;
                swap(nums[cur], nums[dest]);
            }
        }
    }
};
