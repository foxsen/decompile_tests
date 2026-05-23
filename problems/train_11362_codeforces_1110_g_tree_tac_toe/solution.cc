#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[2000000];
int main() {
  int i, j;
  int T, t;
  int n, u, v;
  char c;
  scanf("%d", &T);
  for (t = 0; t < T; t++) {
    scanf("%d", &n);
    for (i = 0; i < n - 1; i++) {
      scanf("%d %d", &u, &v);
      u--, v--;
      adjList[u].push_back(v);
      adjList[v].push_back(u);
    }
    int nn = n;
    for (i = 0; i < nn; i++) {
      scanf(" %c", &c);
      if (c == 'W') {
        adjList[i].push_back(n), adjList[n].push_back(i);
        adjList[n].push_back(n + 1), adjList[n + 1].push_back(n);
        adjList[n].push_back(n + 2), adjList[n + 2].push_back(n);
        n += 3;
      }
    }
    int c = 0;
    for (i = 0; i < n; i++) {
      if (adjList[i].size() >= 4)
        break;
      else if (adjList[i].size() >= 3) {
        c++;
        int c2 = 0;
        for (j = 0; j < adjList[i].size(); j++) {
          v = adjList[i][j];
          if (adjList[v].size() >= 2) c2++;
        }
        if (c2 >= 2) break;
      }
    }
    if ((i < n) || ((c == 2) && (n & 1)))
      printf("White\n");
    else
      printf("Draw\n");
    for (i = 0; i < n; i++) adjList[i].clear();
  }
  return 0;
}
