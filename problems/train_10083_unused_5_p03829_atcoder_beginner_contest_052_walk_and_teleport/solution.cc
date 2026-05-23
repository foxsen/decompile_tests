#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, a, b; cin >> n >> a >> b;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	long long ans = 0;
	for(int i = 0; i < n - 1; i++) ans += min(1ll * (v[i + 1] - v[i]) * a, 1ll * b);
	cout << ans << endl;
	return 0;
}
