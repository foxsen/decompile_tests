#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

signed main(){
  int V, E; cin >> V >> E;
  vector<vector<int> > dist(V, vector<int> (V, INF));
  for(int i = 0; i < E; i++){
    int s, t, d; cin >> s >> t >> d;
    dist[s][t] = d;
 }  
 vector<vector<int> > dp(V, vector<int> (1 << V, INF));
 dp[0][0] = 0;
 for(int i = 0; i < (1 << V); i++){
   for(int j = 0; j < V; j++){
     if(!(i & (1 << j))){
       for(int k = 0; k < V; k++){
         dp[j][i + (1 << j)] = min(dp[j][i + (1 << j)], dp[k][i] + dist[k][j]);
       }
     }
   }
 }
 int ans = dp[0][(1 << V) - 1];
 if(ans == INF) cout << -1 << endl;
 else cout << ans << endl;
}
