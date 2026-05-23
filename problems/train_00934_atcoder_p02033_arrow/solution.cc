#include <bits/stdc++.h>
  
using namespace std;
  
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define repr(i, n) REPR(i, n, 0)
#define REPR(i, s, e) for(int i=(int)(s-1); i>=(int)(e); i--)
#define pb push_back
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()
#define fi first
#define se second
  
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const int INF = 1e9;
const ll MOD = 1e9 + 7;
double EPS = 1e-8;

#define DEBUG_MODE
#ifdef DEBUG_MODE
#define dump(x) cout << #x << " : " << x << endl
#define LINE cout << "line : " << __LINE__ << endl
#define dumpV(v) cout << #v << " : ["; for(auto& t : v) cout << t << ", "; cout<<"]" << endl
#define STOP assert(false)
#else
#define dump(x) ;
#define LINE     ;
#define dumpV(v);
#define STOP     ;
#endif
#define mp make_pair

namespace std{
  template<class S,class T>
  ostream &operator <<(ostream& out,const pair<S,T>& a){
    out<<'('<<a.fi<<", "<<a.se<<')';
    return out;
  }
}

using ull = unsigned long long;


constexpr ll initVal = 0LL;     //TODO: fix type and value
constexpr ll initLazy = 0LL;    //TODO: fix type and value
template <typename T>
struct Node {
    T val;
    T lazy;
    ull l, r;
    Node<T>* l_node = nullptr;
    Node<T>* r_node = nullptr;
    Node(ull l, ull r, const T& val = initVal) : l(l), r(r), val(val), lazy(initLazy) {}
    T getVal() {
        return val + lazy * (r - l); //TODO: fix
    }
    T f1(const T& a, const T& b) {
        return a+b;               //TODO: fix
    }
    T f2(const T& a, const T& b) {
        return a+b;                       //TODO: fix
    }
    void push() {
        if(r - l > 1) {
            auto m = (l+r)/2;
            {
                if(l_node == nullptr) l_node = new Node(l, m);
                if(lazy != initLazy) l_node->lazy = f2(l_node->lazy, this->lazy);
            }
            {
                if(r_node == nullptr) r_node = new Node(m, r);
                if(lazy != initLazy) r_node->lazy = f2(r_node->lazy, this->lazy); 
            }
        }
        val = getVal();
        lazy = initLazy;
    }
    void fix() {
        if(r - l == 1) return;
        val = f1(l_node->getVal(), r_node->getVal());
    }
    T query(ull qL, ull qR) {
        if(qR <= l || r <= qL) return initVal;
        if(qL <= l && r <= qR) return getVal();
        if(r - l == 1)  return getVal();

        push();
        T l_val = l_node->query(qL, qR), r_val = r_node->query(qL, qR);
        return f1(l_val, r_val);
    }
    void update(ull uL, ull uR, const T& uVal) {
        if(uR <= l || r <= uL) return;
        if(uL <= l && r <= uR) lazy = f2(lazy, uVal);
        else {
            push();
            l_node->update(uL, uR, uVal);
            r_node->update(uL, uR, uVal);
            fix();
        }
    }
};

template <typename T>
struct DynamicLazySegTree {
    Node<T> root;
    DynamicLazySegTree(ull l, ull r, const T& val) : root(l, r, val) {}
    T query(ull l, ull r) {
        return root.query(l, r);
    }
    void update(ull l, ull r, const T& val) {
        root.update(l, r, val);
    }
};



int main(){
    ll n, m;
    cin >> n >> m;
    vl a(m+1);
    rep(i, m) cin >> a[i];
    a[m] = n+1;
    vl d(m);
    rep(i, m) d[i] = a[i+1] - a[i]-1;
    sort(all(d));

    DynamicLazySegTree<ll> seg(0, d.size(), 0);
    rep(i, d.size()) seg.update(i, i+1, d[i]);

    vi x(n);
    const int r = d.size();
    rep(i, n) {
        int l = lower_bound(all(d), i+1) - d.begin();
        x[i] = seg.query(l, r) - i * (r - l);
    }
    reverse(all(x));

    // dumpV(d);
    // dumpV(x);


    int Q;
    cin >> Q;
    rep(i, Q) {
        int l;
        cin >> l;

        auto it = upper_bound(all(x), l - a[0]+1);

        if(it == x.begin()) cout << -1 << endl;
        else {
            int id = it - x.begin() - 1;
            cout << n - id << endl;
        }
    }
    
    return 0;
}
