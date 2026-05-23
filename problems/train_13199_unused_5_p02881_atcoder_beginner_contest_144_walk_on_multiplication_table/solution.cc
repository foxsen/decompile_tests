# include <bits/stdc++.h>
using namespace std;
int main(){
	long long n , res = 1e15;
	cin >> n;
	for(long long i = 1; i * i <= n; i ++)
		if(n % i == 0)
			res = min(res , i + n / i - 2);
	cout << res << "\n";
}