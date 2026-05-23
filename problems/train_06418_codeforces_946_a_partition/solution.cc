#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int LIM = 1000010;
int main() {
  cin.sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  int ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ans += abs(x);
  }
  cout << ans << endl;
}
