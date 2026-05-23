#include<bits/stdc++.h>
using namespace std;

typedef pair<long long,int> P;

int n;
vector<long long> bit(200010,0);
void add(int a, int w) {
	for (int x = a;x <= n;x += x&-x) bit[x] += w;
}
int sum(int a) {
	int ret = 0;
	for (int x = a;x > 0;x -= x&-x) ret += bit[x];
	return ret;
}

int main() {
	int k;
	long long ans = 0;
	vector<int> s;
	cin >> n >> k;
	vector<P> a(n+1);
	for (int i = 1;i <= n;++i) {
		cin >> a[i].first;
		a[i].first -= k;
		a[i].second = i;
	}
	a[0] = P(0,0);
	for (int i = 0;i < n;++i) a[i+1].first += a[i].first;
	
	sort(a.begin(),a.end());

	n++;
	for (int i = n;i > 0;--i) {
		ans += sum(n)-sum(a[i-1].second+1);
		add(a[i-1].second+1,1);
	}

	cout << ans << endl;
		
	return 0;
}