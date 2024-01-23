#define  _CRT_SECURE_NO_WARNINGS
int main()
{
    string s1, s2, str;
    getline(cin, s1);
    getline(cin, s2);

    for (int i = 0; i < s1.size(); i++)
    {
        int flag = 0;
        for (int j = 0; j < s2.size(); j++)
        {
            if (s1[i] == s2[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            str += s1[i];
    }
    cout << str;
    return 0;
}
// 64 位输出请用 printf("%lld")

#include <iostream>
using namespace std;

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    for (int i = 0; i < s2.size(); i++)
    {
        size_t pos;
        while ((pos = s1.find(s2[i])) != string::npos)
        {
            s1.erase(pos, 1);
        }
    }
    cout << s1;
    return 0;

}
// 64 位输出请用 printf("%lld")