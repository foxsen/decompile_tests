#include<bits/stdc++.h>
using namespace std;

#define INF (int(1e9)+1)
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=100005;
int n,ans;
pii dat[maxn];
int pre[maxn],suf[maxn]; 

int main(){
	scanf("%d",&n);
	REP(i,n)scanf("%d%d",&dat[i].fst,&dat[i].snd);
	sort(dat+1,dat+1+n);
	pre[0]=INF;
	REP(i,n)pre[i]=min(pre[i-1],dat[i].snd);
	suf[n+1]=INF;
	for(int i=n;i>=1;i--)suf[i]=min(suf[i+1],dat[i].snd);
	REP(i,n){
		int cl=i==n?dat[n-1].fst:dat[n].fst,cr=min(pre[i-1],suf[i+1]);
		ans=max(ans,dat[i].snd-dat[i].fst+1+max(0,cr-cl+1));
	}
	REP(i,n){
		int cur=max(pre[i]-dat[i].fst+1,0);
		if(i<n)cur+=max(suf[i+1]-dat[n].fst+1,0);
		ans=max(ans,cur);
	}
	printf("%d\n",ans);
	return 0;
}