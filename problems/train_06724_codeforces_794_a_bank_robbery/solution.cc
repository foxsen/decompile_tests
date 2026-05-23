#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int n;
  cin >> n;
  int res = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x > b && x < c) res++;
  }
  cout << res;
  return 0;
}
