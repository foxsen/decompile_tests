#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  long long g = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    g = gcd(g, a[i]);
  }
  sort(a.begin(), a.end());
  int res = (a[a.size() - 1] / g - a.size()) % 2;
  cout << (res ? "Alice\n" : "Bob\n");
}
