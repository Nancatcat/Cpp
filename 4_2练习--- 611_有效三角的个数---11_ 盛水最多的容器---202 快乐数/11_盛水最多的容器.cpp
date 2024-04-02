#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        size_t  left = 0;
        size_t right = height.size() - 1;
        int Max = 0;
        while (left < right)
        {
            int v = (right - left) * min(height[right], height[left]);
            Max = max(v, Max);
            if (height[right] > height[left])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return Max;
    }
};