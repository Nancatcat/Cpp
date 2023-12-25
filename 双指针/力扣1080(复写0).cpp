#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>

using namespace std;


//因为从前向后遍历会覆盖数据,所以这道题需要从后向前赋值
class Solution {
public:
    void duplicateZeros(vector<int>& arr)
    {
        int cur = 0, desc = -1;//定义指针,从前向后遍历,确认cur最终位置
        int n = arr.size();
        while (cur < n) {
            if (arr[cur]) {
                desc++;
            }
            else {
                desc += 2;
            }
            if (desc >= n - 1)//如果desc==n或者大于n,证明越界.立刻终止循环
                break;
            cur++;
        }


        if (desc == n)//desc只有等于零的结果
        {
            arr[n - 1] = 0;//修正复写
            cur--; desc -= 2;//修正指针
        }
        while (cur >= 0)//正常循环,如果cur为1正常复制
        {
            if (arr[cur])
                arr[desc--] = arr[cur--];
            else//如果为零,desc赋值0,cur正常减
            {
                arr[desc--] = 0;
                arr[desc--] = 0;
                cur--;
            }
        }

    }
};