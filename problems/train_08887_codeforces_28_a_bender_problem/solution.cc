#include <bits/stdc++.h>
using namespace std;
struct Node {
  int x, y;
} A[510];
int B[510];
int F[510];
int L[510];
int n;
map<int, int> mm;
bool DFS(int i, int cnt) {
  if (cnt == n) {
    return true;
  }
  for (i = i; i < n; i++) {
    if (F[i] != -1) continue;
    int t = (i - 1 + n) % n;
    if (F[t] == -1) {
      if (mm[L[t] + L[i]] > 0) {
        mm[L[t] + L[i]]--;
        F[i] = L[t] + L[i];
        F[t] = 0;
        if (DFS(i + 1, cnt + 2)) return true;
        mm[L[t] + L[i]]++;
        F[i] = F[t] = -1;
      }
    }
    t = (i + 1) % n;
    if (F[t] == -1) {
      if (mm[L[t] + L[i]] > 0) {
        mm[L[t] + L[i]]--;
        F[i] = 0;
        F[t] = L[t] + L[i];
        if (DFS(i + 2, cnt + 2)) return true;
        mm[L[t] + L[i]]++;
        F[i] = F[t] = -1;
      }
    }
    if (mm[L[i]] > 0) {
      mm[L[i]]--;
      F[i] = L[i];
      DFS(i + 1, cnt + 1);
    }
  }
  return false;
}
int main() {
  int m;
  while (scanf("%d%d", &n, &m) != EOF) {
    mm.clear();
    memset(F, -1, sizeof(F));
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &A[i].x, &A[i].y);
    }
    for (int i = 0; i < m; i++) {
      scanf("%d", &B[i]);
      mm[B[i]]++;
    }
    for (int i = 0; i < n; i++) {
      if (A[i].x == A[(i + 1) % n].x) {
        L[i] = abs(A[i].y - A[(i + 1) % n].y);
      } else
        L[i] = abs(A[i].x - A[(i + 1) % n].x);
    }
    bool lf = DFS(0, 0);
    if (lf == 0)
      printf("NO\n");
    else {
      printf("YES\n");
      for (int i = 0; i < n; i++) {
        if (F[i] == 0)
          printf("-1 ");
        else {
          for (int j = 0; j < m; j++) {
            if (F[i] == B[j]) {
              printf("%d ", j + 1);
              B[j] = -1;
              break;
            }
          }
        }
      }
      printf("\n");
    }
  }
  return 0;
}
