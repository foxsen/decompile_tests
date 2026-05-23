#include <bits/stdc++.h>
using namespace std;

#define dump(...) (cerr<<#__VA_ARGS__<<" = "<<(DUMP(),__VA_ARGS__).str()<<endl)
struct DUMP : stringstream {
	template<class T>
	DUMP &operator,(const T &t) {
		if(this->tellp()) *this << ", ";
		*this << t;
		return *this;
	}
};

constexpr double EPS = 1e-8;

struct point {
	double x, y;
	point(double x_ = 0, double y_ = 0):x(x_), y(y_) {}
	point(const point &p):x(p.x), y(p.y) {}

	point operator+(const point &p) const {
		return point(x + p.x, y + p.y);
	}

	point operator-(const point &p) const {
		return point(x - p.x, y - p.y);
	}

	point operator*(double s) const {
		return point(x * s, y * s);
	}

	point operator*(const point &p) const {
		return point(x * p.x - y * p.y, x * p.y + y * p.x);
	}

	point operator/(const double s) const {
		return point(x / s, y / s);
	}

	bool operator<(const point &p) const {
		return x + EPS < p.x || (abs(x - p.x) < EPS && y + EPS < p.y);
	}

	bool operator==(const point &p) const {
		return abs(x - p.x) < EPS && abs(y - p.y) < EPS;
	}
};

ostream &operator<<(ostream &os, const point &p) {
	return os << '(' << p.x << ", " << p.y << ')';
}

point rotate90(const point &p) {
	return point(-p.y, p.x);
}

double norm(const point &p) {
	return p.x * p.x + p.y * p.y;
}

double abs(const point &p) {
	return sqrt(norm(p));
}

double dot(const point &a, const point &b) {
	return a.x * b.x + a.y * b.y;
}

double cross(const point &a, const point &b) {
	return a.x * b.y - a.y * b.x;
}

struct line {
	point a, b;
	line(const point &a_, const point &b_):a(a_), b(b_) {}
};

struct segment {
	point a, b;
	segment(const point &a_, const point &b_):a(a_), b(b_) {}
};

struct circle {
	point c;
	double r;
	circle(const point &c_, double r_):c(c_), r(r_) {}
};

double dist(const point &a, const point &b) {
	return abs(a - b);
}

double dist(const line &l, const point &p) {
	return abs(cross(l.b - l.a, p - l.a)) / abs(l.b - l.a);
}

double dist(const segment &s, const point &p) {
	if(dot(s.b - s.a, p - s.a) < 0) return dist(p, s.a);
	if(dot(s.a - s.b, p - s.b) < 0) return dist(p, s.b);
	return dist(line(s.a, s.b), p);
}

bool intersect(const circle &c, const point &p) {
	return dist(p, c.c) + EPS < c.r;
}

bool intersect(const circle &c, const segment &s) {
	return dist(s, c.c) + EPS < c.r;
}

point crosspoint(const line &a, const line &b) {
	const double tmp = cross(a.b - a.a, b.b - b.a);
	if(abs(tmp) < EPS) return a.a;
	return b.a + (b.b - b.a) * cross(a.b - a.a, a.a - b.a) / tmp;
}

vector<point> tangent(const circle &c, const point &p) {
	const double x = norm(p - c.c);
	double d = x - c.r * c.r;
	if(d < -EPS) return vector<point>();
	d = max(d, 0.0);
	const point p1 = (p - c.c) * (c.r * c.r / x);
	const point p2 = rotate90((p - c.c) * (-c.r * sqrt(d) / x));
	vector<point> res;
	res.push_back(c.c + p1 - p2);
	res.push_back(c.c + p1 + p2);
	return res;
}

constexpr double W = 50.0;
constexpr double H = 94.0;
constexpr double INF = INT_MAX;

template<class T> inline void chmin(T &a, const T &b) { if(a > b) a = b; }

bool out(const point &p) {
	return p.x < EPS || p.y < EPS || p.x + EPS > W || p.y + EPS > H;
}

vector<line> get_line(const circle &c, const point &p) {
	const auto ts = tangent(c, p);
	vector<line> res;
	for(const auto &t : ts) {
		if(t == p) {
			res.emplace_back(p, p + rotate90(c.c - p));
		}
		else {
			res.emplace_back(p, t);
		}

	}
	return res;
}

int main() {
	const point start(W / 2.0, 0);
	const point goal(W / 2.0, H);

	cout.flags(ios::fixed);
	cout.precision(10);

	int N, D;
	cin >> N >> D;

	vector<circle> circles;
	circles.reserve(N);

	for(int i = 0; i < N; ++i) {
		int x, y, r;
		cin >> x >> y >> r;
		circles.emplace_back(point(x, y), r);
	}

	int cnt = 0;
	for(const auto &c : circles) {
		if(intersect(c, segment(start, goal))) ++cnt;
	}

	if(cnt <= D) {
		cout << 94.0 << endl;
		return 0;
	}

	vector<line> s_lines;
	vector<line> g_lines;
	s_lines.reserve(2 * N);
	g_lines.reserve(2 * N);

	for(const auto &c : circles) {
		auto ls = get_line(c, start);
		s_lines.insert(s_lines.end(), ls.begin(), ls.end());
		ls = get_line(c, goal);
		g_lines.insert(g_lines.end(), ls.begin(), ls.end());
	}

	double ans = INF;
	for(const auto &s_l : s_lines) {
		for(const auto &g_l : g_lines) {
			const point cp = crosspoint(s_l, g_l);
			if(out(cp)) continue;

			const segment s1(start, cp);
			const segment s2(cp, goal);

			cnt = 0;
			for(const auto &c : circles) {
				const bool i1 = intersect(c, s1);
				const bool i2 = intersect(c, s2);

				if(i1 && i2 && !intersect(c, cp)) {
					cnt += 2;
				}
				else if(i1 || i2) {
					++cnt;
				}
			}

			if(cnt <= D) chmin(ans, dist(start, cp) + dist(cp, goal));
		}
	}

	if(ans == INF) {
		puts("-1");
	}
	else {
		cout << ans << endl;
	}

	return 0;
}