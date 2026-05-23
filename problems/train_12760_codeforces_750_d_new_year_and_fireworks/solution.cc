#include <bits/stdc++.h>
using namespace std;
class C_ {};
template <typename T>
C_& operator<<(C_& __m, const T& __s) {
  if (!1) cerr << "\E[91m" << __s << "\E[0m";
  return __m;
}
C_ merr;
struct __s {
  __s() {
    if (1) {
      ios_base::Init i;
      cin.sync_with_stdio(0);
      cin.tie(0);
    }
  }
  ~__s() {
    merr << "Execution time: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
  }
} __S;
void sym(int& x, int& y, int x0, int y0, int dx, int dy) {
  x -= x0;
  y -= y0;
  if (labs(dx) + labs(dy) == 2) {
    swap(x, y);
    if (dx + dy == 0) {
      x *= -1;
      y *= -1;
    }
  } else {
    if (dx == 0) {
      x *= -1;
    } else {
      y *= -1;
    }
  }
  x += x0;
  y += y0;
}
void rot(int& dx, int& dy) {
  int ndx = dx + dy;
  if (abs(ndx) > 1) ndx /= 2;
  int ndy = dy - dx;
  if (abs(ndy) > 1) ndy /= 2;
  dx = ndx;
  dy = ndy;
}
void rotrev(int& dx, int& dy) {
  int ndx = dx - dy;
  if (abs(ndx) > 1) ndx /= 2;
  int ndy = dx + dy;
  if (abs(ndy) > 1) ndy /= 2;
  dx = ndx;
  dy = ndy;
}
int main() {
  size_t n;
  vector<int> A;
  cin >> n;
  A.resize(n);
  for (size_t i = 0; i < n; i++) {
    cin >> A[i];
  }
  int x = 0, y = 0;
  int dx = 0, dy = 1;
  for (size_t i = 0; i < n; i++) {
    x += dx * (A[i] - (i == 0));
    y += dy * (A[i] - (i == 0));
    rot(dx, dy);
  }
  reverse(A.begin(), A.end());
  set<pair<int, int>> S;
  rotrev(dx, dy);
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < (size_t)A[i]; j++) {
      S.insert({x, y});
      x -= dx;
      y -= dy;
    }
    if (i == n - 1) break;
    rotrev(dx, dy);
    vector<pair<int, int>> V;
    for (const auto& p : S) {
      int x1, y1;
      tie(x1, y1) = p;
      sym(x1, y1, x, y, dx, dy);
      V.emplace_back(x1, y1);
    }
    for (const auto& p : V) {
      S.insert(p);
    }
  }
  for (size_t i = 0; i < 8; i++) {
    rotrev(dx, dy);
  }
  cout << S.size() << '\n';
  return 0;
}
