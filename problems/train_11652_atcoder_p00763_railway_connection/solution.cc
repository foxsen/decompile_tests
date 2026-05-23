#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

int n, m, c, s, g;
int matrix[30][110][110];
int ps[100];
int qs[100][100];
int rs[100][100];
int cost[30][20100];

int main() {
  while (scanf("%d %d %d %d %d", &n, &m, &c, &s, &g), n) {
    s--; g--;
    MEMSET(matrix, 0x0f);
    REP(a, c) REP(i, n) { matrix[a][i][i] = 0; }
    REP(i, m) {
      int f, t, d, g;
      scanf("%d %d %d %d", &f, &t, &d, &g);
      f--; t--; g--;
      matrix[g][f][t] = matrix[g][t][f] = min(matrix[g][f][t], d);
    }
    REP(a, c) REP(k, n) REP(i, n) REP(j, n) {
      matrix[a][i][j] = min(matrix[a][i][j], matrix[a][i][k] + matrix[a][k][j]);
    }
    REP(i, c) { scanf("%d", &ps[i]); }
    REP(i, c) {
      REP(j, ps[i] - 1) {
        scanf("%d", &qs[i][j]);
      }
      qs[i][ps[i] - 1] = 1e+9;
      REP(j, ps[i]) {
        scanf("%d", &rs[i][j]);
      }
      cost[i][0] = 0;
      int index = 0;
      FOREQ(j, 1, 20010) {
        while (qs[i][index] < j) { index++; }
        cost[i][j] = cost[i][j - 1] + rs[i][index];
      }
    }
    REP(a, c) REP(i, n) REP(j, n) {
      if (matrix[a][i][j] == 0x0f0f0f0f) { continue; }
      matrix[a][i][j] = cost[a][matrix[a][i][j]];
    }
    REP(a, c) REP(i, n) REP(j, n) {
      matrix[0][i][j] = min(matrix[0][i][j], matrix[a][i][j]);
    }
    REP(k, n) REP(i, n) REP(j, n) {
      matrix[0][i][j] = min(matrix[0][i][j], matrix[0][i][k] + matrix[0][k][j]);
    }
    if (matrix[0][s][g] == 0x0f0f0f0f) {
      puts("-1");
    } else {
      printf("%d\n", matrix[0][s][g]);
    }
  }
}