#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  vector<bool> vis(n, false);
  vector<int> level(n);
  int p;
  for (int i = 0; i < n; i++) {
    cin >> p;
    v[i] = (p - 1);
  }
  bool flag = false;
  for (int i = 0; i < n; i++) {
    if (v[v[v[i]]] == i) {
      cout << "YES";
      flag = true;
      break;
    }
  }
  if (flag == false) {
    cout << "NO";
  }
}
