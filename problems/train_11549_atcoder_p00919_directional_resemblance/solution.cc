#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()
const ld EPS = 1e-8;
bool eq(ld a, ld b) { return abs(a - b) < EPS; }

template<class T>
struct Point {
    T x, y, z;
    bool operator < (const Point<T> &r) const { return make_tuple(x, y, z) < make_tuple(r.x, r.y, r.z); }
};

template<class T>
ld length(const Point<T> &p) {
    return sqrtl(p.x * p.x + p.y * p.y + p.z * p.z);
}
template<class T>
ld dot(const Point<T> &a, const Point<T> &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
template<class T>
ld angle(const Point<T> &a, const Point<T> &b) {
    return acosl(dot(a, b) / length(a) / length(b));
}
template<class T>
Point<ld> unit(Point<T> a) {
    Point<ld> p = {(ld)a.x, (ld)a.y, (ld)a.z};
    ld l = length(p);
    p.x /= l;
    p.y /= l;
    p.z /= l;
    return p;
}

bool solve() {
    using PI = Point<int>;
    int m, n, S, W; cin >> m >> n >> S >> W;
    if(m == 0 and n == 0 and S == 0 and W == 0) return false;
    vector<PI> V(m + n);
    rep(i, m) cin >> V[i].x >> V[i].y >> V[i].z;
    { // generate
        int g = S;
        for(int i=m; i<m+n; i++) {
            V[i].x = (g/7)    %100 + 1;
            V[i].y = (g/700)  %100 + 1;
            V[i].z = (g/70000)%100 + 1;
            if( g%2 == 0 ) { g = (g/2); }
            else           { g = (g/2) ^ W; }
        }
    }
    sort(all(V), [&] (PI a, PI b) { return unit(a).x > unit(b).x; });
    
    ld min_angle = 1e9;    
    PI a, b;

    auto need_check = [&] (PI &a, PI &b) {
        ld alpha = acosl(unit(a).x);
        return cosl(alpha + min_angle) < unit(b).x + EPS;
    };
    
    queue<PI> que;
    rep(i, V.size()) {
        queue<PI> nxt_que;
        while(que.size()) {
            auto p = que.front(); que.pop();
            if(not need_check(p, V[i])) continue;
            ld ang = angle(V[i], p);
            if(ang > EPS) {
                if(min_angle + EPS > ang) {                    
                    auto va = V[i], vb = p;
                    if(vb < va) swap(va, vb);
                    if(!eq(min_angle, ang) or make_pair(a, b) > make_pair(va, vb)) {
                        a = va;
                        b = vb;
                    }
                    min_angle = ang;
                }
            }
            nxt_que.push(p);
        }
        nxt_que.push(V[i]);
        swap(que, nxt_que);
    }
    printf("%d %d %d %d %d %d\n", a.x, a.y, a.z, b.x, b.y, b.z);
    return true;
}

int main() {
    while(solve());
    return 0;
}