#include <bits/stdc++.h>
using namespace std;
template <typename T>
void input(vector<T>& v, T n) {
  for (T i = 0; i < n; i++) {
    cin >> v[i];
  }
}
int main() {
  int t;
  long long n;
  cin >> t;
  int Case = 0;
  while (t--) {
    cin >> n;
    map<long long, long long> mp1;
    vector<long long> v(n), v2(n);
    for (int i = 0; i < n; i++) {
      mp1.insert({i, 0});
      cin >> v[i];
      if (v[i] >= 0) {
        v2[i] = v[i] % n;
      } else {
        v2[i] = n - (abs(v[i])) % n;
      }
      long long z = (v2[i] + i) % n;
      mp1[z]++;
    }
    int flag = 1;
    for (int i = 0; i < n; i++) {
      if (mp1[i] == 0) {
        flag = 0;
        break;
      }
    }
    if (flag == 0) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}
