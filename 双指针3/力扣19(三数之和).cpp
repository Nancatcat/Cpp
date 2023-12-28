#define  _CRT_SECURE_NO_WARNINGS

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> num;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int m = j + 1; m < n; m++)
                {
                    if (nums[i] + nums[j] + nums[m] == 0)
                    {
                        num.push_back({ nums[i],nums[j],nums[m] });
                        while (m + 1 < n && nums[m] == nums[m + 1])
                        {
                            m++;
                        }
                    }
                }
                while (j + 1 < n && nums[j] == nums[j + 1])
                {
                    j++;
                }

            }
            while (i + 1 < n && nums[i] == nums[i + 1])
            {
                i++;
            }
        }
        return num;
    }
};



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> num;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n;)
        {
            if (nums[i] > 0) break;
            int left = i + 1;
            int right = n - 1;
            int fnums = -nums[i];
            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum > fnums)
                {
                    right--;
                }
                else if (sum < fnums)
                {
                    left++;
                }
                else
                {
                    num.push_back({ nums[left], nums[right], nums[i] });
                    left++, right--;
                    while (left < right && nums[left - 1] == nums[left])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }
            i++;
            if (i + 1 < n && nums[i] == nums[i - 1]) i++;
        }
        return num;
    }
};
//����˼·,�ο�����֮��, �ó��Ż��㷨 ,��������,�ó���һ����λ����,
//�Զ�λ������һ�������һ������Ϊ������,��������
//��������֮��,�ó������ؼ���
//1.�����Сֵ�����ֵ���ڵ�һ�������෴�� ,�� right-- ,��Ϊright�������
//2.�����Сֵ�����ֵС�ڵ�һ�������෴��,�� left++,ӦΪleft��������С;
//3.������,β��ó����,��������
//�Ż��� 
//1. ���i�±�������Ѿ�������,��������û����ӵ��������,break����
//2. left��right��++ -- ������,�� ��һ�����ֱȽ�,����������,�����ظ�++ -- ����,ֱ�����ظ�
// ע���
// 1. i�ı�������,��Ϊi��++�����ж��Ƿ����ظ����ֺ�Ž��е�,���Բ��ɷ���forѭ����
// 2.left��right�ı߽�����
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> num;//������ά����,������
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n;) {//����
            if (nums[i] > 0)//���i>0,�˳�����
                break;
            int left = i + 1;//left����i����һ������right֮���������ڵ�
            int right = n - 1;// size -1;ȷ���±�
            int fnums = -nums[i];//ȡ�����Ƚ�
            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum > fnums) {//����--
                    right--;
                }
                else if (sum < fnums) {//С��++
                    left++;
                }
                else {//����ж��Ƿ�����һ�����ظ�,�ظ�++,ֱ�����ظ�
                    num.push_back({ nums[left], nums[right], nums[i] });
                    left++, right--;
                    while (left < right && nums[left - 1] == nums[left])//ע��ѭ��,��Ϊ��ֹ�����ж�һ��,����ʹ��while������if
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }
            i++;//++i
            while (i + 1 < n && nums[i] == nums[i - 1])// �ж��Ƿ��ظ�
                i++;
        }
        return num;//���ؽ��
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> num;
        for (int i = 0; i < n;)
        {
            for (int j = i + 1; j < n;)
            {
                long long tmp = (long long)target - nums[i] - nums[j];
                int left = j + 1;
                int right = n - 1;
                while (left < right)
                {
                    tmp = abs(tmp); 
                    int sum = nums[left] + nums[right];
                    if (sum > tmp) right--;
                    else if (sum < tmp) left++;
                    else
                    {
                        num.push_back({ nums[i],nums[j],nums[left++],nums[right--] });
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    }
                }
                j++;
                while (j < n && nums[j] == nums[j - 1])
                    j++;
            }
            i++;
            while (i < n && nums[i] == nums[i - 1])
                i++;
        }
        return num;
    }
};