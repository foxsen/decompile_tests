#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)9e18 + 7LL;
struct event {
  long long sta, dur, per;
  event() {
    sta = 0;
    dur = 0;
    per = 0;
  }
  event(long long s, long long d, long long p) {
    sta = s;
    dur = d;
    per = p;
  }
  long long value(void) const {
    assert(INF / per >= dur);
    return (dur * per);
  }
  pair<long long, long long> expand(void) const {
    long long first = sta;
    long long second = sta + value() - 1;
    return (pair<long long, long long>(first, second));
  }
  bool operator<(const event &x) const { return (sta < x.sta); }
};
int prime[1000100];
long long res[1000100];
vector<event> alle[1000100];
long long k;
void eratosthene(void) {
  for (int i = 0; i < (2); i = i + 1) prime[i] = -1;
  for (int i = (2); i <= (1000100 - 1); i = i + 1)
    if (prime[i] == 0)
      for (int j = 2 * i; j < 1000100; j = j + i)
        if (prime[j] == 0) prime[j] = i;
}
void init(void) {
  int m;
  cin >> m;
  for (int i = 0; i < (m); i = i + 1) {
    int p;
    long long t;
    cin >> p >> t;
    alle[p].push_back(event(0, 1, t));
  }
  cin >> k;
}
void getdiv(int p, vector<int> &v) {
  v.clear();
  while (p > 1) {
    if (prime[p] == 0) {
      v.push_back(p);
      return;
    }
    v.push_back(prime[p]);
    int t = prime[p];
    while (p % t == 0) p = p / t;
  }
}
int multi(long long x, int p) {
  int ret = 0;
  while (x % p == 0) {
    ret++;
    x = x / p;
  }
  return (ret);
}
void processprime(int p) {
  if (alle[p].empty()) return;
  sort(alle[p].begin(), alle[p].end());
  long long prev = 0;
  long long rem = 0;
  vector<int> div;
  getdiv(p - 1, div);
  pair<long long, long long> cur = pair<long long, long long>(-1, -1);
  for (__typeof((alle[p]).begin()) it = (alle[p]).begin();
       it != (alle[p]).end(); it++) {
    pair<long long, long long> tmp = it->expand();
    if (tmp.first >= k) {
      res[p] += tmp.second - tmp.first + 1;
      continue;
    }
    if (cur.first < 0) {
      cur = tmp;
      if (cur.second >= k) {
        res[p] += cur.second - k + 1;
        cur.second = k - 1;
      }
      continue;
    }
    if (tmp.first > cur.second) {
      for (__typeof((div).begin()) it = (div).begin(); it != (div).end(); it++)
        alle[*it].push_back(event(cur.first + 1, cur.second - cur.first + 1,
                                  multi(p - 1, *it)));
      cur = tmp;
    } else
      cur.second += tmp.second - tmp.first + 1;
    if (cur.second >= k) {
      res[p] += cur.second - k + 1;
      cur.second = k - 1;
    }
  }
  if (cur.first >= 0)
    for (__typeof((div).begin()) it = (div).begin(); it != (div).end(); it++)
      alle[*it].push_back(
          event(cur.first + 1, cur.second - cur.first + 1, multi(p - 1, *it)));
}
void process(void) {
  for (int i = (1000100 - 1); i >= (2); i = i - 1)
    if (prime[i] == 0) processprime(i);
  int cnt = 0;
  for (int i = (2); i <= (1000100 - 1); i = i + 1)
    if (prime[i] == 0 && res[i] > 0) cnt++;
  cout << cnt << "\n";
  for (int i = (2); i <= (1000100 - 1); i = i + 1)
    if (prime[i] == 0 && res[i] > 0) cout << i << " " << res[i] << "\n";
}
int main(void) {
  ios::sync_with_stdio(false);
  eratosthene();
  init();
  process();
  return 0;
}
