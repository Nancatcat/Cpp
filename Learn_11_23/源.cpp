#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
int main()
{
	//string s1("hello,Linux");
	//s1.insert(5, "xxxxx");//ͷ��
	//s1.erase(1);//ɾ��
	//s1.replace(2, 1, "%%");//�滻,Ч�ʵ�
	//s1.find('x');//����


	//string filename("Դ.cpp");
	//FILE* fout = fopen(filename.c_str(), "r");
	//c_str ����c���͵��ַ��� ͬ���� data
	//string s2 = substr(pos, s1.size() - pos);�����Ӵ�
	//s1.rfind()
	//str.find_first_of("abc")�����������ַ�,��ǰ����
	//str.find_first_of("abc")�����������ַ�,�Ӻ�
	//str.find_first_not_of("abc")(����abc����)�����������ַ�,��ǰ����
	//str.find_first_not_of("abc")�����������ַ�,�Ӻ�
	//operator_(string);
	string s1("hello");
	string s2("C++");
	s1 +=s2;
	//gteline();//�����ո񲻽���,�������н���
	cout << s1 << endl;
	return 0;
}