#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;cin>>n;
  vector<VI> cost(n,vector<int>(n));
  for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>cost[i][j];
  ll res=0;
  for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)res+=min(cost[i][j],cost[j][i]);
  cout<<res<<endl;
}