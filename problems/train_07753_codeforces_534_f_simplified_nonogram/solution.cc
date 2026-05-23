#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000100;
int Cnt[6];
int Cnt1[6];
inline void Decode(long long Code, int &y, int &S);
inline long long Encode(int y, int S, int *Cnt);
long long que[MAXN];
int qhead, qtail;
const int HashMOD = 10000017;
long long HashX[MAXN];
long long HashY[MAXN];
bool HashVis[MAXN];
long long HashGet(long long x);
void HashInsert(long long x, long long y);
int n, m;
int A[100], B[100];
bool Check(int y, int S);
bool Place(int y, int S, int S1);
int Ans[30][30];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &A[i]);
  for (int i = 1; i <= m; ++i) scanf("%d", &B[i]);
  for (int S = 0; S < (1 << n); ++S)
    if (Check(1, S) && Place(1, 0, S)) {
      long long Code = Encode(1, S, Cnt1);
      que[qtail++] = Code;
      HashInsert(Code, 0);
    }
  for (; qhead < qtail; ++qhead) {
    long long Code = que[qhead];
    int y, S;
    Decode(Code, y, S);
    if (y == m) {
      bool flag = 1;
      for (int i = 1; i <= n; ++i)
        if (Cnt[i] != A[i]) {
          flag = 0;
          break;
        }
      if (!flag) continue;
      while (Code != 0) {
        Decode(Code, y, S);
        for (int x = 0; x < n; ++x) Ans[x + 1][y] = (S >> x) & 1;
        Code = HashGet(Code);
      }
      break;
    }
    for (int S1 = 0; S1 < (1 << n); ++S1)
      if (Check(y + 1, S1) && Place(y + 1, S, S1)) {
        long long C = Encode(y + 1, S1, Cnt1);
        if (HashGet(C) != -1) {
          continue;
        }
        que[qtail++] = C;
        HashInsert(C, Code);
      }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j)
      if (Ans[i][j])
        printf("*");
      else
        printf(".");
    printf("\n");
  }
  return 0;
}
inline void Decode(long long Code, int &y, int &S) {
  y = Code % 21;
  Code /= 21;
  S = Code % 32;
  Code /= 32;
  for (int i = 1; i <= n; ++i) {
    Cnt[i] = Code % 11;
    Code /= 11;
  }
}
inline long long Encode(int y, int S, int *Cnt) {
  long long Code = 0;
  for (int i = n; i >= 1; --i) {
    Code *= 11;
    Code += Cnt[i];
  }
  Code = Code * 32 + S;
  Code = Code * 21 + y;
  return Code;
}
bool Check(int y, int S) {
  int cnt = 0, las = 0;
  for (int i = 0; i != n; ++i)
    if ((S >> i) & 1) {
      if (las == 0) cnt++;
      las = 1;
    } else
      las = 0;
  return cnt == B[y];
}
bool Place(int y, int S, int S1) {
  memcpy(Cnt1, Cnt, sizeof(Cnt1));
  for (int i = 1; i <= n; ++i) {
    if (((S >> i - 1) & 1) == 0 && ((S1 >> i - 1) & 1) == 1) {
      Cnt1[i]++;
      if (Cnt1[i] > A[i]) {
        return 0;
      }
    }
    if (Cnt1[i] + (m - y + 1) / 2 < A[i]) {
      return 0;
    }
  }
  return 1;
}
long long HashGet(long long x) {
  int h = x % HashMOD;
  for (; HashVis[h]; h += 117)
    if (HashX[h] == x) return HashY[h];
  return -1;
}
void HashInsert(long long x, long long y) {
  int h = x % HashMOD;
  for (; HashVis[h]; h += 117)
    ;
  HashX[h] = x;
  HashY[h] = y;
  HashVis[h] = 1;
}
