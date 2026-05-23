#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vll = vector<ll>;
using pdd = pair<double, double>;
using vpdd = vector<pdd>;
template <typename T>
using uset = unordered_set<T>;
template <typename T>
using umultiset = unordered_multiset<T>;
template <typename K, typename V>
using umap = unordered_map<K, V>;
template <typename K, typename V>
using umultimap = unordered_multimap<K, V>;
const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dc[] = {0, 1, 0, -1, 1, -1, -1, 1};
const double eps = 1e-9;
const int INF = 0x7FFFFFFF;
const ll INFLL = 0x7FFFFFFFFFFFFFFFLL;
const double pi = acos(-1);
template <typename T>
T take(queue<T>& O) {
  T tmp = O.front();
  O.pop();
  return tmp;
}
template <typename T>
T take(stack<T>& O) {
  T tmp = O.top();
  O.pop();
  return tmp;
}
template <typename T>
T take(priority_queue<T>& O) {
  T tmp = O.top();
  O.pop();
  return tmp;
}
template <typename T>
inline bool inRange(const T& z, const T& a, const T& b) {
  return a <= z && z <= b;
}
void OPEN(const string& in = "input.txt", const string& out = "output.txt") {
  freopen(in.c_str(), "r", stdin);
  freopen(out.c_str(), "w", stdout);
  return;
}
priority_queue<ii> PQ[1000005];
int caw[1000005];
ll ans = INFLL;
int n, m, k;
struct Data {
  int d, f, t, c, idx;
  friend istream& operator>>(istream& is, Data& d) {
    is >> d.d >> d.f >> d.t >> d.c;
    return is;
  }
};
Data data[1000005];
vector<int> dvec[1000005];
int adacnt = 0;
bitset<1000005> ada;
int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int(i) = (0), _t = (m); i < (_t); ++(i)) {
    cin >> data[i];
    dvec[data[i].d].push_back(i);
    data[i].idx = i;
  }
  for (int(z) = (1000000), _t = (k + 1); z >= (_t); --(z)) {
    for (const int& id : dvec[z]) {
      const Data& d = data[id];
      if (d.f == 0) {
        PQ[d.t].push(make_pair(-d.c, d.idx));
      }
    }
  }
  ll tmpAns = 0LL;
  for (int(i) = (1), _t = (n); i <= (_t); ++(i)) {
    if (PQ[i].empty()) {
      cout << "-1\n";
      return 0;
    }
    tmpAns += -PQ[i].top().first;
  }
  int ed = k + 1;
  for (int(st) = (1), _t = (1000000 - k + 1); st <= (_t); ++(st)) {
    for (const int& id : dvec[st]) {
      const Data& d = data[id];
      if (d.t == 0) {
        tmpAns -= caw[d.f];
        if (!ada.test(d.f)) {
          ++adacnt;
          caw[d.f] = INF;
        }
        ada.set(d.f, 1);
        caw[d.f] = min(caw[d.f], d.c);
        tmpAns += caw[d.f];
      }
    }
    bool abis = 0;
    for (const int& id : dvec[ed]) {
      const Data& d = data[id];
      if (d.f == 0) {
        auto& PQ = ::PQ[d.t];
        tmpAns -= -PQ.top().first;
        while (!PQ.empty() && data[PQ.top().second].d <= ed) {
          PQ.pop();
        }
        if (PQ.empty()) {
          abis = 1;
          break;
        }
        tmpAns += -PQ.top().first;
      }
    }
    ++ed;
    if (abis) break;
    if (adacnt == n) {
      ans = min(ans, tmpAns);
    }
  }
  if (ans == INFLL) {
    cout << -1 << "\n";
    return 0;
  }
  cout << ans << "\n";
}
