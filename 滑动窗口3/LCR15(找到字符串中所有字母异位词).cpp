//�������ڽ���˼·
//.���ù�ϣ���ԭ��������,����p�ַ����ֵĶ����±�λ,��ɱ��
//������λΪ2,֤���ظ�,ɾ��ǰһ�����λ,����Ϊ�ַ����λ2,ǰһ��
//����ͬ,,��p�ֹ涨�˲����ַ��ķ�Χ��С,���Ǵ�ʱ����,left,right
//��ͬʱ�����ƶ���,���û������ڵ����Ե�ԭ��,����count����,��ɽ��� 
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