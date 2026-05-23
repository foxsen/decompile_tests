#include <bits/stdc++.h>
using namespace std;
struct node {
  long long no, cnt, len, prc;
};
long long n, k, a, b;
long long plc[100005];
vector<node> s, s1;
signed main() {
  cin >> n >> k >> a >> b;
  long long mu = 1 << n;
  for (long long i = 1; i <= k; i++) {
    cin >> plc[i];
  }
  sort(plc + 1, plc + k + 1);
  long long it = 0;
  plc[0] = plc[1];
  for (long long i = 1; i <= k; i++) {
    if (plc[i] != plc[i - 1]) {
      s.emplace_back((node){plc[i - 1] + mu - 1, it, 1, b * it});
      it = 1;
    } else
      it++;
  }
  s.emplace_back((node){plc[k] + mu - 1, it, 1, b * it});
  while (s[0].no != 1) {
    s1.clear();
    for (long long i = 0; i < s.size(); i++) {
      if (i == s.size() - 1 || s[i].no / 2 != s[i + 1].no / 2) {
        s1.emplace_back((node){s[i].no / 2, s[i].cnt, s[i].len * 2,
                               min(a + s[i].prc, s[i].cnt * b * s[i].len * 2)});
      } else {
        s1.emplace_back(
            (node){s[i].no / 2, s[i].cnt + s[i + 1].cnt, s[i].len * 2,
                   min(s[i].prc + s[i + 1].prc,
                       (s[i].cnt + s[i + 1].cnt) * b * s[i].len * 2)});
        i++;
      }
    }
    s = s1;
  }
  cout << s[0].prc;
}
