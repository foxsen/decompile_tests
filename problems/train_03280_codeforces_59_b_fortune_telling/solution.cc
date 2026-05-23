#include <bits/stdc++.h>
using namespace std;
int n, sum;
bool error;
vector<int> oddvec, evenvec;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int xs;
    cin >> xs;
    sum += xs;
    if (xs & 1)
      oddvec.push_back(xs);
    else
      evenvec.push_back(xs);
  }
  sort(oddvec.begin(), oddvec.end());
  sort(evenvec.begin(), evenvec.end());
  if (sum % 2 == 0) {
    if (!oddvec.size())
      error = true;
    else
      sum -= oddvec[0];
  }
  if (!error)
    cout << sum << "\n";
  else
    cout << 0 << "\n";
  return 0;
}
