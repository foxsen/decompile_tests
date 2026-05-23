#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1200];
int main() {
  int t, n, x, a, b;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < 1200; i++) adj[i].clear();
    scanf("%d%d", &n, &x);
    for (int i = 1; i < n; i++) {
      scanf("%d%d", &a, &b);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    if (adj[x].size() <= 1) {
      printf("Ayush\n");
      continue;
    }
    if (n == 1) {
      printf("Ayush\n");
      continue;
    }
    if (n & 1) {
      printf("Ashish\n");
    } else {
      printf("Ayush\n");
    }
  }
}
