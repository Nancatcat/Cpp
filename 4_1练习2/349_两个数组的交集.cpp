#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        set<int> s1(nums1.begin(), nums1.end());//set插入去重数据
        set<int> s2(nums2.begin(), nums2.end());
        vector<int> ret;
        for (auto& ch : s2)
        {
            if (s1.count(ch))//取map_s2的数据判断s1是否相同,相同插入
                ret.push_back(ch);
        }
        return ret;
    }
};
//同步算法
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());//set插入去重数据
        vector<int> ret;
        auto it1 = s1.begin();
        auto it2 = s2.begin();//遍历
        while (it1 != s1.end() && it2 != s2.end())
        {
            if (*it1 > *it2)//因为set的特性,数据已经没有重复值,又因为数据是递增排序,所以小于一定是差集,等于一定是交集
                it2++;
            else if (*it1 < *it2)
                it1++;
            else
            {
                ret.push_back(*it1);//插入
                it1++;
                it2++;
            }
        }
        return ret;
    }
};