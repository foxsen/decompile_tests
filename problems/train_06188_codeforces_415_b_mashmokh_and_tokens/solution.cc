#include <bits/stdc++.h>
using namespace std;
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  fast();
  long long n, a, b, i, x;
  cin >> n >> a >> b;
  for (i = 0; i < n; i++) {
    cin >> x;
    cout << ((x * a) % b) / a << " ";
  }
  return 0;
}
