#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<long long int> a(n), b(n);
  for (register int i = 0; i < n; i++) cin >> a[i];
  for (register int i = 0; i < n; i++) cin >> b[i];
  long long int sum = 0;
  vector<long long int> groups;
  vector<long long int> temp;
  vector<long long int> leftout;
  vector<bool> visited(n);
  for (register int i = 0; i < n; i++) {
    if (visited[i]) continue;
    temp.clear();
    temp.push_back(i);
    for (register int j = i + 1; j < n; j++) {
      if ((a[i] ^ a[j]) == 0LL) {
        temp.push_back(j);
        visited[j] = true;
      }
    }
    if (temp.size() < 2) {
      leftout.push_back(i);
      continue;
    }
    for (auto elem : temp) {
      groups.push_back(elem);
      sum += b[elem];
    }
  }
  int xor_sum = 0;
  bool flag = false;
  for (int i = 0; i < leftout.size(); i++) {
    xor_sum = 0;
    for (auto elem : groups) {
      if (a[leftout[i]] & ~a[elem]) {
        xor_sum++;
      }
    }
    if (groups.size() >= 2 && xor_sum < groups.size()) {
      groups.push_back(leftout[i]);
      sum += b[leftout[i]];
    }
  }
  cout << sum << "\n";
  return 0;
}
