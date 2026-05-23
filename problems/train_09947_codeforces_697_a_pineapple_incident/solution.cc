#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, s, x;
  cin >> t >> s >> x;
  if ((x - t) < s && x != t) {
    cout << "NO";
    return 0;
  }
  if (((x - t) % s != 0) && ((x - t - 1) % s != 0)) {
    cout << "NO";
    return 0;
  }
  cout << "YES";
  return 0;
}
