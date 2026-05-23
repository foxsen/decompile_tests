#include <bits/stdc++.h>
using namespace std;
template <typename T>
string toString(T x) {
  if (x == 0) return "0";
  bool negative = x < 0;
  string res;
  while (x) {
    res.push_back('0' + x % 10);
    x /= 10;
  }
  if (negative) res.push_back('-');
  reverse(res.begin(), res.end());
  return res;
}
template <typename T>
T gcd(T a, T b) {
  return a == 0 ? b : gcd(b % a, a);
}
template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
void ioFromFile(string inputFileName = "input.txt",
                string outputFileName = "output.txt") {
  ifstream* fin = new ifstream(inputFileName);
  ofstream* fout = new ofstream(outputFileName);
  cin.rdbuf(fin->rdbuf());
  cout.rdbuf(fout->rdbuf());
}
int read() {
  int res;
  scanf("%d", &res);
  return res;
}
void write(int x) { printf("%d ", x); }
int main() {
  string s;
  cin >> s;
  int at = 2;
  string res = s.substr(0, 2);
  for (int i = 2; i < (int)s.length(); i++) {
    if (s[i] == res[at - 1] && s[i] == res[at - 2]) continue;
    res.push_back(s[i]);
    at++;
  }
  s = res;
  res = res.substr(0, 3);
  at = 3;
  for (int i = 3; i < (int)s.length(); i++) {
    if (s[i] == res[at - 1] && res[at - 2] == res[at - 3]) continue;
    res.push_back(s[i]);
    at++;
  }
  cout << res;
  return 0;
}
