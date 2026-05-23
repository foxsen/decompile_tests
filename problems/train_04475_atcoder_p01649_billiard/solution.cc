#include <array>
#include <climits>
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

	point operator+(const point &p) const {
		return point(x + p.x, y + p.y);
	}

	point operator-(const point &p) const {
		return point(x - p.x, y - p.y);
	}

	point operator*(double s) const {
		return point(x * s, y * s);
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

istream &operator>>(istream &is, point &p) {
	return is >> p.x >> p.y;
}

// ax^2 + bx + c = 0
vector<double> solve_quadratic_equation(double a, double b, double c) {
	if(abs(a) <= EPS) {
		if(abs(b) <= EPS) {
			if(abs(c) <= EPS) return {0};
			return {};
		}
		return {-c / b};
	}

	const double d = b * b - 4 * a * c;
	if(d < -EPS) return {};

	return {(-b - sqrt(d)) / (2 * a), (-b + sqrt(d)) / (2 * a)};
}

double collision_time(const point &a, const point &va, const point &b, const point &vb, double r) {
	const point d_p = a - b;
	const point d_v = va - vb;
	const double l = norm(d_v);
	const double m = 2 * dot(d_p, d_v);
	const double n = norm(d_p) - r * r;

	double res = INT_MAX;
	for(const auto &e : solve_quadratic_equation(l, m, n)) {
		if(e > EPS && res - EPS > e) {
			res = e;
		}
	}

	return res;
}

double calc(point p, point v, point g) {
	if(g.x == -1) {
		swap(g.x, g.y);
		swap(p.x, p.y);
		swap(v.x, v.y);
	}

	if(abs(v.x) < EPS) return INT_MAX;

	const double res = (g.x - p.x) / v.x;
	return res > EPS ? res : INT_MAX;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	for(int n; cin >> n && n;) {
		int w, h, r;
		point v;
		cin >> w >> h >> r >> v;

		vector<point> balls(n);
		for(auto &e : balls) cin >> e;

		const array<point, 4> table{{point(r, -1), point(-1, r), point(w - r, -1), point(-1, h - r)}};
		double rest_time = 10000 / abs(v);

		while(true) {
			double min_time = rest_time;
			int idx = -1;

			for(const auto &g : table) {
				const double t = calc(balls.front(), v, g);
				if(min_time - EPS > t) {
					min_time = t;
					idx = 0;
				}
			}

			for(int i = 1; i < n; ++i) {
				const double t = collision_time(balls.front(), v, balls[i], point(0, 0), r + r);
				if(min_time - EPS > t) {
					min_time = t;
					idx = i + 1;
				}
			}

			if(idx) {
				cout << idx << endl;
				break;
			}

			rest_time -= min_time;
			balls.front() = balls.front() + v * min_time;

			for(int i = 0; i < 4; ++i) {
				if((i & 1)) {
					if(abs(balls.front().y - table[i].y) < EPS) v.y = -v.y;

				}
				else {
					if(abs(balls.front().x - table[i].x) < EPS) v.x = -v.x;
				}
			}
		}
	}

	return EXIT_SUCCESS;
}