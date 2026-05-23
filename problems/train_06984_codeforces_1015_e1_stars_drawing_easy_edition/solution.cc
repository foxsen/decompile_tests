#include <bits/stdc++.h>
using namespace std;
const int maxn = int(1e3) + 10;
const int maxm = 1005;
int Left[maxn][maxm], Right[maxn][maxm], up[maxn][maxm], down[maxn][maxm];
int cnt[maxn][maxn];
char str[maxn][maxn];
char s[maxn][maxn];
int n, m;
int a[maxn][maxm];
int c[maxn][maxm];
int top = 0;
int lowbit(int x) { return x & (-x); }
void update(int x, int y, int z) {
  for (int i = x; i <= n; i += lowbit(i))
    for (int j = y; j <= m; j += lowbit(j)) c[i][j] += z;
}
int sum(int x, int y) {
  int ret = 0;
  for (int i = x; i >= 1; i -= lowbit(i))
    for (int j = y; j >= 1; j -= lowbit(j)) ret += c[i][j];
  return ret;
}
void update_section(int x1, int y1, int x2, int y2, int w) {
  update(x1, y1, w);
  update(x2 + 1, y2 + 1, w);
  update(x2 + 1, y1, -w);
  update(x1, y2 + 1, -w);
}
void debug() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%d", Left[i][j]);
    }
    printf("\n");
  }
  cout << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%d", Right[i][j]);
    }
    printf("\n");
  }
  cout << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%d", up[i][j]);
    }
    printf("\n");
  }
  cout << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%d", down[i][j]);
    }
    printf("\n");
  }
  cout << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%d", cnt[i][j]);
    }
    printf("\n");
  }
  cout << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%d", sum(i, j));
    }
    cout << endl;
  }
}
void init() {
  memset(Left, 0, sizeof(Left));
  memset(Right, 0, sizeof(Right));
  memset(up, 0, sizeof(up));
  memset(down, 0, sizeof(down));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (str[i][j] == '*')
        Left[i][j] = j - 1 >= 1 ? Left[i][j - 1] + 1 : 1;
      else
        Left[i][j] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= 1; j--) {
      if (str[i][j] == '*')
        Right[i][j] = j + 1 <= m ? Right[i][j + 1] + 1 : 1;
      else
        Right[i][j] = 0;
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      if (str[i][j] == '*')
        up[i][j] = i - 1 >= 1 ? up[i - 1][j] + 1 : 1;
      else
        up[i][j] = 0;
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = n; i >= 1; i--) {
      if (str[i][j] == '*')
        down[i][j] = i + 1 <= n ? down[i + 1][j] + 1 : 1;
      else
        down[i][j] = 0;
    }
  }
}
void work() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int Min = min(Left[i][j], Right[i][j]);
      Min = min(Min, up[i][j]);
      Min = min(Min, down[i][j]);
      if (Min >= 2) {
        Min--;
        cnt[i][j] = Min;
        update_section(i, j - Min, i, j + Min, 1);
        update_section(i - Min, j, i + Min, j, 1);
        top++;
      }
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i]);
    for (int j = 0; j < m; j++) str[i][j + 1] = s[i][j];
  }
  top = 0;
  init();
  work();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (str[i][j] == '*' && sum(i, j) == 0) {
        printf("-1\n");
        return 0;
      }
    }
  }
  printf("%d\n", top);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (cnt[i][j] != 0) {
        printf("%d %d %d\n", i, j, cnt[i][j]);
      }
    }
  }
  return 0;
}
