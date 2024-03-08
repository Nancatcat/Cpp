#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
//
using namespace std;
//
////class A
////{
////public:
////	virtual void func(int a = 0)
////	{
////		cout << "class A func()" << endl;
////	}
////
////		int _a = 0;
////};
////class B: public A
////{
////public:
////	void func(int b = 0)
////	{
////		cout << "class B func()" << endl;
////	}
////	int _b = 1;
////};
////int main()
////{
////
////	A p1;
////	B p2;
////
////	A* ptr1 = &p1;
////	A* ptr2 = &p2;
////	ptr1->func();
////	ptr2->func();
////
////
////
////	return 0;
////
////}
//class Car
//{
//public :
//	virtual void  Drive() = 0;//´¿Ðéº¯Êý
//
//};
//
//class Bint : public Car
//{
//public:
//	void  Drive()
//	{
//		cout << "Bint ÊæÊÊ" << endl;
//	}
//};
//class BWM : public Car
//{
//public :
//	void Drive()
//	{
//		cout << "BWM ÉÌÎñ" << endl;
//	}
//
//};
//int main()
//{
//	Bint c1;
//	BWM c2;
//	Car* ptr1 = &c1;
//	Car* ptr2 = &c2;
//	ptr1->Drive();
//	ptr2->Drive();
//
//	return 0;
//}


#include <iostream>
//class A
//{
//public:
//	virtual void func1()
//	{
//		cout << "classA func1()" << endl;
//	}
//};
//class B : public A
//{
//public :
//	virtual void func1()
//	{
//		cout << "classB func1()" << endl;
//	}
//	virtual void func2()
//	{
//		cout << "classB func2()" << endl;
//	}
//};
//int main()
//{
//	A* ptr = new A;
//	A* ptr2 = new B;
//	ptr->func1();
//	ptr2->func1();
//
//	return 0;
//}

class A 
{ 
	public: void test(float a) { cout << a; } 
}; 
class B :public A 
{ 
	public: void test(int b) { cout << b; } 
};
void main() 
{ 
	A* a = new A; 
	B* b = new B; 
	a = b; 
	a->test(1.1); 
}