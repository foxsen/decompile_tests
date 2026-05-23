#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, res = 0;
  cin >> n >> k;
  vector<int> arrAB;
  vector<int> arrA;
  vector<int> arrB;
  for (int i = 0; i < n; i++) {
    int time, a, b;
    cin >> time >> a >> b;
    if (a == 1 && b == 1) {
      arrAB.push_back(time);
    } else if (a == 1) {
      arrA.push_back(time);
    } else if (b == 1) {
      arrB.push_back(time);
    }
  }
  sort(arrA.begin(), arrA.end());
  sort(arrB.begin(), arrB.end());
  for (int i = 0; i < arrA.size() && i < arrB.size(); i++) {
    arrAB.push_back(arrA[i] + arrB[i]);
  }
  sort(arrAB.begin(), arrAB.end());
  if (arrAB.size() < k)
    cout << "-1" << endl;
  else {
    for (int i = 0; i < k; i++) res += arrAB[i];
    cout << res << endl;
  }
  return 0;
}
