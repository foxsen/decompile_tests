#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  }
  if (b == 0) {
    return a;
  }
  if (a > b) {
    return gcd(a % b, b);
  } else {
    return gcd(b % a, a);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  long long a[n + 1];
  long long k = 1, a1 = 0, a2 = 1110;
  for (int i = 1; i < n + 1; i++) cin >> a[i];
  for (int i = 1; i < n + 1; i++) {
    bool v[201] = {0};
    long long c = 0, c1 = 0;
    int j = a[i];
    while (v[j] != 1) {
      v[j] = 1;
      c++;
      j = a[j];
    }
    bool v1[201] = {0};
    while (v1[j] != 1) {
      c1++;
      v1[j] = 1;
      j = a[j];
    }
    a1 = max(a1, c - c1);
    k = c1 * k / gcd(c1, k);
  }
  long long an = k;
  while (an <= a1) {
    an += k;
  }
  cout << an << "\n";
  return 0;
}
