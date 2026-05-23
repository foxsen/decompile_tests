#include <bits/stdc++.h>
using namespace std;
void boost() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int N = 1e6;
const int inf = 1e9 + 7;
int q;
int a;
map<int, int> ans;
vector<int> nums;
int cnt;
int main() {
  boost();
  for (int mask = 3, i = 2; mask < (1 << 25); i++) {
    nums.push_back(mask);
    mask |= 1 << i;
  }
  ans[nums[cnt++]] = 1;
  ans[nums[cnt++]] = 1;
  ans[nums[cnt++]] = 5;
  ans[nums[cnt++]] = 1;
  ans[nums[cnt++]] = 21;
  ans[nums[cnt++]] = 1;
  ans[nums[cnt++]] = 85;
  ans[nums[cnt++]] = 73;
  ans[nums[cnt++]] = 341;
  ans[nums[cnt++]] = 89;
  ans[nums[cnt++]] = 1365;
  ans[nums[cnt++]] = 1;
  ans[nums[cnt++]] = 5461;
  ans[nums[cnt++]] = 4681;
  ans[nums[cnt++]] = 21845;
  ans[nums[cnt++]] = 1;
  ans[nums[cnt++]] = 87381;
  ans[nums[cnt++]] = 1;
  ans[nums[cnt++]] = 349525;
  ans[nums[cnt++]] = 299593;
  ans[nums[cnt++]] = 1398101;
  ans[nums[cnt++]] = 178481;
  ans[nums[cnt++]] = 5592405;
  ans[nums[cnt++]] = 1082401;
  cin >> q;
  while (q--) {
    int mask = 0;
    cin >> a;
    int i;
    for (i = 0; (1 << i) <= a; i++) {
      if (!((1 << i) & a)) {
        mask |= (1 << i);
      }
    }
    if (mask == 0) {
      cout << ans[a] << "\n";
    } else {
      cout << (a ^ mask) << "\n";
    }
  }
}
