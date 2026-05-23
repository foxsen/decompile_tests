#include<iostream>
using namespace std;
int main() {
	long long int a, b;
	int n,m;
	cin >> n;
	a = 0;
	for (int i = 1; i <= n; i++) {
		cin >> m;
		a = a + m;
	}
	cout << a / n << endl;
}
