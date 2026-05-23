#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, l;
    cin >> n >> l;
    double t[n + 2], t1[n + 2], a[n + 2];
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    t[0] = (double)0;
    t1[n + 1] = (double)0;
    a[0] = (double)0;
    a[n + 1] = (double)l;
    int sp = (double)1;
    int in = (double)1;
    for (int i = 1; i <= n; i++) {
      t[i] = (a[i] - a[i - 1]) / sp;
      t[i] += t[i - 1];
      sp += in;
    }
    t[n + 1] = (a[n + 1] - a[n]) / sp;
    t[n + 1] += t[n];
    sp = (double)1;
    for (int i = n; i >= 1; i--) {
      t1[i] = (a[i + 1] - a[i]) / sp;
      t1[i] += t1[i + 1];
      sp += in;
    }
    t1[0] = (a[1] - a[0]) / sp;
    t1[0] += t1[1];
    for (int i = 0; i <= n + 1; i++) {
      if (t[i] > t1[i]) {
        double baseTime = t[i - 1];
        double bTime = t1[i];
        double rDist;
        bool flag = false;
        if (baseTime > bTime) {
          rDist = (baseTime - bTime) * (double)(n + (double)2 - (double)i);
        } else {
          flag = true;
          rDist = (bTime - baseTime) * (double)((double)i);
        }
        double dist = a[i] - a[i - 1] - rDist;
        double tot = n + 2;
        double ans = dist / tot;
        if (flag) {
          cout << fixed << setprecision(8) << ans + t1[i] << "\n";
        } else {
          cout << fixed << setprecision(8) << ans + t[i - 1] << "\n";
        }
        i = n + 3;
      } else if (t[i] == t1[i]) {
        cout << t[i] << "\n";
        i = n + 3;
      }
    }
  }
}
