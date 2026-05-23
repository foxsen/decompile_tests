#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  if (min(n, m) % 2 == 0)
    cout << "Malvika"
         << "\n";
  else
    cout << "Akshat"
         << "\n";
  return 0;
}
