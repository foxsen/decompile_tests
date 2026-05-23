#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;
int Dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int Dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long powm(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b % 2) res *= a;
    a *= a;
    b /= 2;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  vector<pair<string, int> > v;
  map<int, int> m;
  int n, x;
  string s;
  cin >> n;
  while (n--) {
    cin >> s;
    if (s == "insert") {
      cin >> x;
      m[x]++;
      v.push_back({"insert", x});
    } else if (s == "getMin") {
      cin >> x;
      while (m.size() && m.begin()->first < x) {
        m.begin()->second--;
        if (m.begin()->second == 0) m.erase(m.begin());
        v.push_back({"removeMin", 1});
      }
      if (m.size() == 0 || m.begin()->first != x) {
        v.push_back({"insert", x});
        m[x]++;
      }
      v.push_back({"getMin", x});
    } else {
      if (m.size() == 0) {
        v.push_back({"insert", 1});
        m[1]++;
      }
      m.begin()->second--;
      if (m.begin()->second == 0) m.erase(m.begin());
      v.push_back({"removeMin", 1});
    }
  }
  cout << v.size() << '\n';
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].first;
    if (v[i].first != "removeMin") cout << " " << v[i].second;
    cout << '\n';
  }
  return 0;
}
