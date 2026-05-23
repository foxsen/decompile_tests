#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    long long a, b, N, s;
    cin >> a >> b >> N >> s;
    if (s > N * a + b || b < s % N)
      cout << "NO" << endl;
    else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
