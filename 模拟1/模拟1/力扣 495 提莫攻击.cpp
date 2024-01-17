class Solution {
public:
    int findPoisonedDuration(vector<int>& t, int d)
    {
        int ret = 0;
        for (int i = 1; i < t.size(); i++)
        {
            int x = t[i] - t[i - 1];
            if (x >= d) ret += d;
            else ret += x;
        }
        return ret + d;
    }
};