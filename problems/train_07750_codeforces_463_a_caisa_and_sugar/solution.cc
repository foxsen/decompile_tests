#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:667177216")
const long long mod = 1000000007;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, s;
  cin >> n >> s;
  s *= 100;
  long long mx = -1;
  for (int i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    a = a * 100 + b;
    if (s < a) continue;
    mx = max(mx, (s - a) % 100);
  }
  cout << mx;
  return 0;
}
