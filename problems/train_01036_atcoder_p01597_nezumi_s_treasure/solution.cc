#include<queue>
#include<cstdio>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

struct point{
	int x,y;
	point(){}
	point(int x,int y):x(x),y(y){}
	bool operator==(const point &a)const{ return x==a.x && y==a.y; }
};
bool cmp_point_1(const point &a,const point &b){ return a.x>b.x || a.x==b.x && a.y>b.y; } // (x,y) の降順
bool cmp_point_2(const point &a,const point &b){ return a.y<b.y || a.y==b.y && a.x<b.x; } // (y,x) の昇順
bool cmp_point_3(const point &a,const point &b){ return a.x<b.x || a.x==b.x && a.y<b.y; } // (x,y) の昇順
bool cmp_point_4(const point &a,const point &b){ return a.y>b.y || a.y==b.y && a.x>b.x; } // (y,x) の降順

class segment_tree_max{
	static const int N_MAX=3*4*40000;
	int n;
	int dat[2*N_MAX];
	void update_max(int l,int r,int a,int b,int u,int v){
		if(l<=a && b<=r){ dat[u]=max(dat[u],v); return; }
		int c=(a+b+1)/2;
		if(l<c && a<r) update_max(l,r,a,c,2*u,v);
		if(l<b && c<r) update_max(l,r,c,b,2*u+1,v);
	}
public:
	void build(int N,int val){
		for(n=1;n<N;n*=2);
		rep(u,2*n) dat[u]=val;
	}
	void update_max(int l,int r,int v){ update_max(l,r,0,n,1,v); }
	int query(int u){
		u+=n;
		int res=dat[u];
		for(u/=2;u>=1;u/=2) res=max(res,dat[u]);
		return res;
	}
};

class segment_tree_min{
	static const int N_MAX=3*4*40000;
	int n;
	int dat[2*N_MAX];
	void update_min(int l,int r,int a,int b,int u,int v){
		if(l<=a && b<=r){ dat[u]=min(dat[u],v); return; }
		int c=(a+b+1)/2;
		if(l<c && a<r) update_min(l,r,a,c,2*u,v);
		if(l<b && c<r) update_min(l,r,c,b,2*u+1,v);
	}
public:
	void build(int N,int val){
		for(n=1;n<N;n*=2);
		rep(u,2*n) dat[u]=val;
	}
	void update_min(int l,int r,int v){ update_min(l,r,0,n,1,v); }
	int query(int u){
		u+=n;
		int res=dat[u];
		for(u/=2;u>=1;u/=2) res=min(res,dat[u]);
		return res;
	}
};

struct event{
	int type,x1,x2,y1,y2;
	event(){}
	event(int type,int x1,int x2,int y1,int y2):type(type),x1(x1),x2(x2),y1(y1),y2(y2){}
};
bool cmp_event_1(const event &e,const event &f){ return e.y1<f.y1; }
bool cmp_event_2(const event &e,const event &f){ return e.y1>f.y1; }
bool cmp_event_3(const event &e,const event &f){ return e.x1<f.x1; }
bool cmp_event_4(const event &e,const event &f){ return e.x1>f.x1; }

