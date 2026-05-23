#include <bits/stdc++.h>
using namespace std;
bool is_pal(int n, int a, int b) {
  if (a < 0 || b < 0) return false;
  bool a_even = a % 2 == 0;
  bool b_even = b % 2 == 0;
  if (n % 2 == 0) {
    if (!a_even || !b_even) return false;
    return true;
  } else {
    if (a_even || b_even) return true;
    if (a == 0 || b == 0) return true;
    return false;
  }
}
struct check {
  int zeros;
  int ones;
  int length;
};
int32_t main() {
  ios_base::sync_with_stdio(false);
  int Q;
  cin >> Q;
  for (int q = 0; q < Q; q++) {
    int n;
    cin >> n;
    vector<check> ans;
    int cur_res = 0;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      int zeros = 0;
      int ones = 0;
      for (int j = 0; j < s.length(); j++) {
        int num = s[j] - '0';
        if (num)
          ones++;
        else
          zeros++;
      }
      check cur;
      cur.ones = ones;
      cur.zeros = zeros;
      cur.length = s.length();
      ans.push_back(cur);
    }
    for (int i = 0; i < ans.size(); i++) {
      check x = ans[i];
      if (!is_pal(x.length, x.ones, x.zeros)) {
        for (int j = 0; j < ans.size(); j++) {
          if (i == j) continue;
          check y = ans[j];
          if (is_pal(x.length, x.ones - 1, x.zeros + 1) &&
              is_pal(y.length, y.ones + 1, y.zeros - 1)) {
            ans[j].ones++;
            ans[j].zeros--;
            ans[i].ones--;
            ans[i].zeros++;
            break;
          } else if (is_pal(x.length, x.ones + 1, x.zeros - 1) &&
                     is_pal(y.length, y.ones - 1, y.zeros + 1)) {
            ans[j].ones--;
            ans[j].zeros++;
            ans[i].ones++;
            ans[i].zeros--;
            break;
          }
        }
      }
    }
    for (int i = 0; i < ans.size(); i++) {
      check x = ans[i];
      if (is_pal(x.length, x.ones, x.zeros)) {
        cur_res++;
      }
    }
    cout << cur_res << endl;
  }
  return 0;
}
