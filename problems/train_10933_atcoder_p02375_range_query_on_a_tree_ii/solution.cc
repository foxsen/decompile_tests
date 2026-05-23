// includes
#include <bits/stdc++.h>
using namespace std;

// macros
#define pb emplace_back
#define mk make_pair
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for(int i=((int)(n)-1);i>=0;i--)
#define irep(itr, st) for(auto itr = (st).begin(); itr != (st).end(); ++itr)
#define irrep(itr, st) for(auto itr = (st).rbegin(); itr != (st).rend(); ++itr)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define bit(n) (1LL<<(n))
// functions
template <class T>bool chmax(T &a, const T &b){if(a < b){a = b; return 1;} return 0;}
template <class T>bool chmin(T &a, const T &b){if(a > b){a = b; return 1;} return 0;}
template <typename T> istream &operator>>(istream &is, vector<T> &vec){for(auto &v: vec)is >> v; return is;}
template <typename T> ostream &operator<<(ostream &os, const vector<T>& vec){for(int i = 0; i < vec.size(); i++){ os << vec[i]; if(i + 1 != vec.size())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const set<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const unordered_set<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const multiset<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p){os << p.first << " " << p.second; return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &mp){for(auto itr = mp.begin(); itr != mp.end(); ++itr){ os << itr->first << ":" << itr->second; auto titr = itr; if(++titr != mp.end())os << " "; } return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const unordered_map<T1, T2> &mp){for(auto itr = mp.begin(); itr != mp.end(); ++itr){ os << itr->first << ":" << itr->second; auto titr = itr; if(++titr != mp.end())os << " "; } return os;}
//  types
using ll = long long int;
using P = pair<int, int>;
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;
const int mod = 1000000007;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
// io
struct fast_io{
  fast_io(){ios_base::sync_with_stdio(false); cin.tie(0); cout << fixed << setprecision(20);}
} fast_io_;

template <typename T>
struct HeavyLightDecomposition{
  struct edge{
    int to;
    T w;
    edge(int to, T w): to(to), w(w){}
  };
  int n, cid;
  vector<vector<edge>> edges;
  vector<int> par, chain, depth, siz, pos_seg, head;
  vector<T> parw;
  HeavyLightDecomposition(){}
  explicit HeavyLightDecomposition(int n): n(n){
    edges.resize(n);
    par.resize(n, -1);
    chain.resize(n, -1);
    depth.resize(n, -1);
    siz.resize(n, 1);
    pos_seg.resize(n, -1);
    head.resize(n, -1);
    parw.resize(n);
  }
  void adde(int from, int to, T w){
    edges[from].emplace_back(to, w);
  }
  void build(int r = 0){
    par.assign(n, -1);
    chain.assign(n, -1);
    depth.assign(n, -1);
    siz.assign(n, -1);
    pos_seg.assign(n, -1);

    dfs(r);

    hld(r);
  }
  void dfs(int r = 0){
    par[r] = r;
    depth[r] = 0;
    deque<int> dq;
    dq.push_back(r);

    int l = 0;
    while(l < (int)dq.size()){
      int i = dq[l];
      siz[i] = 1;
      for(auto &e: edges[i]){
        if(par[e.to] != -1)continue;
        par[e.to] = i;
        parw[e.to] = e.w;
        depth[e.to] = depth[i] + 1;
        dq.push_back(e.to);
      }
      l++;
    }
    while(!dq.empty()){
      int i = dq.back(); dq.pop_back();
      if(par[i] != i){
        siz[par[i]] += siz[i];
      }
    }
  }
  void hld(int r = 0){
    cid = 0;
    chain[r] = cid;
    pos_seg[r] = 0;
    head[r] = r;

    stack<int> st;
    st.push(r);

    while(!st.empty()){
      int i = st.top(); st.pop();
      int max_siz = 0;
      int idx = -1;
      for(auto &e: edges[i]){
        if(par[e.to] != i)continue;
        if(max_siz < siz[e.to]){
          max_siz = siz[e.to];
          idx = e.to;
        }
      }
      if(idx == -1)continue;
      for(auto &e: edges[i]){
        if(par[e.to] != i)continue;
        if(idx == e.to){
          chain[e.to] = chain[i];
          pos_seg[e.to] = pos_seg[i] + 1;
          head[e.to] = head[i];
          st.push(e.to);
        }else{
          chain[e.to] = ++cid;
          pos_seg[e.to] = 0;
          head[e.to] = e.to;
          st.push(e.to);
        }
      }
    }
  }
  int lca(int u, int v){
    while(true){
      if(chain[u] == chain[v]){
        if(depth[u] < depth[v])return u;
        else return v;
      }
      if(depth[head[u]] > depth[head[v]])swap(u, v);
      v = par[head[v]];
    }
  }
};

template<typename T, typename E>
struct LazySegmentTree_ {
  function<T(T, T)> f; // aggregation
  function<E(E, E)> h; // update lazy element
  function<T(T, E, int)> p; // update element with lazy element
  int n;
  T def;
  E l_def;
  vector<T> vec;
  vector<E> lazy;
  LazySegmentTree_(){}
  LazySegmentTree_(int n_, function<T(T, T)> f, T def,
                   function<E(E, E)> h, E l_def, function<T(T, E, int)> p,
                   vector<T> v=vector<T>()): f(f), def(def), h(h), l_def(l_def), p(p){

    // initialize vector
    n = 1;
    while(n < n_){
      n *= 2;
    }
    vec = vector<T>(2*n-1, def);
    lazy = vector<E>(2*n-1, l_def);

    // initialize segment tree
    for(int i = 0; i < v.size(); i++){
      vec[i + n - 1] = v[i];
    }
    for(int i = n - 2; i >= 0; i--){
      vec[i] = f(vec[2*i+1], vec[2*i+2]);
    }
  }
  void eval(int k, int len){
    if(lazy[k] != l_def){
      if(k < n - 1){
        lazy[2*k+1] = h(lazy[2*k+1], lazy[k]);
        lazy[2*k+2] = h(lazy[2*k+2], lazy[k]);
      }
      vec[k] = p(vec[k], lazy[k], len);
      lazy[k] = l_def;
    }
  }
  E update(int a, int b, const E &val, int k, int l, int r){
    eval(k, r - l);
    if(r <= a || b <= l){
      return vec[k];
    }else if(a <= l && r <= b){
      lazy[k] = h(lazy[k], val);
      eval(k, r - l);
      return vec[k];
    }else{
      return vec[k] = f(update(a, b, val, 2*k+1, l, (l+r)/2),
                        update(a, b, val, 2*k+2, (l+r)/2, r));
    }
  }
  E update(int a, int b, E val){
    return update(a, b, val, 0, 0, n);
  }
  // [l, r) -> [a, b) (at k)
  T query(int a, int b, int k, int l, int r){
    eval(k, r - l);
    if(r <= a || b <= l)return def;
    if(a <= l && r <= b)return vec[k];
    T ld = query(a, b, 2*k+1, l, (l+r)/2);
    T rd = query(a, b, 2*k+2, (l+r)/2, r);
    return f(ld, rd);
  }
  T query(int a, int b){
    return query(a, b, 0, 0, n);
  }
};

template<typename T, typename E>
using LazySegmentTree = struct LazySegmentTree_<T, E>;
using LazySegmentTreeI = LazySegmentTree<int, int>;
using LazySegmentTreeL = LazySegmentTree<long long, long long>;


int main(int argc, char const* argv[])
{
  int n; cin >> n;
  HeavyLightDecomposition<ll> hld(n);
  rep(i, n){
    int k; cin >> k;
    rep(j, k){
      int u; cin >> u;
      hld.adde(i, u, 0);
    }
  }
  hld.build();

  vector<int> cnt(n, 0), acc(n, 0);
  rep(i, n)cnt[hld.head[i]]++;
  rep(i, n){
    acc[i] = (i > 0 ? acc[i-1] + cnt[i-1]: 0);
  }

  LazySegmentTreeL seg = LazySegmentTreeL(n, [](ll a, ll b){return a + b;},
                                          0, [](ll a, ll b){return a + b;},
                                          0, [](ll a, ll b, int c){return a + b * c;},
                                          vector<ll>(n, 0));

  int q; cin >> q;
  rep(i_, q){
    int c; cin >> c;
    if(c == 0){
      int v;
      ll w;
      cin >> v >> w;
      while(true){
        if(hld.chain[v] == hld.chain[0]){
          seg.update(0, hld.pos_seg[v], w);
          break;
        }
        seg.update(acc[hld.head[v]], acc[hld.head[v]] + hld.pos_seg[v], w);
        hld.parw[hld.head[v]] += w;
        v = hld.par[hld.head[v]];
      }
    }else{
      int u; cin >> u;
      ll res = 0;
      while(true){
        if(hld.chain[u] == hld.chain[0]){
          res += seg.query(0, hld.pos_seg[u]);
          break;
        }
        res += seg.query(acc[hld.head[u]], acc[hld.head[u]] + hld.pos_seg[u]);
        res += hld.parw[hld.head[u]];
        u = hld.par[hld.head[u]];
      }
      cout << res << endl;
    }
  }
  return 0;
}

