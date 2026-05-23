#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m, aib[4002][4002], q;
bool pus[2002][2002];
void add(int L, int C) {
  for (int i = L; i <= n + m - 1; i += (i & (-i)))
    for (int j = C; j <= n + m - 1; j += (j & (-j))) aib[i][j]++;
}
int query(int L, int C) {
  int ans = 0;
  for (int i = L; i; i -= (i & (-i)))
    for (int j = C; j; j -= (j & (-j))) ans += aib[i][j];
  return ans;
}
bool tri(int L, int C, int mid) {
  int X = L + C - 1;
  int Y = L - C + m;
  int val = query(min(n + m - 1, X + mid), min(n + m - 1, Y + mid)) -
            query(max(0, X - mid - 1), min(n + m - 1, Y + mid));
  val = val - query(min(n + m - 1, X + mid), max(0, Y - mid - 1)) +
        query(max(0, X - mid - 1), max(0, Y - mid - 1));
  int tot = 0;
  int st = C - mid;
  int dr = C + mid;
  int lstline = max(1, L - mid);
  for (int i = L; i >= lstline; --i) {
    tot += min(m, dr) - max(1, st) + 1;
    ++st;
    --dr;
  }
  st = C - mid + 1;
  dr = C + mid - 1;
  lstline = min(n, L + mid);
  for (int i = L + 1; i <= lstline; ++i) {
    tot += min(m, dr) - max(1, st) + 1;
    ++st;
    --dr;
  }
  return (tot == val);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> q;
  for (; q; --q) {
    int L, C;
    cin >> L >> C;
    int st = 0;
    int dr = n + m;
    int ans = 0;
    while (st <= dr) {
      int mid = (st + dr) / 2;
      if (tri(L, C, mid))
        ans = mid + 1, st = mid + 1;
      else
        dr = mid - 1;
    }
    int ansA = 0, ansB = 0;
    int C1 = C;
    int C2 = C;
    for (int first = L - ans; first <= L; ++first) {
      if (first >= 1) {
        if (C1 >= 1 && !pus[first][C1]) {
          pus[first][C1] = 1;
          ansA = first;
          ansB = C1;
          break;
        }
        if (C2 <= m && !pus[first][C2]) {
          pus[first][C2] = 1;
          ansA = first;
          ansB = C2;
          break;
        }
      }
      --C1;
      ++C2;
    }
    C1 = C - ans;
    C2 = C + ans;
    if (ansA == 0)
      for (int first = L; first <= n; ++first) {
        if (first >= 1) {
          if (C1 >= 1 && !pus[first][C1]) {
            pus[first][C1] = 1;
            ansA = first;
            ansB = C1;
            break;
          }
          if (C2 <= m && !pus[first][C2]) {
            pus[first][C2] = 1;
            ansA = first;
            ansB = C2;
            break;
          }
        }
        ++C1;
        --C2;
        if (C1 > C2) break;
      }
    cout << ansA << " " << ansB << '\n';
    add(ansA + ansB - 1, ansA - ansB + m);
  }
  return 0;
}
