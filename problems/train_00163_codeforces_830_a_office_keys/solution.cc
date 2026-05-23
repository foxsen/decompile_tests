#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
class A830 {
 private:
  i64 cost(i64 a, i64 b, i64 c) { return abs(a - b) + abs(b - c); }

 public:
  void solve(istream& in, ostream& out) {
    int n, k, p;
    in >> n >> k >> p;
    vector<int> a(n), b(k);
    for (int i = 0; i < n; ++i) {
      in >> a[i];
    }
    for (int i = 0; i < k; ++i) {
      in >> b[i];
    }
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    i64 low = 0, high = 1e11, ans = high;
    while (low <= high) {
      i64 mid = (low + high) / 2;
      bool ok1 = true;
      for (int i = 0, j = 0; i < n; ++i) {
        while (j < k && cost(a[i], b[j], p) > mid) {
          ++j;
        }
        if (j == k) {
          ok1 = false;
          break;
        }
        ++j;
      }
      bool ok2 = true;
      for (int i = n - 1, j = k - 1; i >= 0; --i) {
        while (j >= 0 && cost(a[i], b[j], p) > mid) {
          --j;
        }
        if (j == -1) {
          ok2 = false;
          break;
        }
        --j;
      }
      if (ok1 || ok2) {
        high = mid - 1;
        ans = mid;
      } else {
        low = mid + 1;
      }
    }
    out << ans << "\n";
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  A830 solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
