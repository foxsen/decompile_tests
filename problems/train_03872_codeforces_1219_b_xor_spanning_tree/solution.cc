#include <bits/stdc++.h>
using namespace std;
template <typename T>
void cetak(T t) {
  cout << t << ')' << endl;
}
template <typename T, typename... V>
void cetak(T t, V... v) {
  cout << t;
  if (sizeof...(v)) cerr << ", ";
  cetak(v...);
}
int MOD = 1e9 + 7;
const int mx = 1e5 + 10;
const int N = 1 << 17;
template <typename T>
struct FWT {
  void fwt(vector<T> &io, int n, int t) {
    for (int d = 1; d < n; d <<= 1) {
      for (int i = 0, m = d << 1; i < n; i += m) {
        for (int j = 0; j < d; j++) {
          T x = io[i + j], y = io[i + j + d];
          if (t == 0)
            io[i + j] = (x + y) % MOD, io[i + j + d] = (x + MOD - y) % MOD;
          else if (t == 1)
            io[i + j] = (x + y) % MOD;
          else
            io[i + j + d] = (x + y) % MOD;
        }
      }
    }
  }
  void ufwt(vector<T> &io, int n, int t) {
    for (int d = 1; d < n; d <<= 1) {
      for (int i = 0, m = d << 1; i < n; i += m) {
        for (int j = 0; j < d; j++) {
          T x = io[i + j], y = io[i + j + d];
          T dua = MOD + 1;
          dua >>= 1;
          if (t == 0)
            io[i + j] = (x + y) * dua % MOD,
                   io[i + j + d] = (x - y + MOD) * dua % MOD;
          else if (t == 1)
            io[i + j] = (x - y + MOD) % MOD;
          else
            io[i + j + d] = (y - x + MOD) % MOD;
        }
      }
    }
  }
  void convolution(vector<T> &a, vector<T> &b, int n, int t) {
    fwt(a, n, t);
    fwt(b, n, t);
    for (int i = 0; i < n; i++) a[i] = a[i] * b[i] % MOD;
    ufwt(a, n, t);
  }
};
FWT<long long> ini;
vector<long long> kali(vector<vector<long long>> &ve, int l, int r) {
  if (l == r) return ve[l];
  int mid = (l + r) >> 1;
  auto kiri = kali(ve, l, mid);
  auto kanan = kali(ve, mid + 1, r);
  ini.convolution(kiri, kanan, N, 0);
  return kiri;
}
vector<long long> atau(vector<vector<long long>> &ve, int l, int r) {
  if (l == r) return ve[l];
  int mid = (l + r) >> 1;
  auto kiri = kali(ve, l, mid);
  auto kanan = kali(ve, mid + 1, r);
  ini.convolution(kiri, kanan, N, 0);
  for (auto &i : kiri)
    if (i > 0) i = 1;
  return kiri;
}
int disc[mx], low[mx], idx, sudah[mx];
map<pair<int, int>, int> itu;
set<pair<int, int>> bridge;
vector<int> g[mx];
void dfs(int now, int par) {
  disc[now] = low[now] = ++idx;
  for (int i : g[now]) {
    if (i == par) continue;
    if (!disc[i]) {
      dfs(i, now);
      low[now] = min(low[now], low[i]);
      if (low[i] > disc[now]) {
        bridge.insert({now, i});
        bridge.insert({i, now});
      }
    } else
      low[now] = min(low[now], disc[i]);
  }
}
vector<int> isi;
void DFS(int now) {
  sudah[now] = 1;
  isi.push_back(now);
  for (int i : g[now]) {
    if (!sudah[i] && !bridge.count({now, i})) DFS(i);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    itu[{u, v}] = itu[{v, u}] = w;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  int akhir = 0;
  for (auto i : bridge) {
    if (i.first < i.second) akhir ^= itu[i];
  }
  vector<vector<long long>> ve, ve2;
  for (int i = 1; i <= n; i++) {
    if (!sudah[i]) {
      isi.clear();
      DFS(i);
      if ((int)(isi.size()) == 1) {
        continue;
      }
      int tadi = -1;
      vector<int> tour;
      for (int j : isi) {
        if (tadi == -1) {
          tadi = j;
          continue;
        }
        tour.push_back(itu[{tadi, j}]);
        tadi = j;
      }
      int j = isi[0];
      tour.push_back(itu[{tadi, j}]);
      int semua = 0;
      for (int j : tour) semua ^= j;
      vector<long long> hasil(N, 0), hasil2(N, 0);
      for (int j : tour) hasil[semua ^ j] += 1;
      for (int j : tour) hasil2[semua ^ j] |= 1;
      ve.push_back(hasil);
      ve2.push_back(hasil2);
    }
  }
  for (auto &i : ve) ini.fwt(i, N, 0);
  vector<long long> satu(N, 1);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < (int)(ve.size()); j++)
      satu[i] = satu[i] * ve[j][i] % MOD;
  }
  ini.ufwt(satu, N, 0);
  MOD = 1e9 + 9;
  for (auto &i : ve2) ini.fwt(i, N, 0);
  vector<long long> dua(N, 1);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < (int)(ve2.size()); j++)
      dua[i] = dua[i] * ve2[j][i] % MOD;
  }
  ini.ufwt(dua, N, 0);
  for (int i = 0; i < N; i++) {
    if (dua[i ^ akhir] || satu[i ^ akhir]) {
      cout << i << ' ' << satu[i ^ akhir] << endl;
      return 0;
    }
  }
}
