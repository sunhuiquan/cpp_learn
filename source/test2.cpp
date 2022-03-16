int main()
{
	// 	goto end; // wrong 控制传输跳过的实例化:
	// 	int a = 1;
	// end:
	// 	a = 2;
	// 	return 0;

	goto end; // right
	int a;
	a = 1;
end:
	a = 2;
	return 0;
}