//滑动窗口解题思路
//.利用哈希表的原理创建数字,插入p字符数字的对于下表位,完成标记
//如果标记位为2,证明重复,删除前一个标记位,又因为字符如果位2,前一个
//必相同,,而p又规定了查找字符的范围大小,我们此时发现,left,right
//是同时向右移动的,利用滑动窗口单调性的原理,定义count计数,完成解题 
class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        int hash1[26] = { 0 };
        for (auto ch : p) hash1[ch - 'a']++;
        int hash2[26] = { 0 };
        int m = p.size();
        int n = s.size();
        vector<int> nums;
        for (int left = 0, right = 0, count = 0; right < n; right++)
        {
            char in = s[right];
            if (++hash2[in - 'a'] <= hash1[in - 'a']) count++;
            if (right - left + 1 > m)
            {
                char out = s[left++];
                if (hash2[out - 'a']-- <= hash1[out - 'a']) count--;
            }
            if (count == m)
            {
                nums.push_back(left);
            }
        }
        return nums;
    }
};