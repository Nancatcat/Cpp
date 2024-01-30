#include<iostream>
#include<vector>
using namespace std;


//int MoreThanHalfNum_Solution(vector<int>& numbers)
//{
//    vector<int> arr(10, 0);
//    int max = INT_MIN;
//    for (int i = 0; i < numbers.size(); i++)
//    {
//        arr[numbers[i]]++;
//        if (max < arr[numbers[i]]) max = arr[numbers[i]];
//    }
//    return max;
//}

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int begin = 0, end = 1;
        while (end < nums.size())
        {
            if (nums[begin] != nums[end])
            {
                ++begin;
                nums[begin] = nums[end];
            }
            end++;
        }
        return begin + 1;
    }
};
int main()
{
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);

    cout << removeDuplicates(nums) << endl;
    return 0;
}

//class Solution {
//public:
//
//    int MoreThanHalfNum_Solution(vector<int>& numbers)
//    {
//        unordered_map<int, int> mp;
//        for (int i = 0; i < numbers.size(); i++)
//        {
//            mp[numbers[i]]++;
//            if (mp[numbers[i]] > numbers.size() / 2)
//                return numbers[i];
//        }
//        return  0;
//    }
//};