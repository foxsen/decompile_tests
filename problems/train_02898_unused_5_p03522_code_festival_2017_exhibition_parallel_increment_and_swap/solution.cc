#include<bits/stdc++.h>
using namespace std;
#define REP(i,st,ed) for(register int i=st,i##end=ed;i<=i##end;++i)
#define DREP(i,st,ed) for(register int i=st,i##end=ed;i>=i##end;--i)
typedef long long ll;
template<typename T>inline bool chkmin(T &x,T y){return (y<x)?(x=y,1):0;}
template<typename T>inline bool chkmax(T &x,T y){return (y>x)?(x=y,1):0;}
inline int read(){
	int x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') f=-1,c=getchar();
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1)+(x<<3)+(c^'0');
	return x*f;
}
inline ll readll(){
	ll x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') f=-1,c=getchar();
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1ll)+(x<<3ll)+(c^'0');
	return x*f;
}
const int maxn=2e5+10,inf=0x3f3f3f3f;
int idx[maxn],idx_cnt,a[maxn];
struct Segment_tree{
	int Min[maxn<<2],tag[maxn<<2];
	inline void push_down(int x){
		if(tag[x]){
			Min[x<<1]+=tag[x];
			Min[x<<1|1]+=tag[x];
			tag[x<<1]+=tag[x];
			tag[x<<1|1]+=tag[x];
			tag[x]=0;
		}
	}
	inline void push_up(int x){
		Min[x]=min(Min[x<<1],Min[x<<1|1]);
	}
	void build_tree(int x,int L,int R){
		if(L==R){
			Min[x]=idx[L];
			return;
		}
		int Mid=(L+R)>>1;
		build_tree(x<<1,L,Mid),build_tree(x<<1|1,Mid+1,R);
		push_up(x);
	}
	void update(int x,int L,int R,int ql,int qr,int v){
		if(ql>qr) return;
		if(ql<=L && R<=qr){
			tag[x]+=v,Min[x]+=v;
			return;
		}
		int Mid=(L+R)>>1;
		push_down(x);
		if(ql<=Mid) update(x<<1,L,Mid,ql,qr,v);
		if(qr>Mid) update(x<<1|1,Mid+1,R,ql,qr,v);
		push_up(x);
	}
	int query(int x,int L,int R,int ql,int qr){
		if(ql<=L && R<=qr) return Min[x];
		int Mid=(L+R)>>1,res=inf;
		push_down(x);
		if(ql<=Mid) chkmin(res,query(x<<1,L,Mid,ql,qr));
		if(qr>Mid) chkmin(res,query(x<<1|1,Mid+1,R,ql,qr));
		push_up(x);
		return res;
	}
}Seg;

ll ans;
int main(){
	int n=read();
	REP(i,1,n) a[i]=read();
	REP(i,1,n) idx[++idx_cnt]=a[i];
	sort(idx+1,idx+idx_cnt+1);
	idx_cnt=unique(idx+1,idx+idx_cnt+1)-idx-1;
	Seg.build_tree(1,1,idx_cnt);
	REP(i,1,n){
		int u=lower_bound(idx+1,idx+idx_cnt+1,a[i])-idx;
		ans+=Seg.query(1,1,idx_cnt,u,idx_cnt)-a[i];
		Seg.update(1,1,idx_cnt,1,u-1,1);
	}
	printf("%lld\n",ans);
	return 0;
}
