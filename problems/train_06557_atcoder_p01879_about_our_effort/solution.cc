#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using P = pair<int, int>;

/**
 * Fenwick Tree 
 *
 * 0-indexed
 */
template <int N>
struct FenwickTree {
    using D = ll; /// ????´???????
    D seg[N+1];
    
    /// ????´???????????????????
    void init() {
        fill_n(seg, N+1, 0);
    }

    /// i?????????????´????x???????????????
    void add(int i, D x) {
        i++;
        while (i <= N) {
            seg[i] += x;
            i += i & -i;
        }
    }

    /// [0, i)???sum
    D sum(int i) {
        D s = 0;
        while (i > 0) {
            s += seg[i];
            i -= i & -i;
        }
        return s;
    }

    /// [a, b)???sum
    D sum(int a, int b) {
        return sum(b) - sum(a);
    }
};


struct Node {
    using NP = Node*;

    ll sm, lz;

    void init_node() {
        sm = lz = 0;
    }
    void update() {
        sm = l->sm + r->sm;
    }
    void push() {
        if (lz) {
            l->lzdata(lz);
            r->lzdata(lz);
            lz = 0;
        }
    }
    void lzdata(ll x) {
        sm += sz * x;
        lz += x;
    }

    void add(int a, int b, ll x) {
        if (b <= 0 or sz <= a) return;
        if (a <= 0 and sz <= b) {
            lzdata(x);
            return;
        }
        push();
        l->add(a, b, x);
        r->add(a - sz/2, b - sz/2, x);
        update();
    }

    void add(int a, ll x) {
        add(a, a+1, x);
    }

    ll get(int k) {
        if (sz == 1) return sm;
        push();
        if (k < sz/2) {
            return l->get(k);
        } else {
            return r->get(k - sz/2);
        }
    }
    NP l, r;
    int sz;
    Node(int sz) : sz(sz) {
        init_node();
        if (sz == 1) return;
        l = new Node(sz/2);
        r = new Node(sz - sz/2);
        update();
    }
};

const int N = 1<<17;
const int BS = 1<<8;
const int BN = N/BS;


P V[N];
int yv[BN][BS];
P p[BN][BS];
int p2idx[BN][BS];
ll rngsm[BN];
int psm[BN][BS];

//Node* st[BN];
FenwickTree<BS> st[BN];

void init() {

    for (int i = 0; i < N; i++) {
        p[i/BS][i%BS] = V[i];
    }

    static int idx[BS];
    for (int i = 0; i < BN; i++) {
        sort(p[i], p[i]+BS, [&](const P &l, const P &r){
            return l.second < r.second;
        });
        for (int j = 0; j < BS; j++) {
            yv[i][j] = p[i][j].second;
        }

    }

    for (int i = 0; i < BN; i++) {
        rngsm[i] = 0;
//        st[i] = new Node(BS);
        st[i].init();
    }
}

void add(int r, int l) {
    int i;
    for (i = 0; (i+1)*BS <= r; i++) {
//        st[i]->add(lower_bound(yv[i], yv[i]+BS, l)-yv[i], BS, 1);
        st[i].add(lower_bound(yv[i], yv[i]+BS, l)-yv[i], 1);
        rngsm[i] += BS - (lower_bound(yv[i], yv[i]+BS, l)-yv[i]);
    }
    if (r % BS == 0) return;
    for (int j = 0; j < BS; j++) {
        if (p[i][j].first < r and l <= p[i][j].second) {
//            st[i]->add(j, 1);
            psm[i][j]++;
            rngsm[i]++;
        }
    }
}

ll get(int r) {
    ll sm = 0;
    int i;
    for (i = 0; (i+1)*BS <= r; i++) {
        sm += rngsm[i];
    }
    if (r % BS == 0) return sm;
    for (int j = 0; j < BS; j++) {
        if (p[i][j].first < r) {
            sm += st[i].sum(j+1);
            sm += psm[i][j];
//            sm += st[i].sum(j);
        }
    }
    return sm;
}
ll get(int l, int r) {
    return get(r) - get(l);
}


const int MN = 1<<17;
int a[MN];
vector<P> qv[MN];
ll res[MN*2];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i); a[i]--;
        V[i] = P(i, a[i]);
    }
    for (int i = n; i < N; i++) {
        V[i] = P(i, i);
    }

    init();

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r); l--; r--;
        qv[r].push_back(P(l, i));
    }

    for (int i = 0; i < n; i++) {
        add(i, a[i]+1);
        for (auto qu : qv[i]) {
            res[qu.second] = get(qu.first, i);
        }
    }
    for (int i = 0; i < q; i++) {
        printf("%lld\n", res[i]);
    }
}