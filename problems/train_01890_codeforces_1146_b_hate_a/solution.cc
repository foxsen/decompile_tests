#include <bits/stdc++.h>
using namespace std;
bool isprime(unsigned long long int ar) {
  if (ar == 1) return false;
  unsigned long long int i;
  for (i = 2; i * i <= ar; i++) {
    if (ar % i == 0) return false;
  }
  return true;
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int m, k;
  string s, v = "", z = "", a = "", b = "", p;
  char t;
  cin >> s;
  for (long long int i = 0; i < s.size(); i++) {
    if (s[i] != 'a') z = z + s[i];
  }
  if (z.size() % 2) {
    cout << ":(\n";
  } else {
    m = z.size() / 2;
    k = s.size() - m;
    v = s.substr(k, s.size() - 1);
    a = z.substr(0, m);
    if (v == a) {
      s = s.substr(0, k);
      cout << s << endl;
    } else
      cout << ":(\n";
  }
}
