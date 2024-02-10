#include <iostream>
#include <algorithm>
#include <vector> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
最小和最大次大组队，次小和第三大第四大组队……
如，123456789
下标012345678
组队方案如下：
189,267,345 水平值总和为8+6+4=18，是最大值
每队队员中第二高水平值的下标：size-2*i（i=1,2,...,n）
所有队伍的水平值总和=每队队员中第二高水平值的总和
int main() 
{
	int n = 0;
	while ( cin >> n )
	{
		long long sum = 0;
		vector<int> arr;
		arr.resize(3*n);
		for (int i = 0; i < arr.size(); i++)
		{
			cin >> arr[i];
		}
		sort(arr.begin(),arr.end());
		for (int i = 1; i <= n; i++)
		{
			sum +=arr[arr.size()-2*i];
		}
		cout << sum << endl;
	}
	
	return 0;
}

描述
输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”
输入描述：
每个测试输入包含2个字符串
输出描述：
输出删除后的字符串
示例1
输入：
They are students. 
aeiou
复制
输出：
Thy r stdnts.

#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string s1, s2;
    getline(cin,s1);
    getline(cin,s2);
    char map[256] = {0};
    for (auto ch : s2)
    {
        map[ch]++;
    }
    string str = "";
    for (auto ch : s1)
    {
        if(map[ch] !=1)  
            str+=ch;
    }
    cout << str << endl;
    return 0;
}

// 64 位输出请用 printf("%lld")
