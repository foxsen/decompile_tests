#include<bits/stdc++.h>
using namespace std;
#define MAX 2005
typedef long long ll;
struct edge{ll to,cost;};
vector<ll> ans;
vector<edge> G[MAX];
ll A[MAX];
int n,m;
ll a,b,c;

ll dfs(int pos,int prev,int root,ll cost){
  vector<ll> res;
  for(int i=0;i<(int)G[pos].size();i++){
    edge e=G[pos][i];
    if(e.to==prev)continue;
    res.push_back(dfs(e.to,pos,root,cost)+e.cost*A[root]);
  }
  sort(res.begin(),res.end());
  reverse(res.begin(),res.end());
  for(int i=1;i<(int)res.size();i++)ans.push_back(res[i]);
  return (res.empty()?0LL:res[0]);
}

int main(){
  cin>>n>>m;
  for(int i=0;i<n-1;i++){
    cin>>a>>b>>c;
    a--,b--;
    G[a].push_back((edge){b,c});
    G[b].push_back((edge){a,c});
  }
  for(int i=0;i<n;i++)cin>>A[i];
  for(int i=0;i<n;i++)ans.push_back(dfs(i,-1,i,0));
  sort(ans.begin(),ans.end());
  reverse(ans.begin(),ans.end());
  for(int i=1;i<(int)ans.size();i++)ans[i]+=ans[i-1];
  cout<< ans[ min(m-1,(int)ans.size()-1) ] <<endl;
  return 0;
}