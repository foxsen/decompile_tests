#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, epo;
  vector<int> epos;
  cin >> n;
  for (i = 1; i < n; i++) {
    cin >> epo;
    epos.push_back(epo);
  }
  sort(epos.begin(), epos.end());
  epo = 1;
  for (i = 0; i < n; i++, epo++) {
    if (epos[i] != epo) {
      cout << epo;
      break;
    }
  }
  return 0;
}
