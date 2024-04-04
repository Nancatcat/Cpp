#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    vector<int> twoSum(vector<int>& price, int target)
    {
        int left = 0;
        int right = price.size() - 1;//˫ָ���ʼ��
        while (price[right] > target)//βָ�붨λ��������
        {
            right--;
        }
        while (left < right)
        {
            if (price[left] + price[right] > target)//������Сβָ�붨λ
                right--;
            else if (price[left] + price[right] < target)//С������ͷָ�붨λ
                left++;
            else//����±�λΪ����֮��
                break;
        }
        return { price[left],price[right] };
    }
};