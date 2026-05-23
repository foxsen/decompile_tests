#include <iostream>

int main()
{
	unsigned long long N=100, X;
	std::cin >> X;
	int i=0;
	while (N < X) {
		N *= 1.01;
		i++;
	}
    std::cout << i;
}