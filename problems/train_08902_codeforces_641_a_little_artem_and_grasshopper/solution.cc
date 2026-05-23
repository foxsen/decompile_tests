#include <bits/stdc++.h>
using namespace std;
int n, now = 1, w[100005], dir[100005];
bool vis[100005];
char a[5];
string m;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    if (m[i] == '<') {
      dir[i + 1] = -1;
    } else {
      dir[i + 1] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  while (true) {
    if (now < 1 || now > n) {
      cout << "FINITE";
      return 0;
    } else if (vis[now] == true) {
      cout << "INFINITE";
      return 0;
    }
    vis[now] = true;
    now += w[now] * dir[now];
  }
  return 0;
}
