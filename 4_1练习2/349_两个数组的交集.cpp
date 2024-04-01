#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        set<int> s1(nums1.begin(), nums1.end());//set����ȥ������
        set<int> s2(nums2.begin(), nums2.end());
        vector<int> ret;
        for (auto& ch : s2)
        {
            if (s1.count(ch))//ȡmap_s2�������ж�s1�Ƿ���ͬ,��ͬ����
                ret.push_back(ch);
        }
        return ret;
    }
};
//ͬ���㷨
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());//set����ȥ������
        vector<int> ret;
        auto it1 = s1.begin();
        auto it2 = s2.begin();//����
        while (it1 != s1.end() && it2 != s2.end())
        {
            if (*it1 > *it2)//��Ϊset������,�����Ѿ�û���ظ�ֵ,����Ϊ�����ǵ�������,����С��һ���ǲ,����һ���ǽ���
                it2++;
            else if (*it1 < *it2)
                it1++;
            else
            {
                ret.push_back(*it1);//����
                it1++;
                it2++;
            }
        }
        return ret;
    }
};