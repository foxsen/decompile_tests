#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, ind = 1;
    string a, b;
    cin >> n >> a >> b;
    for (long long i = 0; i < n; i++)
      if (a[i] > b[i]) {
        cout << -1 << endl;
        ind = 0;
        break;
      }
    if (ind == 1) {
      long long rez = 0;
      for (long long i = 0; i < 20; i++) {
        char bm = 't' + 1;
        for (long long i1 = 0; i1 < n; i1++) {
          if (a[i1] == ('a' + i) && b[i1] != ('a' + i))
            if (b[i1] < bm) bm = b[i1];
        }
        if (bm == ('t' + 1))
          continue;
        else {
          rez++;
          for (long long i1 = 0; i1 < n; i1++)
            if (a[i1] == ('a' + i) && b[i1] != ('a' + i)) a[i1] = bm;
        }
      }
      cout << rez << endl;
    }
  }
  return 0;
}
