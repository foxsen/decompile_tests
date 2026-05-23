#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
using namespace std;
const int D_MAX_V=20002;
const int D_v_size=20002;
struct D_wolf{
	int t,c,r;
	D_wolf(){t=c=r=0;}
	D_wolf(int t1,int c1,int r1){
		t=t1;c=c1;r=r1;
	}
};
vector<D_wolf>D_G[D_MAX_V];
int D_level[D_MAX_V];
int D_iter[D_MAX_V];

void add_edge(int from,int to,int cap){
	D_G[from].push_back(D_wolf(to,cap,D_G[to].size()));
	D_G[to].push_back(D_wolf(from,0,D_G[from].size()-1));
}
void D_bfs(int s){
	for(int i=0;i<D_v_size;i++)D_level[i]=-1;
	queue<int> Q;
	D_level[s]=0;
	Q.push(s);
	while(Q.size()){
		int v=Q.front();
		Q.pop();
		for(int i=0;i<D_G[v].size();i++){
			if(D_G[v][i].c>0&&D_level[D_G[v][i].t]<0){
				D_level[D_G[v][i].t]=D_level[v]+1;
				Q.push(D_G[v][i].t);
			}
		}
	}
}
int D_dfs(int v,int t,int f){
	if(v==t)return f;
	for(;D_iter[v]<D_G[v].size();D_iter[v]++){
		int i=D_iter[v];
		if(D_G[v][i].c>0&&D_level[v]<D_level[D_G[v][i].t]){
			int d=D_dfs(D_G[v][i].t,t,min(f,D_G[v][i].c));
			if(d>0){
				D_G[v][i].c-=d;
				D_G[D_G[v][i].t][D_G[v][i].r].c+=d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t){
	int flow=0;
	for(;;){
		D_bfs(s);
		if(D_level[t]<0)return flow;
		for(int i=0;i<D_v_size;i++)D_iter[i]=0;
		int f;
		while((f=D_dfs(s,t,99999999))>0){flow+=f;}
	}
	return 0;
}

const double EPS = 1e-10;
double eps=1e-6;
const double INF = 1e+10;
const double PI = acos(-1);
int sig(double r) { return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0; }
inline double ABS(double a){return max(a,-a);}
struct Pt {
	double x, y;
	Pt() {}
	Pt(double x, double y) : x(x), y(y) {}
	Pt operator+(const Pt &a) const { return Pt(x + a.x, y + a.y); }
	Pt operator-(const Pt &a) const { return Pt(x - a.x, y - a.y); }
	Pt operator*(const Pt &a) const { return Pt(x * a.x - y * a.y, x * a.y + y * a.x); }
	Pt operator-() const { return Pt(-x, -y); }
	Pt operator*(const double &k) const { return Pt(x * k, y * k); }
	Pt operator/(const double &k) const { return Pt(x / k, y / k); }
	double ABS() const { return sqrt(x * x + y * y); }
	double abs2() const { return x * x + y * y; }
	double arg() const { return atan2(y, x); }
	double dot(const Pt &a) const { return x * a.x + y * a.y; }
	double det(const Pt &a) const { return x * a.y - y * a.x; }
};
inline bool operator< (const Pt&a,const Pt &b){
	int t=sig(b.x-a.x);
	if(t)return t>0;
	t=sig(b.y-a.y);
	return t>0;
}
double tri(const Pt &a, const Pt &b, const Pt &c) { return (b - a).det(c - a); }
int iCC(Pt a, double r, Pt b, double s) {
	double d = (b - a).ABS();
	if (sig(d) == 0 && sig(r - s) == 0) return -1; // correspond
	if (sig(r - s - d) > 0) return +2; // r > s
	if (sig(s - r - d) > 0) return -2; // s > r
	return (sig(r + s - d) >= 0) ? 1 : 0;
}
double dLP(Pt a, Pt b, Pt c) {
	return ABS(tri(a, b, c)) / (b - a).ABS();
}
pair<Pt,Pt> pCC(Pt a, double r, Pt b, double s) {
	double d = (b - a).ABS();
	double x = (d * d + r * r - s * s) / (d * 2);
	Pt e = (b - a) / d, w = e * Pt(0, 1) * sqrt(max(r * r - x * x, 0.0));
	return make_pair(a + e * x - w, a + e * x + w);
}
pair<Pt,Pt> pCL(Pt a, double r, Pt b, Pt c) {
	Pt h = b + (c - b) * (c - b).dot(a - b) / (c - b).abs2(); // perp(b, c, a)
	double d = (h - a).ABS();
	double y = sqrt(max(r * r - d * d, 0.0));
	Pt e = (c - b) / (c - b).ABS();
	return make_pair(h - e * y, h + e * y);
}

double x[30];
double y[30];
double r[30];
Pt p[30];
vector<Pt> v;

vector<int>now;
vector<pair<double,double> > seg;
int UF[1200];
int FIND(int a){
	if(UF[a]<0)return a;
	return UF[a]=FIND(UF[a]);
}
void UNION(int a,int b){
	a=FIND(a);b=FIND(b);if(a==b)return;UF[a]+=UF[b];UF[b]=a;
}
int to[1200];
int g[1200][1200];
int tg[1200][1200];
int tL[1200];
int L[1200];
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<1200;i++)UF[i]=-1;
	for(int i=0;i<a;i++)scanf("%lf%lf%lf",x+i,y+i,r+i);
	for(int i=0;i<a;i++){
		p[i]=Pt(x[i],y[i])*Pt(cos(1),sin(1));
	}
	p[a]=Pt(0,0);
	r[a]=1000000;
	//a++;
	//for(int i=0;i<a;i++)r[i]+=EPS;
	for(int i=0;i<a;i++){
		bool ok=true;
		for(int j=0;j<v.size();j++){
			if((p[i]-Pt(r[i],0)-v[j]).ABS()<eps)ok=false;
		}
		if(ok)v.push_back(p[i]-Pt(r[i],0));
		ok=true;
		for(int j=0;j<v.size();j++){
			if((p[i]+Pt(r[i],0)-v[j]).ABS()<eps)ok=false;
		}
		if(ok)v.push_back(p[i]+Pt(r[i],0));
	}
	for(int i=0;i<a;i++){
		for(int j=i+1;j<a;j++){
			if(iCC(p[i],r[i],p[j],r[j])==1){
				pair<Pt,Pt> tmp=pCC(p[i],r[i],p[j],r[j]);
				bool ok=true;
				for(int k=0;k<v.size();k++){
					if((v[k]-tmp.first).ABS()<eps)ok=false;
				}
				if(ok)v.push_back(tmp.first);
				ok=true;
				for(int k=0;k<v.size();k++){
					if((v[k]-tmp.second).ABS()<eps)ok=false;
				}
				if(ok)v.push_back(tmp.second);
			}
		}
	}
	std::sort(v.begin(),v.end());
	v.push_back(Pt(10000,0));
	seg.push_back(make_pair(-10000,10000));
	int sz=0;
	now.push_back(sz++);
	for(int i=0;i<v.size()-1;i++){
		int t=1;
	//	printf("%.12f %.12f\n",v[i].x,v[i].y);
		double mx=(v[i+1].x+v[i].x)/2;
		vector<double>tmp2;
		tmp2.push_back(-10000);
		tmp2.push_back(10000);
		for(int j=0;j<a;j++){
			if(dLP(Pt(mx,0),Pt(mx,1),p[j])<r[j]){
				t+=2;
				pair<Pt,Pt>sc=pCL(p[j],r[j],Pt(mx,0),Pt(mx,1));
				tmp2.push_back(sc.first.y);
				tmp2.push_back(sc.second.y);
			}
		}
		std::sort(tmp2.begin(),tmp2.end());
		vector<double>tmp;
		tmp.push_back(tmp2[0]);
		for(int j=1;j<tmp2.size();j++)tmp.push_back(tmp2[j]);
	//	t=tmp.size()-1;
		for(int j=0;j<now.size()-1;j++){
			tg[now[j]][now[j+1]]=tg[now[j+1]][now[j]]=1;
		}
	//	for(int j=0;j<seg.size();j++)printf("(%.12f, %.12f) ",seg[j].first,seg[j].second);printf("\n");
		if(t>now.size()){
			int at=-1;
			for(int j=0;j<tmp2.size()-1;j++)if(tmp2[j]<v[i].y&&tmp2[j+1]>v[i].y)at=j;
			at--;
	//		printf("%d\n",at);
			
			now.push_back(-1);
			now.push_back(-1);
			for(int j=now.size()-3;j>=at;j--){
				now[j+2]=now[j];
			}
			if(at%2==0)tL[sz]=1;
			now[at+1]=sz++;
		}else if(t<now.size()){
			int at=-1;
			for(int j=0;j<now.size();j++)if(seg[j].first<v[i].y&&v[i].y<seg[j].second)at=j;	
	//		printf("%d\n",at);
			UNION(now[at-1],now[at+1]);
			for(int j=at;j<now.size()-2;j++)now[j]=now[j+2];
			now.pop_back();now.pop_back();
		}else{
			int at=-1;
			for(int j=0;j<now.size();j++){
				int ci=-1;
				int cj=-1;
				for(int k=0;k<a;k++)if(ABS((Pt(mx,tmp2[j])-p[k]).ABS()-r[k])<eps)ci=k;
				bool ui=false;
				bool uj=false;
				if(v[i].y>p[ci].y)ui=true;
				for(int k=0;k<a;k++)if(ABS((Pt(mx,tmp2[j+1])-p[k]).ABS()-r[k])<eps)cj=k;
				if(v[i].y>p[cj].y)uj=true;
				if(!~ci||!~cj)continue;
				if(ABS((v[i]-p[ci]).ABS()-r[ci])<eps&&ABS((v[i]-p[cj]).ABS()-r[cj])<eps){
					if(ui&&tmp2[j]<p[ci].y)continue;
					if(uj&&tmp2[j+1]<p[cj].y)continue;
					if(!ui&&tmp2[j]>p[ci].y)continue;
					if(!uj&&tmp2[j+1]>p[cj].y)continue;
					
					at=j;
			//		printf("%d\n",j);
					if(at%2)tL[sz]=1;
					now[at]=sz++;
				}
			}
		}
		seg.clear();
		for(int j=0;j<tmp.size()-1;j++){
			seg.push_back(make_pair(tmp[j],tmp[j+1]));
		}
	//	for(int j=0;j<now.size();j++)printf("%d ",now[j]);
		//printf("\n");
	}
	
	int n=0;
	for(int i=0;i<sz;i++)if(UF[i]<0)to[i]=n++;
	for(int i=0;i<sz;i++)to[i]=to[FIND(i)];
	for(int i=0;i<sz;i++)L[to[i]]=tL[i];
	for(int i=0;i<sz;i++){
		for(int j=0;j<sz;j++){
			if(to[i]!=to[j])g[to[i]][to[j]]|=tg[i][j];
		}
	}
	//for(int i=0;i<sz;i++)printf("%d ",to[i]);
	//printf("\n");
	sz=n;
	if(b>=2){
		printf("%d\n",sz-1);return 0;
	}
	int S=sz*2;
	int T=sz*2+1;
	for(int i=0;i<sz;i++){
		if(to[0]==i)continue;
		if(L[i])add_edge(S,i,1);
		else add_edge(i+sz,T,1);
	}
	for(int i=0;i<sz;i++)for(int j=0;j<sz;j++){
		if(to[0]==i||to[0]==j)continue;
		if(L[i]&&g[i][j]){
			add_edge(i,j+sz,1);
		}
	}
	//printf("%d\n",sz);
	//for(int i=0;i<sz;i++){
	//	for(int j=0;j<sz;j++){
	//		printf("%d ",g[i][j]);
	//	}
	//	printf("\n");
//	}
	printf("%d\n",sz-1-max_flow(S,T));
}