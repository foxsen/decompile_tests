#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

struct Rectangle {
    ll h;
    ll p;  // position from left
};

ll max_area_of_histgram(ll n, vector<ll>& height) {
    stack<Rectangle> S;
    ll maxv = 0;
    
    for (int i = 0; i <= n; i++) {
        Rectangle rect;
        rect.h = height[i];
        rect.p = i;
        
        if (S.empty()) {
            S.push(rect);
        }
        else if (S.top().h < rect.h) {
            S.push(rect);
        }
        else if (S.top().h > rect.h) {
            ll now = i;
            while ((!S.empty()) && (S.top().h >= rect.h)) {
                Rectangle pre = S.top(); S.pop();
                ll area = 1LL * pre.h * (i - pre.p);
                maxv = max(maxv, area);
                now = pre.p;
            }
            rect.p = now;
            S.push(rect);
        }
    }
    return maxv;
}

ll solve(){
    ll N; cin >> N;
    vector<ll> dp(N,0); for(auto& in:dp) cin >> in;
    dp.push_back(0);
    return max_area_of_histgram(N, dp);
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}

