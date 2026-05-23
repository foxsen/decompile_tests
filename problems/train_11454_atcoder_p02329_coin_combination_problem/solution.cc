#pragma region kyomukyomupurin

/**
 *    author  : 𝒌𝒚𝒐𝒎𝒖𝒌𝒚𝒐𝒎𝒖𝒑𝒖𝒓𝒊𝒏
 *    created : 2020-04-24 14:15:54
 **/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using int64 = long long;

template <class T>
using binary_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
  return os << '(' << p.first << ", " << p.second << ')';
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  int flag = 0;
  for (auto e : vec) os << (flag++ ? ", " : "{") << e;
  return os << '}';
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& st) {
  int flag = 0;
  for (auto e : st) os << (flag++ ? ", " : "{") << e;
  return os << '}';
}

template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::map<T, U>& mp) {
  int flag = 0;
  for (auto e : mp) os << (flag++ ? ", " : "{") << e;
  return os << '}';
}

template <class T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
  for (T& e : vec) is >> e;
  return is;
}

#define all(_) begin(_), end(_)
#define rall(_) rbegin(_), rend(_)

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

void debug_out() { std::cerr << '\n'; }

template <class Head, class... Tail>
void debug_out(Head&& head, Tail&&... tail) {
  std::cerr << head;
  if (sizeof...(Tail) != 0) std::cerr << ", ";
  debug_out(std::forward<Tail>(tail)...);
}

#pragma endregion kyomukyomupurin

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  int64 v; cin >> v;
  vector<int64> a(n), b(n), c(n), d(n); cin >> a >> b >> c >> d;

  vector<int64> ab, cd;

  for (int64 ea : a) {
    for (int64 eb : b) {
      ab.emplace_back(ea + eb);
    }
  }

  for (int64 ec : c) {
    for (int64 ed : d) {
      cd.emplace_back(ec + ed);
    }
  }

  sort(all(ab));
  sort(all(cd));

  int64 ans = 0;

  for (int64 e : ab) {
    ans += upper_bound(all(cd), v - e) - lower_bound(all(cd), v - e);
  }

  cout << ans << endl;

  return 0;
}
