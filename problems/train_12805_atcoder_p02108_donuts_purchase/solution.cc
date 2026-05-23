#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vec;
typedef vector<vec> mat;
  
void dfs(mat &G,vec &vd,int pos){
  if(vd[pos])return;
  vd[pos]=1;
  for(int i=0;i<(int)G[pos].size();i++){
    dfs(G,vd,G[pos][i]);
  }
}
  
void solve(mat &G,vec &c){
  int V=G.size();
  vec vd(V, 0);
  dfs(G,vd,0);
      
  vec X;
  mat nG;
  vec nc;
  for(int i=0;i<V;i++){
    if(vd[i]){
      X.push_back(i);
      nc.push_back(c[i]);
    }
  }
  
  nG.resize(X.size());
  for(int from=0;from<V;from++){
    for(int i=0;i<(int)G[from].size();i++){
      int to=G[from][i];
      if(vd[from]==0||vd[to]==0)continue;
      int nfrom=lower_bound(X.begin(),X.end(),from)-X.begin();
      int nto=lower_bound(X.begin(),X.end(),to)-X.begin();
      nG[nfrom].push_back(nto);
    }
  }
  
  G=nG;
  c=nc;
}
  
void scc_rdfs(mat &rG,vec &vd,vec &cmp,int pos,int k){
  if(vd[pos])return;
  vd[pos]=1;
  cmp[pos]=k;
  for(int i=0;i<(int)rG[pos].size();i++){
    scc_rdfs( rG,vd,cmp,rG[pos][i],k);
  }
}
  
void scc_dfs(mat &G,vec &vd,vec &vs,int pos){
  if(vd[pos])return;
  vd[pos]=1;
  for(int i=0;i<(int)G[pos].size();i++)
    scc_dfs(G,vd,vs,G[pos][i]);
  vs.push_back(pos);
}
  
vec scc(mat G){
  int V=G.size();
  mat rG(V);
  for(int from=0;from<V;from++){
    for(int i=0;i<(int)G[from].size();i++){
      int to=G[from][i];
      rG[to].push_back(from);
    }
  }
    
  vec vd(V,0), vs, cmp(V,0);
  for(int i=0;i<V;i++)
    if(vd[i]==0)scc_dfs(G,vd,vs,i);
  
  vd= vec(V,0);
  
  for(int i=V-1;i>=0;i--)
    if(vd[ vs[i] ]==0)scc_rdfs(rG,vd,cmp, vs[i] , vs[i] );
    
  return cmp;
}
  
int main(){
  int n,m;
  cin>>n>>m;
  vector<int> c(n*2, 0);
  vector< vector<int> > G;
  G.resize(n*2);
  for(int i=0;i<n;i++)cin>>c[i];
    
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    G[a].push_back(n+b);
    G[n+a].push_back(b);
  }
  solve(G,c);
  /*
  for(int i=0;i<(int)G.size();i++){
    cout<<"node "<<i<<", c="<<c[i]<<endl;
    for(int j=0;j<(int)G[i].size();j++){
      cout<<G[i][j]<<' ';
    }
    cout<<endl<<endl;
      
  }
  */
  vec cmp=scc(G);
  
  vec X;
    
  for(int i=0;i<(int)cmp.size();i++)
    if(i==cmp[i])X.push_back(i);
  
  map<int, map<int,int> > flg;
  mat g( X.size() );
  vec val( X.size() , 0 );
  vec C(X.size(), 0);
  
  for(int i=0;i<(int)cmp.size();i++){
    int I=lower_bound(X.begin(),X.end(),cmp[i])-X.begin();
    val[I]+=c[i];
  }
    
  for(int from=0;from<(int)cmp.size();from++){
    for(int i=0;i<(int)G[from].size();i++){
      int to=G[from][i];
      int nfrom=lower_bound(X.begin(),X.end(),cmp[from])-X.begin();
      int nto=lower_bound(X.begin(),X.end(),cmp[to])-X.begin();
      if( flg[nfrom][nto] || nfrom==nto)continue;
      flg[nfrom][nto]=1;
      g[nfrom].push_back(nto);
      C[nto]++;
    }
  }
  /*
  for(int i=0;i<g.size();i++){
    cout<<"node "<<i<<" ,val="<<val[i]<<endl;
    for(int j=0;j<g[i].size();j++)
      cout<<g[i][j]<<' ';
    cout<<endl<<endl;
  }
  */
  
  int si=lower_bound(X.begin(),X.end(),cmp[0])-X.begin();
    
  int ans=val[ si ];
    
  vec dp(g.size(), -1);
  queue<int> Q;
  Q.push( si );
  dp[ si ]=val[ si ];
    
  while(!Q.empty()){
    int pos=Q.front();Q.pop();
    for(int i=0;i<(int)g[pos].size();i++){
      int to=g[pos][i];
      C[to]--;
      if(C[to]==0)Q.push(to);
      dp[to]=max(dp[to],dp[pos]+val[to]);
      ans=max(ans,dp[to]);
    }
  }
   
  cout<<ans<<endl;
  return 0;
}