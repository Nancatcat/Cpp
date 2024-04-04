#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)//������֮����ͬ����˼·
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> num;
        for (int i = 0; i < n;)
        {
            for (int j = i + 1; j < n;)
            {
                long long tmp = (long long)target - nums[i] - nums[j];//��ͬ��,��Ϊint���ݻᳬ�����ݷ�Χ,��������Χ
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
                        num.push_back({ nums[i],nums[j],nums[left++],nums[right--] });//�ؼ���,ѭ�����ݷ�ΧҪ�����ȶ���Խ��
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