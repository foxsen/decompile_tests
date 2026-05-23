#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7ll;
const int N = (int)1e5 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int flag = 0;
    for (int i = n; i >= 1; i--) {
      if (a[i] != i) {
        flag = 1;
        break;
      }
    }
    if (!flag) {
      cout << "0" << endl;
    } else {
      flag = 0;
      int tmp;
      for (int i = n; i >= 1; i--) {
        if (a[i] != i && flag == 0) {
          flag = 1;
        }
        if (a[i] == i && flag == 1) {
          flag = 2;
          tmp = i;
        }
      }
      if (flag == 2) {
        flag = 1;
        for (int i = 1; i <= tmp; i++) {
          if (a[i] != i) {
            flag = 2;
            break;
          }
        }
      }
      cout << flag << endl;
    }
  }
}
