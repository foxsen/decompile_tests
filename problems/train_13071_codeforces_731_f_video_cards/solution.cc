#include <bits/stdc++.h>
using namespace std;
long long t[2020202];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    ++t[a];
  }
  for (int i = 1; i <= 2e6; ++i) t[i] += t[i - 1];
  long long V = 0, s = 0;
  for (int i = 1; i <= 2e5; ++i) {
    s = 0;
    if (t[i] - t[i - 1] > 0)
      for (long long j = i; j <= 2e5 + 1; j += i)
        s += j * (t[j + i - 1] - t[j - 1]);
    V = max(V, s);
  }
  cout << V;
}
