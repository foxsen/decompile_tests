#include <bits/stdc++.h>
using ll = long long;
using P = std::pair<ll, ll>;
constexpr ll INF = 1ll << 60;
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class S, class T>
std::ostream& operator<<(std::ostream& out, const std::pair<S, T>& a) {
  std::cout << '(' << a.first << ", " << a.second << ')';
  return out;
}
template <class T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& a) {
  std::cout << '[';
  for (ll i = (0); i < (a.size()); ++i) {
    std::cout << a[i];
    if (i != a.size() - 1) std::cout << ", ";
  }
  std::cout << ']';
  return out;
}
struct Node {
  ll nxt[10];
  ll p;
  char pch;
  ll link;
  ll go[10];
  bool term;
  Node() {
    memset(nxt, -1, sizeof(nxt));
    memset(go, -1, sizeof(go));
    link = p = -1;
    term = false;
  }
  ll& operator[](ll x) { return nxt[x]; }
};
std::vector<Node> trie;
void add_string(const std::string& s) {
  ll v = 0;
  for (auto ch : s) {
    ll c = ch - '1';
    if (trie[v][c] == -1) {
      trie.emplace_back(Node());
      trie[trie.size() - 1].p = v;
      trie[trie.size() - 1].pch = c;
      trie[v][c] = trie.size() - 1;
    }
    v = trie[v][c];
  }
  trie[v].term = true;
  return;
}
ll go(ll v, ll c);
ll get_link(ll v) {
  if (trie[v].link == -1) {
    if (v == 0 || trie[v].p == 0)
      trie[v].link = 0;
    else
      trie[v].link = go(get_link(trie[v].p), trie[v].pch);
  }
  return trie[v].link;
}
ll go(ll v, ll c) {
  if (trie[v].go[c] == -1) {
    if (trie[v][c] != -1)
      trie[v].go[c] = trie[v][c];
    else
      trie[v].go[c] = (!v ? 0 : go(get_link(v), c));
  }
  return trie[v].go[c];
}
std::string s;
ll x;
std::string t;
void generate(ll i, ll sum) {
  if (sum == x) {
    bool fl = true;
    for (ll l = (0); l < (t.size()); ++l) {
      ll cur = 0;
      for (ll r = (l); r < (t.size()); ++r) {
        cur += t[r] - '0';
        if (x % cur == 0 && cur != x) fl = false;
      }
    }
    if (fl) {
      add_string(t);
    }
    return;
  }
  for (ll j = (1); j < (std::min(x - sum, 9ll) + 1); ++j) {
    t += '0' + j;
    generate(i + 1, sum + j);
    t.pop_back();
  }
}
int main() {
  std::cin >> s >> x;
  trie.emplace_back(Node());
  generate(0, 0);
  std::vector<std::vector<ll>> dp(s.size() + 1,
                                  std::vector<ll>(trie.size(), INF));
  dp[0][0] = 0;
  for (ll i = (0); i < (s.size()); ++i)
    for (ll j = (0); j < (trie.size()); ++j)
      if (dp[i][j] != INF) {
        chmin(dp[i + 1][j], dp[i][j] + 1);
        ll nxt = go(j, s[i] - '1');
        if (!trie[nxt].term) chmin(dp[i + 1][nxt], dp[i][j]);
      }
  std::cout << *min_element((dp[s.size()]).begin(), (dp[s.size()]).end())
            << '\n';
  return 0;
}
