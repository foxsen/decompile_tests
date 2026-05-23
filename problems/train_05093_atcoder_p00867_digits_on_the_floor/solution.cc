#include<queue>
#include<cstdio>
#include<vector>
#include<complex>

#define	pb			push_back
#define	rep(i,n)	for(int i=0;i<n;i++)

using namespace std;

typedef	vector<bool>	vb;
typedef	vector<int>		vi;
typedef	vector<vb>		vvb;
typedef	vector<vi>		vvi;

typedef	complex<double>	Point;

enum {CCW=1,CW=-1,ON=0};
const double EPS=1e-9;

namespace std{
	bool operator <(const Point &a,const Point &b){
		return (real(a)==real(b))?(imag(a)<imag(b)):(real(a)<real(b));
	}
	bool operator >(const Point &a,const Point &b){
		return b<a;
	}
}

class Line:public vector<Point>{
public:
	Line(){}
	Line(const Point &a,const Point &b){
		pb(a),pb(b);
	}
};

class Segment:public Line{
public:
	Segment(){}
	Segment(const Point &a,const Point &b):Line(a,b){}
};

double cross(const Point &a,const Point &b){
	return real(a)*imag(b)-imag(a)*real(b);
}

int ccw(const Point &a,Point b,Point c){
	b-=a,c-=a;
	double rotdir=cross(b,c);
	if(rotdir>EPS)		return CCW;
	if(rotdir<-EPS)		return CW;
	return ON;
}

bool intersect(const Segment &s,const Segment &t){
	if(max(real(s[0]),real(s[1]))<min(real(t[0]),real(t[1]))
	|| max(real(t[0]),real(t[1]))<min(real(s[0]),real(s[1]))
	|| max(imag(s[0]),imag(s[1]))<min(imag(t[0]),imag(t[1]))
	|| max(imag(t[0]),imag(t[1]))<min(imag(s[0]),imag(s[1])))	return false;

	if(ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1])<=0
	&& ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1])<=0)	return true;
	return false;
}

vvi toConnectedComponents(const vvi &adj){
	int n=adj.size();
	vvi res;
	vb visited(n);
	rep(i,n)if(!visited[i]){
		vi comp;
		queue<int> qu; qu.push(i); visited[i]=true;
		while(!qu.empty()){
			int u=qu.front();	qu.pop();
			comp.pb(u);
			rep(j,adj[u].size()){
				int v=adj[u][j];
				if(!visited[v]){ qu.push(v); visited[v]=true; }
			}
		}
		res.pb(comp);
	}
	return res;
}

int main(){
	for(int n;scanf("%d",&n),n;){
		Segment s[1000];
		rep(i,n){
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			s[i]=Segment(Point(x1,y1),Point(x2,y2));
		}

		vvi adj(n);
		rep(i,n)rep(j,i){
			if(intersect(s[i],s[j])){
				adj[i].pb(j);
				adj[j].pb(i);
			}
		}

		int hist[10]={};
		vvi comps=toConnectedComponents(adj);
		rep(i,comps.size()){
			vi comp=comps[i];
			int num=comp.size();
			int degsum=0;
			rep(j,num)	degsum+=adj[comp[j]].size();

			if(num==1)	hist[1]++;
			else if(num==3){
				int mid;
				rep(j,3) if(adj[comp[j]].size()==2) mid=comp[j];
				int cnt=0;
				rep(j,3)if(comp[j]!=mid){
					if(s[mid][0]==s[comp[j]][0] || s[mid][0]==s[comp[j]][1]
					|| s[mid][1]==s[comp[j]][0] || s[mid][1]==s[comp[j]][1])	cnt++;
				}
				if(cnt==1)	hist[4]++;
				else		hist[7]++;
			}
			else if(num==4){
				if(degsum==6)	hist[3]++;
				else{
					int cnt=0;
					rep(j,4){
						int u=comp[j];
						rep(k,2){
							int v=adj[u][k];
							if(s[u][0]==s[v][0] || s[u][0]==s[v][1]
							|| s[u][1]==s[v][0] || s[u][1]==s[v][1])	cnt++;
						}
					}
					if(cnt==8)	hist[0]++;
					else		hist[9]++;
				}
			}
			else{	// num==5
				if(degsum==10)		hist[6]++;
				else if(degsum==12)	hist[8]++;
				else{
					Segment e1,e2;
					rep(j,5){
						if(adj[comp[j]].size()==1){
							e1=s[comp[j]];
							e2=s[adj[comp[j]][0]];
							break;
						}
					}
					if(e1[0]==e2[0])		swap(e1[0],e1[1]);
					else if(e1[0]==e2[1])	swap(e1[0],e1[1]),swap(e2[0],e2[1]);
					else if(e1[1]==e2[1])	swap(e2[0],e2[1]);

					if(cross(e1[1]-e1[0],e2[1]-e2[0])<-1+EPS)	hist[2]++;
					else	hist[5]++;
				}
			}
		}

		rep(i,10)	printf("%s%d",i?" ":"",hist[i]);
		putchar('\n');
	}

	return 0;
}