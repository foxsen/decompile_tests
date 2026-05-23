#include <bits/stdc++.h>
using namespace std;
double PI = acos(-1);
double EPS = 1e-7;
int INF = 1000000000;
long long INFLL = 1000000000000000000LL;
bool cek(int x) {
  int dir = 0;
  int prev = -1;
  while (x) {
    int p = x % 10;
    if (dir == 0 && prev != -1) {
      if (p > prev)
        dir = 1;
      else if (p < prev)
        dir = -1;
      else
        return 0;
    }
    if (dir == 1) {
      if (p > prev)
        ;
      else
        return 0;
    }
    if (dir == -1) {
      if (p < prev)
        ;
      else
        return 0;
    }
    x /= 10;
    prev = p;
    dir = -dir;
  }
  return 1;
}
bool cekblock(int x) {
  int dir = 0;
  int prev = -1;
  int u = 7;
  while (u--) {
    int p = x % 10;
    if (dir == 0 && prev != -1) {
      if (p > prev)
        dir = 1;
      else if (p < prev)
        dir = -1;
      else
        return 0;
    }
    if (dir == 1) {
      if (p > prev)
        ;
      else
        return 0;
    }
    if (dir == -1) {
      if (p < prev)
        ;
      else
        return 0;
    }
    x /= 10;
    prev = p;
    dir = -dir;
  }
  return 1;
}
int num[2][10][760000];
int mapping[2][10000000];
int main() {
  long long dv, k, m, lim = 1;
  cin >> dv >> k;
  m = 14;
  while (m--) lim *= 10;
  memset(num, 0, sizeof(num));
  memset(mapping, 0, sizeof(mapping));
  int co = 0;
  vector<int> haha[2];
  vector<pair<int, int> > data[2];
  for (int(a) = (0); (a) <= (10000000 - 1); (a)++) {
    if (cekblock(a)) {
      int i = a / 1000000;
      int j = (a - i * 1000000) / 100000;
      if (i > j) {
        haha[0].push_back(a % dv);
        data[0].push_back(make_pair(a % dv, i));
      } else {
        haha[1].push_back(a % dv);
        data[1].push_back(make_pair(a % dv, i));
      }
      co++;
    }
  }
  sort((haha[0]).begin(), (haha[0]).end());
  (haha[0]).erase(unique((haha[0]).begin(), (haha[0]).end()), (haha[0]).end());
  sort((haha[1]).begin(), (haha[1]).end());
  (haha[1]).erase(unique((haha[1]).begin(), (haha[1]).end()), (haha[1]).end());
  memset(mapping, -1, sizeof(mapping));
  for (int(a) = (0); (a) <= ((int)haha[0].size() - 1); (a)++) {
    int i = haha[0][a];
    mapping[0][i] = a;
  }
  for (int(a) = (0); (a) <= ((int)data[0].size() - 1); (a)++) {
    num[0][data[0][a].second][mapping[0][data[0][a].first]]++;
  }
  for (int(a) = (0); (a) <= ((int)haha[1].size() - 1); (a)++) {
    int i = haha[1][a];
    mapping[1][i] = a;
  }
  for (int(a) = (0); (a) <= ((int)data[1].size() - 1); (a)++) {
    num[1][data[1][a].second][mapping[1][data[1][a].first]]++;
  }
  long long ways = 0;
  for (int(a) = (0); (a) <= (10000000 - 1); (a)++) {
    if (a == 0) {
      for (int b = dv; b < 10000000; b += dv) {
        if (cek(b)) {
          ways++;
          if (ways == k) {
            long long ans = b;
            if ((long long)ans > lim) ans = -1;
            cout << ans << endl;
            goto lala;
          }
        }
      }
    } else if (cek(a)) {
      long long mod = ((long long)a * 10000000) % dv;
      long long match = dv - mod;
      if (match == dv) match = 0;
      if (match >= 10000000) continue;
      if (a < 10) {
        long long tmp = 0;
        if (mapping[0][match] != -1) {
          for (int(b) = (a + 1); (b) <= (9); (b)++)
            tmp += num[0][b][mapping[0][match]];
        }
        if (mapping[1][match] != -1) {
          for (int(b) = (a - 1); (b) >= (0); (b)--)
            tmp += num[1][b][mapping[1][match]];
        }
        if (ways + tmp >= k) {
          for (int(b) = (0); (b) <= (10000000 - 1); (b)++) {
            if (cekblock(b)) {
              int i = b / 1000000;
              int j = (b - i * 1000000) / 100000;
              if (((a < i && i > j) || (a > i && i < j)) && b % dv == match) {
                ways++;
                if (ways == k) {
                  long long ans = (long long)a * 10000000 + b;
                  if ((long long)ans > lim) ans = -1;
                  cout << ans << endl;
                  goto lala;
                }
              }
            }
          }
        }
        ways += tmp;
      } else {
        int p = a % 100;
        int q = a % 10;
        p /= 10;
        if (p > q) {
          long long tmp = 0;
          if (mapping[0][match] != -1) {
            for (int(b) = (q + 1); (b) <= (9); (b)++)
              tmp += num[0][b][mapping[0][match]];
          }
          if (ways + tmp >= k) {
            for (int(b) = (0); (b) <= (10000000 - 1); (b)++) {
              if (cekblock(b)) {
                int i = b / 1000000;
                int j = (b - i * 1000000) / 100000;
                if (q < i && i > j && b % dv == match) {
                  ways++;
                  if (ways == k) {
                    long long ans = (long long)a * 10000000 + b;
                    if ((long long)ans > lim) ans = -1;
                    cout << ans << endl;
                    goto lala;
                  }
                }
              }
            }
          }
          ways += tmp;
        } else {
          long long tmp = 0;
          if (mapping[1][match] != -1) {
            for (int(b) = (q - 1); (b) >= (0); (b)--)
              tmp += num[1][b][mapping[1][match]];
          }
          if (ways + tmp >= k) {
            for (int(b) = (0); (b) <= (10000000 - 1); (b)++) {
              if (cekblock(b)) {
                int i = b / 1000000;
                int j = (b - i * 1000000) / 100000;
                if (q > i && i < j && b % dv == match) {
                  ways++;
                  if (ways == k) {
                    long long ans = (long long)a * 10000000 + b;
                    if ((long long)ans > lim) ans = -1;
                    cout << ans << endl;
                    goto lala;
                  }
                }
              }
            }
          }
          ways += tmp;
        }
      }
    }
  }
  cout << "-1" << endl;
lala:;
}
