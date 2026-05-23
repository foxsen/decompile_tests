#include<unordered_map>
#include<utility>
template<typename T>
class UnionFind {
public:
  void unite(const T& a, const T& b) {
    T x = find(a), y = find(b);
    if(size_[x] < size_[y]) std::swap(x, y);
    if(x != y) parent_[y] = x, size_[x] += size_[y];
  }
  const T find(const T& x) {
    if(!parent_.count(x)) {
      size_[x] = 1;
      return parent_[x] = x;
    }
    return (parent_[x] == x) ? x : (parent_[x] = find(parent_[x]));
  }
  const int size(const T& x) {
    return size_[find(x)];
  }
private:
  std::unordered_map<T, T> parent_;
  std::unordered_map<T, int> size_;
};

#include<bits/stdc++.h>
using namespace std;

using Weight = long long int;
using Vertex = int;
struct Edge {Vertex from, to; Weight weight;};
using Row = valarray<Weight>;
using Matrix = valarray<Row>;

const Weight MOD = 1e9 + 7;
int N, M;
vector<Vertex> root;
vector<Edge> E;

Weight power(Weight m, Weight n) {
  if(!n) return 1;
  if(n & 1) return (power(m, n - 1) * m) % MOD;
  return power((m * m) % MOD, n >> 1);
}

Weight determinant(Matrix A) {
  const int N = A.size() - 1;
  Weight det = 1;
  for(int i = 0; i < N; ++i) {
    for(int k = i; k < N; ++k) if(A[k][i] != 0) {
      if((k - i) & 1) det = -det + MOD;
      swap(A[i], A[k]);
      break;
    }
    if(A[i][i] == 0) return 0;
    det = (det * A[i][i]) % MOD;
    for(int k = i + 1; k < N; ++k) {
      auto c = (A[k][i] * power(A[i][i], MOD - 2)) % MOD;
      c = -c + MOD;
      for(int j = 0; j < N; ++j) A[k][j] = (A[k][j] + c * A[i][j] + MOD) % MOD;
    }
  }
  return det % MOD;
}

Matrix Laplacian(UnionFind<Vertex> cc, Vertex c) {
  Matrix L(Row(Weight(0), cc.size(c) - 1), cc.size(c) - 1);
  vector<Vertex> V;
  for(Vertex v = 0; v < N; ++v) if(cc.find(v) == cc.find(c)) V.push_back(v);
  vector<int> index(N, -1);
  for(int i = 0; i < V.size(); ++i) index[V[i]] = i;
  for(auto e: E) if(cc.find(e.from) == cc.find(c) && cc.find(e.to) == cc.find(c)) {
    L[index[e.from]][index[e.to]] = L[index[e.to]][index[e.from]] = -1 + MOD;
    ++L[index[e.from]][index[e.from]];
    ++L[index[e.to]][index[e.to]];
  }
  return L;
}

Weight spaninng_trees(UnionFind<Vertex> cc, vector<Vertex> root, int bit) {
  auto COUNTRY = {N, N + 1};
  for(int i = 0; i < root.size(); ++i) {
    if((bit >> i) & 1) cc.unite(root[i], N + 1);
    else               cc.unite(root[i], N);
  }
  vector<Weight> det;
  for(auto c: COUNTRY) det.push_back(determinant(Laplacian(cc, c)));
  return (det[0] * det[1]) % MOD;
}

Weight Kruskal() {
  sort(begin(E), end(E), [](Edge lhs, Edge rhs) {return lhs.weight < rhs.weight;});
  UnionFind<Vertex> group;
  for(auto e: E) {
    group.unite(e.from, e.to);
    if(group.size(e.from) == N) return e.weight;
  }
  exit(1);
}

void solve() {
  auto D = Kruskal();

  UnionFind<Vertex> cc;
  for(auto e: E) if(e.weight < D) cc.unite(e.from, e.to);

  set<Vertex> tmp;
  for(Vertex v = 0; v < N; ++v) tmp.insert(cc.find(v));
  vector<Vertex> root(begin(tmp), end(tmp));

  Weight res = 0;
  for(int bit = 1; bit < (1 << root.size()) - 1; ++bit) {
    res = (res + spaninng_trees(cc, root, bit)) % MOD;
  }
  cout << D << " " << res << endl;
}

int main() {
  cin >> N >> M;
  for(int i = 0; i < M; ++i) {
    Vertex s, t; Weight d;
    cin >> s >> t >> d;
    --s; --t;
    E.push_back({s, t, d});
  }
  solve();
}