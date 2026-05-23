#include <iostream>
#include <queue>
#include <cstdio>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef long double real;

const real EPS = 1e-7;

struct Point {
    real x, y;
    Point() {}
    Point(real x, real y) : x(x), y(y) {}
    Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
    Point operator*(real k) const { return Point(k * x, k * y); }
    Point operator/(real k) const { return Point(x / k, y / k); }
};
real dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
real cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }
real norm(const Point& a) { return sqrt(dot(a, a)); }
Point rot90(const Point& p) { return Point(-p.y, p.x); } // 反時計回りに90度回転 
ostream& operator<<(ostream& os, const Point& p) { return os << "(" << p.x << "," << p.y << ")"; }
istream& operator>>(istream& is, Point& p) { return is >> p.x >> p.y; }

int ccw(Point a, Point b, Point c){
    b = b - a; c = c - a;
    if (cross(b, c) > EPS) return +1;      // a,b,cの順に反時計周り
    if (cross(b, c) < -EPS) return -1;     // a,b,cの順に時計周り
    if (dot(b, c) < 0) return +2;          // c--a--b 直線
    if (norm(b) < norm(c)) return -2;      // a--b--c 直線
    return 0;                              // a--c--b 直線
}

struct Line {
    Point a, b;
    Line() {}
    Line(const Point& a, const Point& b) : a(a), b(b) {}
};
bool contains(const Line& l, const Point& p) { return ccw(l.a, l.b, p) % 2 == 0; }

Point projection(const Line& l, const Point& p) {
    Point u = (p - l.a), v = (l.b - l.a);
    return l.a + (v / norm(v)) * (dot(u, v) / norm(v));
}

int N;
vector<Point> ps;
real tg, tw;
Point S, T;
bool input() {
    cin >> N;
    if (N == 0) return false;
    ps.clear(); ps.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> ps[i];
    }
    cin >> tg >> tw;
    cin >> S >> T;
    return true;
}

Point turning_point(Point a, Point b, Point t) {
    Line l(a, b);
    Point p = projection(l, t);
    Point lb = a, ub = p;
    for (int _ = 0; _ < 2000; _++) {
        Point mid0 = lb + (ub - lb) / 3;
        Point mid1 = lb + (ub - lb) * 2 / 3;
        if (tg * norm(a - mid0) + tw * norm(t - mid0) < tg * norm(a - mid1) + tw * norm(t - mid1)) {
            ub = mid1;
        } else {
            lb = mid0;
        }
    }
    return lb;
}

vector<Point> V;

const real INF = 1e9;

struct State {
    int v;
    real cost;
    State(int v, real cost) : v(v), cost(cost) {}
    bool operator<(const State& s) const {
        return cost > s.cost;
    }
};

bool on_the_same_edge(Point a, Point b) {
    for (int i = 0; i < N; i++) {
        Point s = ps[i], t = ps[(i + 1) % N];
        if (ccw(s, t, a) == 0 && ccw(s, t, b) == 0) return true;
    }
    return false;
}

real calc() {
    int s = V.size();
    V.push_back(S);
    int t = V.size();
    V.push_back(T);
    int nV = V.size();
    vector<real> D(nV, INF);
    D[s] = 0;
    priority_queue<State> Q;
    Q.push(State(s, 0));
    while (!Q.empty()) {
        State cur = Q.top(); Q.pop();
        for (int next = 0; next < nV; next++) {
            if (next == cur.v) continue;
            real ncost = cur.cost;
            if (on_the_same_edge(V[cur.v], V[next])) {
                ncost += tg * norm(V[cur.v] - V[next]);
            } else {
                ncost += tw * norm(V[cur.v] - V[next]);
            }
            if (D[next] > ncost) {
                D[next] = ncost;
                Q.push(State(next, ncost));
            }
        }
    }
    return D[t];
}

void solve() {
    V.clear();
    for (int i = 0; i < N; i++) {
        Point a = ps[i],
              b = ps[(i + 1) % N];
        V.push_back(a);
        V.push_back(turning_point(a, b, T));
        V.push_back(turning_point(b, a, T));
        if (ccw(a, b, S) != 0) {
            V.push_back(turning_point(a, b, S));
            V.push_back(turning_point(b, a, S));
        }
    }
    printf("%.18Lf\n", calc());
}

int main() {
    while (input()) {
        solve();
    }
    return 0;
}