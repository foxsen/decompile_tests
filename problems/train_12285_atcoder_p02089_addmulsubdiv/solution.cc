#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

struct Query{
    i64 q, x, s, t;
};

void update(int idx, vector<i64> &v, deque<bool> &updated, const vector<Query> &query){
    if(updated[idx])return;
    for(auto q: query){
        if(q.q == 1){
            if(v[idx] < q.x)continue;
            v[idx] += q.s;
            v[idx] *= q.t;
        }else{
            if(v[idx] > q.x)continue;
            v[idx] -= q.s;
            v[idx] /= q.t;
        }
    }
    updated[idx] = true;
}

int main(){
    i64 n, q, l, r;
    cin >> n >> q >> l >> r;
    vector<i64> v;
    for(int i=0;i<n;++i){
        i64 a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    deque<bool> updated(n, false);

    vector<Query> query;
    for(int i=0;i<q;++i){
        i64 q, x, s, t;
        cin >> q >> x >> s >> t;
        query.push_back({q, x, s, t});
    }

    int ri = n, li = -1;
    while(ri-li > 1){
        int mi = (ri + li) / 2;
        update(mi, v, updated, query);
        if(v[mi] > r)ri = mi;
        else li = mi;
    }
    int R = ri;
    ri = n; li = -1;
    while(ri-li > 1){
        int mi = (ri + li) / 2;
        update(mi, v, updated, query);
        if(v[mi] < l)li = mi;
        else ri = mi;
    }
    int L = li + 1;

    cout << R - L << endl;

    return 0;
}
