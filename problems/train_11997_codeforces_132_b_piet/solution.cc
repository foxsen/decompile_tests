#include <bits/stdc++.h>
using namespace std;
const int maxn = 262, hm = 52 * 52, maxt = 200;
const long long INF = 1000;
const long double EPS = 1E-9, EPS2 = 1E-8;
const long double M_PIS = 3.14159265358979323846264338327950288;
unsigned char color[hm];
string s[maxn];
pair<int, int> deltas[4];
pair<int, int> pix[hm][4][4];
int used[maxn][maxn], numb = 0, m, p, whose[maxn][maxn], was[hm][4][4];
pair<int, int> cmp(pair<int, int> a, pair<int, int> b, int dp, int cp) {
  if (a.first == -1) return b;
  if (b.first == -1) return a;
  if (dp == 0 && ((a.first < b.first) ||
                  (a.first == b.first && ((a.second < b.second) != cp))))
    return a;
  if (dp == 1 && ((a.second > b.second) ||
                  (a.second == b.second && ((a.first < b.first) != cp))))
    return a;
  if (dp == 2 && ((a.first > b.first) ||
                  (a.first == b.first && ((a.second > b.second) != cp))))
    return a;
  if (dp == 3 && ((a.second < b.second) ||
                  (a.second == b.second && ((a.first > b.first) != cp))))
    return a;
  return b;
}
void dfs(int i, int j, unsigned char c) {
  if (i < 0 || i >= m || j < 0 || j >= p || used[i][j] || s[i][j] != c) return;
  used[i][j] = 1;
  whose[i][j] = numb;
  for (int k = 0; k < 4; ++k)
    for (int l = 0; l < 2; ++l)
      pix[numb][k][l] = cmp(make_pair(i, j), pix[numb][k][l], k, l);
  dfs(i + 1, j, c);
  dfs(i, j + 1, c);
  dfs(i - 1, j, c);
  dfs(i, j - 1, c);
}
pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
void bfs(int id, int dp, int cp, int ost) {
  if (was[id][dp][cp]) {
    ost = (ost % (was[id][dp][cp] - ost));
  }
  was[id][dp][cp] = ost;
  if (ost == 0) {
    cout << color[id] << endl;
    exit(0);
  }
  pair<int, int> px = pix[id][dp][cp] + deltas[dp];
  if (px.first < 0 || px.first >= m || px.second < 0 || px.second >= p ||
      s[px.first][px.second] == '0') {
    if (cp == 0)
      bfs(id, dp, 1, ost - 1);
    else
      bfs(id, (dp + 1) % 4, 0, ost - 1);
  } else
    bfs(whose[px.first][px.second], dp, cp, ost - 1);
}
int main() {
  deltas[0] = make_pair(-1, 0);
  deltas[1] = make_pair(0, 1);
  deltas[2] = make_pair(1, 0);
  deltas[3] = make_pair(0, -1);
  int k, tmp, n;
  cin >> m >> n;
  for (int i = 0; i < m; ++i) cin >> s[i];
  p = s[0].size();
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < s[i].size(); ++j)
      if (!used[i][j] && s[i][j] != '0') {
        color[numb] = s[i][j];
        for (int k = 0; k < 4; ++k)
          for (int l = 0; l < 2; ++l) pix[numb][k][l] = make_pair(-1, 0);
        dfs(i, j, s[i][j]);
        ++numb;
      }
  bfs(0, 1, 0, n);
}
