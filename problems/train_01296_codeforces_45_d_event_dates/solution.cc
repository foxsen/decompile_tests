#include <bits/stdc++.h>
using namespace std;
template <typename Tp>
inline void outarr(Tp _begin, Tp _end, const char* _delim = " ") {
  for (Tp current = _begin; current != _end; ++current) {
    std::cout << *current << _delim;
  }
  std::cout << '\n';
}
using ll = long long;
using pii = std::pair<int, int>;
constexpr int INF = 0x3f3f3f3f;
constexpr int MOD = static_cast<const int>(1e9 + 7);
struct Segment {
  int L;
  int R;
  int ID;
};
bool operator<(const Segment& lhs, const Segment& rhs) {
  if (lhs.R == rhs.R) {
    return lhs.L < rhs.L;
  }
  return lhs.R < rhs.R;
}
Segment arr[100];
int ans[100];
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < (n); ++i) {
    cin >> arr[i].L >> arr[i].R;
    arr[i].ID = i;
  }
  sort(arr, arr + n);
  set<int> line;
  for (int i = 0; i < (n); ++i) {
    for (int x = arr[i].L;; ++x) {
      if (line.find(x) == line.end()) {
        ans[arr[i].ID] = x;
        line.insert(x);
        break;
      }
    }
  }
  outarr(ans, ans + n);
  return 0;
}
