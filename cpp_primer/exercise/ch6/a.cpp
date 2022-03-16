#include <iostream>

const std::string &f()
{
	return "a";
}

int main()
{
	std::cout << f() << std::endl; // Segmentation fault
	return 0;
}
