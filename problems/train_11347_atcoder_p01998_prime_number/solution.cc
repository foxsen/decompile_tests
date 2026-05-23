#include <bits/stdc++.h>
using namespace std;
/*
bool isPrime(int x)
{
	test++;
	if(x < 2)
		return false;
	if(x == 2)
		return true;
	if(x % 2 == 0)
		return false;
	for(int i = 3; i * i <= x; i += 2)
	{
		if(x % i == 0)
			return false;
	}
	return true;
}
*/
vector<bool> prime(1e7 + 1, true);
void make_prime()
{
	prime[0] = prime[1] = false;
	for(int i = 2; i <= 1e7 + 10; i++)
	{
		if(prime[i])
		{
			for(int j = 2 * i; j <= 1e7 + 10; j += i)
				prime[j] = false;
		}
	}
}
int main()
{
	long n;
	cin >> n;
	int p = 2;
	int cnt = 0;
	make_prime();
	for(int q = 3; q <= n; q++)
	{
		if(prime[q] && prime[p + q] == true)
			cnt++;
	}
	cout << cnt * 2 << endl;
	return 0;
}

