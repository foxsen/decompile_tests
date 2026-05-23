#include<cstdio>
#include<cstring>
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<string>
#include<cmath>
#include<algorithm>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef pair<LL,LL> pa;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
const int MO=1e9+7;
int n,ts,top,tot,now;
vector<pa> v[22222];
LL pt,L,R,K,rch,ans,tmp[222],c[222],a[222],x[222],y[222];
pa stk[222];
struct node{
	LL w[200];
	node(){memset(w,0,sizeof(w));}
	bool operator < (const node & A) const{
		FOR(i,0,199)
			if (w[i]<A.w[i]) return 1;
			else if (w[i]>A.w[i]) return 0;
		return 0;
	}
};
LL bcm(LL x,LL y){
	LL ans=0;
	FOR(i,0,60)
		if ((y>>i)&1){
			if (y-(1ll<<i)>=x) y-=1ll<<i;
			else ++ans;
		}
	return ans;
}
map<node,int> M;
int main(){
	cin>>n>>K;
	FOR(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	tmp[0]=-1;
	FOR(j,0,60){
		FOR(i,1,n){
			x[i]=(a[i]>>j);
			y[i]=(a[i])%(1ll<<j);
			tmp[i]=y[i];
		}
		sort(tmp+1,tmp+n+1);
		ts=unique(tmp+1,tmp+n+1)-tmp-1;
		if (tmp[ts]!=(1ll<<j)-1) tmp[++ts]=(1ll<<j)-1;
		FOR(k,1,ts){
			FOR(i,1,n)
				if (tmp[k]<=y[i]) c[i]=x[i];
				else c[i]=x[i]-1;
			pt=bcm(tmp[k-1]+1,tmp[k])+j;
			if (pt>K) continue;
			node P;
			FOR(i,2,n) P.w[i-1]=c[i]-c[i-1];
			if (M.find(P)==M.end()) M[P]=++tot;
			now=M[P];
		//	tmp[k-1]+1~tmp[k]
			L=max(0ll,c[1]-(K-pt)),R=c[1];
			v[now].pb(mp(L,R));
		}
	}
	FOR(i,1,tot){
		top=0;
		for (int j=0;j<v[i].size();++j) stk[++top]=v[i][j];
		sort(stk+1,stk+top+1);
		rch=-1;
		FOR(j,1,top){
			if (stk[j].se<=rch) continue;
			if (stk[j].fi>rch) (ans+=stk[j].se-stk[j].fi+1)%=MO,rch=stk[j].se;
			else (ans+=stk[j].se-rch)%=MO,rch=stk[j].se;
		}
	}
	cout<<(ans+MO)%MO<<endl;
	return 0;
}
