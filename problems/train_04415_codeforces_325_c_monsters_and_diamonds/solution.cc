#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int INF = 0x3f3f3f3f;
const int iinf = 1 << 30;
const long long linf = 2e18;
const int mod = 1000000007;
const int TOO_BIG = 314000000;
const double eps = 1e-7;
void douout(double x) { printf("%lf\n", x + 0.0000000001); }
template <class T>
void print(T a) {
  cout << a << endl;
  exit(0);
}
template <class T>
void chmin(T &a, T b) {
  if (a > b) a = b;
}
template <class T>
void chmax(T &a, T b) {
  if (a < b) a = b;
}
void add(int &a, int b) { a = a + b < mod ? a + b : a + b - mod; }
void sub(int &a, int b) { a = (a - b + mod) % mod; }
void mul(int &a, int b) { a = (long long)a * b % mod; }
int addv(int a, int b) { return (a += b) >= mod ? a -= mod : a; }
int subv(int a, int b) { return (a -= b) < 0 ? a += mod : a; }
int mulv(int a, int b) { return (long long)a * b % mod; }
int read() {
  int f = 1, x = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int pw(int a, int b) {
  int s = 1;
  for (; b; b >>= 1, a = (long long)a * a % mod)
    if (b & 1) s = (long long)s * a % mod;
  return s;
}
int m, n, numHeap;
int dest[N], val[N], first[N], id[N], src[N], minCost[N], maxCost[N],
    curDeadChildren[N], curMinSum[N];
int nextSameSrc[N], firstBySrc[N], heap[N], heapAt[N], countByDest[N];
void Swap(int a, int b) {
  int tmp = heap[a];
  heap[a] = heap[b];
  heap[b] = tmp;
  heapAt[heap[a]] = a;
  heapAt[heap[b]] = b;
}
void heapDown(int at) {
  while (true) {
    int i = at;
    if (2 * at + 1 < numHeap &&
        curMinSum[heap[2 * at + 1]] < curMinSum[heap[i]]) {
      i = 2 * at + 1;
    }
    if (2 * at + 2 < numHeap &&
        curMinSum[heap[2 * at + 2]] < curMinSum[heap[i]]) {
      i = 2 * at + 2;
    }
    if (i == at) break;
    Swap(at, i);
    at = i;
  }
}
void heapUp(int at) {
  while (at > 0) {
    int i = (at - 1) / 2;
    if (curMinSum[heap[i]] > curMinSum[heap[at]]) {
      Swap(at, i);
      at = i;
    } else
      break;
  }
}
signed main() {
  scanf("%d%d", &m, &n);
  int cnt = 0;
  for (int i = (0); i <= (m - 1); i++) {
    first[i] = cnt;
    scanf("%d", &dest[i]);
    dest[i]--;
    int len;
    scanf("%d", &len);
    for (int j = (0); j <= (len - 1); j++) {
      int cur;
      scanf("%d", &cur);
      if (cur < 0)
        ++val[i];
      else {
        cur--;
        id[cnt] = i;
        src[cnt] = cur;
        cnt++;
      }
    }
  }
  first[m] = cnt;
  memset(minCost, -1, sizeof(minCost));
  memcpy(curMinSum, val, sizeof(val));
  memset(firstBySrc, -1, sizeof(firstBySrc));
  for (int i = 0; i < cnt; ++i) {
    nextSameSrc[i] = firstBySrc[src[i]];
    firstBySrc[src[i]] = i;
  }
  for (int i = 0; i < m; ++i)
    if (first[i + 1] - first[i] == curDeadChildren[i]) {
      heap[numHeap++] = i;
      heapAt[i] = numHeap - 1;
      heapUp(numHeap - 1);
    }
  while (numHeap > 0) {
    int cur = heap[0];
    Swap(0, numHeap - 1);
    --numHeap;
    if (numHeap > 1) heapDown(0);
    heapAt[cur] = -1;
    if (minCost[dest[cur]] >= 0) {
      continue;
    }
    minCost[dest[cur]] = curMinSum[cur];
    int at = firstBySrc[dest[cur]];
    while (at >= 0) {
      curMinSum[id[at]] += curMinSum[cur];
      if (curMinSum[id[at]] >= TOO_BIG) {
        curMinSum[id[at]] = TOO_BIG;
      }
      ++curDeadChildren[id[at]];
      int delta = curDeadChildren[id[at]] - (first[id[at] + 1] - first[id[at]]);
      if (delta >= 0) {
        heap[numHeap++] = id[at];
        heapAt[id[at]] = numHeap - 1;
        heapUp(numHeap - 1);
      }
      at = nextSameSrc[at];
    }
  }
  memcpy(curMinSum, val, sizeof(curMinSum));
  memset(curDeadChildren, 0, sizeof(curDeadChildren));
  for (int i = 0; i < m; ++i) {
    bool nice = true;
    for (int j = first[i]; j < first[i + 1]; ++j)
      if (minCost[src[j]] < 0) nice = false;
    if (nice) ++countByDest[dest[i]];
  }
  numHeap = 0;
  for (int i = 0; i < n; ++i)
    if (minCost[i] >= 0 && countByDest[i] == 0) {
      heap[numHeap++] = i;
    }
  for (int i = 0; i < m; ++i)
    if (first[i + 1] - first[i] == curDeadChildren[i] &&
        minCost[dest[i]] >= 0) {
      maxCost[dest[i]] = max(maxCost[dest[i]], curMinSum[i]);
      if (maxCost[dest[i]] >= TOO_BIG) {
        maxCost[dest[i]] = TOO_BIG;
      }
      --countByDest[dest[i]];
      if (countByDest[dest[i]] == 0) {
        heap[numHeap++] = dest[i];
      }
    }
  while (numHeap > 0) {
    int cur = heap[--numHeap];
    int at = firstBySrc[cur];
    while (at >= 0) {
      if (minCost[dest[id[at]]] >= 0) {
        curMinSum[id[at]] += maxCost[cur];
        if (curMinSum[id[at]] >= TOO_BIG) {
          curMinSum[id[at]] = TOO_BIG;
        }
        ++curDeadChildren[id[at]];
        int delta =
            curDeadChildren[id[at]] - (first[id[at] + 1] - first[id[at]]);
        if (delta >= 0) {
          maxCost[dest[id[at]]] = max(maxCost[dest[id[at]]], curMinSum[id[at]]);
          --countByDest[dest[id[at]]];
          if (countByDest[dest[id[at]]] <= 0) {
            heap[numHeap++] = dest[id[at]];
          }
        }
      }
      at = nextSameSrc[at];
    }
  }
  for (int i = (0); i <= (n - 1); i++) {
    if (minCost[i] < 0) {
      puts("-1 -1");
    } else {
      printf("%d", minCost[i]);
      putchar(' ');
      if (countByDest[i] > 0)
        puts("-2");
      else
        printf("%d\n", maxCost[i]);
    }
  }
  return 0;
}
