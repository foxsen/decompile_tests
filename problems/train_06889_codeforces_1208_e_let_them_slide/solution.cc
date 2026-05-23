#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int N = 100010;
const int MX = 123456;
const int mod = (int)1e9 + 7;
const int base = 1023456789;
const unsigned long long BS1 = 10000019ULL;
const int INF = (1 << 29);
template <class T>
inline void fastScan(T &x) {
  register char c = getchar();
  int neg = 0;
  x = 0;
  for (; (c < 48 || c > 57) && (c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (neg) x = -x;
}
int n, m;
long long arr[N * 10];
long long cum[N * 10];
struct Data {
  int value;
  int indx;
} inp[N * 10];
bool as(Data a, Data b) { return a.value > b.value; }
int main() {
  fastScan(n);
  fastScan(m);
  for (int i = 1; i <= n; i++) {
    int sz;
    fastScan(sz);
    int cover = m - sz;
    for (int j = 0; j <= sz + 1; j++) {
      inp[j].indx = j;
      inp[j].value = 0;
    }
    for (int j = 1; j <= sz; j++) {
      fastScan(inp[j].value);
    }
    if (sz == m) {
      for (int j = 1; j <= sz; j++) {
        arr[j] += inp[j].value;
      }
    } else {
      sort(inp + 0, inp + sz + 2, as);
      set<int> mySet;
      for (int j = 0; j <= sz + 1; j++) {
        int l = inp[j].indx, r = inp[j].indx + cover;
        if (mySet.empty()) {
          cum[l] += inp[j].value;
          cum[r + 1] -= inp[j].value;
          mySet.insert(l);
        } else {
          auto it = mySet.upper_bound(l);
          if (it == mySet.end()) {
            it--;
            l = max(l, (*it) + cover + 1);
          } else if (it == mySet.begin()) {
            r = min(r, (*it) - 1);
          } else {
            r = min(r, (*it) - 1);
            it--;
            l = max(l, (*it) + cover + 1);
          }
          if (l <= r) {
            cum[l] += inp[j].value;
            cum[r + 1] -= inp[j].value;
            mySet.insert(inp[j].indx);
          }
        }
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    cum[i] += cum[i - 1];
    arr[i] += cum[i];
  }
  for (int i = 1; i <= m; i++) {
    printf("%lld%c", arr[i], (i == m ? '\n' : ' '));
  }
  return 0;
}
