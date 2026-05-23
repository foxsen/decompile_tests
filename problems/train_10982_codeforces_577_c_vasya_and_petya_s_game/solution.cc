#include <bits/stdc++.h>
using namespace std;
void seive(int n, set<int> &s) {
  bool primes[n + 1];
  memset(primes, true, sizeof(primes));
  for (int p = 2; p * p <= n; p++) {
    if (primes[p]) {
      for (int i = p * p; i <= n; i += p) primes[i] = false;
    }
  }
  for (int i = 2; i <= n; i++)
    if (primes[i]) s.insert(i);
}
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  set<int> s;
  vector<int> out;
  seive(n, s);
  for (auto i = s.begin(); i != s.end(); i++) {
    int p = *i;
    while (p <= n) {
      out.push_back(p);
      p = p * (*i);
    }
  }
  cout << out.size() << endl;
  for (int x : out) cout << x << " ";
  return 0;
}
