#define  _CRT_SECURE_NO_WARNINGS
//����˼· �������� ʾ�� barfoothefoobarman   words :bar foo
//ת��˼·,���ж�һ�����ַ�ת��Ϊ�ж�һ�����ַ��ִ�,
//����hash1 ��¼ÿ���ִ����ֵĴ��� count ��¼�Ϸ�����
// ���� hash2 ,��ÿ�α������������鼼��,��hash1�Ա� ,�Ϸ� count++
// ���right-left+1>words.size()֤�����Ϸ�,�� left--;
// �ж� ,���count�������� wodrs,size() ֤�����, pushback nums;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        vector<int>nums;//�����������
        unordered_map<string, int> hash1;//����ӳ���ϵ1
        for (auto& s : words) hash1[s]++;//ӳ���ϵ

        int len = words[0].size(), n = words.size();
        //len ��ʾÿ�����ʵķ�Χ, n ��ʾ words���ܸ���
        for (int i = 0; i < len; i++)//ѭ���������ڵ��ʷ�Χ
        {
            unordered_map<string, int> hash2;//����ӳ���ϵ2
            for (int left = i, right = i, count = 0; right + len <= s.size(); right += len)
            {
                //��Ϊ�������ǵ���,����right+len���ܱ�������һ������, ͬʱΪ�˱���Խ��,
                //right+len<=s.size()�涨��Χ
                string in = s.substr(right, len);//��ȡ����
                hash2[in]++;//����ͶӰ��ϵ

                if (hash2[in] <= hash1[in]) count++;//�ж�,�����ȴ���Ϸ�,count++


                if (right - left + 1 > len * n)//���Խ��,��ʾ�Ƿ�,�����ж�
                {
                    string out = s.substr(left, len);
                    left += len;//left��λ��һ������
                    if (hash2[out]-- <= hash1[out])  count--;//�����ϵ�Ϸ�,����count�����˺Ϸ�����
                }

                if (count == n)//������,�����±�
                {
                    nums.push_back(left);
                }

            }

        }
        return nums;
    }
};