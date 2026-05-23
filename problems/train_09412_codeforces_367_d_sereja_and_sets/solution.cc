#include <bits/stdc++.h>
using namespace std;
const long long UNDEF = -1;
const long long INF = 1e18;
template <typename T>
inline bool chkmax(T& aa, T bb) {
  return aa < bb ? aa = bb, true : false;
}
template <typename T>
inline bool chkmin(T& aa, T bb) {
  return aa > bb ? aa = bb, true : false;
}
static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof(stdinBuffer);
static const char* stdinPos = stdinDataEnd;
void readAhead(size_t amount) {
  size_t remaining = stdinDataEnd - stdinPos;
  if (remaining < amount) {
    memmove(stdinBuffer, stdinPos, remaining);
    size_t sz = fread(stdinBuffer + remaining, 1,
                      sizeof(stdinBuffer) - remaining, stdin);
    stdinPos = stdinBuffer;
    stdinDataEnd = stdinBuffer + remaining + sz;
    if (stdinDataEnd != stdinBuffer + sizeof(stdinBuffer)) *stdinDataEnd = 0;
  }
}
int readInt() {
  readAhead(16);
  int x = 0;
  bool neg = false;
  while (*stdinPos == ' ' || *stdinPos == '\n') ++stdinPos;
  if (*stdinPos == '-') {
    ++stdinPos;
    neg = true;
  }
  while (*stdinPos >= '0' && *stdinPos <= '9') {
    x *= 10;
    x += *stdinPos - '0';
    ++stdinPos;
  }
  return neg ? -x : x;
}
char readCh() {
  readAhead(16);
  while (*stdinPos == ' ' || *stdinPos == '\n') ++stdinPos;
  char ans = *stdinPos;
  ++stdinPos;
  return ans;
}
int s[20];
int a[20][100000];
int f[1 << 20];
int imincache[1 << 20][20];
int binsearch(int i, int key, int imin) {
  int imax = s[i];
  while (imin < imax) {
    int imid = (imin + imax) >> 1;
    if (a[i][imid] < key)
      imin = imid + 1;
    else
      imax = imid;
  }
  return imin - 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n = readInt(), m = readInt(), d = readInt();
  for (int i = 0; i < m; i++) {
    int sz = readInt();
    s[i] = sz;
    for (int j = 0; j < sz; j++) a[i][j] = readInt();
    sort(a[i], a[i] + sz);
  }
  int zlim = 1 << m;
  int final = m + 1;
  for (int z = 1; z < zlim; z++) {
    int popz = __builtin_popcount(z);
    if (popz >= final) continue;
    pair<int, int> best = make_pair(-1, -1);
    for (int k = 0; k < m; k++) {
      if (z & (1 << k)) {
        int pz = z ^ (1 << k);
        chkmax(best, make_pair(f[pz], k));
      }
    }
    int addk = best.second;
    memcpy(imincache[z], imincache[z ^ (1 << addk)], sizeof(imincache[0]));
    int x = best.first;
    while (1) {
      bool ch = 0;
      for (int k = 0; k < m; k++) {
        if (z & (1 << k)) {
          int gotimin = binsearch(k, x + d + 1, imincache[z][k]);
          if (gotimin < 0) continue;
          int nx = a[k][gotimin];
          if (nx > x) {
            chkmax(imincache[z][k], gotimin + 1);
            x = nx;
            ch = 1;
            break;
          }
        }
      }
      if (!ch) break;
    }
    f[z] = x;
    if (x >= n - d + 1) {
      chkmin(final, popz);
    }
  }
  printf("%d\n", final);
}
