#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    vector<int> twoSum(vector<int>& price, int target)
    {
        int left = 0;
        int right = price.size() - 1;//双指针初始化
        while (price[right] > target)//尾指针定位到结束点
        {
            right--;
        }
        while (left < right)
        {
            if (price[left] + price[right] > target)//大于缩小尾指针定位
                right--;
            else if (price[left] + price[right] < target)//小于扩大头指针定位
                left++;
            else//相等下标位为两数之和
                break;
        }
        return { price[left],price[right] };
    }
};