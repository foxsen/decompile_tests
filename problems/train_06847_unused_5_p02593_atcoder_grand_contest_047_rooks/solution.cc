#include<bits/stdc++.h>
using namespace std;
const int maxn=200009;

int n;
struct Point{
	int x,y,id;
	bool operator < (const Point &rhs) const{
		return x<rhs.x;
	}
}r[maxn];

int sy[maxn];

long long ans[maxn];
long long f[maxn][2];
vector<pair<int,int>>section;

int dist(int i,int j){
	return abs(r[i].x-r[j].x)+abs(r[i].y-r[j].y);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		r[i].id=i;scanf("%d%d",&r[i].x,&r[i].y);
		sy[i]=r[i].y;
	}
	sort(r+1,r+1+n);
	sort(sy+1,sy+1+n);sy[0]=0;sy[n+1]=1e9;
	
	for(int i=1;i<=n;++i)ans[i]=-1;
	for(int i=1;i<=n;++i){
		if(ans[r[i].id]!=-1)continue;
		int t=lower_bound(sy+1,sy+1+n,r[i].y)-sy;
		int t1=t-1,t2=t+1,L=i,R=i,predir=-1,dir;
		for(;;){
			int flag=0; 
			for(int i:{L-1,R+1}){
				if(i<=0||i>n)continue;
				if(r[i].y!=sy[t1]&&r[i].y!=sy[t2])continue;
				if(i==L-1){
					dir=r[i].y==sy[t1];
				}else{
					dir=r[i].y==sy[t2];
				}
				if(predir!=-1&&dir!=predir){
					section.push_back(pair<int,int>(L,R));
				}
				predir=dir;
				if(r[i].y==sy[t1])--t1;else ++t2;
				if(i==L-1)--L;else ++R;
				flag=1;
			}
			if(!flag)break;
		}
		section.push_back(pair<int,int>(L,R));
		
		int s=section.size();
		f[s-1][0]=f[s-1][1]=0;
		for(int i=s-1;i>=1;--i){
			int l1=section[i].first,r1=section[i].second;
			int l2=section[i-1].first,r2=section[i-1].second;
			f[i-1][0]=min(dist(l2,l1)+dist(l1,r1)+f[i][1],(r1==r2?dist(l1,l2):dist(l2,r1)+dist(r1,l1))+f[i][0]);
			f[i-1][1]=min(dist(r2,r1)+dist(r1,l1)+f[i][0],(l1==l2?dist(r1,r2):dist(r2,l1)+dist(l1,r1))+f[i][1]);
		}
		L=section[0].first;R=section[0].second;
		for(int i=L;i<=R;++i){
			int id=r[i].id;
			ans[id]=min(dist(i,R)+dist(R,L)+f[0][0],dist(i,L)+dist(L,R)+f[0][1])-(section[s-1].second-section[s-1].first);
		}
		section.clear();
	}
	
	for(int i=1;i<=n;++i)printf("%lld\n",ans[i]);
	
	return 0;
}