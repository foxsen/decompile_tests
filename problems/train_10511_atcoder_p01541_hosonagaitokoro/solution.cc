#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int dist;
  cin>>dist;
  Int n;
  cin>>n;
  vector<Int> s(n);
  for(Int i=0;i<n;i++) cin>>s[i];
  Int m;
  cin>>m;
  vector<Int> d(m);
  for(Int i=0;i<m;i++) cin>>d[i];

  const Int INF = 1e17;
  Int t[10][10];
  Int ans=INF;
  auto check=
    [&]()->Int{
      struct edge{
	Int from,to,cost;
	edge(Int from,Int to,Int cost):from(from),to(to),cost(cost){}
      };
      vector<edge> es;
      
      for(Int i=1;i<n;i++){
	// p[i-1] + 1 <= p[i]
	// p[i-1] - p[i] <= -1
	es.emplace_back(i,i-1,-1);
      }
      for(Int i=0;i<n;i++){
	for(Int j=i+1;j<n;j++){
	  // j catch up i at t[i][j]
	  if(t[i][j]>m) continue;
	  if(t[i][j]==m){
	    // dist * s[i] + p[i] <= dist * s[j] + p[j]
	    // p[i] - p[j] <= dist * s[j] - dist * s[i]	    
	    es.emplace_back(j,i,dist*(s[j]-s[i]));
	    continue;
	  }
	  Int x=d[t[i][j]];
	  // x * s[i] + p[i] == x * s[j] + p[j]
	  
	  // x * s[i] + p[i] <= x * s[j] + p[j]	  
	  // p[i] - p[j] <= x * s[j] - x * s[i]
	  es.emplace_back(j,i,x*(s[j]-s[i]));
	  // x * s[i] + p[i] >= x * s[j] + p[j]
	  // p[j] - p[i] <= x * s[i] - x * s[j]
	  es.emplace_back(i,j,x*(s[i]-s[j]));
	}
      }
      
      vector<Int> p(n,INF);
      // minimize p[n-1] - p[0]
      // maximize p[0] - p[n-1]
      p[n-1] = 0;
      Int flg=1;
      for(Int t=0;t<n*3;t++){
	flg=0;
	for(auto e:es){
	  if(p[e.from]+e.cost<p[e.to]){
	    p[e.to]=p[e.from]+e.cost;
	    flg=1;	    
	  }
	}
      }
      if(flg) return -1;      
      vector<Int> z(n);
      for(Int i=0;i<n;i++) z[i]=p[i]-p[0];
      
      for(Int i=0;i<m;i++){
	map<Int, Int> cnt;
	for(Int j=0;j<n;j++)
	  cnt[d[i]*s[j]+z[j]]++;
	for(auto p:cnt) if(p.second>2) return -2;
      }
      
      Int res=0;
      for(Int i=0;i<n;i++) chmax(res,dist*s[i]+z[i]);
      return res;
    };

  using P = pair<Int, Int>;
  vector<P> vp;
  for(Int i=0;i<n;i++)
    for(Int j=i+1;j<n;j++)
      vp.emplace_back(i,j);
  
  for(Int i=0;i<n;i++)
    for(Int j=0;j<n;j++)
      t[i][j]=m+1;
  
  function<void(Int)> dfs=
    [&](Int x){
      Int res=check();
      if(res==-1) return;
      if(x==(Int)vp.size()){
	if(res>=0) chmin(ans,res);
	return;
      }
      for(Int i=0;i<=m;i++){
	t[vp[x].first][vp[x].second]=i;
	dfs(x+1);
	t[vp[x].first][vp[x].second]=m+1;
      }
    };
  
  dfs(0);
  cout<<ans<<endl;
  return 0;
}

