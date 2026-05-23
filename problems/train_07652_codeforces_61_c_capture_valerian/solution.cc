#include <bits/stdc++.h>
using namespace std;
struct Digit {
  vector<int> d;
  Digit() {}
  Digit(long long n, int b) {
    if (!n) {
      d.push_back(0);
      return;
    }
    for (; n; n /= b) d.push_back(n % b);
  }
  void out() {
    for (int i = (((int)(d).size())) - 1; i >= (0); --i)
      printf("%c", d[i] <= 9 ? d[i] + '0' : d[i] - 10 + 'A');
  }
};
const int rom[30] = {3000, 2000, 1000, 900, 800, 700, 600, 500, 400, 300,
                     200,  100,  90,   80,  70,  60,  50,  40,  30,  20,
                     10,   9,    8,    7,   6,   5,   4,   3,   2,   1};
string smb[30] = {"MMM", "MM",  "M",   "CM",  "DCCC", "DCC",  "DC",   "D",
                  "CD",  "CCC", "CC",  "C",   "XC",   "LXXX", "LXX",  "LX",
                  "L",   "XL",  "XXX", "XX",  "X",    "IX",   "VIII", "VII",
                  "VI",  "V",   "IV",  "III", "II",   "I"};
string toRoman(long long d) {
  string r;
  for (int i = (0); i < (30); ++i)
    if (d >= rom[i]) d -= rom[i], r += smb[i];
  return r;
}
char str[5000];
long long read(int b) {
  scanf(" %s", str);
  int len = strlen(str);
  long long ret = 0;
  for (int i = (0); i < (len); ++i) {
    int d = str[i] - '0';
    if (d < 0 || d > 9) d += '0' - 'A' + 10;
    ret = ret * b + d;
  }
  return ret;
}
int a;
char strb[100];
int getb() {
  int b = 0;
  for (int i = (0); i < (strlen(strb)); ++i) b = b * 10 + strb[i] - '0';
  return b;
}
void solve() {
  if (strb[0] != 'R')
    Digit(read(a), getb()).out();
  else
    printf("%s", toRoman(read(a)).c_str());
  puts("");
}
int main() {
  while (~scanf("%d %s", &a, strb)) solve();
  return 0;
}
