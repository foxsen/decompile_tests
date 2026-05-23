#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define INF         1e9
#define EPS         1e-9
#define REP(i,n)    for(lint i=0,i##_len=(n);i<i##_len;++i)
#define REP1(i,n)   for(lint i=1,i##_len=(n);i<=i##_len;++i)
#define REPR(i,n)   for(lint i=(n)-1;i>=0;--i)
#define REPR1(i,n)  for(lint i=(n);i>0;--i)
#define REPC(i,obj) for(auto i:obj)
#define R_UP(a,b)   (((a)+(b)-1)/(b))
#define ALL(obj)    (obj).begin(),(obj).end()
#define SETP        cout << fixed << setprecision(8)
using namespace std;
using lint = long long;
template<typename T = lint>inline T in() { T x; cin >> x; return x; }

signed main() {
	int n = in();
	cout << "0:" << endl;
	REP1(i, pow(2, n) - 1) {
		cout << i << ':';
		int i_copy = i;
		for (int j = 0; i_copy > 0; ++j) {
			if (i_copy % 2 == 1)cout << ' ' << j;
			i_copy >>= 1;
		}
		cout << endl;
	}
}
