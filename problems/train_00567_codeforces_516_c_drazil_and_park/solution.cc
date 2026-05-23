#include <bits/stdc++.h>
using namespace std;
const int INF = numeric_limits<int>::max();
const int MINF = numeric_limits<int>::min();
const int INFF = (INF / 2 - 1);
const double EPS = 1e-9;
const int dy8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx8[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy4[] = {-1, 0, 1, 0};
const int dx4[] = {0, 1, 0, -1};
const double pi = 3.1415926535897932384626;
template <typename Data, Data (*merge)(Data, Data)>
class SegmentTree {
 private:
  vector<Data> tree;
  const Data* data;
  int left, right;
  void build(const int node, const int l, const int r) {
    if (l == r) {
      tree[node] = data[l];
    } else {
      const int mid = (l + r) / 2;
      const int left_child = node * 2 + 1;
      const int right_child = left_child + 1;
      build(left_child, l, mid);
      build(right_child, mid + 1, r);
      tree[node] = merge(tree[left_child], tree[right_child]);
    }
  }
  Data query(const int node, const int l, const int r, const int i,
             const int j) {
    if (l == i && r == j) {
      return tree[node];
    } else {
      const int mid = (l + r) / 2;
      const int left_child = node * 2 + 1;
      const int right_child = left_child + 1;
      if (j <= mid) return query(left_child, l, mid, i, j);
      if (i > mid) return query(right_child, mid + 1, r, i, j);
      return merge(query(left_child, l, mid, i, mid),
                   query(right_child, mid + 1, r, mid + 1, j));
    }
  }
  void update(const int node, const int l, const int r, const int idx,
              const Data val) {
    if (l == r) {
      tree[node] += val;
    } else {
      const int mid = (l + r) / 2;
      const int left_child = node * 2 + 1;
      const int right_child = left_child + 1;
      if (idx <= mid)
        update(left_child, l, mid, idx, val);
      else
        update(right_child, mid + 1, r, idx, val);
      tree[node] = merge(tree[left_child], tree[right_child]);
    }
  }

 public:
  SegmentTree() {}
  SegmentTree(const Data* d, int n) : left(0), right(n - 1), data(d) {
    tree = vector<Data>(n * 4);
    build(0, left, right);
  }
  SegmentTree(const vector<Data>& d)
      : left(0), right(d.size() - 1), data(d.data()) {
    tree = vector<Data>(d.size() * 4);
    build(0, left, right);
  }
  inline Data query(const int i, const int j) {
    return query(0, left, right, i, j);
  }
  inline void update(const int idx, const int val) {
    update(0, left, right, idx, val);
  }
  inline void set(const int idx, const int val) {
    Data tmp = query(idx, idx);
    update(idx, -tmp + val);
  }
};
struct Interval {
  long long bestL, bestR, bestLR;
};
Interval mergeInterval(Interval a, Interval b) {
  Interval res;
  res.bestL = max(a.bestL, b.bestL);
  res.bestR = max(a.bestR, b.bestR);
  res.bestLR = max(a.bestLR, b.bestLR);
  res.bestLR = max(res.bestLR, a.bestL + b.bestR);
  return res;
}
class TaskC_516 {
 public:
  int h[200002], d[200002];
  long long sum[200002];
  Interval v[200002];
  void solve(std::istream& in, std::ostream& out) {
    memset(h, 0, sizeof h);
    memset(d, 0, sizeof d);
    memset(sum, 0, sizeof sum);
    memset(v, 0, sizeof v);
    int n, m;
    in >> n >> m;
    for (int i = 0; i < n; i++) {
      in >> d[i];
      d[n + i] = d[i];
    }
    for (int i = 0; i < n; i++) {
      in >> h[i];
      h[n + i] = h[i];
    }
    v[0].bestL = v[0].bestR = 2 * h[0];
    v[0].bestLR = numeric_limits<long long>::min();
    for (int i = 1; i <= n << 1; i++) {
      sum[i] = sum[i - 1] + d[i - 1];
      v[i].bestL = (long long)2 * h[i] - sum[i];
      v[i].bestR = (long long)2 * h[i] + sum[i];
      v[i].bestLR = numeric_limits<long long>::min();
    }
    SegmentTree<Interval, mergeInterval> seg(v, n << 1);
    while (m--) {
      int a, b;
      in >> a >> b;
      if (b < a) b += n;
      int length = n - (b - a + 1);
      out << seg.query(b, b + length - 1).bestLR << endl;
    }
  }
};
namespace SHelper {
TaskC_516 solver;
}
int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(0);
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  SHelper::solver.solve(in, out);
  return 0;
}
