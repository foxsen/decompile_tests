#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

int n,m,res=0;
vi s;
vvi g;

int dfs(int v,int p){
	vi a,b;
	for(auto u:g[v]) if(u!=p){
		a.push_back(dfs(u,v));
		b.push_back((s[u]>=m?1:0));
		s[v]+=s[u];
	}
	if(a.empty()) return 0;
	int sum=0,N=b.size(),tmp=0;
	for(auto i:b) sum+=i;
//	cout<<a[0]<<' '<<b[0]<<endl;
	for(int i=0;i<N;i++) tmp=max(tmp,sum-b[i]+a[i]);
//	cout<<tmp<<endl;
	res=max(res,tmp+(n-s[v]>=m?1:0));
	vi c(N);
	for(int i=0;i<N;i++) c[i]=a[i]-b[i];
	if(N>=2){
		sort(c.rbegin(),c.rend());
		res=max(res,sum+c[0]+c[1]+(n-s[v]>=m?1:0));
	}
//	cout<<v+1<<' '<<tmp<<endl;
	return max(tmp,sum);
}

int main(){
	cin>>n>>m;
	g=vvi(n);
	s=vi(n,1);
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		u--,v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0,-1);
	cout<<res<<endl;
}
