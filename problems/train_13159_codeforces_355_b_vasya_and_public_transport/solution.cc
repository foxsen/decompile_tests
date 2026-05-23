#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  ;
  int arr[4];
  for (int i = 0; i < 4; ++i) {
    cin >> arr[i];
  }
  int n, m;
  cin >> n >> m;
  vector<int> b(n), t(m);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> t[i];
  }
  int ansB = 0, ansT = 0, resB = 0, resT = 0, totalB = 0, totalT = 0;
  for (int i = 0; i < n; ++i) {
    ansB = b[i] * arr[0];
    ansB = min(ansB, arr[1]);
    resB += ansB;
  }
  totalB = min(resB, arr[2]);
  for (int i = 0; i < m; ++i) {
    ansT = t[i] * arr[0];
    ansT = min(ansT, arr[1]);
    resT += ansT;
  }
  totalT = min(resT, arr[2]);
  cout << min(arr[3], totalB + totalT);
  return 0;
}
