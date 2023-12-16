#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
//class Solution {
//public:
//    int StrToInt(string str) {
//        int ans = 0; int isplus = 1;
//        for (char ch : str) {
//            if (isalpha(ch)) {
//                return 0;
//            }if (ch == '+' || ch == '-') {
//                isplus = (ch == '+') ? 1 : -1;
//            }if (isdigit(ch)) {
//                ans = ans * 10 + ch - '0';
//            }
//        }return isplus * ans;
//    }
//};
//
//class Solution
//{
//public:
//    int StrToInt(string str)
//    {
//        int flag = 1;
//        int num = 0;
//        int i = 0;
//        if (str[0] == '-')
//        {
//            flag = -1;
//            i++;
//        }
//        else if (str[0] == '+')
//        {
//            i++;
//        }
//        for (; i < str.size(); i++)
//        {
//            if (str[i] >= '0' && str[i] <= '9')
//            {
//                num = num * 10 + (str[i] - '0');
//            }
//            else
//            {
//                return 0;
//            }
//        }
//        return flag * num;
//    }
//};
//
//class Solution {
//public:
//    void reverseString(vector<char>& s)
//    {
//        int begin = 0;
//        int end = s.size() - 1;
//        while (begin <= end)
//        {
//            swap(s[begin], s[end]);
//            begin++;
//            end--;
//        }
//    }
//};
//class Solution {
//public:
//    int firstUniqChar(string s)
//    {
//        int num[26] = { 0 };
//        for (auto e : s)
//        {
//            num[e - 'a']++;
//        }
//        for (int i = 0; i < s.size(); i++)
//        {
//            if (num[s[i] - 'a'] == 1)
//            {
//                return i;
//            }
//        }
//        return -1;
//    }
//};
//
//﻿int main(int argc, char* argv[])
//
//{
//
//    string a = "hello world";
//
//    string b = a;
//
//    if (a.c_str() == b.c_str())
//
//    {
//
//        cout << "true" << endl;
//
//    }
//
//    else cout << "false" << endl;
//
//    string c = b;
//
//    c = "";
//
//    if (a.c_str() == b.c_str())
//
//    {
//
//        cout << "true" << endl;
//
//    }
//
//    else cout << "false" << endl;
//
//    a = "";
//
//    if (a.c_str() == b.c_str())
//
//    {
//
//        cout << "true" << endl;
//
//    }
//
//    else cout << "false" << endl;
//
//    return 0;
//
//}

//int main()
//{
//    string str("Hello Bit.");
//    str.reserve(111);
//    str.resize(5);
//    str.reserve(50);
//    cout << str.size() << ":" << str.capacity() << endl;
//    return 0;
//}

int main(int argc, char* argv[])
{
	string strText = "How are you?";
	string strSeparator = " ";
	string strResult;
	int size_pos = 0;
	int size_prev_pos = 0;
	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)
	{
		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
		cout << strResult << " ";
		size_prev_pos = ++size_pos;
	}
	if (size_prev_pos != strText.size())
	{
		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
		cout << strResult << " ";
	}
	cout << endl;
	return 0;

}

