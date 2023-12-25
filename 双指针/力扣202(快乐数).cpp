#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int bitSum(int n)//计算每一位的平方和函数
    {
        int sum = 0;
        while (n)
        {
            int t = n % 10;
            sum += t * t;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n)
    {
        int fast = bitSum(n);//因为是快慢指针,判断条件又是fast!=slow,如果相等无法循环
        //所以赋值fast为slow的下一个数字,又因为在环内一定会相遇,所以不会死循环
        int slow = n;
        while (slow != fast)
        {
            slow = bitSum(slow);//模拟慢指针走一步的特征
            fast = bitSum(bitSum(fast));//模拟快指针走两步的特征
        }
        return slow == 1;//如果为1为true,不为1为falst;
    }
};