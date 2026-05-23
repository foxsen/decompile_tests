#include <bits/stdc++.h>
using namespace std;
string a[1010], b[1010];
set<pair<string, string> > S;
int N, d, t[1010];
int main() {
  cin >> N >> d;
  for (int i = 0; i < N; ++i) cin >> a[i] >> b[i] >> t[i];
  for (int i = 0; i < N; ++i)
    for (int j = i + 1; j < N; ++j)
      if (a[i] == b[j] && a[j] == b[i] && t[j] > t[i] && t[j] - t[i] <= d)
        S.insert(pair<string, string>(min(a[i], a[j]), max(b[i], b[j])));
  cout << S.size();
  for (typeof(S.begin()) i = S.begin(); i != S.end(); ++i)
    cout << endl << i->first << ' ' << i->second;
}
