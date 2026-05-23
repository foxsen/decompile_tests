#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vint = vector<int>;
using vll = vector<ll>;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  if (s.size() < 7) {
    cout << "no";
    return 0;
  }
  int zeros = 0;
  bool was1 = false;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') was1 = true;
    if (s[i] == '0' && was1) zeros++;
  }
  if (zeros < 6)
    cout << "no";
  else
    cout << "yes";
  return 0;
}
