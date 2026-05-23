#include<bits/stdc++.h>
using namespace std;
typedef long long int64;
typedef pair< int64, int64 > Pi;
struct edge
{
  int to, cost;
};
const int64 INF = 1LL << 60;

struct BinaryIndexedTree
{
  vector< int > data;
  BinaryIndexedTree(int sz)
  {
    data.assign(++sz, 0);
  }
  int Query(int k)
  {
    int ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return(ret);
  }
  void Add(int k, int x)
  {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};

int N, M;
vector< edge > graph[100000];

int64 Dijkstra(int s, int g, vector< int64 >& min_cost)
{
  priority_queue< Pi, vector< Pi >, greater< Pi > > Que;
  min_cost.assign(N, INF);
  Que.push(Pi(0, s));
  min_cost[s] = 0;
  while(!Que.empty()) {
    Pi p = Que.top(); Que.pop();
    if(p.second == g) return(p.first);
    if(min_cost[p.second] < p.first) continue;
    for(auto e : graph[p.second]) {
      if(p.first + e.cost < min_cost[e.to]) {
        min_cost[e.to] = p.first + e.cost;
        Que.push(Pi(min_cost[e.to], e.to));
      }
    }
  }
  return(-1);
}


int main()
{
  scanf("%d %d", &N, &M);
  for(int i = 0; i < M; i++) {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    graph[A].push_back((edge){B, C});
    graph[B].push_back((edge){A, C});
  }

  vector< int64 > toS, toG;
  Dijkstra(0    , -1, toS);
  Dijkstra(N - 1, -1, toG);

  vector< Pi > Start(N);
  for(int i = 0; i < N; i++) Start[i] = Pi(toS[i], i);
  sort(Start.begin(), Start.end());

  vector< int64 > nums(toG);
  nums.push_back(-1);
  sort(nums.begin(), nums.end());
  nums.erase(unique(nums.begin(), nums.end()), nums.end());
  for(int i = 0; i < N; i++) {
    toG[i] = lower_bound(nums.begin(), nums.end(), toG[i]) - nums.begin();
  }

  int Q;
  scanf("%d", &Q);
  vector< pair< Pi, int > > Query(Q);
  for(int i = 0; i < Q; i++) {
    scanf("%lld %lld", &Query[i].first.first, &Query[i].first.second);
    Query[i].second = i;
  }
  sort(Query.begin(), Query.end());

  int ptr = 0;
  vector< int > ret(Q);
  BinaryIndexedTree bit(nums.size());
  for(int i = 0; i < Q; i++) {
    const Pi& q = Query[i].first;
    while(ptr < N && q.first >= Start[ptr].first) {
      bit.Add(toG[Start[ptr].second], 1);
      ++ptr;
    }
    int tail = lower_bound(nums.begin(), nums.end(), q.second) - nums.begin();
    ret[Query[i].second] = bit.Query(nums.size() - 1) - bit.Query(tail - 1); 
  }

  for(int i = 0; i < Q; i++) {
    printf("%d\n", ret[i]);
  }
}