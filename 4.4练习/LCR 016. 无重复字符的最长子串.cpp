#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int lengthOfLongestSubstring(string s)//滑动窗口
    {
        int arr[128];//定义符号表对应数组
        int count = 0;//计数器
        int left = 0, right = 0, n = s.size();
        while (right < n)
        {
            arr[s[right]]++;//s[right]字符投影int数组下标, 数据++
            while (arr[s[right]] > 1)//如果大于1,代表数据重复
            {
                arr[s[left++]]--;//更新arr数组关系,更新left位置
            }
            count = max(count, right - left + 1);//更新长度
            right++;//更新判断
        }
        return count;
    }
};