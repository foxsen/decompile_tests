#include <bits/stdc++.h>
using namespace std;
long long read() {
  int f = 1;
  long long res = 0;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = -f;
  } while (ch < '0' || ch > '9');
  do {
    res = res * 10 + ch - '0';
    ch = getchar();
  } while (ch >= '0' && ch <= '9');
  return f == 1 ? res : -res;
}
void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int N = 100005;
const int M = 3010;
const int mod = 1e9 + 7;
const long long INF = 1e18;
int n, m;
int A[N], B[N];
char str[N];
int head[N], to[N * 2], nxt[N * 2], tot;
void addEdge(int u, int v) {
  tot++;
  nxt[tot] = head[u];
  to[tot] = v;
  head[u] = tot;
}
template <class T>
T mmax(T a, T b) {
  return a < b ? b : a;
}
template <class T>
T mmin(T a, T b) {
  return a < b ? a : b;
}
int countOne(long long set) {
  int res = 0;
  while (set) {
    res++;
    set &= set - 1;
  }
  return res;
}
bool contain(long long set, int i) { return (set & (1LL << i)) > 0; }
long long myPow(long long a, long long p) {
  if (p == 0) return 1;
  long long res = myPow(a, p / 2);
  res *= res;
  res %= mod;
  if (p % 2 == 1) {
    res *= a;
    res %= mod;
  }
  return res % mod;
}
void addMode(long long &a, long long b) { a = (a + b) % mod; }
long long mul(long long a, long long b) { return a * b % mod; }
template <class T>
void mySwap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}
long long p[N][2][2];
void no() {
  cout << "NO\n";
  exit(0);
}
void go(int sz, vector<set<pair<long long, long long>>> &nums) {
  if (sz == 1) return;
  long long mx[4] = {-INF, -INF, -INF, -INF};
  set<pair<long long, long long>>::iterator its[4];
  for (int i = 0; i < 4; i++) {
    its[i] = nums[i].begin();
  }
  bool okok = false;
  vector<long long> idxs;
  for (int i = 1; i < sz; i++) {
    for (int j = 0; j < 4; j++) {
      mx[j] = mmax(mx[j], -p[its[j]->second][(j >> 1) ^ 1][(j & 1)]);
      its[j]++;
    }
    for (int j = 0; j < 4; j++) {
      if (mx[j] <= its[j]->first) {
        okok = true;
        for (auto it = nums[j].begin(); it != its[j]; it++) {
          idxs.push_back(it->second);
        }
      }
      if (okok) break;
    }
    if (okok) break;
  }
  if (!okok) no();
  vector<set<pair<long long, long long>>> nnums(4);
  for (int i : idxs) {
    nnums[0].insert(make_pair(p[i][0][0], i));
    nnums[1].insert(make_pair(p[i][0][1], i));
    nnums[2].insert(make_pair(p[i][1][0], i));
    nnums[3].insert(make_pair(p[i][1][1], i));
    nums[0].erase(make_pair(p[i][0][0], i));
    nums[1].erase(make_pair(p[i][0][1], i));
    nums[2].erase(make_pair(p[i][1][0], i));
    nums[3].erase(make_pair(p[i][1][1], i));
  }
  go(idxs.size(), nnums);
  go(sz - idxs.size(), nums);
}
int main() {
  fast_io();
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i][0][0] >> p[i][0][1];
    cin >> p[i][1][0] >> p[i][1][1];
  }
  vector<set<pair<long long, long long>>> nums(4);
  for (int i = 0; i < n; i++) {
    p[i][1][0] *= -1;
    p[i][1][1] *= -1;
    nums[0].insert(make_pair(p[i][0][0], i));
    nums[1].insert(make_pair(p[i][0][1], i));
    nums[2].insert(make_pair(p[i][1][0], i));
    nums[3].insert(make_pair(p[i][1][1], i));
  }
  go(n, nums);
  cout << "YES\n";
  return 0;
}
