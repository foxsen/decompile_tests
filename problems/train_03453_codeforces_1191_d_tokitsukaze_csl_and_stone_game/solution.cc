#include <bits/stdc++.h>
using namespace std;
vector<long long> nums;
long long repetidos() {
  sort(nums.begin(), nums.end());
  long long rta = 0, ant = -1;
  for (auto x : nums) {
    if (x == ant) {
      rta++;
    }
    ant = x;
  }
  return rta;
}
bool falla(int n) {
  for (int i = 1; i < n - 1; i++) {
    if (nums[i] == nums[i - 1] + 1 && nums[i] == nums[i + 1]) {
      return true;
    }
  }
  return false;
}
int main() {
  int n;
  long long acum = 0, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    nums.push_back(x);
    acum += x;
  }
  long long rep = repetidos();
  if (rep > 1 || (n > 1 && nums[0] == nums[1] && nums[0] == 0) || falla(n)) {
    cout << "cslnb\n";
    return 0;
  }
  long long N = n;
  long long menos = (N * (N - 1)) / 2;
  if ((acum - menos) % 2 == 0) {
    cout << "cslnb\n";
  } else {
    cout << "sjfnb\n";
  }
}
