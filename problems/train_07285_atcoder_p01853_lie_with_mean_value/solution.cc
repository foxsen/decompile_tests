#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;

int main() {
	int n,m;
	cin >> n >> m;

	int cnt;
	if(n==1) {
		cout << m/2 << endl;
		return 0;
	}
	for(int i=0; i<=n/2; i++) {
		cout << 0 << ' ';
		cnt++;
	}
	for(int i=cnt; i<n-1; i++)
		cout << m << ' ';
	if(cnt < n) cout << m;
	cout << endl;

	return 0;
}