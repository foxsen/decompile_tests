#include <bits/stdc++.h>
using namespace std;
const int MAXN = 42;
const int INF = INT_MAX / 2;
const int MOD = 1e9 + 7;
struct suffix_automaton {
  struct node {
    int len, link;
    bool end;
    map<char, int> next;
  };
  vector<node> sa;
  int last;
  suffix_automaton() {}
  suffix_automaton(string s) {
    sa.reserve(s.size() * 2);
    last = add_node();
    sa[last].len = 0;
    sa[last].link = -1;
    for (int i = 0; i < s.size(); ++i) sa_append(s[i]);
    for (int cur = last; cur; cur = sa[cur].link) sa[cur].end = 1;
  }
  int add_node() {
    sa.push_back({});
    return sa.size() - 1;
  }
  void sa_append(char c) {
    int cur = add_node();
    sa[cur].len = sa[last].len + 1;
    int p = last;
    while (p != -1 && !sa[p].next[c]) {
      sa[p].next[c] = cur;
      p = sa[p].link;
    }
    if (p == -1)
      sa[cur].link = 0;
    else {
      int q = sa[p].next[c];
      if (sa[q].len == sa[p].len + 1)
        sa[cur].link = q;
      else {
        int clone = add_node();
        sa[clone] = sa[q];
        sa[clone].len = sa[p].len + 1;
        sa[q].link = sa[cur].link = clone;
        while (p != -1 && sa[p].next[c] == q) {
          sa[p].next[c] = clone;
          p = sa[p].link;
        }
      }
    }
    last = cur;
  }
  node &operator[](int i) { return sa[i]; }
};
suffix_automaton sa;
int move(char c, int node) {
  if (sa[node].next[c]) return sa[node].next[c];
  return 0;
}
string p;
int phi[MAXN];
void get_phi() {
  phi[0] = 0;
  for (int i = 1, j = 0; i < p.size(); ++i) {
    while (j > 0 && p[i] != p[j]) j = phi[j - 1];
    if (p[i] == p[j]) ++j;
    phi[i] = j;
  }
}
int process(char c, int j) {
  if (j == p.size()) j = phi[j - 1];
  while (j > 0 && c != p[j]) j = phi[j - 1];
  if (c == p[j]) ++j;
  return j;
}
int memo[MAXN][MAXN];
bool can(int len_pref, int len_suf) {
  int &r = memo[len_pref][len_suf];
  if (r != -1) return r;
  if (len_pref == 0 || len_suf == 0) return r = 0;
  r = 0;
  int n = p.size();
  string pref = p.substr(0, len_pref);
  string suf = p.substr(n - len_suf);
  for (int i = 0; i < pref.size(); i++) {
    string l = pref.substr(i);
    string R = suf.substr(0, n - l.size());
    if (l + R == p) return r = 1;
  }
  return r;
}
int n;
long long dp[MAXN][MAXN][2 * MAXN][MAXN][2][2];
bool seen[MAXN][MAXN][2 * MAXN][MAXN][2][2];
long long go(int i, int max_pref, int node_suf, int max_suf, int match,
             int fail) {
  if (i == n) {
    return match || can(max_pref, max_suf);
  }
  long long &r = dp[i][max_pref][node_suf][max_suf][match][fail];
  bool &se = seen[i][max_pref][node_suf][max_suf][match][fail];
  if (se == 0) {
    se = 1;
    r = 0;
    for (char c = '0'; c <= '1'; c++) {
      int j = process(c, max_pref);
      int next_node = move(c, node_suf);
      bool nfail = (next_node == 0);
      if (nfail || fail) {
        r += go(i + 1, j, 0, max_suf, (j == p.size() || match), true);
      } else {
        int max_suf_len = max_suf;
        if (sa[next_node].end) max_suf_len = i + 1;
        r += go(i + 1, j, next_node, max_suf_len, (j == p.size() || match),
                false);
      }
    }
  }
  return r;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (cin >> n >> p) {
    memset(memo, -1, sizeof memo);
    sa = suffix_automaton(p);
    get_phi();
    cout << go(0, 0, 0, 0, 0, 0) << '\n';
  }
  return 0;
}
