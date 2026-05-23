#include <bits/stdc++.h>
using namespace std;
int n, puesto;
tuple<long long int, long long int> v[200010];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> puesto;
  long long int a, b;
  long long int maximo = -1;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    maximo = max(maximo, a);
    v[i] = make_tuple(a, b);
  }
  if (puesto == n + 1) {
    printf("0\n");
    return 0;
  }
  sort(v, v + n);
  int pos = n - puesto;
  if (get<0>(v[pos]) > n) {
    printf("-1\n");
    return 0;
  }
  long long int val = get<0>(v[pos]);
  long long int esfuerzo = 0LL, ans = (1LL << 60), puntos, costo;
  multiset<long long int> sw, S;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    tie(puntos, costo) = v[i];
    if (puntos == val || puntos == val - 1) {
      sw.insert(costo);
      if (i <= pos) cnt++;
    } else
      S.insert(costo);
  }
  while (cnt--) {
    val--;
    esfuerzo += *sw.begin();
    sw.erase(sw.begin());
  }
  for (auto x : sw) S.insert(x);
  while (val > 0) {
    esfuerzo += *S.begin();
    S.erase(S.begin());
    val--;
  }
  ans = min(ans, esfuerzo);
  val = get<0>(v[pos]) + 1;
  if (val <= n) {
    esfuerzo = 0LL;
    sw.clear();
    S.clear();
    cnt = 0;
    for (int i = 0; i < n; i++) {
      tie(puntos, costo) = v[i];
      if (puntos == val || puntos == val - 1) {
        sw.insert(costo);
        if (i <= pos) cnt++;
      } else
        S.insert(costo);
    }
    while (cnt--) {
      val--;
      esfuerzo += *sw.begin();
      sw.erase(sw.begin());
    }
    for (auto x : sw) S.insert(x);
    while (val > 0 && S.size() > 0) {
      esfuerzo += *S.begin();
      S.erase(S.begin());
      val--;
    }
    ans = min(ans, esfuerzo);
  }
  val = get<0>(v[pos]) + 2;
  if (val <= n) {
    esfuerzo = 0LL;
    S.clear();
    for (int i = n - 1; i >= 0; i--) {
      tie(puntos, costo) = v[i];
      S.insert(costo);
    }
    cnt = 0;
    while (cnt < val) {
      cnt++;
      esfuerzo += *S.begin();
      S.erase(S.begin());
    }
    ans = min(ans, esfuerzo);
  }
  cout << ans << endl;
  return 0;
}
