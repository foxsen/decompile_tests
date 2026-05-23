#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int N = 300 + 5;
map<string, int> Map;
int id[N], w[N], a[N], p[N];
void getNext(int a[], int n) {
  p[0] = -1;
  int j = -1;
  for (int i = 1; i < n; i++) {
    while (j != -1 && a[j + 1] != a[i]) j = p[j];
    if (a[j + 1] == a[i]) j++;
    p[i] = j;
  }
}
int KMP(int a[], int n, int b[], int m) {
  int ret = 0;
  int j = -1;
  for (int i = 0; i < m; i++) {
    while (j != -1 && a[j + 1] != b[i]) j = p[j];
    if (a[j + 1] == b[i]) j++;
    if (j == n - 1) {
      ret++;
      j = -1;
    }
  }
  return ret;
}
int main() {
  int n;
  cin >> n;
  int idx = 0;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    id[i] = Map[s];
    if (!id[i]) id[i] = Map[s] = ++idx;
    w[i] = s.size() + w[i - 1];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++) {
      for (int k = i; k <= j; k++) a[k - i] = id[k];
      getNext(a, j - i + 1);
      int s = KMP(a, j - i + 1, id + 1, n);
      if (s > 1) ans = max(ans, (w[j] - w[i - 1] - 1) * s);
    }
  cout << w[n] + n - 1 - ans;
  return 0;
}
