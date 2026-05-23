#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdio>
#include<sstream>
#include<iomanip>
#include<assert.h>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
typedef int Def;
typedef pair<Def,Def> pii;
typedef vector<Def> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<Def,pii> pip;
typedef vector<pip>vip;
//#define mt make_tuple
//typedef tuple<double,int,double> tp;
//typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
const double PI=acos(-1);
const double EPS=1e-7;
Def inf=sizeof(Def)==sizeof(long long)?2e18:1e9;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int n,m;
int out;
vi in;
vvi G;
int dfs(int a){
	int t=inf;
	rep(i,G[a].size()){
		t=min(t,dfs(G[a][i]));
	}
	if(t==inf)t=0;
	t++;
	if(t<=m&&in[a])out++;
	return t;
}
int main(){
	out=0;
	cin>>n>>m;
	in=vi(n);
	rep(i,n)cin>>in[i];
	G=vvi(n);
	rep(i,n)if(in[i]){
		G[in[i]-1].pb(i);
	}
	rep(i,n)if(!in[i]){
		out++;
		dfs(i);
	}
	cout<<out<<endl;
}




/*
vi G;
vvi rG;
int out;
int n,k;
int dfs(int a){
	int t=inf;
	rep(i,rG[a].size())t=min(t,dfs(rG[a][i]));
	if(t==inf)t=0;
	t++;
	if(t<=k&&G[a])out++;
	return t;
}
int main(){
	cin>>n>>k;
	G=vi(n);
	rep(i,n)cin>>G[i];
	rG=vvi(n);
	rep(i,n)if(G[i])rG[G[i]-1].pb(i);
	out=0;
	rep(i,n)if(!G[i]){
		out++;
		dfs(i);
	}
	cout<<out<<endl;
}
*/