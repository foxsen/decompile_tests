#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  map<int, int> m;
  int mmax = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    m[a]++;
    if (m[a] > mmax) mmax = m[a];
  }
  if (mmax <= (n + 1) / 2)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
