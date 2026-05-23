#include <bits/stdc++.h>

#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)

#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=int(a)-1;i>=int(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)

#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))

template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0;}
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0;}

using namespace std;
using ll=long long;

const ll inf =1LL << 62;
const ll mod=1000000007LL;
const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};

int w,h,n;
int p[110];

int main(void){
	cin >> w >> h >> n;
	rep(i,n) cin >> p[i];
	int cx[2]={0,0},cy[2]={0,1},mode[2]={1,1};
	
	int ans=0;
	rep(i,n){
		switch(mode[p[i]]){
			case 1:
				cx[p[i]]+=1;
				break;
			case 2:
				cy[p[i]]+=1;	
				break;
			case 3:
				cx[p[i]]-=1;
				break;
		}
		if(cx[p[i]]==w-1-p[i] && mode[p[i]]==1) mode[p[i]]++;
		if(cy[p[i]]==h-1-p[i] && mode[p[i]]==2) mode[p[i]]++;
		if(abs(cx[1]-cx[0])+abs(cy[1]-cy[0])==1) ans++;
	}
	cout << ans << endl;
	return 0;
}