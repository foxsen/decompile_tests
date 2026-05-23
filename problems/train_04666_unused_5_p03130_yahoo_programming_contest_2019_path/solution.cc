#include <bits/stdc++.h>
using namespace std;
int main() {
	map<int,int> a;
	for (int i = 0; i < 3; ++ i) {
		int u,v;
		cin >> u >> v;
		++ a[u];
		++ a[v];
	}
	bool ok = true;
	for (auto p : a) {
		if (p.second >= 3) ok = false;
	}
	cout << (ok ? "YES" : "NO") << endl;
}
