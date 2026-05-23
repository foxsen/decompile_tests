#include <bits/stdc++.h>
using namespace std;
typedef priority_queue<long long, vector<long long>, greater<long long>>
    minHeap;
const int INF = 1e9 + 9;
const long long LINF = 1e17 + 9;
const long long MD = 998244353;
inline long long po(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % MD;
    a = (a * a) % MD;
    b /= 2;
  }
  return ans;
}
const int N = 2e3 + 33;
long long n, m, k, t;
int arr[N][N];
string s;
vector<int> r[N], c[N], rr[N], cc[N];
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  cout << fixed;
  cout << setprecision(7);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      rr[i].push_back(arr[i][j]);
      cc[j].push_back(arr[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    sort(rr[i].begin(), rr[i].end());
    int l = -1;
    for (int x : rr[i]) {
      if (l != x) {
        r[i].push_back(x);
        l = x;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    sort(cc[i].begin(), cc[i].end());
    int l = -1;
    for (int x : cc[i]) {
      if (l != x) {
        c[i].push_back(x);
        l = x;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int R = lower_bound(r[i].begin(), r[i].end(), arr[i][j]) - r[i].begin();
      int C = lower_bound(c[j].begin(), c[j].end(), arr[i][j]) - c[j].begin();
      cout << max(R, C) + max(r[i].size() - R, c[j].size() - C) << " ";
    }
    cout << endl;
  }
  return 0;
}
