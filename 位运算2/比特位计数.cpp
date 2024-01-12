#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            //״̬ת�ƹ�ʽ
            dp[i] = dp[i & (i - 1)] + 1;
        }
        return dp;
    }

};
