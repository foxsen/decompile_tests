#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
constexpr int32_t mod = 1009, m1 = 1e9 + 123, m2 = 1e9 + 321;
static const int base = uniform_int_distribution<int>(300, (int)1e9 + 122)(rng);
static inline int add(int a, int b, int Mod) {
  return ((long long)a + b) % Mod;
}
static inline int sub(int a, int b, int Mod) {
  return (((long long)a - b) % Mod + Mod) % Mod;
}
static inline int mul(int a, int b, int Mod) { return 1ll * a * b % Mod; }
int n, k, p[100100];
vector<pair<int, int> > v;
vector<bool> vis;
int get(int a) {
  if (p[a] == a) return a;
  return p[a] = get(p[a]);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) p[i] = i;
  int ans = 0;
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back({a, b});
    a = get(a), b = get(b);
    if (a == b) {
      ans++;
      continue;
    }
    p[b] = a;
  }
  cout << ans << '\n';
  return 0;
}
