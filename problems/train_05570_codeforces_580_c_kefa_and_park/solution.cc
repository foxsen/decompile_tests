#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int is_cat[MAXN], n, m;
vector<int> g[MAXN];
int ans;
void get_input(), write_output();
void dfs(int, int, int);
int main() {
  get_input();
  dfs(-1, 0, 0);
  write_output();
}
void write_output() { cout << ans << endl; }
void dfs(int dad, int adjcat, int indx) {
  int size = g[indx].size();
  if (is_cat[indx] == 1)
    adjcat++;
  else
    adjcat = 0;
  if (adjcat <= m && size == 1 && indx != 0) {
    ans++;
    return;
  }
  if (adjcat > m) return;
  for (int i = 0; i < size; i++)
    if (g[indx][i] != dad) dfs(indx, adjcat, g[indx][i]);
}
void get_input() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> is_cat[i];
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
}
