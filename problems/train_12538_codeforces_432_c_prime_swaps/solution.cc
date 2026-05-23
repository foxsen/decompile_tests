#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j;
  int N;
  cin >> N;
  vector<int> prime;
  prime.push_back(1);
  prime.push_back(2);
  for (i = 3; i <= N; i++) {
    for (j = 1; j < prime.size(); j++)
      if (i % prime[j] == 0) break;
    if (j == prime.size()) prime.push_back(i);
  }
  while (1) {
    for (j = 1; j < prime.size(); j++)
      if (i % prime[j] == 0) break;
    if (j == prime.size()) {
      prime.push_back(i);
      break;
    }
    i++;
  }
  vector<pair<int, int> > a(N);
  for (i = 0; i < N; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  vector<pair<int, int> > c = a;
  vector<int> pos(N);
  for (i = 0; i < N; i++) pos[i] = i;
  sort(a.begin(), a.end());
  vector<pair<int, int> > ans;
  for (i = 0; i < N; i++) {
    if (c[i] == a[i]) continue;
    int from = pos[a[i].second];
    int len = from - i + 1;
    while (len > 1) {
      int p = lower_bound(prime.begin(), prime.end(), len) - prime.begin();
      if (prime[p] > len) p--;
      p = prime[p];
      p--;
      int val = c[from - p].second;
      swap(c[from - p], c[from]);
      swap(pos[val], pos[a[i].second]);
      ans.push_back(make_pair(from - p + 1, from + 1));
      len -= p;
      from -= p;
    }
  }
  cout << ans.size() << endl;
  for (i = 0; i < ans.size(); i++)
    cout << ans[i].first << " " << ans[i].second << endl;
}
