#define  _CRT_SECURE_NO_WARNINGS

class Solution {
public:
    int mySqrt(int x)
    {
        if (x < 1) return 0;
        int left = 1, right = x;
        while (left < right)
        {
            long long  mid = (right - left + 1) / 2 + left;
            if (mid * mid <= x) left = mid;
            else right = mid - 1;
        }
        return left;
    }
};