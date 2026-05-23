#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int a = n - k;
  a /= 2;
  int r = 0;
  for (int i = 0; i < n; i++) {
    cout << ((i + 1) % (a + 1) == 0);
  }
  cout << endl;
}
