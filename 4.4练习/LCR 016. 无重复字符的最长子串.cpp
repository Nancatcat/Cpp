#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int lengthOfLongestSubstring(string s)//��������
    {
        int arr[128];//������ű��Ӧ����
        int count = 0;//������
        int left = 0, right = 0, n = s.size();
        while (right < n)
        {
            arr[s[right]]++;//s[right]�ַ�ͶӰint�����±�, ����++
            while (arr[s[right]] > 1)//�������1,���������ظ�
            {
                arr[s[left++]]--;//����arr�����ϵ,����leftλ��
            }
            count = max(count, right - left + 1);//���³���
            right++;//�����ж�
        }
        return count;
    }
};