#include<bits/stdc++.h>
using namespace std;
using Int = signed;
//INSERT ABOVE HERE
Int dp[2][1010][1010];
Int pv[1010][1010];
signed main(){
  Int n,m;
  cin>>n>>m;
  vector<Int> a(m),b(m);
  for(Int i=0;i<m;i++) cin>>a[i]>>b[i],a[i]--,b[i]--;

  vector<vector<Int> > G(n);
  for(Int i=0;i<m;i++) G[a[i]].emplace_back(b[i]);

  memset(dp,0,sizeof(dp));
  memset(pv,-1,sizeof(pv));
  
  using T = tuple<Int, Int, Int>;
  queue<T> q;
  for(Int i=0;i<m;i++){
    pv[a[i]][b[i]]=i;
    dp[0][a[i]][b[i]]=1;
    q.emplace(0,a[i],b[i]);
  }
  while(!q.empty()){
    Int t,x,y;
    tie(t,x,y)=q.front();q.pop();
    //cout<<t<<":"<<x<<":"<<y<<"::"<<pv[x][y]<<endl;
    for(Int z:G[y]){
      if(x==z) continue;
      Int nt=t||(~pv[x][z]&&pv[x][y]!=pv[x][z]);
      if(dp[nt][x][z]) continue;
      if(pv[x][z]<0) pv[x][z]=pv[x][y];
      dp[nt][x][z]=1;
      q.emplace(nt,x,z);
    }    
  }

  for(Int i=0;i<m;i++){
    Int s=dp[1][a[i]][b[i]];
    Int t=dp[0][b[i]][a[i]]|dp[1][b[i]][a[i]];
    //cout<<s<<" "<<t<<endl;
    cout<<(s^t?"diff":"same")<<endl;
  }
  
  return 0;
}
