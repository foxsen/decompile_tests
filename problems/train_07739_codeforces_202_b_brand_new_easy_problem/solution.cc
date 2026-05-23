#include <bits/stdc++.h>
using namespace std;
int simi, n, minsim = -1e9, fir, sec;
;
vector<pair<int, int> > inv;
string lesha[6], archive[30][30];
int indexes[6], m, k[30];
int count_inv() {
  int res = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++)
      if (indexes[i] < indexes[j]) res++;
  }
  return res;
}
int main() {
  cin >> n;
  simi = n * (n - 1) / 2;
  simi++;
  for (int i = 0; i < n; i++) {
    cin >> lesha[i];
    indexes[i] = i;
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> k[i];
    for (int j = 0; j < k[i]; j++) cin >> archive[i][j];
  }
  do {
    sec = 0;
    fir = 0;
    for (int i = 0; i < n; i++) {
      fir *= 10;
      fir += indexes[i];
    }
    sec = count_inv();
    inv.push_back(make_pair(fir, sec));
  } while (next_permutation(indexes, indexes + n));
  int ind = 0;
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < inv.size(); i++) {
      int code = inv[i].first, inve = inv[i].second;
      string currentarray[6];
      for (int z = n - 1; z >= 0; z--) {
        currentarray[z] = lesha[code % 10];
        code /= 10;
      }
      int cur = 0;
      bool f = false;
      for (int l = 0; l < k[j]; l++) {
        if (archive[j][l] == currentarray[cur]) {
          cur++;
        }
        if (cur == n) {
          f = true;
          break;
        }
      }
      if (f) {
        if ((n * (n - 1) / 2 - inve + 1) > minsim) {
          minsim = (n * (n - 1) / 2 - inve + 1);
          ind = j;
        }
      }
    }
  }
  if (minsim == -1e9)
    cout << "Brand new problem!";
  else {
    cout << ind + 1 << endl;
    cout << "[:";
    for (int i = 0; i < minsim; i++) cout << "|";
    cout << ":]";
  }
  return 0;
}
