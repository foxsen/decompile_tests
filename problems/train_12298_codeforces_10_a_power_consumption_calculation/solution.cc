#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, l[N], r[N];
int64_t P1, P2, P3, T1, T2, sum;
int main() {
  cin >> n >> P1 >> P2 >> P3 >> T1 >> T2;
  for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];
  for (int i = 0; i < n; ++i) sum += (r[i] - l[i]) * P1;
  for (int i = 1; i < n; ++i) {
    int64_t time = l[i] - r[i - 1], d;
    d = min(T1, time);
    time -= d;
    sum += d * P1;
    d = min(T2, time);
    time -= d;
    sum += d * P2;
    sum += time * P3;
  }
  cout << sum;
}
