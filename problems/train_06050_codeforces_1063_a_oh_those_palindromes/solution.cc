#include <bits/stdc++.h>
using namespace std;
vector<int> vv1;
int lim = 1000000;
bool prime[1000000];
void sieve() {
  memset(prime, true, sizeof(prime));
  prime[0] = prime[1] = false;
  for (int i = 2; i * i < lim; i++) {
    if (prime[i]) {
      for (int j = i * i; j < lim; j = j + i) {
        prime[j] = false;
      }
    }
  }
  for (int i = 0; i < lim; i++)
    if (prime[i]) vv1.push_back(i);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  sieve();
  long long tt, cn = 0, cn1 = 0, r = 0, l = 0, h = 0;
  tt = 1;
read:
  while (tt--) {
    vector<long long> vec2, vec1, vec, vec3, vec4, vec11;
    vector<pair<long long, long long>> ve;
    double x1, x2, x3, x4, y1, y2, y3, y4;
    long long a, d, b, c, cn = 0, sum = 0, mx = 0, mx1 = 0, cn1 = 0;
    string s;
    cin >> a >> s;
    sort(s.begin(), s.end());
    cout << s << endl;
  }
  return 0;
}
