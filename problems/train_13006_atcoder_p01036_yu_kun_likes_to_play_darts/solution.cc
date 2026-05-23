#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

constexpr double EPS = 1e-9;

struct point {
	double x, y;
	explicit point(double x_ = 0.0, double y_ = 0.0):x(x_), y(y_) {}
	point(const point &p):x(p.x), y(p.y) {}

	point operator+ (const point &p) const {
		return point(x + p.x, y + p.y);
	}

	point operator- (const point &p) const {
		return point(x - p.x, y - p.y);
	}

	point operator* (double s) const {
		return point(x * s, y * s);
	}

	point operator* (const point &p) const {
		return point(x * p.x - y * p.y, x * p.y + y * p.x);
	}

	point operator/ (double s) const {
		return point(x / s, y / s);
	}

	bool operator< (const point &p) const {
		return x + EPS < p.x || (abs(x - p.x) < EPS && y + EPS < p.y);
	}

	bool operator== (const point &p) const {
		return abs(x - p.x) < EPS && abs(y - p.y) < EPS;
	}
};

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
	line(const point &a_, const point &b_):a(a_), b(b_){}
};

struct circle {
	point c;
	double r;
	circle(const point &c_, const double &r_):c(c_), r(r_){}
};

typedef vector<point> polygon;

int ccw(const point &a, point b, point c) {
	b = b - a;
	c = c - a;
	const double tmp = cross(b, c);
	if(tmp > EPS) return 1; // ccw
	if(tmp < -EPS) return -1; // cw
	if(dot(b, c) < 0) return 2; // c, a, b 順に一直線上
	if(norm(b) < norm(c)) return -2; // a, b, c 順に一直線上
	return 0; //a, c, b 順で一直線上
}

point project(const line &l, const point &p) {
	const point dif = l.b - l.a;
	const double tmp = dot(p - l.a, dif) / norm(dif);
	return l.a + dif * tmp;
}

vector<point> crosspoint(const circle &c, const line &l) {
	vector<point> res;
	const point h = project(l, c.c);
	const double d = abs(h - c.c);
	if(d > c.r + EPS) {
		// nothing
	}
	else if(d > c.r - EPS) {
		res.emplace_back(h);
	}
	else if(d <= c.r - EPS) {
		point v = l.b - l.a;
		v = v * sqrt(c.r * c.r - d * d) / abs(v);
		res.emplace_back(h - v);
		res.emplace_back(h + v);
	}

	return res;
}

double rad(const point &a, const point &b) {
	const int c = ccw(point(0, 0), a, b);
	if(abs(c) != 1) return 0;
	const double res = acos(dot(a, b) / (abs(a) * abs(b)));
	return c * res;
}

double area(circle c, point a, point b) {
	a = a - c.c;
	b = b - c.c;
	c.c = c.c - c.c;

	const auto cp = crosspoint(c, line(a, b));
	if(cp.size() == 0) return c.r * c.r * rad(a, b) / 2;

	const bool b1 = abs(a) > c.r + EPS;
	const bool b2 = abs(b) > c.r + EPS;

	if(b1 && b2) {
		if(dot(a - cp.front(), b - cp.front()) < EPS && dot(a - cp.back(), b - cp.back()) < EPS) {
			return (c.r * c.r * (rad(a, b) - rad(cp.front(), cp.back()))
					+ cross(cp.front(), cp.back())) / 2;
		}
		else {
			return c.r * c.r * rad(a, b) / 2;
		}
	}
	else if(b1) {
		return (c.r * c.r * rad(a, cp.front()) + cross(cp.front(), b)) / 2;
	}
	else if(b2) {
		return (c.r * c.r * rad(cp.back(), b) + cross(a, cp.back())) / 2;
	}
	else {
		return cross(a, b) / 2;
	}
}

double area(const circle &c, const polygon &P) {
	double res = 0.0;
	point prev = P.back();

	for(const auto &curr : P) {
		res += area(c, prev, curr);
		prev = curr;
	}

	return abs(res);
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout.setf(ios::fixed);
	cout.precision(10);

	int n, cx, cy, r;
	cin >> n >> cx >> cy >> r;

	const circle c(point(cx, cy), r);
	const double all = c.r * c.r * M_PI;

	double ans = 0.0;
	for(int i = 0; i < n; ++i) {
		int m, score;
		cin >> m >> score;

		polygon P;
		P.reserve(m);
		for(int j = 0; j < m; ++j) {
			int x, y;
			cin >> x >> y;
			P.emplace_back(x, y);
		}

		const double s = area(c, P);
		ans += s / all * score;
	}

	cout << ans << endl;

	return EXIT_SUCCESS;
}
