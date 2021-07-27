#include <iostream>

void func(const int &cri, int &ri)
{
	std::cout << cri << std::endl;
	ri = 2;
	std::cout << cri << std::endl;
}

int main()
{
	int i = 1;
	const int &cr_i = i;
	std::cout << cr_i << std::endl;

	i = 2;
	std::cout << cr_i << "\n"
			  << std::endl;

	double d = 1.1;
	const int &cr_d = d;
	std::cout << cr_d << std::endl;

	d = 2.2;
	std::cout << cr_d << "\n"
			  << std::endl;

	short s = 1;
	const int &cr_s = s;
	std::cout << cr_s << std::endl;

	s = 2;
	std::cout << cr_s << "\n"
			  << std::endl;

	long l = 1;
	const int &cr_l = l;
	std::cout << cr_l << std::endl;

	l = 2;
	std::cout << cr_l << "\n"
			  << std::endl;

	return 0;
}