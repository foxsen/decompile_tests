#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,Q;
    cin >> N >> Q;
    vec<ll> A(N);
    for(auto& x:A) cin >> x;
    vec<ll> S(N+1),sum(N+1);
    for(int i=0;i<N;i++){
        S[i+1] = A[i];
        if(i-1>=0) S[i+1] += S[i-1];
        sum[i+1] = sum[i]+A[i];
    }

    auto solve = [&](ll x){
        int l = 0,r = (N+1)/2;
        //上からm番目を取れるか？
        while(l+1<r){
            int m = (l+r)/2;
            ll target = A[N-m-1];
            ll opp = A[N-2*m-1];
            if(abs(x-opp)<=abs(x-target)) l = m;
            else r = m;
        }
        ll res = sum[N]-sum[N-l-1];
        int ar = N-2*l-1;
//        cerr << x << " " << ar << "\n";
        if(ar) res += S[ar-1];
        return res;
    };

    while(Q--){
        ll x;
        cin >> x;
        cout << solve(x) << "\n";
    }
}