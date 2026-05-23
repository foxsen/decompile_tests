#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (m == 0) {
    cout << "YES" << endl;
  } else {
    int a[m];
    set<int> s;
    int x;
    for (int i = 0; i < m; i++) {
      cin >> a[i];
      s.insert(a[i]);
    }
    if (s.count(1) == 1) {
      cout << "NO" << endl;
    } else if (s.count(n) == 1) {
      cout << "NO" << endl;
    } else {
      if (m < 3) {
        cout << "YES" << endl;
      } else {
        sort(a, a + m);
        int flag = 0;
        for (int i = 1; i < m - 1; i++) {
          if ((a[i] == a[i - 1] + 1) && (a[i + 1] == a[i] + 1)) {
            cout << "NO" << endl;
            flag = 1;
            break;
          }
        }
        if (!flag) {
          cout << "YES" << endl;
        }
      }
    }
  }
  return 0;
}
