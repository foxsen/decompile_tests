#include <bits/stdc++.h>
using namespace std;
bool win(long long a, long long b) {
  if (a == 0) return false;
  if (!win(b % a, a)) return true;
  return !(((b / a) % (a + 1)) % 2);
}
int main() {
  ios::sync_with_stdio(false);
  int i, n;
  long long a, b;
  cin >> n;
  for ((i) = 0; (i) < (n); (i)++) {
    cin >> a >> b;
    if (a > b) swap(a, b);
    cout << (win(a, b) ? "First" : "Second") << endl;
  }
  return 0;
}
