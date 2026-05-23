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

int n, f;
int field[10][10];
int memo[3][2][1 << 16][8];
int win;

int GetP(int fs, int turn, int prev, int next) {
  int ret = 0;
  if (turn != 0) {
    if (fs == 0) {
      ret = field[next][prev];
    } else {
      ret = field[prev][next];
    }
  }
  return ret;
}

int calc(int yowai, int fs, int use, int prev) {
  int turn = __builtin_popcount(use);
  if (turn == 2 * n) { return f; }
  if (memo[yowai][fs][use][prev] != -1) { return memo[yowai][fs][use][prev]; }
  int used = 0;
  if (fs == 0) {
    used = use & ((1 << n) - 1);
  } else {
    used = (use >> n) & ((1 << n) - 1);
  }
  int ret = -10000000;
  if (yowai == fs) { ret = 10000000; }
  REP(i, n) {
    int nused = used | (1 << i);
    if (used == nused) { continue; }
    int nret = GetP(fs, turn, prev, i);
    int nuse = use | (nused << (fs * n));
    nret -= calc(yowai, fs ^ 1, nuse, i);
    if (yowai == fs) {
      ret = min(ret, nret);
    } else {
      ret = max(ret, nret);
    }
  }
  return memo[yowai][fs][use][prev] = ret;
}

int Search(int fs, int use, int prev, int p, int beta, int alpha) {
  int turn = __builtin_popcount(use);
  if (turn == 2 * n) { return 2 * n; }
  //cout << turn << " " << fs << " " << use << " "<< prev << " " << p << " " << p + calc(fs ^ 1, fs, use, prev) << endl;
  if (p + calc(fs ^ 1, fs, use, prev) < 0) { return turn + 1; }
  int used = 0;
  if (fs == 0) {
    used = use & ((1 << n) - 1);
  } else {
    used = (use >> n) & ((1 << n) - 1);
  }
  if (beta <= alpha || turn + 1 >= beta) { return turn + 1; }
  int ret = turn + 1;
  if (win == fs) { ret = 100; }
  REP(i, n) {
    if (beta <= alpha) { break; }
    int nused = used | (1 << i);
    if (used == nused) { continue; }
    int np = p + GetP(fs, turn, prev, i);
    int nuse = use | (nused << (fs * n));
    if (win == fs && np - calc(2, fs ^ 1, nuse, i) < 0) { continue; }
    int nret = Search(fs ^ 1, nuse, i, -np, beta, alpha);
    if (win == fs) {
      ret = min(ret, nret);
      beta = min(beta, ret);
      if (ret <= alpha) { break; }
    } else {
      ret = max(ret, nret);
      alpha = max(alpha, ret);
      if (ret >= beta) { break; }
    }
  }
  return ret;
}

int main() {
  while (scanf("%d %d", &n, &f) > 0) {
    MEMSET(memo, -1);
    REP(y, n) {
      REP(x, n) {
        scanf("%d", &field[y][x]);
      }
    }
    int ans = calc(2, 0, 0, 0);
    if (ans > 0) {
      win = 0;
      puts("First");
      printf("%d\n", Search(0, 0, 0, 0, 100, -100));
    } else if (ans == 0) {
      puts("Draw");
      printf("%d\n", 2 * n);
    } else {
      win = 1;
      puts("Second");
      printf("%d\n", Search(0, 0, 0, 0, 100, -100));
    }
  }
}