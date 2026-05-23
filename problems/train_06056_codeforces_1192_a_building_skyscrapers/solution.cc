#include <bits/stdc++.h>
using namespace std;
void vin(std::vector<int> &a) {
  for (auto &x : a) cin >> x;
}
void vout(std::vector<int> &a) {
  for (auto x : a) cout << x << " ";
  cout << endl;
}
std::vector<set<int> > pqp, pqb;
struct UF {
  std::vector<int> p;
  UF(int n) {
    p.resize(n);
    pqb.resize(n);
    pqp.resize(n);
    iota(p.begin(), p.end(), 0);
  }
  int root(int a) {
    if (a == p[a]) return a;
    return (p[a] = root(p[a]));
  }
  bool find(int a, int b) { return root(a) == root(b); }
  void connect(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return;
    if (pqp[a].size() < pqp[b].size()) swap(a, b);
    p[b] = a;
    for (auto x : pqp[b]) pqp[a].insert(x);
    pqp[b].clear();
  }
};
std::vector<pair<long long, long long> > nei{
    make_pair(-1, 0), make_pair(-1, 1), make_pair(0, 1),  make_pair(1, 1),
    make_pair(1, 0),  make_pair(1, -1), make_pair(0, -1), make_pair(-1, -1)};
std::vector<pair<pair<long long, long long>, pair<int, int> > > s;
int indexb(long long x, long long y) {
  auto it = lower_bound(s.begin(), s.end(),
                        make_pair(make_pair(x, y), make_pair(-1, -1)));
  if (it == s.end()) return -1;
  if (it->first == make_pair(x, y) && it->second.second) return it - s.begin();
  return -1;
}
int indexp(long long x, long long y) {
  auto it = lower_bound(s.begin(), s.end(),
                        make_pair(make_pair(x, y), make_pair(-1, -1)));
  if (it == s.end()) return 0;
  if (it->first == make_pair(x, y) && it->second.second) return -1;
  return it - s.begin();
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, tin;
  cin >> n >> tin;
  s.resize(n);
  long long xmi = 1000000000, xma = -1000000000, ymi = 1000000000,
            yma = -1000000000;
  for (int i = 0; i < n; i++) {
    cin >> s[i].first.first >> s[i].first.second;
    s[i].second.first = i;
    s[i].second.second = 1;
    xmi = min(xmi, s[i].first.first);
    xma = max(xma, s[i].first.first);
    ymi = min(ymi, s[i].first.second);
    yma = max(yma, s[i].first.second);
  }
  if (xma - xmi > n || yma - ymi > n) {
    cout << "NO\n";
    return 0;
  }
  sort(s.begin(), s.end());
  UF buf(n);
  for (int i = 0; i < n; i++) {
    int j = indexb(s[i].first.first + 1, s[i].first.second);
    if (j != -1) buf.connect(i, j);
    j = indexb(s[i].first.first, s[i].first.second + 1);
    if (j != -1) buf.connect(i, j);
    j = indexb(s[i].first.first + 1, s[i].first.second + 1);
    if (j != -1) buf.connect(i, j);
    j = indexb(s[i].first.first + 1, s[i].first.second - 1);
    if (j != -1) buf.connect(i, j);
  }
  for (int i = 1; i < n; i++)
    if (!buf.find(0, i)) {
      cout << "NO\n";
      cerr << "bufno\n";
      return 0;
    }
  cerr << "bufsi\n";
  UF puf(n);
  for (int i = 0; i < n; i++) {
    if (i > 0 && s[i].first.first == s[i - 1].first.first) {
      if (s[i].first.first == xmi &&
          s[i].first.second > s[i - 1].first.second + 1)
        puf.connect(i, 0);
      for (int j = s[i - 1].first.second + 1; j < s[i].first.second; j++) {
        int k = indexp(s[i - 1].first.first + 1, j);
        if (k == -1) continue;
        puf.connect(i, k);
        if (s[k].first.second < j) break;
        j = s[k].first.second;
      }
    } else {
      puf.connect(i, 0);
      for (int j = s[(i + n - 1) % n].first.second + 1; j <= yma; j++) {
        int k = indexp(s[(i + n - 1) % n].first.first + 1, j);
        if (k == -1) continue;
        puf.connect(i, k);
        if (s[k].first.second < j) break;
        j = s[k].first.second;
      }
      for (int j = ymi; j < s[i].first.second; j++) {
        int k = indexp(s[i].first.first + 1, j);
        if (k == -1) continue;
        puf.connect(i, k);
        if (s[k].first.second < j) break;
        j = s[k].first.second;
      }
    }
  }
  std::vector<int> ord(n, -1);
  std::vector<int> is(n);
  priority_queue<int> pqm;
  for (int i = 0; i < n; i++) {
    is[s[i].second.first] = i;
    pqm.push(i);
  }
  int o = n - 1;
  int ccfo = 0;
  while (!pqm.empty()) {
    int i = pqm.top();
    pqm.pop();
    ccfo++;
    auto b = s[is[i]];
    int ip = indexb(b.first.first, b.first.second);
    if (ip == -1) continue;
    int co = 0;
    for (int j = 0; j < 8; j += 2) {
      int p =
          indexp(b.first.first + nei[j].first, b.first.second + nei[j].second);
      if (p != -1 && puf.find(p, 0))
        co = 1;
      else if (p != -1)
        pqp[puf.root(p)].emplace(ip);
      else
        pqb[indexb(b.first.first + nei[j].first,
                   b.first.second + nei[j].second)]
            .emplace(ip);
    }
    if (co) {
      std::vector<int> bw;
      for (int j = 0; j < 8; j++) {
        int x = b.first.first + nei[j].first,
            y = b.first.second + nei[j].second;
        int a = indexp(x, y);
        if (a == -1) {
          a = indexb(x, y);
          pqb[a].emplace(ip);
          continue;
        }
        x = b.first.first + nei[(j + 1) % 8].first,
        y = b.first.second + nei[(j + 1) % 8].second;
        if (indexb(x, y) == -1) continue;
        if (j % 2) {
          x = b.first.first + nei[(j + 7) % 8].first,
          y = b.first.second + nei[(j + 7) % 8].second;
          if (indexp(x, y) == -1) continue;
        }
        bw.push_back(a);
      }
      for (int i = 0; i < (int)bw.size(); i++)
        for (int j = i + 1; j < (int)bw.size(); j++)
          if (puf.find(bw[i], bw[j])) {
            co = 0;
            break;
          }
    }
    int ch = 0;
    if (co) {
      s[is[i]].second.second = 0;
      if (indexb(b.first.first - 1, b.first.second) == -1 &&
          !puf.find(indexp(b.first.first - 1, b.first.second), ip)) {
        ch++;
        puf.connect(indexp(b.first.first - 1, b.first.second), ip);
      }
      if (indexb(b.first.first + 1, b.first.second) == -1 &&
          !puf.find(indexp(b.first.first + 1, b.first.second), ip)) {
        ch++;
        puf.connect(indexp(b.first.first + 1, b.first.second), ip);
      }
      if (indexb(b.first.first, b.first.second - 1) == -1 &&
          !puf.find(indexp(b.first.first, b.first.second - 1), ip)) {
        ch++;
        puf.connect(indexp(b.first.first, b.first.second - 1), ip);
      }
      if (indexb(b.first.first, b.first.second + 1) == -1 &&
          !puf.find(indexp(b.first.first, b.first.second + 1), ip)) {
        ch++;
        puf.connect(indexp(b.first.first, b.first.second + 1), ip);
      }
      ord[i] = o--;
      if (i == 69) cerr << "helloworld\n";
      for (auto x : pqp[puf.root(ip)]) pqm.emplace(s[x].second.first);
      pqp[puf.root(ip)].clear();
      for (auto x : pqb[ip]) pqm.emplace(s[x].second.first);
      pqb[ip].clear();
    }
  }
  cerr << ccfo << "\n";
  assert(o == -1);
  cout << "YES\n";
  std::vector<int> out(n);
  for (int i = 0; i < n; i++) {
    assert(ord[i] != -1);
    out[ord[i]] = i + 1;
  }
  vout(out);
}
