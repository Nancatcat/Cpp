//��˹���
//�������������������ܺ�ӦΪ sum = (0 + n) * (n + 1) / 2���Ȳ�������͹�ʽ����
class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int ret = (0 + nums.size() * (0 + nums.size() + 1)) / 2;
        int sum = 0;
        for (auto ch : nums)
        {
            sum += ch;
        }
        return ret - sum;
    }
};

//��ϣ
class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> hash(n + 1);
        for (int i = 0; i < n; i++)
        {
            hash[nums[i]] = 1;
        }
        for (int i = 0; i < n + 1; i++)
        {
            if (hash[i] == 0) return i;
        }
        return 0;
    }
};

//���λ����
class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        vector<int> arr(nums.size() + 1);
        int sum = 0;
        for (auto ch : nums)
        {
            sum ^= ch;
        }
        int sum2 = 0;
        for (int i = 0; i < nums.size() + 1; i++)
        {
            arr[i] = i;
            sum2 ^= arr[i];

        }
        return sum ^ sum2;
    }
};
//���2 �Ż���
class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int ret = 0;
        for (auto ch : nums) ret ^= ch;
        for (int i = 0; i <= nums.size(); i++) ret ^= i;
        return ret;
    }
};