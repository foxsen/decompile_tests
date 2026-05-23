#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#define REP(i, n) for(long long i = 0; i < n; ++i)
#define ALL(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int main() {
	while(1) {
		int t, d, l;
		cin>>t>>d>>l;
		if(t==0&&d==0&&l==0) break;
		int buf = 0;
		int res = 0;
		REP(i, t - 1) {
			int x;
			cin>>x;
			if(x >= l) {
				buf = d - 1;
				res++;
			} else if(buf > 0) {
				++res;
				--buf;
			}
		}
		int x;
		cin>>x;
		cout<<res<<endl;
	}
}