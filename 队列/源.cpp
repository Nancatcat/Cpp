#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

//int main()
//{
//    int n = 0;
//    cin >> n;
//    int sum = 0;
//    while (n--)
//    {
//        vector<int> arr;
//        int tmp = 0;
//        for (int i = 0; i < 3; i++)
//        {
//            cin >> tmp;
//            arr.push_back(tmp);
//        }
//        sort(arr.begin(), arr.end());
//        sum += arr[1];
//    }
//    printf("%d", sum);
//    return 0;
//}
//#include <iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//    int n = 0;
//    long long  sum = 0;
//    cin >> n;
//    vector<int> arr;
//    arr.resize(3 * n);
//    for (int i = 0; i < 3 * n; i++)
//    {
//        cin >> arr[i];
//    }
//    sort(arr.begin(), arr.end());
//    int end = 3 * n - 2;
//    for (int i = 0; i < n; i++)
//    {
//        sum += arr[end];
//        end -= 2;
//    }
//    printf("%ld", sum);
//    return 0;
//}
// 64 位输出请用 printf("%lld")

#include <iostream>
using namespace std;

int main()
{
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    for (int i = 0; i < s2.size(); i++)
    {
        for (int j = 0; j < s1.size(); j++)
        {
            if (s1[j] == s2[i])
            {
                int x = 0;
                for (int x = j; x < s1.size();)
                {
                    s1[x] = s1[x + 1];
                    x++;
                }
            }
        }
    }
    cout << s1;
    return 0;
}
// 64 位输出请用 printf("%lld")
#include <iostream>
#include<string>
using namespace std;

int main() {

    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    for (size_t i = 0; i < str2.size(); i++)
    {
        size_t  pos;
        while ((pos = str1.find(str2[i])) != string::npos)
        {
            str1.erase(pos, 1);
        }
    }
    cout << str1 << endl;
    return 0;

}