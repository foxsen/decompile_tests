#include <bits/stdc++.h>
using namespace std;
int t;
long long a, b;
bool kt(long long n) {
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}
void xuly() {
  cin >> a >> b;
  long long s1 = a + b;
  long long s2 = a - b;
  if (kt(s1) && s2 == 1) {
    cout << "YES";
  } else
    cout << "NO";
  cout << "\n";
}
int main() {
  scanf("%d", &t);
  while (t--) {
    xuly();
  }
  return 0;
}
