#include <bits/stdc++.h>
using namespace std;
struct line {
  long long a, b, c;
};
struct line calc(long long x1, long long y1, long long x2, long long y2) {
  struct line nw;
  nw.a = y2 - y1;
  nw.b = x1 - x2;
  nw.c = (nw.a) * x1 + (nw.b) * y1;
  return nw;
}
bool chk(struct line ln, pair<int, int> point) {
  if ((point.first * ln.a) + (point.second * ln.b) == ln.c) {
    return true;
  }
  return false;
}
int main() {
  long long n;
  cin >> n;
  vector<pair<long long, long long> > list;
  for (long long i = 0, x, y; i < n; ++i) {
    cin >> x >> y;
    list.push_back({x, y});
  }
  if (n <= 3) {
    cout << "YES\n";
    return 0;
  }
  struct line l1 =
      calc(list[0].first, list[0].second, list[1].first, list[1].second);
  struct line l2;
  long long no = 0, sec = 0, ffound = 0, id1, id2;
  for (long long i = 2; i < n; ++i) {
    if (chk(l1, list[i])) {
    } else {
      if (ffound == 0) {
        id1 = i;
        ffound++;
      } else {
        if (sec == 0) {
          l2 = calc(list[id1].first, list[id1].second, list[i].first,
                    list[i].second);
          sec++;
        } else {
          if (!chk(l2, list[i])) {
            no++;
          }
        }
      }
    }
    if (no != 0) break;
  }
  if (no == 0) {
    cout << "YES\n";
    return 0;
  }
  l1 = calc(list[0].first, list[0].second, list[2].first, list[2].second);
  no = 0, sec = 0, ffound = 0, id1, id2;
  for (long long i = 1; i < n; ++i) {
    if (i == 2) continue;
    if (chk(l1, list[i])) {
    } else {
      if (ffound == 0) {
        id1 = i;
        ffound++;
      } else {
        if (sec == 0) {
          l2 = calc(list[id1].first, list[id1].second, list[i].first,
                    list[i].second);
          sec++;
        } else {
          if (!chk(l2, list[i])) {
            no++;
          }
        }
      }
    }
    if (no != 0) break;
  }
  if (no == 0) {
    cout << "YES\n";
    return 0;
  }
  l1 = calc(list[1].first, list[1].second, list[2].first, list[2].second);
  no = 0, sec = 0, ffound = 0, id1, id2;
  for (long long i = 0; i < n; ++i) {
    if (i == 1 || i == 2) continue;
    if (chk(l1, list[i])) {
    } else {
      if (ffound == 0) {
        id1 = i;
        ffound++;
      } else {
        if (sec == 0) {
          l2 = calc(list[id1].first, list[id1].second, list[i].first,
                    list[i].second);
          sec++;
        } else {
          if (!chk(l2, list[i])) {
            no++;
          }
        }
      }
    }
    if (no != 0) break;
  }
  if (no == 0) {
    cout << "YES\n";
    return 0;
  }
  cout << "NO\n";
  return 0;
}
