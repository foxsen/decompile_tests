#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
template <typename T>
inline void gn(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <class T, class T1>
inline void gn(T &first, T1 &second) {
  gn(first);
  gn(second);
}
template <class T, class T1, class T2>
inline void gn(T &first, T1 &second, T2 &z) {
  gn(first);
  gn(second);
  gn(z);
}
template <typename T>
inline void print(T first) {
  if (first < 0) {
    putchar('-');
    return print(-first);
  }
  if (first < 10) {
    putchar('0' + first);
    return;
  }
  print(first / 10);
  putchar(first % 10 + '0');
}
template <typename T>
inline void println(T first) {
  print(first), putchar('\n');
}
template <typename T>
inline void printsp(T first) {
  print(first), putchar(' ');
}
template <class T, class T1>
inline void print(T first, T1 second) {
  printsp(first), println(second);
}
template <class T, class T1, class T2>
inline void print(T first, T1 second, T2 z) {
  printsp(first), printsp(second), println(z);
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
vector<int> val[100100];
vector<int> num[100100];
vector<int> adj[100100];
int vst[100100];
vector<int> vec;
void dfs(int u) {
  vec.push_back(u);
  vst[u] = 1;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (vst[v]) continue;
    dfs(v);
  }
}
vector<pair<int, int> > P;
int dp[100100][2][2];
int ddp[100100][2][2][2];
int DP[100100][2];
inline void add(int &a, int b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
}
int main() {
  int n, m;
  gn(n, m);
  for (int i = 1; i <= n; i++) {
    int k;
    gn(k);
    int u;
    while (k--) {
      gn(u);
      val[i].push_back(u);
      if (u > 0)
        num[u].push_back(i);
      else
        num[-u].push_back(-i);
    }
  }
  int flag = 0;
  int tar = 1;
  int ans = 1;
  for (int i = 1; i <= m; i++) {
    if (num[i].size() > 1) {
      adj[abs(num[i][0])].push_back(abs(num[i][1]));
      adj[abs(num[i][1])].push_back(abs(num[i][0]));
    } else if (num[i].empty()) {
      ans = ans * 2 % 1000000007;
    }
  }
  if (flag) {
    println(power(2, m - 1, 1000000007));
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (adj[i].empty()) {
      vst[i] = 1;
      P.push_back(pair<int, int>(1, (1 << val[i].size()) - 1));
    } else if (!vst[i] && adj[i].size() == 1) {
      vec.clear();
      dfs(i);
      for (int j = 0; j < vec.size(); j++) memset(dp[j], 0, sizeof(dp[j]));
      if (val[vec[0]].size() == 2)
        dp[0][1][1] = 1, dp[0][0][0] = 1;
      else
        dp[0][0][0] = 1;
      for (int j = 1; j < vec.size(); j++) {
        int fl = 0;
        for (int a = 0; a < val[vec[j]].size(); a++) {
          for (int b = 0; b < val[vec[j - 1]].size(); b++)
            if (val[vec[j]][a] == val[vec[j - 1]][b]) fl = 1;
        }
        if (fl) {
          for (int a = 0; a < 2; a++) {
            for (int b = 0; b < 2; b++) {
              add(dp[j][a][0], dp[j - 1][a][b]);
              add(dp[j][a ^ (b == 0) ^ 1][1], dp[j - 1][a][b]);
            }
          }
        } else {
          for (int a = 0; a < 2; a++) {
            for (int b = 0; b < 2; b++) {
              add(dp[j][a ^ (b == 0)][0], dp[j - 1][a][b]);
              add(dp[j][a ^ 1][1], dp[j - 1][a][b]);
            }
          }
        }
      }
      int v[2] = {0, 0};
      for (int k = 0; k < 1 + (val[vec.back()].size() == 2); k++)
        for (int a = 0; a < 2; a++)
          for (int b = 0; b < 2; b++) {
            add(v[a ^ (k && b == 0)], dp[vec.size() - 1][a][b]);
          }
      P.push_back(pair<int, int>(v[0], v[1]));
    }
  }
  for (int i = 1; i <= n; i++)
    if (!vst[i]) {
      vec.clear();
      dfs(i);
      for (int j = 0; j < vec.size(); j++) memset(ddp[j], 0, sizeof(ddp[j]));
      ddp[0][1][1][1] = 1;
      ddp[0][0][0][0] = 1;
      for (int j = 1; j < vec.size(); j++) {
        int fl = 0;
        for (int a = 0; a < val[vec[j]].size(); a++) {
          for (int b = 0; b < val[vec[j - 1]].size(); b++)
            if (val[vec[j]][a] == val[vec[j - 1]][b]) fl = 1;
        }
        if (fl) {
          for (int k = 0; k < 2; k++) {
            for (int a = 0; a < 2; a++) {
              for (int b = 0; b < 2; b++) {
                add(ddp[j][k][a][0], ddp[j - 1][k][a][b]);
                add(ddp[j][k][a ^ (b == 0) ^ 1][1], ddp[j - 1][k][a][b]);
              }
            }
          }
        } else {
          for (int k = 0; k < 2; k++) {
            for (int a = 0; a < 2; a++) {
              for (int b = 0; b < 2; b++) {
                add(ddp[j][k][a ^ (b == 0)][0], ddp[j - 1][k][a][b]);
                add(ddp[j][k][a ^ 1][1], ddp[j - 1][k][a][b]);
              }
            }
          }
        }
      }
      int ok = 0;
      if (vec.size() == 1)
        ok = val[vec[0]][0] == val[vec[0]][1];
      else
        for (int a = 0; a < val[vec[0]].size(); a++) {
          for (int b = 0; b < val[vec.back()].size(); b++)
            if (val[vec[0]][a] == val[vec.back()][b]) ok = 1;
        }
      int v[] = {0, 0};
      for (int k = 0; k < 2; k++)
        for (int a = 0; a < 2; a++)
          for (int b = 0; b < 2; b++) {
            int kk = k ^ (!ok);
            add(v[a ^ (b == 0 && kk)], ddp[vec.size() - 1][k][a][b]);
          }
      P.push_back(pair<int, int>(v[0], v[1]));
    }
  DP[0][0] = 1;
  DP[0][1] = 0;
  for (int i = 0; i < P.size(); i++) {
    DP[i + 1][0] =
        ((long long)DP[i][0] * P[i].first + (long long)DP[i][1] * P[i].second) %
        1000000007;
    DP[i + 1][1] =
        ((long long)DP[i][1] * P[i].first + (long long)DP[i][0] * P[i].second) %
        1000000007;
  }
  println((long long)DP[P.size()][tar] * ans % 1000000007);
  return 0;
}
