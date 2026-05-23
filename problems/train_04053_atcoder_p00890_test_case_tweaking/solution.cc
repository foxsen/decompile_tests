#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
typedef tuple< int, int, int > Pi;
struct edge
{
  int to, cost;
};

int N, M, C;
vector< vector< edge > > graph;
int min_cost[100][101];

int Dijkstra()
{
  
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;  
  fill_n(*min_cost, 100 * 101, INF);
  que.emplace(0, 0, 0);
  min_cost[0][0] = 0;
  int ret = N;
  while(!que.empty()) {
    int cost, now, zero;
    tie(cost, now, zero) = que.top(); que.pop();
    if(cost > C) break;
    if(now == N - 1) {
      ret = min(ret, zero);
      continue;
    }
    if(cost > min_cost[now][zero]) {
      continue;
    }
    for(auto&& e : graph[now]) { 
      if(cost + e.cost < min_cost[e.to][zero]) {
        min_cost[e.to][zero] = cost + e.cost;
        que.emplace(cost + e.cost, e.to, zero);
      }
      if(zero < N && cost < min_cost[e.to][zero + 1]) {
        min_cost[e.to][zero + 1] = cost;
        que.emplace(cost, e.to, zero + 1);
      }
    }
  }
  return(ret);
}
int main()
{  
  while(cin >> N >> M >> C, N) {
    graph.resize(N);
    while(M--) {
      int x, y, c;
      cin >> x >> y >> c;
      --x, --y;
      graph[x].push_back((edge){y, c});
    }
    cout << Dijkstra() << endl;
    graph.clear();
  }
}