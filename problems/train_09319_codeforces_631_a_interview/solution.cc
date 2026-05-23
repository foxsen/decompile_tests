#include <bits/stdc++.h>
using namespace std;
vector<int> a, b;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    b.push_back(x);
  }
  int ret = 0;
  for (int i = 0; i < n; i++) {
    int aa = a[i];
    int bb = b[i];
    ret = max(aa + bb, ret);
    for (int j = i + 1; j < n; j++) {
      aa = aa | a[j];
      bb = bb | b[j];
      ret = max(aa + bb, ret);
    }
  }
  cout << ret << endl;
  return 0;
}
