#include <bits/stdc++.h>
using namespace std;
int vis[1000000];
int n[1000000];
int main() {
  int cnt = 0;
  int l;
  cin >> l;
  for (int i = 0; i < l; i++) {
    cin >> n[i];
  }
  sort(n, n + l);
  for (int i = 0; i < l; i++) {
    int x = n[i] - 1;
    if (x < 1) x = 1;
    int y = n[i];
    int z = n[i] + 1;
    if (!vis[x]) {
      vis[x] = 1;
      ++cnt;
    } else if (!vis[y]) {
      vis[y] = 1;
      ++cnt;
    } else if (!vis[z]) {
      vis[z] = 1;
      ++cnt;
    }
  }
  cout << cnt << endl;
}
