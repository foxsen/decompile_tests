#include <bits/stdc++.h>
using namespace std;
const long long NN = 2e5 + 5;
long long n, m, k, D1, D2, D3, D4, D5, has;
vector<pair<long long, long long> > v[NN];
long long d1[10][10];
long long d2[10][10];
long long d3[10][10];
long long d4[10][10];
long long d5[10][10];
long long p3[NN];
long long p4[NN];
long long p5[NN];
void hai(long long pos, long long jum1, long long jum2, long long jum3,
         long long jum4, long long jum5) {
  if (pos == (k + 1)) {
    if (jum1 == D1 && jum2 == D2 && jum3 == D3 && jum4 == D4 && jum5 == D5)
      has++;
  } else {
    for (long long i = 1; i <= pos; i++)
      hai(pos + 1, jum1 + d1[pos][i], jum2 + d2[pos][i], jum3 + d3[pos][i],
          jum4 + d4[pos][i], jum5 + d5[pos][i]);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(time(NULL));
  cin >> n >> m >> k;
  for (long long i = 1; i <= n; i++) {
    D1 += i;
    D2 += i * i;
    D3 += i;
    D4 += i * i;
    D5 += i * (i + 1);
    p3[i] = i;
    p4[i] = i * i;
    p5[i] = i * (i + 1);
  }
  random_shuffle(p3 + 1, p3 + 1 + n);
  random_shuffle(p4 + 1, p4 + 1 + n);
  random_shuffle(p5 + 1, p5 + 1 + n);
  for (long long i = 1; i <= m; i++) {
    long long ta, tb, tc;
    cin >> ta >> tb >> tc;
    v[ta].push_back(make_pair(tc, tb));
  }
  for (long long i = 1; i <= n; i++) {
    long long sz = v[i].size();
    sort(v[i].begin(), v[i].end());
    for (long long j = 0; j < v[i].size(); j++) {
      d1[sz][j + 1] += v[i][j].second;
      d2[sz][j + 1] += v[i][j].second * v[i][j].second;
      d3[sz][j + 1] += p3[v[i][j].second];
      d4[sz][j + 1] += p4[v[i][j].second];
      d5[sz][j + 1] += p5[v[i][j].second];
    }
  }
  hai(1, 0, 0, 0, 0, 0);
  cout << has << "\n";
}
