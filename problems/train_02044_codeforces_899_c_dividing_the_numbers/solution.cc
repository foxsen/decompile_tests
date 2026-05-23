#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long sum;
  vector<int> v;
  ios::sync_with_stdio(0);
  cin >> n;
  sum = (1LL + n) * n / 2LL;
  if (sum % 2LL == 0LL) {
    sum /= 2LL;
    for (int i = n; i >= 1; i--)
      if (sum >= i) {
        v.push_back(i);
        sum -= i;
      }
    cout << "0" << endl;
    cout << v.size();
    for (int i = 0; i < v.size(); i++) cout << " " << v[i];
    cout << endl;
  } else {
    sum /= 2LL;
    for (int i = n; i >= 1; i--)
      if (sum >= i) {
        v.push_back(i);
        sum -= i;
      }
    cout << "1" << endl;
    cout << v.size();
    for (int i = 0; i < v.size(); i++) cout << " " << v[i];
    cout << endl;
  }
  return 0;
}
