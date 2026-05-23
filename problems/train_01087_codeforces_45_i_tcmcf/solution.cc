#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 1, 0, 0, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0, 0, 0};
const int inf = 10000000;
int main() {
  int n;
  cin >> n;
  int a[n];
  int pos = 0, neg = 0, zero = 0;
  vector<int> ne;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0)
      zero++;
    else if (a[i] > 0) {
      pos++;
      cout << a[i] << " ";
    } else {
      neg++;
      ne.push_back(a[i]);
    }
  }
  if (pos) {
    sort(ne.begin(), ne.end());
    for (int i = 0; i < ne.size(); i += 2) {
      if (i + 1 < ne.size()) {
        cout << ne[i] << " " << ne[i + 1] << " ";
      }
    }
  } else {
    if (neg == 1) {
      if (zero)
        cout << 0 << endl;
      else
        cout << a[0] << endl;
    } else {
      if (neg == 0)
        cout << 0 << endl;
      else {
        sort(ne.begin(), ne.end());
        for (int i = 0; i < ne.size(); i += 2) {
          if (i + 1 < ne.size()) {
            cout << ne[i] << " " << ne[i + 1] << " ";
          }
        }
      }
    }
  }
  return 0;
}
