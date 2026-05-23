#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bitset>
using namespace std;

int n, k, lt, rt, md, ans, a[5005];

int f(int p) {
	int i;
	bitset<5005> bs=1;
	if(a[p] >= k) return 1;
	for(i=0; i<n; i++) {
		if(i!=p) bs |= (bs << a[i]);
	}
	for(i=k-a[p]; i<k; i++) if(bs[i]) return 1;
	return 0;
}

int main() {
	cin >> n >> k;
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);
	rt = n;
	while(lt < rt) {
		md = (lt + rt) / 2;
		if(f(md)) rt= md;
		else lt = md+1;
	}
	cout << lt;
	return 0;
}
