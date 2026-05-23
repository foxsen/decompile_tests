#include <bits/stdc++.h>
using namespace std;

using ld = long double;

constexpr ld eps = 1e-8;

using point = complex<ld>;

class segment {
public:
    segment()
        : a(point(0, 0)), b(point(0, 0))
    {}
    segment(point a_, point b_)
        : a(a_), b(b_)
    {}

    point a, b;
};

class circle {
public:
    circle()
        : p(point(0, 0)), r(0)
    {}
    circle(point p_, ld r_)
        : p(p_), r(r_)
    {}

    point p;
    ld r;
};

ld dot(point const& a, point const& b) {
    return std::real(std::conj(a) * b);
}

point proj(segment const& s, point const& p) {
    ld t = dot(p - s.a, s.a - s.b) / std::norm(s.a - s.b);
    return s.a + t * (s.a - s.b);
}

bool isis_sp(segment const& s, point const& p) {
    return (std::abs(s.a - p) + std::abs(s.b - p) - std::abs(s.b - s.a) < eps);
}

ld dist_sc(segment const& s, circle const& c) {
    ld res = 1e18;
    res = min(res, abs(c.p - s.a));
    res = min(res, abs(c.p - s.b));
    auto pp = proj(s, c.p);
    if(isis_sp(s, pp)) {
        res = min(res, abs(c.p - pp));
    }
    return res;
}

int main() {
    int N;
    cin >> N;
    vector<circle> s, t;
    vector<segment> seg;
    for(int i = 0; i < N; ++i) {
        ld r, sx, sy, tx, ty;
        cin >> r >> sx >> sy >> tx >> ty;
        s.emplace_back(point(sx, sy), r);
        t.emplace_back(point(tx, ty), r);
        seg.emplace_back(point(sx, sy), point(tx, ty));
    }

    int res = 0;
    vector<int> dp(1 << N);
    for(int S = 0; S < (1 << N); ++S) {
        if(__builtin_popcount(S) != dp[S]) {
            continue;
        }
        for(int i = 0; i < N; ++i) {
            if(S & (1 << i)) {
                continue;
            }
            if(dp[S | (1 << i)] != 0) { // 計算済み
                continue;
            }
            bool ok = true;
            for(int j = 0; j < N; ++j) {
                if(i == j) {
                    continue;
                }
                circle c;
                c.r = s[j].r;
                if(S & (1 << j)) {
                    c.p = t[j].p;
                } else {
                    c.p = s[j].p;
                }
                ld dist = dist_sc(seg[i], c);
                if(dist <= s[i].r + c.r + eps) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                dp[S | (1 << i)] = dp[S] + 1;
            }
        }
        res = max(res, dp[S]);
    }
    cout << res << endl;
}

