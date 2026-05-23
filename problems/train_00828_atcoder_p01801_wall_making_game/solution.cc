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

const int M=21;
int h,w;
vs a;
int dp[M][M][M][M];

int Rec(int lx,int rx,int ly,int ry){
	if(lx==rx||ly==ry) return 0;
	if(dp[lx][rx][ly][ry]>=0) return dp[lx][rx][ly][ry];
	set<int> st;
	for(int i=lx;i<rx;i++) for(int j=ly;j<ry;j++) if(a[i][j]=='.'){
		st.insert(Rec(lx,i,ly,j)^Rec(lx,i,j+1,ry)^Rec(i+1,rx,ly,j)^Rec(i+1,rx,j+1,ry));
	}
	for(int i=0;;i++) if(st.find(i)==st.end()){
		dp[lx][rx][ly][ry]=i;
		break;
	}
	return dp[lx][rx][ly][ry];
}

int main(){
	for(int i=0;i<M;i++) for(int j=0;j<M;j++) for(int k=0;k<M;k++) fill(dp[i][j][k],dp[i][j][k]+M,-1);
	cin>>h>>w;
	a=vs(h);
	for(int i=0;i<h;i++) cin>>a[i];
	cout<<(Rec(0,h,0,w)?"First":"Second")<<endl;
}
