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
//解题思路,参考两数之和, 得出优化算法 ,排序数组,得出第一个定位数字,
//以定位数的下一个与最后一个数字为计算域,遍历数组
//根据两数之和,得出几个关键点
//1.如果最小值加最大值大于第一个数的相反数 ,则 right-- ,因为right代表最大
//2.如果最小值加最大值小于第一个数的相反数,则 left++,应为left在域内最小;
//3.如果相等,尾插得出结果,继续遍历
//优化点 
//1. 如果i下标的数字已经是正数,则代表后续没有相加等于零的数,break即可
//2. left与right在++ -- 操作后,与 后一个数字比较,如果数字相等,可以重复++ -- 操作,直到不重复
// 注意点
// 1. i的遍历问题,因为i的++是在判断是否有重复数字后才进行的,所以不可放在for循环中
// 2.left与right的边界问题
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> num;//创建二维数组,保存结果
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n;) {//遍历
            if (nums[i] > 0)//如果i>0,退出程序
                break;
            int left = i + 1;//left是在i的下一个数与right之间数据域内的
            int right = n - 1;// size -1;确定下标
            int fnums = -nums[i];//取负数比较
            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum > fnums) {//大于--
                    right--;
                }
                else if (sum < fnums) {//小于++
                    left++;
                }
                else {//相等判断是否与上一个数重复,重复++,直至不重复
                    num.push_back({ nums[left], nums[right], nums[i] });
                    left++, right--;
                    while (left < right && nums[left - 1] == nums[left])//注意循环,因为不止可能判断一次,所以使用while而不是if
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }
            i++;//++i
            while (i + 1 < n && nums[i] == nums[i - 1])// 判断是否重复
                i++;
        }
        return num;//返回结果
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