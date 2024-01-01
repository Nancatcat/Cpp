#define  _CRT_SECURE_NO_WARNINGS

//��̬�滮 ����˼·
//1.����dp��
//2.������ʽ
//3.��ʼ��
//4.���
//5.����߽����
//6.����
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

//C++��

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


//�Ż���

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