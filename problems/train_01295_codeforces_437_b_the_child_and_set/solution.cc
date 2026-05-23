#include <bits/stdc++.h>
using namespace std;
void hehe() {
  int sum, limit;
  cin >> sum >> limit;
  vector<int> ans;
  for (int i = limit; i > 0; i--) {
    int j = i, count = 0;
    while (j % 2 == 0) {
      count++;
      j = j / 2;
    }
    int p = pow(2, count);
    if (sum - p >= 0) {
      sum -= p;
      ans.push_back(i);
    }
  }
  if (sum) {
    cout << -1 << endl;
    return;
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
int main() {
  int t = 1;
  while (t--) {
    hehe();
  }
  return 0;
}
