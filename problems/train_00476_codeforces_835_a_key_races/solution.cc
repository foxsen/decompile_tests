#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, v1, v2, t1, t2;
  cin >> s >> v1 >> v2 >> t1 >> t2;
  int st = s * v1 + t1 * 2, nd = s * v2 + t2 * 2;
  if (st < nd) {
    cout << "First";
  } else if (st > nd) {
    cout << "Second";
  } else {
    cout << "Friendship";
  }
  return 0;
}
