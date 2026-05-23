#include <bits/stdc++.h>
using namespace std;
map<int, long long> mb;
map<int, long long> ms;
map<int, long long>::iterator it;
map<int, long long>::reverse_iterator it2;
vector<pair<int, long long> > v;
int main() {
  int n, s, i, p, q;
  char ch;
  cin >> n >> s;
  for (i = 1; i <= n; i++) {
    cin >> ch;
    scanf("%d %d", &p, &q);
    if (ch == 'B') {
      mb[p] += q;
    } else {
      ms[p] += q;
    }
  }
  for (it = ms.begin(), i = 1; it != ms.end() && i <= s; it++, i++) {
    v.push_back(make_pair(it->first, it->second));
  }
  for (i = i - 2; i >= 0; i--) {
    printf("S %d %d\n", v[i].first, v[i].second);
  }
  for (it2 = mb.rbegin(), i = 1; it2 != mb.rend() && i <= s; it2++, i++) {
    printf("B %d %d\n", it2->first, it2->second);
  }
  return 0;
}
