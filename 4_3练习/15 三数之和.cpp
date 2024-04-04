#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> num;//������������
        sort(nums.begin(), nums.end());//����,��������޷����õ�����
        int n = nums.size();//ָ���ƶ���Χ
        for (int i = 0; i < n;) //��λi,�ж�i�������������
        {
            if (nums[i] > 0)//��Ϊ�ǵ�����ϵ,���i������,����û�����Ϊ�������.�Ż�ѭ��
                break;
            int left = i + 1;//ָ���ʼ��
            int right = n - 1;
            int fnums = -nums[i];//ȡiλ�õ��෴��,�����ж�����Ƿ�Ϊ��
            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum > fnums) {//������С��ָ��
                    right--;
                }
                else if (sum < fnums) {
                    left++;//�෴
                }
                else {
                    num.push_back({ nums[left], nums[right], nums[i] });//��Ȳ���
                    left++, right--;//�����ж�
                    while (left < right && nums[left - 1] == nums[left])//�����ͬ��������,ֱ����ͬ
                        left++;
                    while (left < right && nums[right] == nums[right + 1])//ͬ��һ��
                        right--;
                }
            }
            i++;
            while (i + 1 < n && nums[i] == nums[i - 1])//�ж�i�������Ƿ����һ���������,��ȼ�������,ֱ������
                i++;
        }
        return num;//���ؽ������
    }
};
