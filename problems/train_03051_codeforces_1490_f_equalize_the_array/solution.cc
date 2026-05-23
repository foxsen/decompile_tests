#include <iostream>
#include <algorithm>

using namespace std;

#ifndef ONLINE_JUDGE
  #include <fstream>
  #define cin fin
  #define cout fout
  ifstream fin ("test.in");
  ofstream fout ("test.out");
#endif

int t, n, a[200001], f[200001], nra, p[100001], k;

int rasp (int mij) {
  int r = 0;
  for (int i = 1; i <= k; i++) {
    if (p[i] - mij < 0)
      r += p[i] * f[p[i]];
    else
      r += (p[i] - mij) * f[p[i]];
  }
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    cin >> n; int r = n + 1; k = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; f[i] = 0;
    }
    sort (a + 1, a + n + 1);
    nra = 0; a[0] = a[1]; a[n + 1] = a[n] + 1;
    for (int i = 1; i <= n + 1; i++) {
      if (a[i] == a[i - 1])
        nra++;
      else {
        f[nra]++;
        nra = 1;
      }
    }
    for (int i = 1; i <= n; i++)
      if (f[i])
        p[++k] = i;
    for (int i = 1; i <= k; i++)
      r = min (r, rasp(p[i]));
    cout << r << '\n';
  }
  return 0;
}
