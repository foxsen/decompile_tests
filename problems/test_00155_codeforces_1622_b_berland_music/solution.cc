#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e9 + 7;
const int N = 1e5 + 10;
vector<int> vis(N);
int g[1001][1001];
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long expo(long long a, long long b, long long mod) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    vector<long long> v1;
    vector<long long> v2;
    map<char, long long> m1;
    for (long long i = 0; i < n; i++) cin >> v[i];
    string s;
    cin >> s;
    for (long long i = 0; i < n; i++) {
      m1[s[i]] += 1;
      if (s[i] == '0') {
        v1.push_back(v[i]);
      } else {
        v2.push_back(v[i]);
      }
    }
    if (m1['0'] == 0 || m1['1'] == 0) {
      for (long long i = 0; i < n; i++) cout << v[i] << " ";
    } else {
      sort(v1.begin(), v1.end());
      sort(v2.begin(), v2.end());
      map<int, int> m2;
      for (long long i = 0; i < v1.size(); i++) {
        m2[v1[i]] = i + 1;
      }
      long long x = v1.size();
      for (long long i = 0; i < v2.size(); i++) {
        m2[v2[i]] = x + 1;
        x += 1;
      }
      for (long long i = 0; i < n; i++) {
        cout << m2[v[i]] << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}
