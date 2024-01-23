#define  _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    long long sum = 0;
    vector<int> nums;
    nums.resize(3 * n);
    for (int i = 0; i < nums.size(); ++i)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int end = 3 * n - 2;
    for (int i = 0; i < n; i++)
    {
        sum += nums[end];
        end -= 2;
    }
    printf("%lld", sum);
    return 0;
}
// 64 位输出请用 printf(\"%lld\")#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    long long sum = 0;
    vector<int> nums;
    nums.resize(3 * n);
    for (int i = 0; i < nums.size(); ++i)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int end = 3 * n - 2;
    for (int i = 0; i < n; i++)
    {
        sum += nums[end];
        end -= 2;
    }
    printf("%lld", sum);
    return 0;
}
// 64 位输出请用 printf(\"%lld\")