#include <bits/stdc++.h>
using namespace std;
void err() { cout << endl; }
template <class T, class... Ts>
void err(const T& arg, const Ts&... args) {
  cout << arg << ' ';
  err(args...);
}
using ll = long long;
using db = double;
using pII = pair<int, int>;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int N = 2e2 + 10;
int n;
int a[N], b[N];
int vis[N];
void RUN() {
  memset(vis, 0, sizeof vis);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }
  for (int i = 1, j = 1; i <= n; ++i, j += 2) {
    a[j] = b[i];
    vis[b[i]] = 1;
  }
  for (int i = 2; i <= 2 * n; i += 2) {
    int lst = -1;
    for (int j = a[i - 1] + 1; j <= 2 * n; ++j) {
      if (!vis[j]) {
        vis[j] = 1;
        lst = j;
        break;
      }
    }
    if (lst == -1) {
      cout << -1 << "\n";
      return;
    }
    a[i] = lst;
  }
  for (int i = 1; i <= 2 * n; ++i) {
    cout << a[i] << " \n"[i == 2 * n];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    RUN();
  }
  return 0;
}
