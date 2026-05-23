#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#define int long long
#define mod 1000000007
#define for0(i, n) for(int i = 0; i < (n); i++)
#define for1(i, n) for(int i = 1; i <= (n);i++)
#define mp make_pair
using namespace std;
int a, b, c, d, m, n, ans;
int ar[234567];
string s;
bool b1, b2;
signed main() {
	cin >> m >> n;
	for1(i, n)cin >> ar[i];
	if (m == 2) {
		int ans1 = 0, ans2 = 0;
		for1(i, n) {
			if (ar[i] % 2 == i % 2) {
				ans1++;
			}
			else ans2++;
		}
		cout << min(ans1, ans2) << endl;
	}
	else {
		for1(i, n) {
			if (i > 1 && ar[i] == ar[i - 1]) {
				ans++; i++;
			}
		}
		cout << ans << endl;
	}
}
