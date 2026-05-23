#include <bits/stdc++.h>
using namespace std;
void file() {}
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long setbit(long long num, int idx, int val = 1) {
  return (val) ? (num | (1 << idx)) : (num & ~(1 << idx));
}
long long getbit(long long num, int idx) { return ((num >> idx) & 1) == 1; }
int contbit(int num) {
  int ret = 0;
  while (num) {
    if (num % 2) ret++;
    num /= 2;
  }
  return ret;
}
int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
long long foo(string s) {
  long long sum = 1;
  for (int i = 0; i < s.size(); i++) {
    if (i + 1 == s.size() && s[i] == '0') continue;
    sum *= s[i] - '0';
  }
  return sum;
}
int main() {
  file();
  fast();
  string s;
  cin >> s;
  string z = s;
  long long sum = foo(s);
  reverse(s.begin(), s.end());
  for (int i = 1; i < s.size(); i++)
    if (s[i] != '0') {
      s[i]--;
      for (int j = 0; j < i; j++) s[j] = '9';
      sum = max(sum, foo(s));
    }
  cout << sum;
}
