#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define mod 1000000007
#define INF_LL 1145141919810364

#define MAX_N 200005
#define MAX_Q 200005

int N, Q;
LL A[MAX_Q], B[MAX_Q], C[MAX_Q];

void input()
{
  cin >> N >> Q;
  for (size_t i = 0; i < Q; i++) {
    scanf("%lld %lld %lld", &A[i], &B[i], &C[i]);
  }
}

class UnionFind{
public:
  UnionFind(int _n)
  {
    init(_n);
  }

  void init(int _n)
  {
    par.clear();
    par.resize(_n);
    for (size_t i = 0; i < par.size(); i++) {
      par[i] = i;
    }
  }

  int find(int _x)
  {
    if(_x == par[_x]){
      return _x;
    }
    else{
      return par[_x] = find(par[_x]);
    }
  }

  void unite(int _x, int _y)
  {
    _x = find(_x);
    _y = find(_y);
    if(_x == _y){
      return;
    }
    par[_x] = _y;
  }

  bool same(int _x, int _y)
  {
    return find(_x) == find(_y);
  }

private:
  vector<int> par;
};

LL dp[MAX_N][2];
LL Cost[MAX_N];

vector<pair<LL, pair<int, int>>> EdgeList;
LL solve()
{
  for (size_t i = 0; i < N; i++) {
    Cost[i] = INF_LL;
  }

  for (size_t i = 0; i < Q; i++) {
    Cost[A[i]] = min(Cost[A[i]], C[i]+1);
    Cost[B[i]] = min(Cost[B[i]], C[i]+2);
  }

  for (size_t d = 0; d < 2; d++) {
    for (size_t i = 0; i < N; i++) {
      Cost[(i+1)%N] = min(Cost[(i+1)%N], Cost[i]+2);
    }
  }

  UnionFind uf(N);
  for (size_t i = 0; i < Q; i++) {
    EdgeList.push_back(make_pair(C[i], make_pair(A[i], B[i])));
  }
  for (size_t i = 0; i < N; i++) {
    EdgeList.push_back(make_pair(Cost[i], make_pair(i, (i+1)%N)));
  }

  sort(EdgeList.begin(), EdgeList.end());

  LL ret = 0;
  for (size_t i = 0; i < EdgeList.size(); i++) {
    auto edge = EdgeList[i];
    if(!uf.same(edge.second.first, edge.second.second)){
      uf.unite(edge.second.first, edge.second.second);
      ret += edge.first;
    }
  }

  return ret;
}

int main()
{
  input();

  cout << solve() << endl;

  return 0;
}
