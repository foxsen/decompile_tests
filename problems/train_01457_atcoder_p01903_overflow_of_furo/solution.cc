#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
using lint = long long int;
long long int INF = 1001001001001001LL;
int inf = 1000000007;
long long int MOD = 1000000007LL;
double PI = 3.1415926535897932;

template<typename T1,typename T2>inline void chmin(T1 &a,const T2 &b){if(a>b) a=b;}
template<typename T1,typename T2>inline void chmax(T1 &a,const T2 &b){if(a<b) a=b;}

#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()

/* do your best */

// verified : http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
// O(E V^2)

// [使い方]
// add_edge(from, to, cap) :  from から to へ 容量 cap の辺を貼る
// max_flow(s, t) :  s から t への最大フローを返す

template< typename T >
struct Dinic{
    const T inf;

    struct edge{
        int to;
        T cap;
        int rev;
        bool isrev;
    };

    vector<vector<edge>> g;
    vector<int> min_cost, iter;

    Dinic(int V) : inf(numeric_limits<T>::max()), g(V){}


    // 0-indexed
    void add_edge(int from, int to, T cap){
        g[from].emplace_back((edge){to, cap, (int)g[to].size(), false});
        g[to].emplace_back((edge){from, 0, (int)g[from].size() - 1, true});
    }

    bool bfs(int s, int t) {
        min_cost.assign(g.size(), -1);
        queue<int> que;
        min_cost[s] = 0;
        que.push(s);
        while(!que.empty() && min_cost[t] == -1){
            int p = que.front();
            que.pop();
            for(auto &e : g[p]) {
                if(e.cap > 0 && min_cost[e.to] == -1){
                    min_cost[e.to] = min_cost[p] + 1;
                    que.push(e.to);
                }
            }
        }
        return min_cost[t] != -1;
    }
    
    T dfs(int idx, const int t, T flow){
        if(idx == t) return flow;
        for(int &i = iter[idx]; i < g[idx].size(); i++){
            edge &e = g[idx][i];
            if(e.cap > 0 && min_cost[idx] < min_cost[e.to]){
                T d = dfs(e.to, t, min(flow, e.cap));
                if(d > 0){
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    
    // 0-indexed
    T max_flow(int s, int t){
        T flow = 0;
        while(bfs(s, t)){
            iter.assign(g.size(), 0);
            T f = 0;
            while((f = dfs(s, t, inf)) > 0) flow += f;
        }

        return flow;
    }
    
    void output() {
        for(int i = 0; i < g.size(); i++) {
            for(auto &e : g[i]) {
                if(e.isrev) continue;
                auto &rev_e = g[e.to][e.rev];
                cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
            }
        }
    }
};

int main() {

  int k, n, m; cin >> k >> n >> m;
  int source = n + k + 1;
  int sink = 0;

  // 0 と (1 ~ k) が直接繋がっていたら，overfuro

  Dinic<lint> dc(n + k + 2);
  bool overfuro = false;
  for (int i = 0; i < m; i++) {
    lint a, b, c; cin >> a >> b >> c;
    if (a > b) swap(a, b);
    if (a == sink and 1 <= b and b <= k) {
      overfuro = true;
    }
    dc.add_edge(a, b, c);
    dc.add_edge(b, a, c);
  }

  if (overfuro) {
    cout << "overfuro" << endl;
    return 0;
  }

  for (int i = 1; i <= k; i++) {
    dc.add_edge(source, i, INF);
  }

  lint ans = dc.max_flow(source, sink);

  lint add = 0;
  for(int i = 0; i < dc.g.size(); i++) {
    for(auto &e : dc.g[i]) {
      if(e.isrev) continue;
      auto &rev_e = dc.g[e.to][e.rev];
      if (rev_e.cap == e.cap + rev_e.cap) {
        auto extra = dc;
        extra.add_edge(i, e.to, INF);
        lint tmp = extra.max_flow(source, sink);
        add = max(add, tmp);
      }
      // cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
    }
  }

  cout << ans + add << endl;
  return 0;
}

