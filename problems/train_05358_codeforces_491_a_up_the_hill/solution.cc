#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long a, b, n;
  cin >> a >> b;
  n = a + b + 1;
  for (int i = b + 1; i <= n; i++) cout << i << " ";
  for (int i = b; i >= 1; i--) cout << i << " ";
}
