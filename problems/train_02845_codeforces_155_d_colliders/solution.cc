#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
int main() {
  const int MAX_P = 100000 + 1;
  bool p[MAX_P];
  for (int i = 0; i < MAX_P; ++i) p[i] = true;
  p[0] = p[1] = false;
  for (int i = 2; i * i <= MAX_P; ++i) {
    if (p[i]) {
      for (int j = i + i; j < MAX_P; j += i) p[j] = false;
    }
  }
  vector<int> prime;
  for (int i = 0; i < MAX_P; ++i) {
    if (p[i]) prime.push_back(i);
  }
  vector<vector<int> > factor(MAX_P);
  for (int i = 2; i < MAX_P; ++i) {
    int n = i;
    for (unsigned int j = 0; j < prime.size() && prime[j] <= n; ++j) {
      if (n % prime[j] == 0) {
        factor[i].push_back(prime[j]);
        while (n % prime[j] == 0) n /= prime[j];
      }
    }
  }
  string s;
  int n, m, index;
  while (cin >> n >> m) {
    vector<int> active(n + 1, 0), relative(n + 1, 0);
    for (int i = 0; i < m; ++i) {
      cin >> s >> index;
      if (s == "+") {
        if (active[index]) {
          puts("Already on");
        } else {
          bool rp = true;
          for (unsigned int j = 0; j < factor[index].size(); ++j) {
            if (relative[factor[index][j]] != 0) {
              rp = false;
              printf("Conflict with %d\n", relative[factor[index][j]]);
              break;
            }
          }
          if (rp) {
            active[index] = 1;
            for (unsigned int j = 0; j < factor[index].size(); ++j)
              relative[factor[index][j]] = index;
            puts("Success");
          }
        }
      } else {
        if (active[index]) {
          active[index] = 0;
          for (unsigned int j = 0; j < factor[index].size(); ++j)
            relative[factor[index][j]] = 0;
          puts("Success");
        } else {
          puts("Already off");
        }
      }
    }
  }
  return 0;
}
