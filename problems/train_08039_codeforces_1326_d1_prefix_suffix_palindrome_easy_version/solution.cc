#include <bits/stdc++.h>
using namespace std;
const long long int INF = 3000000000000000000;
bool isPalindrome(string str) {
  int l = 0;
  int h = str.size() - 1;
  while (h > l) {
    if (str[l++] != str[h--]) {
      return false;
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int T = 1, xp = 1;
  cin >> T;
  while (T--) {
    long long int i = 0, j = 0, n, x = 0, y = 0, m, k = 0, l = 0, r = 0, o = 0,
                  cnt1 = INT_MAX, cnt2 = 0, cnt3 = INT_MIN, cnt4 = 0,
                  min1 = INT_MIN;
    string s;
    cin >> s;
    n = s.size();
    if (n == 1) {
      cout << s << endl;
      continue;
    }
    string pp;
    long long int ans = 0;
    l = 0;
    r = n - 1;
    string a, b;
    cnt2 = 0;
    string ans1, ans2;
    while (l <= r) {
      if (s[l] == s[r]) {
        if (l < r) {
          a += s[l];
          b += s[r];
          cnt2 += 2;
        }
        l++;
        r--;
        if (l == r) {
          a += s[l];
          reverse(b.begin(), b.end());
          ans1 = a + b;
          break;
        }
        if (l > r) {
          reverse(b.begin(), b.end());
          ans1 = a + b;
        }
      } else {
        reverse(b.begin(), b.end());
        string temp = a;
        string kkk = s.substr(l, r - l + 1);
        n = kkk.size();
        vector<int> d1(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
          int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
          while (0 <= i - k && i + k < n && kkk[i - k] == kkk[i + k]) {
            k++;
          }
          d1[i] = k--;
          if (i + k > r) {
            l = i - k;
            r = i + k;
          }
        }
        vector<int> d2(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
          int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
          while (0 <= i - k - 1 && i + k < n && kkk[i - k - 1] == kkk[i + k]) {
            k++;
          }
          d2[i] = k--;
          if (i + k > r) {
            l = i - k - 1;
            r = i + k;
          }
        }
        long long int mx = 0, idx = -1;
        for (i = 0; i < d1.size(); i++) {
          if (mx < d1[i] && ((d1[i] == (n - i)) || (d1[i] == (i + 1)))) {
            mx = d1[i];
            idx = i;
          }
        }
        long long int mx1 = 0, idx1 = -1;
        for (i = 0; i < d2.size(); i++) {
          if (mx1 < d2[i] && (d2[i] == (n - i) || d2[i] == (i))) {
            mx1 = d2[i];
            idx1 = i;
          }
        }
        string cr1, cr2;
        if (idx != -1) cr1 = kkk.substr(idx - mx + 1, 2 * mx - 1);
        if (idx1 != -1) {
          cr2 = kkk.substr(idx1 - mx1, 2 * mx1);
        }
        ans1 = a + cr1 + b;
        ans2 = a + cr2 + b;
        break;
      }
    }
    m = ans1.size();
    n = ans2.size();
    if (m > n) {
      cout << ans1 << endl;
    } else {
      cout << ans2 << endl;
    }
  }
}
