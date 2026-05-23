#include <bits/stdc++.h>
using namespace std;
const int maxn = 200 + 10;
queue<pair<pair<int, int>, int> > q;
vector<int> nei[maxn][30];
bool mark[maxn][maxn][maxn];
pair<pair<int, int>, int> par[maxn][maxn][maxn];
vector<pair<int, int> > v;
char mat[maxn][maxn];
int n, s[3], p[3], ans[3], c[maxn], st[3];
void bfs() {
  q.push({{st[0], st[1]}, st[2]});
  mark[st[0]][st[1]][st[2]] = true;
  while (!q.empty()) {
    auto fr = q.front();
    q.pop();
    int a1 = fr.first.first, a2 = fr.first.second, a3 = fr.second;
    for (auto v : nei[a1][mat[a2][a3] - 'a']) {
      s[0] = v, s[1] = a2, s[2] = a3;
      sort(s, s + 3);
      if (!mark[s[0]][s[1]][s[2]] && v != a2 && v != a3) {
        par[s[0]][s[1]][s[2]] = {{a1, a2}, a3};
        mark[s[0]][s[1]][s[2]] = true;
        q.push({{s[0], s[1]}, s[2]});
      }
    }
    for (auto v : nei[a2][mat[a1][a3] - 'a']) {
      s[0] = a1, s[1] = v, s[2] = a3;
      sort(s, s + 3);
      if (!mark[s[0]][s[1]][s[2]] && v != a1 && v != a3) {
        par[s[0]][s[1]][s[2]] = {{a1, a2}, a3};
        mark[s[0]][s[1]][s[2]] = true;
        q.push({{s[0], s[1]}, s[2]});
      }
    }
    for (auto v : nei[a3][mat[a1][a2] - 'a']) {
      s[0] = a1, s[1] = a2, s[2] = v;
      sort(s, s + 3);
      if (!mark[s[0]][s[1]][s[2]] && v != a1 && v != a2) {
        mark[s[0]][s[1]][s[2]] = true;
        par[s[0]][s[1]][s[2]] = {{a1, a2}, a3};
        q.push({{s[0], s[1]}, s[2]});
      }
    }
  }
}
void printpar(int x, int y, int z) {
  cerr << " hell " << endl;
  if (st[0] == x && st[1] == y && st[2] == z) return;
  int finala, finalb;
  p[0] = par[x][y][z].first.first, p[1] = par[x][y][z].first.second,
  p[2] = par[x][y][z].second;
  ans[0] = x, ans[1] = y, ans[2] = z;
  cerr << p[0] << " " << p[1] << " " << p[2] << endl;
  cerr << ans[0] << " " << ans[1] << " " << ans[2] << endl;
  for (int i = 0; i < 3; i++) c[p[i]]++, c[ans[i]]++;
  for (int i = 0; i < 3; i++) {
    if (c[p[i]] == 1) finala = p[i];
    if (c[ans[i]] == 1) finalb = ans[i];
  }
  for (int i = 0; i < 3; i++) c[p[i]]--, c[ans[i]]--;
  printpar(p[0], p[1], p[2]);
  v.push_back({finala, finalb});
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < 3; i++) {
    cin >> st[i];
    st[i]--;
  }
  cerr << " reahced 1 " << endl;
  sort(st, st + 3);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> mat[i][j];
      if (i != j) {
        nei[i][mat[i][j] - 'a'].push_back(j);
        nei[j][mat[i][j] - 'a'].push_back(i);
      }
    }
  cerr << " reached " << endl;
  bfs();
  cerr << " reached 2 " << endl;
  if (!mark[0][1][2]) {
    cout << -1 << endl;
    return 0;
  }
  printpar(0, 1, 2);
  cerr << " reahced 4 " << endl;
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++)
    cout << v[i].first + 1 << " " << v[i].second + 1 << endl;
}
