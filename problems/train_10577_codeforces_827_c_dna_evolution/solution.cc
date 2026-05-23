#include <bits/stdc++.h>
using namespace std;
int sum[11][11][4][100002], n, m, num[100], block, cur, ans = 0, lef[12],
                                                        ri[12], now[12];
char second[100002], ch, ss[15];
void update(int pos, int c, int val) {
  for (int i = 1; i <= 10; i++) {
    block = pos / i, cur = pos % i;
    if (cur)
      block++;
    else
      cur = i;
    for (; block <= 100002; block += (block & -block))
      sum[i][cur][c][block] += val;
  }
}
int query(int lol) {
  ans = 0;
  for (int i = 1, tmp = 0, tpp = 0; i <= lol; i++) {
    block = lef[i] - 1, tmp = 0, tpp = 0;
    for (; block > 0; block -= (block & -block))
      tmp += sum[lol][i][now[i]][block];
    block = ri[i];
    for (; block > 0; block -= (block & -block))
      tpp += sum[lol][i][now[i]][block];
    ans += (tpp - tmp);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  num['A'] = 0, num['T'] = 1, num['C'] = 2, num['G'] = 3;
  cin >> second;
  n = strlen(second);
  for (int i = 0; i < n; i++) {
    update(i + 1, num[second[i]], 1);
  }
  cin >> m;
  for (int i = 1, t, j, l, r; i <= m; i++) {
    cin >> t;
    if (t == 1) {
      cin >> t >> ch;
      update(t, num[second[t - 1]], -1);
      update(t, num[ch], 1);
      second[t - 1] = ch;
    } else {
      cin >> l >> r >> ss;
      n = strlen(ss);
      cur = l % n, block = l / n;
      if (cur == 0)
        cur = n;
      else
        block++;
      for (j = 1; j <= n; j++) {
        if (j < cur)
          lef[j] = block + 1;
        else
          lef[j] = block;
      }
      for (j = 0; j < n; j++) {
        now[cur] = num[ss[j]];
        cur++;
        if (cur > n) cur = 1;
      }
      block = r / n, cur = r % n;
      if (cur == 0)
        cur = n;
      else
        block++;
      for (j = 1; j <= n; j++) {
        if (j <= cur)
          ri[j] = block;
        else
          ri[j] = block - 1;
      }
      cout << query(n) << "\n";
    }
  }
  return 0;
}
