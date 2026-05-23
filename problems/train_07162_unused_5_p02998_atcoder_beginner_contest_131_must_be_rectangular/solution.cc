#include <map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;i++)

//abbreviations
typedef long long ll;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vs vector<string>
#define vb vector<bool>

using namespace std;

const int vmax = 100100;
vi graph[vmax*2];
vb seen(vmax*2);
vi cnt(2,0);

void dfs(int v) {
  if(seen[v]) return;
  seen[v] = true; // v を訪問済にする
  cnt[v/vmax]++;

  // v から行ける各頂点 next_v について
  for (int next_v : graph[v]) {
    dfs(next_v); // 再帰的に探索
  }
}



int main(){
  int i = 0;
  int N = 0;
  ll ans = 0;
  cin>>N;
  rep(i,N){
    int x,y;
    cin >> x >> y;
    y += vmax;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  seen.assign(vmax*2,false);
  rep(i,vmax*2){
      if(seen[i])continue;
      cnt[0]=0;cnt[1]=0;
      dfs(i);
      ans+=(ll)cnt[0]*cnt[1];
  }
  ans-=N;
  cout<<ans<<endl;

  return 0;
}
