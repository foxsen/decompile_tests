#include <bits/stdc++.h>
using namespace std;
int power(int b, int a = 10) {
  int res = 1;
  for (; b; b >>= 1, a = (long long)a * a % 1000000007)
    if (b & 1) res = (long long)res * a % 1000000007;
  return res;
}
struct node {
  int x, y;
  node() {}
  node(int x, int y) : x(x), y(y) {}
  node(string &s) {
    x = s.size();
    y = 0;
    for (int i = 0; i < x; ++i)
      y = ((long long)y * 10 + (s[i] - '0')) % 1000000007;
  }
  node operator+(const node &a) {
    return node((x + a.x) % (1000000007 - 1),
                ((long long)y * power(a.x) + a.y) % 1000000007);
  }
  node operator^(string &s) {
    int re = 0;
    for (int i = 0; i < s.size(); ++i)
      re = ((long long)re * 10 + (s[i] - '0')) % (1000000007 - 1);
    if (!x) return node(0, (long long)y * re % 1000000007);
    int tx = power(x);
    int tmp = (long long)(power(re, tx) + 1000000007 - 1) *
              power(1000000007 - 2, tx + 1000000007 - 1) % 1000000007 * y %
              1000000007;
    return node((long long)re * x % (1000000007 - 1), tmp);
  }
};
string get(string &s, int &i) {
  string res;
  while (isdigit(s[i])) res += s[i++];
  return res;
}
int del(string &L, string &R) {
  int l = L.size(), re = 0;
  for (int i = 0; i < l; ++i)
    re = ((long long)re * 10 + (R[i] - L[i])) % (1000000007 - 1);
  return re;
}
node range(string &L, string &R) {
  if (L.size() == R.size()) {
    int nL = node(L).y, nR = node(R).y;
    int x = power(L.size());
    int z = (del(L, R) + 1) % (1000000007 - 1);
    int tmp = ((long long)nL * power(z, x) - nR + 1000000007) % 1000000007 *
              power(1000000007 - 2, x + 1000000007 - 1) % 1000000007;
    (tmp += (long long)(power(z, x) + 1000000007 - x) *
            power(1000000007 - 2, (long long)(x + 1000000007 - 1) *
                                      (x + 1000000007 - 1) % 1000000007) %
            1000000007) %= 1000000007;
    return node(int((long long)L.size() * z % (1000000007 - 1)), tmp);
  } else {
    string LM = string(L.size(), '9');
    string RM = "1" + string(R.size() - 1, '0');
    node res = range(L, LM);
    int nL = power(L.size()),
        nR = ((long long)nL * 10 + 1000000007 - 1) % 1000000007;
    int x = power(L.size() + 1);
    int z = 9;
    for (int i = 1; i <= L.size(); ++i)
      z = (long long)z * 10 % (1000000007 - 1);
    for (int i = L.size() + 1; i < R.size(); ++i) {
      int tmp = ((long long)nL * power(z, x) - nR + 1000000007) % 1000000007 *
                power(1000000007 - 2, x + 1000000007 - 1) % 1000000007;
      (tmp += (long long)(power(z, x) + 1000000007 - x) *
              power(1000000007 - 2, (long long)(x + 1000000007 - 1) *
                                        (x + 1000000007 - 1) % 1000000007) %
              1000000007) %= 1000000007;
      res = res + node((long long)i * z % (1000000007 - 1), tmp);
      nL = (long long)nL * 10 % 1000000007,
      nR = ((long long)nL * 10 + 1000000007 - 1) % 1000000007;
      x = (long long)x * 10 % 1000000007;
      z = (long long)z * 10 % (1000000007 - 1);
    }
    return res + range(RM, R);
  }
}
node work(string &s, int &i) {
  node tmp(0, 0);
  string num = "";
  int l = s.size();
  while (i < l) {
    if (isdigit(s[i])) num = get(s, i);
    if (i == l) break;
    char ty = s[i++];
    if (ty == ')') return tmp + node(num);
    if (ty == '(') tmp = tmp + (work(s, i) ^ num);
    if (ty == '+') tmp = tmp + node(num);
    if (ty == '-') {
      string num2 = get(s, i);
      tmp = tmp + range(num, num2);
    }
    num.clear();
  }
  return tmp + node(num);
}
int main() {
  string s;
  cin >> s;
  int i = 0;
  printf("%d\n", work(s, i).y);
  return 0;
}
