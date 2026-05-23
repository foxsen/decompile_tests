#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
const double EPS = 1e-9;
typedef pair<int, int> P;
typedef unsigned int ui;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
struct ant { int loc; char dir; };
ant a[20]; int n, l; int memo;
void move() {
	bool f = true;
	rep(i, n) {
		if (a[i].loc == 1) {
			memo = i; f = false;
		}
		else if (a[i].loc == l - 1 && f) {
			memo = i;
		}
	}
	rep(i, n) {
		if (a[i].loc == 0 || a[i].loc == l)continue;
		if (a[i].dir == 'R')a[i].loc++;
		else a[i].loc--;
	}
	rep(i, n) {
		if (a[i].loc == 0 || a[i].loc == l)continue;
		Rep(j, i + 1, n) {
			if (a[i].loc == a[j].loc)swap(a[i].dir, a[j].dir);
		}
	}
	return;
}
bool antfall() {
	rep(i, n) {
		if (a[i].loc != 0 && a[i].loc != l)return false;
	}
	return true;
}
int main() {
	while (cin >> n >> l, n) {
		char d; int p;
		rep(i, n) {
			cin >> d >> p;
			a[i] = { p,d };
		}
		int turn;
		for (turn = 1; turn < 105; turn++) {
			move();
			if (antfall())break;
		}
		cout << turn << " " << memo+1 << endl;
	}
	return 0;
}
