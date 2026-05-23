#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  double x, y, z, w;
  cin >> x >> y >> z >> w;
  if (x > z) {
    if (ceil(x / z) * y > w + y) {
      cout << "YES";
    } else {
      cout << "NO";
    }
  } else {
    cout << "NO";
  }
}
