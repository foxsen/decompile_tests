#include <bits/stdc++.h>
using namespace std;
double const pi = 3.1415926535897932384626433832795;
int const NMAX = 101;
int const MMAX = 1441 * 30;
int n, m, k, t[NMAX];
char name[NMAX][50];
bool used[MMAX];
pair<pair<int, int>, pair<int, int> > p[NMAX];
int ans[NMAX][MMAX];
int prev1[NMAX][MMAX];
int prev2[NMAX][MMAX];
int read_data() {
  char ch1, ch2, ch3, ch4, ch5;
  cin >> ch1;
  while (ch1 <= ' ') cin >> ch1;
  cin >> ch2 >> ch3 >> ch4 >> ch5;
  return 60 * (10 * (ch1 - '0') + ch2 - '0') + 10 * (ch4 - '0') + ch5 - '0';
}
int WWW;
void init(int cnt) {
  WWW = -1;
  while (cnt > 0) {
    WWW++;
    while (WWW < MMAX && used[WWW]) WWW++;
    cnt--;
  }
}
void next() {
  WWW++;
  while (WWW < MMAX && used[WWW]) WWW++;
}
void calc(int t) {
  while (used[t]) t++;
  int d = 0;
  while (t >= 1440) t -= 1440, d++;
  cout << d + 1 << " ";
  if (t / 60 < 10) cout << 0;
  cout << t / 60 << ":";
  if (t % 60 < 10) cout << 0;
  cout << t % 60 << " ";
}
void way(int x, int y, int now) {
  if (x == -1) {
    cout << now << endl;
    return;
  }
  if (prev2[x][y] != y) now++;
  way(x - 1, prev2[x][y], now);
  if (prev2[x][y] != y) {
    cout << p[x - 1].first.second + 1 << " ";
    calc(prev2[x][y]);
    calc(y - 1);
    cout << endl;
  }
}
int main() {
  cin >> m >> n >> k;
  for (int i = 0; i < (int)m; i++) cin >> name[i];
  for (int i = 0; i < (int)m; i++) cin >> t[i];
  memset(used, 0, sizeof(used));
  for (int i = 0; i < (int)4; i++) {
    pair<int, int> now;
    now.first = read_data();
    char c;
    cin >> c;
    now.second = read_data();
    for (int f = 0; f < (int)k; f++)
      for (int j = now.first; j <= now.second; j++) used[j + f * 1440] = true;
  }
  for (int i = 0; i < (int)n; i++) {
    char tmp[50];
    cin >> tmp;
    p[i].second.first = -1;
    for (int j = 0; j < (int)m; j++)
      if (strcmp(tmp, name[j]) == 0) p[i].second.first = j;
    int d;
    cin >> d;
    p[i].first.first = (d - 1) * 1440 + read_data();
    p[i].first.second = i;
    cin >> p[i].second.second;
  }
  sort(p, p + n);
  memset(ans, 0, sizeof(ans));
  for (int i = 0; i < (int)n; i++) {
    if (p[i].second.first >= 0) init(t[p[i].second.first]);
    for (int j = 0; j < (int)MMAX - 1; j++) {
      if (ans[i + 1][j] < ans[i][j]) {
        ans[i + 1][j] = ans[i][j];
        prev1[i + 1][j] = i;
        prev2[i + 1][j] = j;
      }
      if (p[i].second.first >= 0 && p[i].first.first > WWW)
        if (ans[i + 1][WWW + 1] < ans[i][j] + p[i].second.second) {
          ans[i + 1][WWW + 1] = ans[i][j] + p[i].second.second;
          prev1[i + 1][WWW + 1] = i;
          prev2[i + 1][WWW + 1] = j;
        }
      if (!used[j]) next();
    }
  }
  int answer = 0, px = 0, py = 0;
  for (int j = 0; j < (int)n + 1; j++)
    for (int i = 0; i < (int)MMAX; i++)
      if (answer < ans[j][i]) {
        answer = ans[j][i];
        px = j;
        py = i;
      }
  cout << answer << endl;
  way(px, py, 0);
  return 0;
}
