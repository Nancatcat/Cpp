#define  _CRT_SECURE_NO_WARNINGS

//动态规划 解题思路
//1.创建dp表
//2.创建公式
//3.初始化
//4.填表
//5.处理边界情况
//6.返回
class Solution {
public:
    int tribonacci(int n)
    {
        int arr[n+1] = { 0 };
        arr[1] = { 1 };
        arr[2] = { 1 };
        int size = sizeof(arr) / sizeof(arr[0]);
        for (int i = 3; i < size; i++)
        {
            arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
        }
        return arr[n];
    }
};

//C++版

class Solution {
public:
    int tribonacci(int n)
    {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        vector<int> arr(n + 1);
        arr[0] = { 0 };
        arr[1] = { 1 };
        arr[2] = { 1 };
        for (int i = 3; i <= n; i++)
        {
            arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
        }
        return arr[n];
    }
};


//优化版

class Solution {
public:
    int tribonacci(int n)
    {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        int a = 0, b = 1, c = 1;
        for (int i = 3; i <= n; i++)
        {
            int d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return d;
    }
};