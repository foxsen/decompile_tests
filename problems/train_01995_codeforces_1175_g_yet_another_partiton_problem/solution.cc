#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct dreapta {
  ll a, b;
  ll operator()(ll x) { return a * x + b; }
};
bool useless(dreapta a, dreapta b, dreapta c) {
  assert(a.a >= b.a && b.a >= c.a);
  return (double)(b.b - a.b) / (a.a - b.a) > (double)(c.b - b.b) / (b.a - c.a);
}
class merging_batch {
  deque<dreapta> buf;

 public:
  merging_batch() {}
  ll query(ll x) {
    ll i = 0;
    for (ll step = 1 << 23; step; step /= 2)
      if (i + step < buf.size() && buf[i + step](x) <= buf[i + step - 1](x))
        i += step;
    assert(i == buf.size() - 1 || buf[i](x) <= buf[i + 1](x));
    return buf[i](x);
  }
  void add_right(dreapta x) {
    while (buf.size() > 1 && useless(buf.rbegin()[1], buf.back(), x))
      buf.pop_back();
    buf.push_back(x);
  }
  void add_left(dreapta x) {
    while (buf.size() > 1 && useless(x, buf[0], buf[1])) buf.pop_front();
    buf.push_front(x);
  }
  void swap_with(merging_batch& rhs) { swap(buf, rhs.buf); }
  void merge_with(merging_batch& rhs) {
    if (buf.size() < rhs.buf.size()) {
      for (auto it = buf.rbegin(); it != buf.rend(); ++it) rhs.add_left(*it);
      swap(buf, rhs.buf);
    } else
      for (auto x : rhs.buf) add_right(x);
  }
};
class undo_batch {
  ll top = 0;
  vector<dreapta> st = vector<dreapta>(
      1000000 + 10,
      dreapta{1000ll * 1000 * 1000, 1000ll * 1000 * 1000 * 1000 * 1000});
  struct modification {
    ll old_top, old_pos;
    dreapta d;
  };
  vector<modification> undo_st;

 public:
  undo_batch() { top = 1; }
  void clear() { top = 1; }
  void print() {
    for (int i = 1; i < top; ++i) {
      cerr << "(" << st[i].a << "," << st[i].b << ") ";
    }
    cerr << endl;
  }
  ll query(ll x) {
    ll i = 0;
    for (ll step = 1 << 23; step; step /= 2)
      if (i + step < top && st[i + step](x) <= st[i + step - 1](x)) i += step;
    assert(i == top - 1 || st[i](x) <= st[i + 1](x));
    return st[i](x);
  }
  void undo() {
    assert(!undo_st.empty());
    top = undo_st.back().old_top;
    st[undo_st.back().old_pos] = undo_st.back().d;
    undo_st.pop_back();
  }
  void add_right(dreapta d) {
    undo_st.push_back(modification{top, 0, 0});
    ll ret = 0;
    for (ll step = 1 << 23; step; step /= 2)
      if (ret + step < top && (!useless(st[ret + step - 1], st[ret + step], d)))
        ret += step;
    top = ret + 2;
    undo_st.back().old_pos = ret + 1;
    undo_st.back().d = st[ret + 1];
    st[ret + 1] = d;
  }
};
void produce_state(const ll n, const vector<ll>& d, const vector<ll>& v,
                   vector<ll>& ret) {
  static vector<ll> posz;
  static vector<merging_batch> mb;
  static undo_batch ub;
  posz.clear();
  mb.clear();
  ub.clear();
  for (ll i = 0; i < n; ++i) {
    merging_batch x;
    x.add_right(dreapta{-i + 1, d[i]});
    while (!posz.empty() && v[posz.back()] <= v[i]) {
      mb.back().merge_with(x);
      x.swap_with(mb.back());
      mb.pop_back();
      posz.pop_back();
      ub.undo();
    }
    posz.push_back(i);
    mb.push_back(move(x));
    ub.add_right(dreapta{v[i], mb.back().query(v[i])});
    ret[i + 1] = ub.query(i);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, k;
  cin >> n >> k;
  vector<ll> v(n);
  for (auto& x : v) cin >> x;
  vector<ll> state(n + 1, (ll)1e9 * (ll)1e9), tmp(n + 1, 0);
  state[0] = 0;
  tmp[0] = 0;
  for (ll i = 0; i < k; ++i) {
    produce_state(n, state, v, tmp);
    swap(state, tmp);
  }
  cout << state.back() << endl;
  return 0;
}
