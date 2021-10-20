#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int a = 1;

	const int &r1 = a;
	const long &r2 = (long)a;

	cout << "未发生类型转换，const引用绑定的是一个 int 左值变量: " << r1 << endl;
	cout << "发生类型转换，const引用绑定的是一个 long 临时右值常量: " << r2 << endl;
	a = 2;
	cout << "绑定的就是那个左值变量: " << r1 << endl;
	cout << "绑定的右值和原来那个变量一点关系都没有: " << r2 << endl;

	return 0;
}