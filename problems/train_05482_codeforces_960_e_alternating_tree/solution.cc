#include <bits/stdc++.h>
using namespace std;
vector<int> krawedzie[200007];
long long waga[200007];
int ojciec[200007];
int warstwa[200007];
long long parz = 0;
long long nparz = 0;
long long wynik = 0;
void dfs1(int u) {
  if (warstwa[u] % 2 == 0) {
    parz++;
  } else {
    nparz++;
  }
  for (int i = 0; i < krawedzie[u].size(); i++) {
    int v = krawedzie[u][i];
    if (v != ojciec[u]) {
      warstwa[v] = warstwa[u] + 1;
      ojciec[v] = u;
      dfs1(v);
    }
  }
}
pair<long long, long long> dfs2(int u) {
  long long p = 0;
  long long np = 0;
  long long mn = 1;
  if (warstwa[u] % 2 == 1) {
    mn = -1;
  }
  for (int i = 0; i < krawedzie[u].size(); i++) {
    int v = krawedzie[u][i];
    if (v != ojciec[u]) {
      pair<long long, long long> tmp = dfs2(v);
      wynik +=
          (mn * (((p + np) * tmp.first) % 1000000007) * waga[u]) % 1000000007;
      wynik = wynik % 1000000007;
      wynik -=
          (mn * (((p + np) * tmp.second) % 1000000007) * waga[u]) % 1000000007;
      wynik = wynik % 1000000007;
      wynik += (mn * (((tmp.first + tmp.second) * p) % 1000000007) * waga[u]) %
               1000000007;
      wynik = wynik % 1000000007;
      wynik -= (mn * (((tmp.first + tmp.second) * np) % 1000000007) * waga[u]) %
               1000000007;
      wynik = wynik % 1000000007;
      p += tmp.first;
      np += tmp.second;
    }
  }
  wynik += (mn * ((p * (parz + nparz - p - np)) % 1000000007) * waga[u]) %
           1000000007;
  wynik = wynik % 1000000007;
  wynik -= (mn * ((np * (parz + nparz - p - np)) % 1000000007) * waga[u]) %
           1000000007;
  wynik = wynik % 1000000007;
  wynik += (mn * (((parz - p) * (p + np)) % 1000000007) * waga[u]) % 1000000007;
  wynik = wynik % 1000000007;
  wynik -=
      (mn * (((nparz - np) * (p + np)) % 1000000007) * waga[u]) % 1000000007;
  wynik = wynik % 1000000007;
  wynik += (waga[u] * (parz + nparz - p - np)) % 1000000007;
  wynik = wynik % 1000000007;
  if (warstwa[u] % 2 == 0) {
    p++;
  } else {
    np++;
  }
  wynik += (((mn * (parz - p)) % 1000000007) * waga[u]) % 1000000007;
  wynik -= (((mn * (nparz - np)) % 1000000007) * waga[u]) % 1000000007;
  wynik = wynik % 1000000007;
  return make_pair(p, np);
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> waga[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    krawedzie[a].push_back(b);
    krawedzie[b].push_back(a);
  }
  dfs1(0);
  dfs2(0);
  if (wynik < 0) {
    wynik += 1000000007;
  }
  cout << wynik;
  return 0;
}
