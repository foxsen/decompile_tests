#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > v;
long long n;
long double pot[200], ipot[200];
long double GCD[200000];
long long gcd(long long a, long long b) {
  if (a < 0) a = -a;
  if (b < 0) b = -b;
  if (b == 0) return a;
  return gcd(b, a % b);
}
long double Area(long long a, long long b) {
  long double res = 0;
  for (long long i = (a + 1) % n; i != b; i = (i + 1) % n) {
    long long next = (i + 1) % n;
    res += abs((v[next].first - v[a].first) * (v[i].second - v[a].second) -
               (v[i].first - v[a].first) * (v[next].second - v[a].second));
  }
  return res * 0.5;
}
inline int MOD(int a, int b) { return (a >= b ? a - b : a); }
long double Perimeter(long long a, long long b) {
  long double res = gcd(v[b].first - v[a].first, v[b].second - v[a].second);
  for (long long i = a; i != b; i = (i + 1) % n) {
    res += gcd(v[(i + 1) % n].first - v[i].first,
               v[(i + 1) % n].second - v[i].second);
  }
  return res;
}
long double prob(int n, int j) {
  return (1 - (n - j - 1 < 200 ? ipot[n - j - 1] : 0)) /
         (pot[j + 1] + (n - j - 1 < 200
                            ? (-1 - n - n * (n - 1) / 2.) * ipot[n - j - 1]
                            : 0));
}
long double IntegerPolls(long long a, long long b) {
  return Area(a, b) + 1. - Perimeter(a, b) / 2.;
}
long double eleva(long long a, long long b) {
  if (b == 0) return 1;
  long double aux = eleva(a, b / 2);
  aux *= aux;
  if ((b & 1) != 0) aux *= a;
  return aux;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  v = vector<pair<long long, long long> >(n);
  for (long long i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
  long double res = Area(0, 0) + 1;
  for (long long i = 0; i < n; i++) {
    GCD[i] = gcd(v[MOD(i + 1, n)].first - v[i].first,
                 v[MOD(i + 1, n)].second - v[i].second);
    res -= 0.5 * GCD[i];
  }
  pot[0] = 1.;
  ipot[0] = 1.;
  for (long long i = 1; i <= 199; i++) {
    pot[i] = pot[i - 1] * 2.;
    ipot[i] = 1. / pot[i];
  }
  for (long long i = 0; i < n; i++) {
    if (n <= 2) continue;
    long double area = 0;
    long double perimetre = 0.;
    long long next = MOD(i + 1, n);
    long long again = MOD(next + 1, n);
    area += 0.5 *
            abs((v[next].first - v[i].first) * (v[again].second - v[i].second) -
                (v[again].first - v[i].first) * (v[next].second - v[i].second));
    perimetre += GCD[i];
    perimetre += GCD[next];
    perimetre -=
        gcd(v[again].first - v[i].first, v[again].second - v[i].second);
    res -= prob(n, 2) * (area - 0.5 * perimetre);
    long double last =
        gcd(v[again].first - v[i].first, v[again].second - v[i].second);
    for (int j = 3; j <= min(n - 1, 80LL); ++j) {
      int act = MOD(i + j, n);
      int ant = MOD(i + j - 1, n);
      area += 0.5 *
              abs((v[act].first - v[i].first) * (v[ant].second - v[i].second) -
                  (v[ant].first - v[i].first) * (v[act].second - v[i].second));
      perimetre += GCD[ant];
      perimetre += last;
      last = gcd(v[act].first - v[i].first, v[act].second - v[i].second);
      perimetre -= last;
      res -= prob(n, j) * (area - 0.5 * perimetre);
    }
  }
  cout.precision(10);
  cout << fixed << res << endl;
}
