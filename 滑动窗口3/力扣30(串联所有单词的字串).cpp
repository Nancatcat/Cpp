#define  _CRT_SECURE_NO_WARNINGS
//解题思路 滑动窗口 示例 barfoothefoobarman   words :bar foo
//转变思路,将判断一个个字符转化为判断一个个字符字串,
//创建hash1 记录每次字串出现的次数 count 记录合法次数
// 创建 hash2 ,将每次遍历出来的数组技术,与hash1对比 ,合法 count++
// 如果right-left+1>words.size()证明不合法,将 left--;
// 判断 ,如果count数量等于 wodrs,size() 证明相等, pushback nums;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        vector<int>nums;//创建结果数字
        unordered_map<string, int> hash1;//创建映射关系1
        for (auto& s : words) hash1[s]++;//映射关系

        int len = words[0].size(), n = words.size();
        //len 表示每个单词的范围, n 表示 words的总个数
        for (int i = 0; i < len; i++)//循环次数等于单词范围
        {
            unordered_map<string, int> hash2;//创建映射关系2
            for (int left = i, right = i, count = 0; right + len <= s.size(); right += len)
            {
                //因为遍历的是单词,所以right+len才能遍历到下一个单词, 同时为了避免越界,
                //right+len<=s.size()规定范围
                string in = s.substr(right, len);//截取单词
                hash2[in]++;//建设投影关系

                if (hash2[in] <= hash1[in]) count++;//判断,如果相等代表合法,count++


                if (right - left + 1 > len * n)//如果越界,表示非法,重新判断
                {
                    string out = s.substr(left, len);
                    left += len;//left定位下一个单词
                    if (hash2[out]-- <= hash1[out])  count--;//如果关系合法,代表count减少了合法单词
                }

                if (count == n)//如果相等,插入下表
                {
                    nums.push_back(left);
                }

            }

        }
        return nums;
    }
};