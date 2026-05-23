#include <bits/stdc++.h>
using namespace std;
int arr[int(1e7 + 100)];
void aum(int i) {
  if (i % 2) {
    arr[i / 2 + 1] += arr[i];
    arr[i / 2] += arr[i];
  } else
    arr[i / 2] += 2 * arr[i];
}
int main() {
  ios_base::sync_with_stdio(0);
  set<int> conj;
  memset(arr, 0, sizeof arr);
  int n, m, l, ans = int(2 * 1e9 + 100), ptr = 0;
  cin >> n >> m;
  long long cnt = n, carry = 0, slices = m;
  for (int i = 0; i < n; ++i) {
    cin >> l;
    carry += l;
    ++arr[l];
  }
  if (carry < m) {
    cout << "-1\n";
    return 0;
  }
  for (int i = int(1e7 + 100); cnt < m; --i) {
    if (arr[i]) {
      aum(i);
      cnt += arr[i];
      arr[i] = 0;
    }
  }
  long long aux = 0;
  for (int i = int(1e7 + 100); i >= 1; --i) {
    if (arr[i]) {
      conj.insert(i);
      aux += arr[i];
      if (aux >= m) {
        ans = i;
        break;
      }
    }
  }
  for (int i = int(1e7 + 100); i >= 1; --i) {
    if (arr[i]) {
      int go = (i % 2 == 1 ? 1 : 0);
      if (i / 2 + go <= *(conj.begin())) {
        break;
      } else {
        aum(i);
        if (i % 2) conj.insert(i / 2 + 1);
        conj.insert(i / 2);
        conj.erase(i);
        aux += arr[i];
        while (1) {
          int val = (*conj.begin());
          if (aux - arr[val] < m) break;
          aux -= arr[val];
          conj.erase(conj.begin());
        }
      }
    }
  }
  cout << max(1, *(conj.begin())) << "\n";
  return 0;
}
