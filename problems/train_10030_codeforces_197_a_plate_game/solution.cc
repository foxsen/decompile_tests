#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, r;
  cin >> n >> m >> r;
  if (2 * r > min(n, m))
    cout << "Second";
  else
    cout << "First";
  return 0;
}
