#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-8;

struct Edge {
  int src, dst;
  int t1, t2;
  bool type;
  Edge(int src, int dst, int t1, int t2, bool type) :
    src(src),dst(dst),t1(t1),t2(t2),type(type) {}
};
vector<Edge> G[1000];
int Y[1000][2];
bool visited[1000];
ll dp[1001][2];

int main() {
  int n,m;
  cin >> n >> m;
  
  REP(i,m) {
    cin >> Y[i][0] >> Y[i][1];
    REP(j,i) {
      REP(k,2) {
        REP(l,2) {
          int x1 = abs(Y[i][k]);
          int x2 = abs(Y[j][l]);
          if (x1 == x2) {
            G[i].push_back(Edge(i,j,k,l,Y[i][k]==Y[j][l]));
            G[j].push_back(Edge(j,i,l,k,Y[i][k]==Y[j][l]));
          }
        }
      }
    }
  }
  const ll MOD = 1e9+7;
  memset(visited,0,sizeof(visited));
  ll ans = 1;
  // ÐÆÂÌßÉ¯¶Ï
  REP(i,m) {
    if (abs(Y[i][0]) == abs(Y[i][1])) {
      visited[i] = 1;
      if (Y[i][0] == -Y[i][1])
        ans = (ans * 2) % MOD;
    }
  }
  // ü
  REP(i,m) {
    if (visited[i]) continue;
    if (G[i].size() <= 1) {
      queue<int> Q;
      Q.push(i);
      vector<bool> v;
      while(!Q.empty()) {
        int p = Q.front(); Q.pop();
        if (visited[p]) continue;
        visited[p] = 1;
        FOR(it, G[p]) {
          if (visited[it->dst]) continue;
          v.push_back(it->type);
          Q.push(it->dst);
        }
      }
      memset(dp,0,sizeof(dp));
      dp[0][0] = 1;
      dp[0][1] = 2;
      int N = v.size();
      REP(i, N) {
        //cout << "v[i]" << v[i] << endl;
        if (v[i]) dp[i+1][0] = dp[i][1];
        else dp[i+1][0] = dp[i][0];
        dp[i+1][1] = (dp[i][0]+dp[i][1]) % MOD;
      }
      //cout << dp[N][0] << " " << dp[N][1] << endl;
      ans = (ans * (dp[N][0] + dp[N][1]) % MOD) % MOD;
    }
  }
  // REP(i,m) {
  //   cout << i << " : ";
  //   FOR(it,G[i]) {
  //     printf("(%d->%d)%d", it->src, it->dst, it->type);
  //   }
  //   cout << endl;
  // }
  // Â
  REP(i, m) {
    if (visited[i]) continue;
    queue<int> Q;
    Q.push(i);
    vector<bool> v;
    bool type = 0;                 // ØÁ½Æ±ëÌGbWÌíÞ
    while(!Q.empty()) {
      int p = Q.front(); Q.pop();
      if (visited[p]) continue;
      visited[p] = 1;
      bool f = 0;
      FOR(it, G[p]) {
        if (visited[it->dst]) continue;
        if (f) {
          type = it->type;
          break;
        }
        v.push_back(it->type);
        Q.push(it->dst);
        f = 1;
      }
    }
    int N = v.size();
    ll tmp = 0;
    memset(dp,0,sizeof(dp));
    // ØÁ½ð0èÄ
    dp[0][1] = 1;
    REP(i, N) {
      if (v[i]) dp[i+1][0] = dp[i][1];
      else dp[i+1][0] = dp[i][0];
      dp[i+1][1] = (dp[i][0]+dp[i][1]) % MOD;
    }
    if (type) tmp = dp[N][0];
    else tmp = dp[N][1];
    //cout << type << " " << tmp << " " << v[0] << endl;
    memset(dp,0,sizeof(dp));
    // ØÁ½ð1èÄ
    dp[0][0] = dp[0][1] = 1;
    REP(i, N) {
      if (v[i]) dp[i+1][0] = dp[i][1];
      else dp[i+1][0] = dp[i][0];
      dp[i+1][1] = (dp[i][0]+dp[i][1]) % MOD;
    }
    if (type) tmp = (tmp + dp[N][1]) % MOD;
    else tmp = (tmp + dp[N][0]) % MOD;
    //cout << tmp << endl;
    ans = (ans * tmp) % MOD;
  }
  cout << ans << endl;
}