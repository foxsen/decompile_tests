#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
struct S{
  int u, cost, change;
  S() {}
  S(int u, int a, int b) : 
    u(u), cost(a), change(b) {}
  bool operator < (const S& s) const {
    if(cost != s.cost) return cost > s.cost;
    return change > s.change;
  }
};
const int MAX_V = 100000;

int main(){
  int N, T;
  while(cin >> N >> T){
    string ST, GL;
    cin >> ST >> GL;
    map<string, vector<int> > st_ids;
    vector<int> to[MAX_V];
    vector<int> cost[MAX_V];
    string name[MAX_V];
    int V = 0;
    REP(i, N){
      int A;
      cin >> A;
      REP(i, A) cin >> name[V + i];
      REP(i, A) st_ids[name[V + i]].push_back(V + i);
      REP(i, A - 1){
        int t; cin >> t;
        to[V + i].push_back(V + i + 1);
        cost[V + i].push_back(t);
        to[V + i + 1].push_back(V + i);
        cost[V + i + 1].push_back(t);
      }
      V += A;
    }
    priority_queue<S> que;
    set<string> used;
    bool used2[MAX_V] = {};
    used.insert(ST);
    REP(i, st_ids[ST].size()){
      que.push(S(st_ids[ST][i], 0, 0));
    }
    bool ok = false;
    while(!que.empty()){
      S s = que.top(); que.pop();
      //printf("id = %d name = %s cost = %d change = %d\n", s.u, name[s.u].c_str(), s.cost, s.change);
      if(name[s.u] == GL){
        printf("%d %d\n", s.cost, s.change);
        ok = true;
        break;
      }
      if(used2[s.u]) continue;
      used2[s.u] = true;
      if(!used.count(name[s.u])){
        REP(i, st_ids[name[s.u]].size()){
          que.push(S(st_ids[name[s.u]][i], s.cost + T, s.change + 1));
        }
        used.insert(name[s.u]);
      }
      REP(i, to[s.u].size()){
        int v = to[s.u][i];
        int c = cost[s.u][i];
        que.push(S(v, s.cost + c, s.change));
      }
    }
    if(!ok) cout << -1 << endl;
  }
  return 0;
}