#include <bits/stdc++.h>
using namespace std;
long n;
vector<long> answer;
long decimal(long a) {
  int ans = a, q;
  for (int i = 0; i <= 9; i++) {
    q = pow(10, i);
    ans += (a / q) % 10;
  }
  return ans;
}
int main() {
  cin >> n;
  for (int i = n; i >= n - 100 && i >= 1; i--) {
    if (decimal(i) == n) {
      answer.push_back(i);
    }
  }
  cout << answer.size();
  sort(answer.begin(), answer.end());
  for (int i = 0; i < answer.size(); i++) {
    cout << endl << answer[i];
  }
  return 0;
}
