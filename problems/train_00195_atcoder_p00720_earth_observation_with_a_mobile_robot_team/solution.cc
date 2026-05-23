#include<cmath>
#include<queue>
#include<cstdio>
#include<string>
#include<cassert>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

#define sq(x)      ((x)*(x))
#define sqsum(x,y) (sq(x)+sq(y))

using namespace std;

struct path{ int n,t[1001],x[1001],y[1001]; };

struct event{ // ロボットの接触イベント
	double t;
	int u,v,io; // ロボット u と v が触れた(io=0)か離れた(io=1)か
	bool operator<(const event &e)const{ return t<e.t; }
};

vector<double> solve_quadratic_equation(double a,double b,double c){
	if(a==0) return vector<double>(0); // a==0 は 2 つのロボットが相対的にみて動いてないということだから, このときイベントは起こらない

	if(b*b-4*a*c<0) return vector<double>(0);
	vector<double> res(2);
	res[0]=(-b-sqrt(b*b-4*a*c))/(2*a);
	res[1]=(-b+sqrt(b*b-4*a*c))/(2*a);
	return res;
}

// パス P の時刻 t での位置を求める
void calc_point(const path &P,int t,int &x,int &y){
	x=P.x[0];
	y=P.y[0];
	rep(i,P.n-1){
		if(t<=P.t[i+1]){
			x+=(t-P.t[i])*P.x[i+1];
			y+=(t-P.t[i])*P.y[i+1];
			return;
		}
		x+=(P.t[i+1]-P.t[i])*P.x[i+1];
		y+=(P.t[i+1]-P.t[i])*P.y[i+1];
	}
	assert(0);
}

int R;

void calc_touch_points(const path &P,const path &Q,int u,int v,vector<event> &E){
	vector<int> t;
	t.insert(t.end(),P.t,P.t+P.n);
	t.insert(t.end(),Q.t,Q.t+Q.n);
	sort(t.begin(),t.end());
	t.erase(unique(t.begin(),t.end()),t.end());

	rep(k,t.size()-1){
		int x1,y1,x2,y2,x3,y3,x4,y4;
		calc_point(P,t[ k ],x1,y1);
		calc_point(P,t[k+1],x2,y2);
		calc_point(Q,t[ k ],x3,y3);
		calc_point(Q,t[k+1],x4,y4);

		int a=sqsum(x2-x1+x3-x4,y2-y1+y3-y4);
		int b=2*(x2-x1+x3-x4)*(x1-x3)+2*(y2-y1+y3-y4)*(y1-y3);
		int c=sqsum(x1-x3,y1-y3)-R*R;
		vector<double> sol=solve_quadratic_equation(a,b,c);
		if(sol.size()==2){
			if(0<=sol[0] && sol[0]<=1) E.push_back((event){t[k]+sol[0]*(t[k+1]-t[k]),u,v,0});
			if(0<=sol[1] && sol[1]<=1) E.push_back((event){t[k]+sol[1]*(t[k+1]-t[k]),u,v,1});
		}
	}
}

int main(){
	for(int n,T;scanf("%d%d%d",&n,&T,&R),n;){
		char s[100][9];
		path P[100];
		rep(i,n){
			scanf("%s",s[i]);
			int m=0,t,x,y;
			while(1){
				scanf("%d%d%d",&t,&x,&y);
				P[i].t[m]=t;
				P[i].x[m]=x;
				P[i].y[m]=y;
				m++;
				if(t==T) break;
			}
			P[i].n=m;
		}

		vector<event> E;
		rep(j,n) rep(i,j) calc_touch_points(P[i],P[j],i,j,E);

		sort(E.begin(),E.end());

		bool ans[100]={true};
		bool adj[100][100]={}; // ロボット i と j が通信できるかどうか
		// 初期状態を計算
		rep(i,n) rep(j,n) if(i!=j && sqsum(P[i].x[0]-P[j].x[0],P[i].y[0]-P[j].y[0])<=R*R) {
			adj[i][j]=adj[j][i]=true;
		}
		rep(_,n) rep(i,n) rep(j,n) if(adj[i][j]) {
			ans[i]|=ans[j];
			ans[j]|=ans[i];
		}
		// シミュレーション
		queue<int> Q;
		rep(i,E.size()){
			event e=E[i];
			int u=e.u,v=e.v;
			if(e.io==0){
				adj[u][v]=adj[v][u]=true;

				if(ans[u]==ans[v]) continue;
				// ans[u]!=ans[v] のとき
				// BFS でロボット 0 の情報を広める
				int tar=(ans[u]?v:u);
				ans[tar]=true;
				assert(Q.empty());
				Q.push(tar);
				while(!Q.empty()){
					int w=Q.front(); Q.pop();
					rep(x,n) if(adj[w][x] && !ans[x]) { ans[x]=true; Q.push(x); }
				}
			}
			else{
				adj[u][v]=adj[v][u]=false;
			}
		}

		vector<string> s_ans;
		rep(i,n) if(ans[i]) s_ans.push_back(s[i]);
		sort(s_ans.begin(),s_ans.end());
		rep(i,s_ans.size()) puts(s_ans[i].c_str());
	}

	return 0;
}