#include <iostream>
#include <fstream>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#pragma comment(linker, "/STACK:400000000")

#define EPS 1e-9
#define INF MOD
#define MOD 1000000007LL
#define fir first
#define foreach(it,X) for(it=X.begin();it!=X.end();it++)
#define iss istringstream
#define ite iterator
#define ll long long
#define mp make_pair
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<n;i++)
#define pi pair<int,int>
#define pb push_back
#define sec second
#define sst stringstream
#define sz size()
#define vc vector
typedef vc<int> vi;
typedef vc<ll> vl;
typedef vc<string> vs;

int N;
string mark[10010];
int used[10010],nex[10010];
map<string,int> M;
vi ans;

void read(int cur){
	if(used[cur])return;
	ans.pb(cur);
	used[cur]=1;
	if(nex[cur]!=-1)read(nex[cur]);
}

int main(){
	while(cin>>N && N){
		rep(i,N)cin>>mark[i];
		fill(used,used+N,0);
		fill(nex,nex+N,-1);
		M.clear();
		ans.clear();
		
		rep(i,N){
			if(mark[i]=="-"){
				read(i);
			}else if(mark[i]=="v"){
				nex[i+1]=i;
			}else{
				string type;
				int number=0;
				int x=0;
				while(islower(mark[i][x])){
					type+=mark[i][x];
					x++;
				}
				while(x<mark[i].sz && isdigit(mark[i][x])){
					number=number*10+mark[i][x]-'0';
					x++;
				}
				if(M.find(type)!=M.end()){
					nex[i]=M[type];
				}
				if(number>1)M[type]=i;
				else M.erase(type);
				if(x<mark[i].sz)nex[i+1]=i;
				else if(number==1)read(i);
			}
		}
		
		rep(i,N)cout<<ans[i]+1<<endl;
	}
}