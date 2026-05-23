#include <bits/stdc++.h>
using namespace std;
using db = double;
using dbl = long double;
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using gr = vector<vector<int> >;
using grl = vector<vector<ll> >;
using st = stack<int>;
using stl = stack<ll>;
using qu = queue<int>;
using qul = queue<ll>;
using pq = priority_queue<int>;
using pql = priority_queue<ll>;
using piq = priority_queue<pair<int, int> >;
using piql = priority_queue<pair<ll, ll> >;
using ma = map<int, int>;
using ms = map<string, int>;
using mal = map<ll, ll>;
using mp = map<pair<int, int>, int>;
using mpl = map<pair<ll, ll>, int>;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
void input();
void compute();
int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    input();
    compute();
  }
  return 0;
}
ll n, k;
ll w;
ll tab[300001];
ll tab2[300001];
unordered_map<ll, ll> m;
void input() {
  m.clear();
  cin >> n >> k;
  for (int(i) = 0; (i) < (n); (i)++) {
    cin >> tab[i];
    tab2[i] = tab[i];
  }
}
void compute() {
  w = 1;
  sort(tab2, tab2 + n);
  for (int(i) = 0; (i) < (n); (i)++) {
    m[tab2[i]] = i;
  }
  for (int(i) = 0; (i) < (n - 1); (i)++) {
    if (m[tab[i]] + 1 != m[tab[i + 1]]) {
      w++;
    }
  }
  if (w <= k)
    printf("YES\n");
  else
    printf("NO\n");
}
