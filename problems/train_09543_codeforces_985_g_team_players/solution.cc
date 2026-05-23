#include <bits/stdc++.h>
using namespace std;
int n, m, arr[200000][2], idx[200000], nl[200000], nr[200000], prn[200000];
unsigned long long a, b, c, sl[200000], sr[200000], prm[200000], r;
vector<int> qr[200000], ql[200000];
vector<unsigned long long> qrs[200000], qls[200000];
struct TRIANGLE {
  int n, *idx, *idv;
  typedef void (*TRI_OP)(int i, int j, int k);
  vector<int> *edges;
  TRIANGLE(int n) : n(n) {
    edges = new vector<int>[n];
    idx = new int[n], idv = new int[n];
    for (int i = 0; i < n; i++) idx[i] = i;
  }
  void run(typename TRIANGLE::TRI_OP op) {
    sort(idx, idx + n,
         [this](int i, int j) { return edges[i].size() > edges[j].size(); });
    for (int i = 0; i < n; i++) idv[idx[i]] = i;
    for (int i = 0; i < n; i++) sort(edges[i].begin(), edges[i].end());
    for (int ii = 0; ii < n; ii++) {
      int i = idx[ii];
      for (auto j : edges[i])
        if (ii < idv[j]) {
          int ki = i, kj = j;
          if (ki > kj) swap(ki, kj);
          vector<int> p(min(edges[i].size(), edges[j].size()));
          p.resize(set_intersection(edges[i].begin(), edges[i].end(),
                                    edges[j].begin(), edges[j].end(),
                                    p.begin()) -
                   p.begin());
          for (auto ip : p)
            if (idv[ip] < ii) {
              if (ip < ki)
                op(ip, ki, kj);
              else if (ip > kj)
                op(ki, kj, ip);
              else
                op(ki, ip, kj);
            }
        }
    }
  }
  ~TRIANGLE() { delete[] edges, delete[] idx, delete[] idv; }
};
void tri_op(int i, int j, int k) { r -= a * i + b * j + c * k; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  cin >> a >> b >> c;
  for (int i = 0; i < m; i++) {
    cin >> arr[i][0] >> arr[i][1], idx[i] = i;
    if (arr[i][1] < arr[i][0]) swap(arr[i][0], arr[i][1]);
    sl[arr[i][1]] += arr[i][0], nl[arr[i][1]]++;
    sr[arr[i][0]] += arr[i][1], nr[arr[i][0]]++;
    qr[arr[i][0]].push_back(arr[i][1]);
    ql[arr[i][1]].push_back(arr[i][0]);
  }
  for (int i = 0; i < n; i++) {
    sort(qr[i].begin(), qr[i].end()), sort(ql[i].begin(), ql[i].end());
    qrs[i].reserve(qr[i].size() + 1), qrs[i].push_back(0);
    qls[i].reserve(ql[i].size() + 1), qls[i].push_back(0);
    for (auto &q : qr[i]) qrs[i].push_back(q + qrs[i].back());
    reverse(ql[i].begin(), ql[i].end());
    for (auto &q : ql[i]) qls[i].push_back(q + qls[i].back());
    reverse(ql[i].begin(), ql[i].end());
  }
  sort(idx, idx + m, [](int i, int j) {
    return arr[i][0] < arr[j][0] ||
           (arr[i][0] == arr[j][0] && arr[i][1] < arr[j][1]);
  });
  for (int i = 1; i < n - 1; i++)
    r = r + b * i * (i - nl[i]) * (n - 1 - i - nr[i]) +
        a * (n - 1 - i - nr[i]) *
            ((unsigned long long)(i - 1) * i / 2 - sl[i]) +
        c * (i - nl[i]) *
            ((unsigned long long)(i + n) * (n - 1 - i) / 2 - sr[i]);
  unsigned long long rr = 0, g;
  for (int i = 1, ix = 0, z = 0; i < n - 1; i++) {
    for (; ix < m && arr[idx[ix]][0] == i - 1; ix++)
      g = a * (i - 1) + c * arr[idx[ix]][1], rr += g, z++,
      prm[arr[idx[ix]][1]] += g, prn[arr[idx[ix]][1]]++;
    rr -= prm[i], z -= prn[i];
    r = r - b * z * i - rr;
  }
  for (int i = 0; i < m; i++) {
    int t = lower_bound(qr[arr[i][0]].begin(), qr[arr[i][0]].end(), arr[i][1]) -
            qr[arr[i][0]].begin();
    r += t * (a * arr[i][0] + c * arr[i][1]) + b * qrs[arr[i][0]][t];
  }
  for (int i = 0; i < m; i++) {
    int t = ql[arr[i][1]].end() -
            upper_bound(ql[arr[i][1]].begin(), ql[arr[i][1]].end(), arr[i][0]);
    r += t * (a * arr[i][0] + c * arr[i][1]) + b * qls[arr[i][1]][t];
  }
  TRIANGLE tri(n);
  for (int i = 0; i < m; i++)
    tri.edges[arr[i][0]].push_back(arr[i][1]),
        tri.edges[arr[i][1]].push_back(arr[i][0]);
  tri.run(&tri_op);
  cout << r << endl;
  return 0;
}
