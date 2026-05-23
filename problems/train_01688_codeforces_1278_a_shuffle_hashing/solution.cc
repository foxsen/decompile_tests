#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
int main() {
  long long x, i, j, k, flag;
  cin >> x;
  string s, s1;
  vector<char> v, v1;
  for (i = 0; i < x; i++) {
    cin >> s;
    cin >> s1;
    if (s.size() <= s1.size()) {
      for (j = 0; j < s.size(); j++) {
        v.push_back(s[j]);
      }
      sort(v.begin(), v.end());
      for (j = 0; j <= s1.size() - s.size(); j++) {
        for (k = j; k < j + s.size(); k++) {
          v1.push_back(s1[k]);
        }
        flag = 0;
        sort(v1.begin(), v1.end());
        for (k = 0; k < v1.size(); k++) {
          if (v1[k] != v[k]) {
            flag = 1;
            break;
          }
        }
        if (flag == 0) {
          break;
        }
        v1.clear();
      }
      v.clear();
      v1.clear();
      if (flag == 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      cout << "NO" << endl;
    }
    v.clear();
    v1.clear();
  }
}
