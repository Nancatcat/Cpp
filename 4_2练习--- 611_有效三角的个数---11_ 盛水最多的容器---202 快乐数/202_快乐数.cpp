#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int bitSum(int n)
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
        int fast = bitSum(n);
        int slow = n;
        while (slow != fast)
        {
            slow = bitSum(slow);
            fast = bitSum(bitSum(fast));
        }
        return slow == 1;
    }
};