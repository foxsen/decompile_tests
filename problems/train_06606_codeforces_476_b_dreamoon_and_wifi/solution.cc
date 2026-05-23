#include <bits/stdc++.h>
using namespace std;
int fact(int n) {
  int f = 1;
  while (n > 1) {
    f = f * n;
    n--;
  }
  return f;
}
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int l = s1.length();
  int c1plus = 0, c2plus = 0, c1minus = 0, c2minus = 0, question = 0, s1sum = 0,
      s2sum = 0, i;
  int reqminus = 0, reqplus = 0;
  double ans = 0.000000000000;
  for (i = 0; i < l; i++) {
    if (s1[i] == '+') {
      c1plus++;
      s1sum++;
    } else {
      c1minus++;
      s1sum--;
    }
    if (s2[i] == '+') {
      c2plus++;
      s2sum++;
    } else if (s2[i] == '-') {
      c2minus++;
      s2sum--;
    } else {
      question++;
    }
  }
  if (c1plus == c2plus && c1minus == c2minus) {
    cout << "1.000000000000";
    return 0;
  }
  if (((c1plus != c2plus) || (c2minus != c1minus)) && question == 0) {
    cout << "0.000000000000";
    return 0;
  }
  if ((c1plus - c1minus <= c2plus - c2minus + question) &&
      (c1plus - c1minus >= c2plus - c2minus - question)) {
    int val = s1sum - s2sum;
    if (val < 0)
      reqminus = abs(val);
    else if (val > 0) {
      reqplus = val;
    }
    int nut = question - reqplus - reqminus;
    reqminus += nut / 2;
    reqplus += nut / 2;
    ans = (double)fact(question) / fact(reqplus);
    ans = ans / fact(abs(question - reqplus));
    ans = ans / (1 << question);
    cout << fixed;
    cout << setprecision(12) << ans;
  } else {
    cout << "0.000000000000";
  }
  return 0;
}
