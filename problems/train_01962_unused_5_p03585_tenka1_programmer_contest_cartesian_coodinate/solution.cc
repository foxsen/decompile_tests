#include <bits/stdc++.h>
using namespace std;

#define times(n, i)      uptil(0, n, i)
#define rtimes(n, i)     downto((n) - 1, 0, i)
#define upto(f, t, i)    for(int i##_to_ = (t), i = (f); i <= i##_to_; i++)
#define uptil(f, t, i)   for(int i##_to_ = (t), i = (f); i <  i##_to_; i++)
#define downto(f, t, i)  for(int i##_to_ = (t), i = (f); i >= i##_to_; i--)
#define downtil(f, t, i) for(int i##_to_ = (t), i = (f); i >  i##_to_; i--)
typedef long double LD;
#define long long long

#if defined(EBUG) && !defined(ONLINE_JUDGE)
#define debug true
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 1
#define ln << endl
#else
#define debug false
#define ln << '\n'
#endif
#define tb << '\t'
#define sp << ' '

class BIT {
    static constexpr int N = 131072/2;
    int node[N];
public:
    BIT() { times(N, i) node[i] = 0; }
    /** 0-based **/
    void set(int i, int v) {
        add(i, v - node[i]);
    }
    /** 0-based **/
    void add(int i, int v) {
        for(++i; i <= N; i += i & -i)
            node[i-1] += v;
    }
    /** [0, i) **/
    int sum(int i) {
        int s = 0;
        for(++i; i; i -= i & -i)
            s += node[i-1];
        return s;
    }
};

int A[48600], B[48600], C[48600];
int e0[48600], e[48600];

signed main() { // long: 64bit
    if(!debug) {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }

    int N; scanf("%d", &N);
    long nn = N * (N - 1) / 2;
    vector<pair<LD, int>> d0(N), d(N);

    times(N, i) {
        scanf("%d%d%d", &A[i], &B[i], &C[i]);
    }

    times(2, o) {
        times(N, i) d0[i] = make_pair((C[i] - (LD)A[i] * -1e9L) / B[i], i);
        if(debug) times(N, i) cout << d0[i].first ln;
        sort(d0.begin(), d0.end());
        if(debug) times(N, i) cout << d0[i].first ln;
        times(N, i) e0[d0[i].second] = i;
        if(debug) { times(N, i) cout << d0[i].first << "," << d0[i].second sp; cout ln; }

        LD l = -1e9L, r = 1e9L;
        times(100, oo) {
            LD m = (l + r) / 2;
            times(N, i) d[i] = {(C[i] - (LD)A[i] * m) / B[i], i};
            sort(begin(d), end(d));

            BIT bit;
            long a = 0;
            times(N, i) {
                int aj = e0[d[i].second];
                a += aj - bit.sum(aj);
                bit.add(aj, 1);
            }
            if(a < (nn + 1) / 2) l = m;
            else r = m;
        }

        cout << std::fixed << setprecision(30) << l << (o ? "\n" : " ");
        swap(A, B);
    }

    return 0;
}
