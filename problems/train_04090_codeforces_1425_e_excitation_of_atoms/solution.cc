#include <bits/stdc++.h>
using namespace std;
long long de_sum[100005];
long long de_soure[100005];
long long A[100005], D[100005];
long long max(long long a, long long b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}
long long min(long long a, long long b) {
  if (a > b) {
    return b;
  } else {
    return a;
  }
}
void PUTBUG(int n) {
  for (int i = 0; i <= n; i++) {
    cout << de_sum[i] << " " << de_soure[i] << endl;
  }
}
int main() {
  int n, k;
  memset(de_sum, 0, sizeof(de_sum));
  memset(de_soure, 0, sizeof(de_soure));
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  long long ss = 0x3f3f3f3f;
  for (int i = 1; i <= n; i++) {
    cin >> D[i];
    if (i < n) {
      ss = min(ss, D[i]);
    }
  }
  for (int i = n; i >= 1; i--) {
    de_sum[i] = de_sum[i + 1] + A[i];
  }
  for (int i = n; i >= 1; i--) {
    de_soure[i] = max(de_sum[i] - D[i], de_soure[i + 1]);
  }
  if (k == 1) {
    long long ans = 0;
    long long aa = 0;
    long long ww = 0x3f3f3f3f;
    for (int i = 1; i < n; i++) {
      aa += A[i];
      ww = min(ww, D[i]);
      long long oo = max(aa - ww, 0);
      ans = max(oo + de_soure[i + 1], ans);
    }
    long long min_A = 0x3f3f3f3f;
    long long ans2 = 0;
    for (int i = n; i >= 1; i--) {
      min_A = min(min_A, A[i]);
      ans2 = max(ans2, de_sum[i] - min_A - D[i]);
    }
    cout << max(ans, ans2) << endl;
  } else if (k == 0) {
    cout << de_soure[1] << endl;
  } else {
    cout << max(de_sum[1] - ss, max(0, A[n] - D[n])) << endl;
  }
  return 0;
}
