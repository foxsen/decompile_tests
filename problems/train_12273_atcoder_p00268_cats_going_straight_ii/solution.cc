#include <bits/stdc++.h>

#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)
#define _all(arg) begin(arg),end(arg)

template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0;}
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0;}

using namespace std;
using R=long double;
using edge=tuple<R,int>;

const int limit=310;
int x[limit],y[limit];

int main(void){
	int n,m;
	while(cin >> n >> m,n){
		rep(i,n) cin >> x[i] >> y[i];

		vector<edge> graph[limit];
		vector<int> used[limit];

		rep(i,m){
			int s,t;
			cin >> s >> t;
			s--,t--;
			graph[s].push_back(make_tuple(atan2(y[t]-y[s],x[t]-x[s]),t));
			used[s].push_back(-1);
			graph[t].push_back(make_tuple(atan2(y[s]-y[t],x[s]-x[t]),s));
			used[t].push_back(-1);
		}

		rep(v,n) sort(_all(graph[v]));
		
		int all=0;
		rep(v,n){
			rep(i,graph[v].size()){
				if(used[v][i]!=-1) continue;
				
				int cur=v,idx=i;
				do{
					used[cur][idx]=all;
					int nxt=get<1>(graph[cur][idx]),nidx=0;
					rep(j,graph[nxt].size()) if(get<1>(graph[nxt][j])==cur) nidx=(j+1)%int(graph[nxt].size());
					cur=nxt,idx=nidx;
				}while(cur!=v);
				all++;
			}
		}
	
		int dual[limit][limit];
		rep(i,all)rep(j,all) dual[i][j]=(i==j)?0:(1<<20);

		int outer=used[min_element(x,x+n)-x][0];
		
		rep(v,n){
			rep(i,graph[v].size()){
				int v2=get<1>(graph[v][i]),j=0;
				while(get<1>(graph[v2][j])!=v) j++;

				dual[used[v][i]][used[v2][j]]=1;
				dual[used[v2][j]][used[v][i]]=1;
			}
		}

		rep(k,all)rep(i,all)rep(j,all) chmin(dual[i][j],dual[i][k]+dual[k][j]);
		int ans=1;
		rep(v,all) chmax(ans,dual[outer][v]);
		cout << ans << endl;
	}		
	return 0;
}