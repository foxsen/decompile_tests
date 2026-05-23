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
#include<cstdio>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double EPS=1e-10;
const int inf=1e8;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
int main(){
	int n,m;
	cin>>n>>m;
	vi in(m);
	rep(i,m)cin>>in[i];
	int ma=in[0]-1;
	rep(i,m-1){
		int q=in[i+1]-in[i];
		q/=2;
		ma=max(ma,q);
	}
	ma=max(ma,n-in[m-1]);
	cout<<ma<<endl;
}