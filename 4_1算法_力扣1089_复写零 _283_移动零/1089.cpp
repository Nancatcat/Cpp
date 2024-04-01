#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void duplicateZeros(vector<int>& arr)
    {
        int cur = 0, desc = -1, n = arr.size();
        while (cur < n)//判断cur,desc位置
        {
            if (arr[cur])//cur!=0 desc前进一次
                desc++;
            else//cur==0 desc前进两次
                desc += 2;
            if (desc >= n - 1) break;//desc超过边界 跳出循环
            cur++;//遍历
        }
        if (desc == n)//如果desc == n, 证明cur是零 ,修改数据
        {
            arr[desc - 1] = 0;
            desc -= 2;
            cur--;
        }
        while (cur >= 0)//正常移动
        {
            if (arr[cur])//不等于零赋值一次
                arr[desc--] = arr[cur--];
            else//等于零赋值两次
            {
                arr[desc--] = 0;
                arr[desc--] = 0;
                cur--;
            }
        }
    }
};