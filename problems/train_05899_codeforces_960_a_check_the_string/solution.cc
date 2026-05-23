#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10, OO = 1e9;
const long long MOD = 998244353;
int n;
void print(string s) {
  cout << s << endl;
  exit(0);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  string t = s;
  sort(t.begin(), t.end());
  n = s.size();
  int a = 0, b = 0, c = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] != t[i]) print("NO");
    if (s[i] == 'a') ++a;
    if (s[i] == 'b') ++b;
    if (s[i] == 'c') ++c;
  }
  if (a == 0 || b == 0) print("NO");
  if (c == a || c == b) print("YES");
  print("NO");
}
