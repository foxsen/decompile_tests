#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int L, b, f;
struct car {
  int s, t, i;
};
list<car> car;
int park(int x, int i) {
  int x0 = -b;
  for (auto it = car.begin(); it != car.end(); it++) {
    if (x0 + b + x + f <= it->s) {
      car.insert(it, {x0 + b, x0 + b + x, i});
      return x0 + b;
    }
    x0 = it->t;
  }
  if (x0 + b + x <= L) {
    car.push_back({x0 + b, x0 + b + x, i});
    return x0 + b;
  }
  return -1;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout << fixed;
  int n;
  cin >> L >> b >> f >> n;
  for (int i = 1; i <= n; i++) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      cout << park(x, i) << endl;
    } else {
      assert(t == 2);
      for (auto it = car.begin(); it != car.end(); it++) {
        if (it->i == x) {
          car.erase(it);
          break;
        }
      }
    }
  }
  return 0;
}
