#include <bits/stdc++.h>
using namespace std;
void read_file(bool outToFile = true) {}
int n, m;
int p[100000 + 9];
vector<vector<int> > cycle;
bool vis[100000 + 9];
void DFS(int i) {
  vis[i] = true;
  cycle[m].push_back(i);
  if (!vis[p[i]]) DFS(p[i]);
}
int main() {
  read_file();
  while (cin >> n) {
    int chosen = -1;
    for (int i = 0; i < n; i++)
      cin >> p[i], p[i]--, chosen = (chosen == -1 && i == p[i]) ? i : chosen;
    if (chosen != -1) {
      cout << "YES" << endl;
      for (int i = 0; i < n; i++) {
        if (i == chosen) continue;
        cout << chosen + 1 << ' ' << i + 1 << endl;
      }
      continue;
    }
    memset(vis, false, sizeof vis);
    cycle.clear();
    m = 0;
    for (int i = 0; i < n; i++) {
      if (!vis[i] && p[i] != i) {
        cycle.push_back(vector<int>());
        DFS(i);
        m++;
      }
    }
    bool canWe = true;
    for (int i = 0; i < m && canWe; i++)
      if (cycle[i].size() % 2 != 0) canWe = false;
    if (!canWe) {
      cout << "NO" << endl;
      continue;
    }
    canWe = false;
    for (int i = 0; i < m && !canWe; i++)
      if (cycle[i].size() == 2) canWe = true, chosen = i;
    if (!canWe) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    cout << cycle[chosen][0] + 1 << ' ' << cycle[chosen][1] + 1 << endl;
    for (int i = 0; i < m; i++) {
      if (i == chosen) continue;
      for (int j = 0; j < cycle[i].size(); j += 2) {
        cout << cycle[chosen][0] + 1 << ' ' << cycle[i][j] + 1 << endl;
        cout << cycle[chosen][1] + 1 << ' ' << cycle[i][j + 1] + 1 << endl;
      }
    }
  }
}
