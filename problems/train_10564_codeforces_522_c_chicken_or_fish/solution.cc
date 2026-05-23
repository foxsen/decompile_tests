#include <bits/stdc++.h>
using namespace std;
const int N = 1234567;
int cnt[N];
bool res[N];
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int people, dishes;
    cin >> people >> dishes;
    for (int i = 0; i < dishes; i++) {
      cin >> cnt[i];
      res[i] = false;
    }
    people--;
    bool good = true;
    int unknown = 0;
    while (people--) {
      int what, disapp;
      cin >> what >> disapp;
      what--;
      if (disapp == 1 && good) {
        good = false;
        for (int i = 0; i < dishes; i++) {
          if (cnt[i] <= unknown) {
            res[i] = true;
          }
        }
      }
      if (what != -1) {
        cnt[what]--;
        res[what] = false;
      } else {
        unknown++;
      }
    }
    int reserved = 0;
    if (!good) {
      reserved = (int)1e9;
      for (int i = 0; i < dishes; i++) {
        if (res[i]) {
          reserved = min(reserved, cnt[i]);
        }
      }
    }
    for (int i = 0; i < dishes; i++) {
      if (cnt[i] <= unknown - reserved) {
        res[i] = true;
      }
      putchar(res[i] ? 'Y' : 'N');
    }
    putchar('\n');
  }
  return 0;
}
