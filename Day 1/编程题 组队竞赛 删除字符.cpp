#include <iostream>
#include <algorithm>
#include <vector> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
��С�����δ���ӣ���С�͵�������Ĵ���ӡ���
�磬123456789
�±�012345678
��ӷ������£�
189,267,345 ˮƽֵ�ܺ�Ϊ8+6+4=18�������ֵ
ÿ�Ӷ�Ա�еڶ���ˮƽֵ���±꣺size-2*i��i=1,2,...,n��
���ж����ˮƽֵ�ܺ�=ÿ�Ӷ�Ա�еڶ���ˮƽֵ���ܺ�
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

����
���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ������磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��
����������
ÿ�������������2���ַ���
���������
���ɾ������ַ���
ʾ��1
���룺
They are students. 
aeiou
����
�����
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

// 64 λ������� printf("%lld")
