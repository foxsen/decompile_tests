/* template.cpp {{{ */
#include <bits/stdc++.h>
using namespace std;
#define get_macro(a, b, c, d, name, ...) name
#define rep(...) get_macro(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep(...) get_macro(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)
#define rep1(n) rep2(i_, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) rep4(i, a, b, 1)
#define rep4(i, a, b, s) for (ll i = (a); i < (ll)(b); i += (ll)(s))
#define rrep1(n) rrep2(i_, n)
#define rrep2(i, n) rrep3(i, 0, n)
#define rrep3(i, a, b) rrep4(i, a, b, 1)
#define rrep4(i, a, b, s) for (ll i = (ll)(b) - 1; i >= (ll)(a); i -= (ll)(s))
#define each(x, c) for (auto &&x : c)
#define fs first
#define sc second
#define all(c) begin(c), end(c)
using ui = unsigned;
using ll = long long;
using ul = unsigned long long;
using ld = long double;
const int inf = 1e9 + 10;
const ll inf_ll = 1e18 + 10;
const ll mod = 1e9 + 7;
const ll mod9 = 1e9 + 9;
const int dx[]{-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[]{0, -1, 0, 1, -1, -1, 1, 1};
template<class T, class U> void chmin(T &x, const U &y){ x = min<T>(x, y); }
template<class T, class U> void chmax(T &x, const U &y){ x = max<T>(x, y); }
struct prepare_ { prepare_(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(12); } } prepare__;
/* }}} */

struct Node {
  int x;
  Node *l, *r;
};

int nm(string::iterator &it){
  int x = 0;
  while (isdigit(*it)){
    x *= 10;
    x += *it - '0';
    ++it;
  }
  return x;
}

Node *dfs(string::iterator &it){
  if (*it != '('){
    ++it;
    return nullptr;
  }
  ++it;
  auto l = dfs(it);
  ++it;
  int x = nm(it);
  ++it, ++it;
  auto r = dfs(it);
  ++it;
  return new Node{x, l, r};
}

string dfs2(Node *v, Node *u){
  if (v == nullptr || u == nullptr) return "";
  auto l = dfs2(v->l, u->l);
  auto x = to_string(v->x + u->x);
  auto r = dfs2(v->r, u->r);
  return "(" + l + ")[" + x + "](" + r + ")";
}

int main(){
  string s, t;
  cin >> s >> t;
  auto it1 = s.begin(), it2 = t.begin();
  auto a = dfs(it1), b = dfs(it2);
  cout << dfs2(a, b) << endl;
}