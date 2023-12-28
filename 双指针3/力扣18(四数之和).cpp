#define  _CRT_SECURE_NO_WARNINGS


class Solution {
public:
    //����˼· 
    //��������֮�͵�ԭ��,���ǿ���׼ȷ��λ����������֮��,�����ԭ������,����
    //����֮��
    //����Sort����,��λ��Сֵ,��Ϊi, ���Ŷ�λ��Сֵ,��Ϊj
    //��˫ָ���ڿ�ʼö�ٱ���,��� left+right=target-a-j
    //��ʱ,���Ǿ͵�������֮��,��Ϊleft+right+i+j һ������ traget 
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());//����,�Ż�����λ��
        int n = nums.size();//��λ��Χ
        vector<vector<int>> num;
        for (int i = 0; i < n;)//��λi
        {
            for (int j = i + 1; j < n;)//��λj
            {
                long long tmp = (long long)target - nums[i] - nums[j];//����target-a-j
                int left = j + 1;//ȷ����Χ��
                int right = n - 1;
                while (left < right)
                {
                    
                    int sum = nums[left] + nums[right];//������������
                    if (sum > tmp) right--;//����right--
                    else if (sum < tmp) left++;//С��left++
                    else
                    {
                        num.push_back({ nums[i],nums[j],nums[left++],nums[right--] });//��������
                        while (left < right && nums[left] == nums[left - 1]) left++;//����ظ�,��ִ��++,�Ż�ʱ��
                        while (left < right && nums[right] == nums[right + 1]) right--;//ͬ��
                    }
                }
                j++;
                while (j < n && nums[j] == nums[j - 1])//�ж��Ƿ��ظ�,�ظ�j++
                    j++;
            }
            i++;
            while (i < n && nums[i] == nums[i - 1])//�ж��Ƿ��ظ�,�ظ�i++
                i++;
        }
        return num;//���ؽ��
    }
};
