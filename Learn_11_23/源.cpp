#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
int main()
{
	//string s1("hello,Linux");
	//s1.insert(5, "xxxxx");//头插
	//s1.erase(1);//删除
	//s1.replace(2, 1, "%%");//替换,效率低
	//s1.find('x');//查找


	//string filename("源.cpp");
	//FILE* fout = fopen(filename.c_str(), "r");
	//c_str 返回c类型的字符串 同作用 data
	//string s2 = substr(pos, s1.size() - pos);创建子串
	//s1.rfind()
	//str.find_first_of("abc")查找括号内字符,从前往后
	//str.find_first_of("abc")查找括号内字符,从后
	//str.find_first_not_of("abc")(不是abc返回)查找括号内字符,从前往后
	//str.find_first_not_of("abc")查找括号内字符,从后
	//operator_(string);
	string s1("hello");
	string s2("C++");
	s1 +=s2;
	//gteline();//遇到空格不结束,遇到换行结束
	cout << s1 << endl;
	return 0;
}