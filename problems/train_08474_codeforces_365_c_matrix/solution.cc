#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
void PLAY() {
  cout << fixed << setprecision(10);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  PLAY();
  int a;
  cin >> a;
  string s;
  cin >> s;
  map<long long, int> mp;
  long long sum = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    sum = 0;
    for (int j = i; j < (int)s.size(); j++) {
      sum += s[j] - '0';
      mp[sum]++;
    }
  }
  long long res = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    sum = 0;
    for (int j = i; j < (int)s.size(); j++) {
      sum += s[j] - '0';
      if (sum && a % sum == 0)
        res += mp[a / sum];
      else if (a + sum == 0)
        res += ((long long)(int)s.size() * ((int)s.size() + 1)) / 2;
    }
  }
  cout << res << endl;
  return 0;
}
