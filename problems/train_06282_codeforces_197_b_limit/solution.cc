#include <bits/stdc++.h>
using namespace std;
int gcd(int n, int m) {
  while (m != 0) {
    int x;
    x = n % m;
    n = m;
    m = x;
  }
  return n;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> v1, v2;
  for (int i = 0; i < n + 1; i++) {
    int num;
    cin >> num;
    v1.push_back(num);
  }
  for (int j = 0; j < m + 1; j++) {
    int num;
    cin >> num;
    v2.push_back(num);
  }
  if (m > n) {
    cout << "0/1";
    return 0;
  }
  if (n > m) {
    if ((v1[0] * v2[0]) < 0) cout << "-";
    cout << "Infinity";
    return 0;
  }
  if ((v1[0] * v2[0]) < 0) cout << "-";
  v1[0] = abs(v1[0]);
  v2[0] = abs(v2[0]);
  cout << v1[0] / gcd(v1[0], v2[0]) << "/" << v2[0] / gcd(v1[0], v2[0]);
}
