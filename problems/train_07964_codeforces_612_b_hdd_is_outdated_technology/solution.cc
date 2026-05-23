#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
class c {
 public:
  int val, pos;
  c(int v, int p) : val(v), pos(p) {}
  c() {}
};
int main() {
  int n;
  cin >> n;
  vector<c> nums(n);
  for (int i = 0; i < n; i++) {
    int f;
    cin >> f;
    c num(f, i);
    nums[i] = num;
  }
  sort(nums.begin(), nums.end(), [](c a, c b) { return a.val < b.val; });
  long long ans = 0;
  for (int i = 1; i < nums.size(); i++) {
    ans += abs(nums[i].pos - nums[i - 1].pos);
  }
  cout << ans << endl;
}
