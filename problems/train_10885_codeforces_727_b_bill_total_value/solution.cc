#include <bits/stdc++.h>
using namespace std;
const long long INF = 4e18;
int digit[5];
int strToInt(string s) {
  int ans = 0;
  int it = 1;
  for (int i = 0; i < s.size(); ++i) {
    ans += (s[i] - '0') * it;
    it *= 10;
  }
  return ans;
}
int main() {
  string s;
  getline(cin, s);
  for (int i = 0; i < 5; ++i) digit[i] = 0;
  bool kop = false;
  for (int i = 0; i < s.size(); ++i) {
    string st = "";
    if (s[i] >= '0' && s[i] <= '9') {
      while (s[i] >= '0' && s[i] <= '9' || s[i] == '.') {
        st += s[i];
        ++i;
      }
      int n = st.size();
      int it = 0;
      if (st[n - 3] != '.') {
        it++;
      }
      string cur = "";
      for (int i = st.size() - 1; i >= 0; --i) {
        if (st[i] == '.') {
          digit[it] += strToInt(cur);
          cur = "";
          it++;
        } else {
          cur += st[i];
        }
      }
      digit[it] += strToInt(cur);
    }
  }
  digit[1] += digit[0] / 100;
  digit[0] %= 100;
  for (int i = 1; i < 3; ++i) {
    digit[i + 1] += digit[i] / 1000;
    digit[i] %= 1000;
  }
  int prin = 1;
  for (int i = 4; i > 0; --i) {
    if (digit[i] > 0) {
      prin = i;
      break;
    }
  }
  cout << digit[prin];
  for (int i = prin - 1; i > 0; --i) {
    cout << ".";
    if (digit[i] < 100) {
      cout << "0";
      if (digit[i] < 10) {
        cout << "0";
      }
    }
    cout << digit[i];
  }
  if (digit[0] > 0) {
    cout << ".";
    if (digit[0] < 10) {
      cout << "0";
    }
    cout << digit[0];
  }
  return 0;
}
