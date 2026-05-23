#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
  cin >> n >> k;
  int total = (n * (n - 1)) / 2;
  if (total >= n * k) {
    total = n * k;
    cout << total << "\n";
    int nod1 = 1;
    int nod2 = nod1 + 1;
    int cate = 0;
    while (total > 0) {
      cate++;
      if (nod2 > n) nod2 = 1;
      cout << nod1 << " " << nod2 << "\n";
      if (cate == k) {
        nod1++;
        nod2 = nod1 + 1;
        cate = 0;
      } else
        nod2++;
      total--;
    }
  } else
    cout << -1 << "\n";
}
