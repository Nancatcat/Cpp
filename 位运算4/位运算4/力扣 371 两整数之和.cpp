class Solution {
public:
    int getSum(int a, int b)
    {
        while (b)
        {
            int tmp = a ^ b;//a^b����޽�λ��ӵĽ��
            int tmp2 = (a & b) << 1;//���Ӧ�ý�λ��λ��
            a = tmp;//��ֵѭ��,ֱ��Ϊ��
            b = tmp2;
        }
        return a;//���ؽ��
    }
};