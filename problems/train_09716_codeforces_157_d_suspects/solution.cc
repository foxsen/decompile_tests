#include <bits/stdc++.h>
using namespace std;
int acc[100005];
int nacc[100005];
int nc;
int a[100005];
int lied[100005];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > 0) {
      acc[a[i]]++;
    } else if (a[i] < 0) {
      nacc[-1 * a[i]]++;
      nc++;
    }
  }
  int lie = 0;
  for (int i = 1; i <= n; i++) {
    int temp = acc[i];
    temp += (nc - nacc[i]);
    if (temp == m) {
      lied[i] = 1;
      lie++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] > 0) {
      if (lied[a[i]]) {
        if (lie == 1) {
          cout << "Truth" << endl;
        } else {
          cout << "Not defined" << endl;
        }
      } else {
        cout << "Lie" << endl;
      }
    } else {
      if (lied[-a[i]]) {
        if (lie == 1) {
          cout << "Lie" << endl;
        } else {
          cout << "Not defined" << endl;
        }
      } else {
        cout << "Truth" << endl;
      }
    }
  }
}
