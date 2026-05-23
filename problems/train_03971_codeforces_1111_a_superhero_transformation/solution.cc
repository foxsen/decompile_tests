#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long maxn = 1000 + 3;
int main() {
  string aa, bb;
  cin >> aa >> bb;
  long long la = aa.length(), lb = bb.length();
  map<char, int> m;
  char lo = 'a';
  m[lo] = 1;
  lo = 'e';
  m[lo] = 1;
  lo = 'i';
  m[lo] = 1;
  lo = 'o';
  m[lo] = 1;
  lo = 'u';
  m[lo] = 1;
  long long flag = 0;
  if (la != lb) {
    cout << "No";
    return 0;
  }
  for (int i = 0; i < la; i++) {
    if (m[aa[i]] != m[bb[i]]) flag = 1;
  }
  if (flag)
    cout << "No";
  else
    cout << "Yes";
  return 0;
}
