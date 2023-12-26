#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    //水桶原理,木桶的水量由最小值决定
    // 由最大值确定宽度,开始遍历枚举
    //定位指针,判定大小会出现两种情况
    //1,高度不变,宽度减少, 水量减少
    //2.高度减少,宽度减少,水量减少
    //由此得出,遍历指针指向的最小值,保存数据,指针移动,继续遍历,丢弃最小值
    //直到遍历完成得出合适的值
    int maxArea(vector<int>& height)
    {
        size_t  left = 0;
        size_t right = height.size() - 1;//定义指针
        int Max = 0;
        while (left < right)//left必须小于right,当==是证明没有水
        {
            int v = (right - left) * min(height[right], height[left]);//计算本次遍历的数值
            Max = max(v, Max);//比较大小
            if (height[right] > height[left])//如果right指向的值大于left,则++left,继续遍历
            {
                left++;
            }
            else//相反
            {
                right--;
            }
        }
        return Max;//返回最大值
    }
};