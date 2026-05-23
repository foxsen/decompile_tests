#include <bits/stdc++.h>
using namespace std;
map<long long, set<pair<long long, long long>>> points;
long long size_ = 0;
map<pair<long long, long long>, long long> cnt_dirs, on_line;
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
void norm(pair<long long, long long>& p) {
  long long d = gcd(p.first, p.second);
  p.first /= d;
  p.second /= d;
}
void norm(long long& x, long long& y) {
  long long d = gcd(x, y);
  x /= d;
  y /= d;
}
void insert(long long x, long long y) {
  size_++;
  long long r2 = x * x + y * y;
  auto& st = points[r2];
  for (auto& pr : st) {
    pair<long long, long long> sum =
        make_pair(abs(x + pr.first), abs(y + pr.second));
    norm(sum);
    cnt_dirs[sum]++;
  }
  st.insert(make_pair(x, y));
  norm(x, y);
  on_line[make_pair(x, y)]++;
}
void erase(long long x, long long y) {
  size_--;
  long long r2 = x * x + y * y;
  auto& st = points[r2];
  st.erase(make_pair(x, y));
  for (auto& pr : st) {
    pair<long long, long long> sum =
        make_pair(abs(x + pr.first), abs(y + pr.second));
    norm(sum);
    cnt_dirs[sum]--;
  }
  norm(x, y);
  on_line[make_pair(x, y)]--;
}
long long get_ans(long long x, long long y) {
  long long d = gcd(abs(x), abs(y));
  x /= d;
  y /= d;
  return size_ - 2 * cnt_dirs[make_pair(x, y)] - on_line[make_pair(x, y)];
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    int tp;
    long long x, y;
    cin >> tp >> x >> y;
    if (tp == 1) {
      insert(x, y);
    } else if (tp == 2) {
      erase(x, y);
    } else if (tp == 3) {
      cout << get_ans(x, y) << endl;
    }
  }
  return 0;
}
