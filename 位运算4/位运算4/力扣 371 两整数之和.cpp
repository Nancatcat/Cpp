class Solution {
public:
    int getSum(int a, int b)
    {
        while (b)
        {
            int tmp = a ^ b;//a^b算出无进位相加的结果
            int tmp2 = (a & b) << 1;//算出应该进位的位置
            a = tmp;//赋值循环,直至为零
            b = tmp2;
        }
        return a;//返回结果
    }
};