#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define PB push_back

using ll=long long;
using pii=pair<int,int>;
using vi=vector<int>;

int read(){
	int i;
	scanf("%d",&i);
	return i;
}

const int inf=1000000007;
struct Seg{
	int mn[1<<18],lz[1<<18],s;
	void Init(int n){
		s=1;
		while(s<n)s*=2;
		fill(mn,mn+s*2,0);
		fill(lz,lz+s*2,0);
	}
	int NodeMin(int i){
		return mn[i]+lz[i];
	}
	void Propagate(int i){
		lz[i*2]+=lz[i];
		lz[i*2+1]+=lz[i];
		mn[i]+=lz[i];
		lz[i]=0;
	}
	void Add(int b,int e,int l,int r,int i,int v){
		if(e<=l||r<=b)
			return;
		if(b<=l&&r<=e){
			lz[i]+=v;
			return;
		}
		Propagate(i);
		Add(b,e,l,(l+r)/2,i*2,v);
		Add(b,e,(l+r)/2,r,i*2+1,v);
		mn[i]=min(NodeMin(i*2),NodeMin(i*2+1));
	}
	void Add(int b,int e,int v){
		Add(b,e,0,s,1,v);
	}
	int Get(int b,int e,int l,int r,int i){
		if(e<=l||r<=b)
			return inf;
		if(b<=l&&r<=e)
			return NodeMin(i);
		Propagate(i);
		return min(Get(b,e,l,(l+r)/2,i*2),Get(b,e,(l+r)/2,r,i*2+1));
	}
	int Get(int b,int e){
		return Get(b,e,0,s,1);
	}
} seg;

const int Nmax=334893;
struct Pos{
	int x,y;
} ps[Nmax];
int n,m,k;

struct Query{
	int y,b,e,v;
	bool operator<(const Query& rhs)const{
		return y<rhs.y;
	}
} qs[Nmax];


pii GetRange(int y){
	int b=abs(y);
	int e=(n-1)+(m-1)-abs(y-((m-1)-(n-1)))+1;
	return pii(b,e);
}

bool Solve(int s){
	REP(i,k){
		qs[i*2]=Query{ps[i].y-s,max(0,ps[i].x-s),min(n+m,ps[i].x+s+1),1};
		qs[i*2+1]=Query{ps[i].y+s+1,max(0,ps[i].x-s),min(n+m,ps[i].x+s+1),-1};
	}
	qs[k*2]=Query{inf,0,0,0};
	sort(qs,qs+2*k+1);
	//for even
	{
		auto modify=[](int& v){
			if(v&1)v++;
		};
		seg.Init(n+m);
		int lastY=-(n-1);
		modify(lastY);
		REP(i,2*k+1){
			Query q=qs[i];
			modify(q.y);
			modify(q.b);
			modify(q.e);
			if(lastY<q.y){
				pii u=GetRange(lastY),b=GetRange(q.y-1);
				if(lastY<=0&&0<=q.y-1)
					u.first=0;
				if(lastY<=(m-1)-(n-1)&&(m-1)-(n-1)<=q.y-1)
					u.second=(m-1)+(n-1)+1;
				modify(u.first);
				modify(u.second);
				modify(b.first);
				modify(b.second);
				if(seg.Get(min(u.first,b.first)/2,max(u.second,b.second)/2)==0)
					return true;
			}
			seg.Add(q.b/2,q.e/2,q.v);
			lastY=q.y;
		}
	}
	//for odd
	{
		auto modify=[](int& v){
			if(!(v&1))v++;
		};
		seg.Init(n+m);
		int lastY=-(n-1);
		modify(lastY);
		REP(i,2*k+1){
			Query q=qs[i];
			modify(q.y);
			modify(q.b);
			modify(q.e);
			if(lastY<q.y){
				pii u=GetRange(lastY),b=GetRange(q.y-1);
				if(lastY<=0&&0<=q.y-1)
					u.first=0;
				if(lastY<=(m-1)-(n-1)&&(m-1)-(n-1)<=q.y-1)
					u.second=(m-1)+(n-1)+1;
				modify(u.first);
				modify(u.second);
				modify(b.first);
				modify(b.second);
				if(seg.Get(min(u.first,b.first)/2,max(u.second,b.second)/2)==0)
					return true;
			}
			seg.Add(q.b/2,q.e/2,q.v);
			lastY=q.y;
		}
	}
	return false;
}

int main(){
	n=read(),m=read(),k=read();
	REP(i,k){
		int x=read(),y=read();
		ps[i]=Pos{x+y,y-x};
	}
	int l=-1,r=n+m;
	while(r-l>1){
		int mid=(r+l)/2;
		if(Solve(mid))
			l=mid;
		else
			r=mid;
	}
	cout<<r<<endl;
}