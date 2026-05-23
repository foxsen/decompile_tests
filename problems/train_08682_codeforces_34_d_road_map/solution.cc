#include <bits/stdc++.h>
using namespace std;
const double EXP = 1e-9;
const int INF = 0x3f3f3f3f;
const long long MINF = 0x3f3f3f3f3f3f3f3f;
const double DINF = 0xffffffffffff;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
int a[N];
int b[N];
int main() {
  std::ios::sync_with_stdio(false);
  int n, r1, r2, x;
  cin >> n >> r1 >> r2;
  for (int i = 1; i <= n; i++) {
    if (i == r1) {
      a[r1] = r1;
      b[r1] = r1;
    } else {
      cin >> x;
      a[i] = x;
      b[i] = x;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[r2] == i) a[i] = r2;
  }
  int now = r2;
  while (1) {
    if (b[now] == r1) {
      a[r1] = now;
      break;
    } else {
      a[b[now]] = now;
      now = b[now];
    }
  }
  bool flag = true;
  for (int i = 1; i <= n; i++) {
    if (i != r2) {
      if (flag)
        flag = false;
      else
        cout << " ";
      cout << a[i];
    }
  }
  cout << endl;
  return 0;
}