int main(){
	int n; scanf("%d",&n);
	static int l[40000],t[40000],r[40000],b[40000];
	rep(i,n) scanf("%d%d%d%d",l+i,t+i,r+i,b+i);

	// 座標圧縮
	vector<int> X,Y;
	rep(i,n){
		X.push_back(l[i]); X.push_back(l[i]+1); X.push_back(l[i]-1);
		X.push_back(r[i]); X.push_back(r[i]+1); X.push_back(r[i]-1);
		Y.push_back(t[i]); Y.push_back(t[i]+1); Y.push_back(t[i]-1);
		Y.push_back(b[i]); Y.push_back(b[i]+1); Y.push_back(b[i]-1);
	}
	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());
	X.erase(unique(X.begin(),X.end()),X.end());
	Y.erase(unique(Y.begin(),Y.end()),Y.end());

	rep(i,n){
		l[i]=lower_bound(X.begin(),X.end(),l[i])-X.begin();
		r[i]=lower_bound(X.begin(),X.end(),r[i])-X.begin();
		t[i]=lower_bound(Y.begin(),Y.end(),t[i])-Y.begin();
		b[i]=lower_bound(Y.begin(),Y.end(),b[i])-Y.begin();
	}

	vector<point> P1,P2,P3,P4; // 答えの候補点

	// P1 : 障害物の右辺から下に進んでぶつかるケース
	{
		static segment_tree_max Seg1;
		Seg1.build(X.size(),-INF);
		vector<event> E;
		rep(i,n){
			E.push_back(event(0,r[i],-1,t[i],-1));
			E.push_back(event(1,l[i],r[i],b[i],-1));
		}
		sort(E.begin(),E.end(),cmp_event_1);
		rep(i,E.size()){
			int type=E[i].type;
			if(type==0){ // 縦の辺
				int x=E[i].x1;
				int res=Seg1.query(x);
				if(res>-INF){
					P1.push_back(point(x,res));
				}
			}
			else{ // 横の辺
				int y=E[i].y1,x1=E[i].x1,x2=E[i].x2;
				if(x1+1<=x2-1) Seg1.update_max(x1+1,x2,y); // 角をかすめても曲がらないため +1, -1 しておく
			}
		}
	}

	// P2 : 障害物の左辺から上に進んでぶつかるケース
	{
		static segment_tree_min Seg2;
		Seg2.build(X.size(),INF);
		vector<event> E;
		rep(i,n){
			E.push_back(event(0,l[i],-1,b[i],-1));
			E.push_back(event(1,l[i],r[i],t[i],-1));
		}
		sort(E.begin(),E.end(),cmp_event_2);
		rep(i,E.size()){
			int type=E[i].type;
			if(type==0){ // 縦の辺
				int x=E[i].x1;
				int res=Seg2.query(x);
				if(res<INF){
					P2.push_back(point(x,res));
				}
			}
			else{ // 横の辺
				int y=E[i].y1,x1=E[i].x1,x2=E[i].x2;
				if(x1+1<=x2-1) Seg2.update_min(x1+1,x2,y);
			}
		}
	}

	// P3 : 障害物の下辺から左に進んでぶつかるケース
	{
		static segment_tree_max Seg3;
		Seg3.build(Y.size(),-INF);
		vector<event> E;
		rep(i,n){
			E.push_back(event(0,l[i],-1,t[i],-1));
			E.push_back(event(1,r[i],-1,t[i],b[i]));
		}
		sort(E.begin(),E.end(),cmp_event_3);
		rep(i,E.size()){
			int type=E[i].type;
			if(type==0){ // 横の辺
				int y=E[i].y1;
				int res=Seg3.query(y);
				if(res>-INF){
					P3.push_back(point(res,y));
				}
			}
			else{ // 縦の辺
				int x=E[i].x1,y1=E[i].y1,y2=E[i].y2;
				if(y1+1<=y2-1) Seg3.update_max(y1+1,y2,x);
			}
		}
	}

	// P4 : 障害物の上辺から右に進んでぶつかるケース
	{
		static segment_tree_min Seg4;
		Seg4.build(Y.size(),INF);
		vector<event> E;
		rep(i,n){
			E.push_back(event(0,r[i],-1,b[i],-1));
			E.push_back(event(1,l[i],-1,t[i],b[i]));
		}
		sort(E.begin(),E.end(),cmp_event_4);
		rep(i,E.size()){
			int type=E[i].type;
			if(type==0){ // 横の辺
				int y=E[i].y1;
				int res=Seg4.query(y);
				if(res<INF){
					P4.push_back(point(res,y));
				}
			}
			else{ // 縦の辺
				int x=E[i].x1,y1=E[i].y1,y2=E[i].y2;
				if(y1+1<=y2-1) Seg4.update_min(y1+1,y2,x);
			}
		}
	}

	// P1 -> P2 -> P3 -> P4 (-> P1) の順に回るよう swap
	swap(P2,P4);
	swap(P3,P4);

	sort(P1.begin(),P1.end(),cmp_point_1);
	sort(P2.begin(),P2.end(),cmp_point_2);
	sort(P3.begin(),P3.end(),cmp_point_3);
	sort(P4.begin(),P4.end(),cmp_point_4);
	P1.erase(unique(P1.begin(),P1.end()),P1.end());
	P2.erase(unique(P2.begin(),P2.end()),P2.end());
	P3.erase(unique(P3.begin(),P3.end()),P3.end());
	P4.erase(unique(P4.begin(),P4.end()),P4.end());

	int m1=P1.size(),m2=P2.size(),m3=P3.size(),m4=P4.size(),m=m1+m2+m3+m4;
	vector< vector<int> > G(m);
	rep(i,m1){
		point q1=P1[i];
		int j=upper_bound(P2.begin(),P2.end(),q1,cmp_point_2)-P2.begin();
		if(j<P2.size() && P2[j].y==q1.y) G[i].push_back(m1+j);
	}
	rep(i,m2){
		point q2=P2[i];
		int j=upper_bound(P3.begin(),P3.end(),q2,cmp_point_3)-P3.begin();
		if(j<P3.size() && P3[j].x==q2.x) G[m1+i].push_back(m1+m2+j);
	}
	rep(i,m3){
		point q3=P3[i];
		int j=upper_bound(P4.begin(),P4.end(),q3,cmp_point_4)-P4.begin();
		if(j<P4.size() && P4[j].y==q3.y) G[m1+m2+i].push_back(m1+m2+m3+j);
	}
	rep(i,m4){
		point q4=P4[i];
		int j=upper_bound(P1.begin(),P1.end(),q4,cmp_point_1)-P1.begin();
		if(j<P1.size() && P1[j].x==q4.x) G[m1+m2+m3+i].push_back(j);
	}

	vector<int> deg(m);
	rep(u,m) rep(i,G[u].size()) deg[G[u][i]]++;

	int ans=m;
	queue<int> Q;
	rep(u,m) if(deg[u]==0) Q.push(u);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		ans--;
		rep(i,G[u].size()){
			int v=G[u][i];
			deg[v]--;
			if(deg[v]==0) Q.push(v);
		}
	}
	printf("%d\n",ans);

	return 0;
}