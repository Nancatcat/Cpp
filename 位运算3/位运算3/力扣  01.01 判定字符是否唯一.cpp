class Solution {
public:
    bool isUnique(string astr)
    {
        if (astr.size() > 26) return fakse;//�ж��ַ��������Ƿ����26��Ӣ����ĸ,�������,�����ظ�
        int bitmap = 0;//����λͼ
        for (auto ch : astr)
        {
            int i = ch - 'a';//��λ�ַ���λ��
            if (((bitmap >> 1) & 1) == 1) return false;//���Ϊ1,�����ظ�.
            bitmap |= 1 << i;//��������ѭ����ʱ��,����δ�ظ�,��bitmap��Ӧ��iλ��Ϊ1
        }
        return true;
    }
};
//2 ��һ������n��ȷ�����Ķ����Ʊ�ʾ�еĵ�xλ��0����1;
//int x = (n >> x) & 1;
// 
//3 ��һ��n�Ķ����Ʊ�ʾ�ĵ�xλ�޸ĳ�1
// nl= (1 << x) ;
