#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define rep(a,b,c) for (int a=b;a<=c;a++)
#define per(a,b,c) for (int a=b;a>=c;a--)
#define go(u) for (int o=ft[u],v;v=E[o].t;o=E[o].n)
#define fi first
#define se second
#define mp make_pair
using namespace std;
typedef long long LL;
typedef pair<int,int> par;
const int N=200010;
int n,a[N],x,y;
struct nod{
	par l,r;
	int s;
}tr[N<<2];
#define ___ int t=1,int l=1,int r=n
#define mid ((l+r)>>1)
#define ls t<<1,l,mid
#define rs t<<1|1,mid+1,r
nod operator + (nod x,nod y){
	if (x.s) swap(y.l,y.r);
	x.l=min(x.l,y.l);
	x.r=min(x.r,y.r);
	x.s^=y.s;
	return x;
}
void bui(___){
	if (l==r){
		tr[t]=(nod){(par){a[l],l},(par){n+233,0},1};
		return;
	}
	bui(ls),bui(rs),tr[t]=tr[t<<1]+tr[t<<1|1];
}
nod ask(___){
	if (x<=l&&y>=r) return tr[t];
	if (y<=mid) return ask(ls);
	if (x>mid) return ask(rs);
	return ask(ls)+ask(rs);
}
struct dat{
	int k,l,r;
};
bool operator < (dat x,dat y){return x.k>y.k;}
priority_queue <dat> q;
void __(int l,int r){
	nod tmp;
	x=l,y=r,tmp=ask();
	q.push((dat){tmp.l.fi,l,r});
}
void push(int l,int r){
	nod tmp;
	x=l,y=r,tmp=ask();
	int xi=tmp.l.se;
	x=xi+1,tmp=ask();
	int yi=tmp.l.se;
	printf("%d %d ",a[xi],a[yi]);
	if (l<xi-1) __(l,xi-1);
	if (xi+1<yi-1) __(xi+1,yi-1);
	if (yi+1<r) __(yi+1,r);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",a+i);
	bui();
	push(1,n);
	while (!q.empty()){
		dat t=q.top();
		q.pop();
		push(t.l,t.r);
	}
	return 0;
}
