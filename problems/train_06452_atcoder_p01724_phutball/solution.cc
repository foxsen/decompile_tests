// g++ -std=c++11 a.cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<random>
#include<cstring>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<sstream>
#include<iomanip>
#include<assert.h>
#include<typeinfo>
#define loop(i,a,b) for(ll i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
//#define int ll
typedef int Def;
//typedef ll Def;
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
//typedef tuple<int,int,int> tp;
//typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
//template<class C>constexpr int size(const C &c){return (int)c.size();}
//template<class T,size_t N> constexpr int size(const T (&xs)[N])noexcept{return (int)N;}
const double PI=acos(-1);
const double EPS=1e-9;
Def inf = sizeof(Def) == sizeof(long long) ? 2e18 : 1e9+10;
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={1,0,-1,0,1,-1,1,-1};
int n=19,m=15;
vs in(n);
int t=inf;
void dfs(int x,int y,int c){
	rep(i,8){
		int nx=x+dx[i],ny=y+dy[i];
		int co=0;
		while(nx>=0&&nx<19&&ny>=0&&ny<15&&in[nx][ny]=='X'){
			in[nx][ny]='.';
			co++;
			nx+=dx[i];
			ny+=dy[i];
		}
		if(co&&nx<=18&&ny>=0&&ny<=14)dfs(nx,ny,c+1);
		
		if(co&&(nx==18&&ny>=0&&ny<15)||nx>18){
			t=min(t,c+1);
		}
		nx-=dx[i],ny-=dy[i];
		while(nx!=x||ny!=y){
			in[nx][ny]='X';
			nx-=dx[i];ny-=dy[i];
		}
	}
}
int main(){
	rep(i,n)cin>>in[i];
	rep(i,n)rep(j,m)if(in[i][j]=='O'){
		dfs(i,j,0);
		in[i][j]='.';
		if(t==inf)t=-1;
		cout<<t<<endl;
		return 0;
	}
}





