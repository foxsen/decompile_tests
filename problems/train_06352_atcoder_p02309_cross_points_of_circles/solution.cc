#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <cmath>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30
#define pb push_back
#define mp make_pair
#define EPS 1e-8
#define equals(a,b) fabs((a) - (b)) < EPS

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

struct Point {
	double x, y;

	Point(double x=0, double y=0) : x(x), y(y) {}

	Point operator+(const Point &o) const { return Point(x+o.x, y+o.y); }

	Point operator-(const Point &o) const { return Point(x-o.x, y-o.y); }

	Point operator*(const double m) const { return Point(x*m, y*m); }

	Point operator/(const double d) const { return Point(x/d, y/d); }

	bool operator<(const Point &o) const { return x != o.x ? x < o.x : y < o.y; }

	bool operator==(const Point &o) const { return fabs(x-o.x) < EPS && fabs(y-o.y) < EPS; }
};

ostream& operator << (ostream& os, const Point& p) {
	os << "(" << p.x << ", " << p.y << ")";
	return os;
}

double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
double atan(Point p) { return atan2(p.y, p.x); }
double norm(Point p) { return p.x * p.x + p.y * p.y; }
double abs(Point p) { return sqrt(norm(p)); }
double distancePP(Point p, Point o) { return sqrt(norm(o - p)); }

int ccw(Point a, Point b, Point c) {
	b = b-a;
	c = c-a;

	if(cross(b, c) > 0.0) return +1;	//conter clockwise
	if(cross(b, c) < 0.0) return -1;	//clockwise
	if(dot(b, c) < 0.0) return +2;	//a on Seg(b,c)
	if(norm(b) < norm(c)) return -2;	//b on Seg(a,c)
	return 0;	//c on Seg(a,b)
}

struct Circle {
	Point p;
	double r;

	Circle() : p(Point(0,0)), r(0) {}

	Circle(Point o, double r) : p(o), r(r) {}

	Circle(double x, double y, double r) : p(Point(x, y)), r(r) {}
};

bool inCircle(Circle c, Point p) {
	Point a = p - c.p;
	return dot(a, a) < c.r * c.r + EPS;
}

// 1:?????§??\?????????0:???????????????-1:?????§??\?????????2:?????????-2:??????
int isIntersectCC(Circle c1, Circle c2) {
	double d = dot(c2.p - c1.p, c2.p - c1.p);
	double len = (c1.r + c2.r) * (c1.r + c2.r);

	if(equals(d, len)) return 1;
	if(d > len) return 0;

	double R = fabs(c2.r - c1.r) * fabs(c2.r - c1.r);
	if(equals(d, R)) return -1;
	if(d > R) return 2;
	return -2;
}


vector<Point> crossPointCC(Circle c1, Circle c2) {
	vector<Point> ret;
	int ch = isIntersectCC(c1, c2);

	if(ch == 0 || ch == -2) return ret;

	Point base = c2.p - c1.p;
	double len = dot(base, base);
	double t = (c1.r*c1.r - c2.r*c2.r + len) / (2.0 * len);

	if(ch == 2) {
		Point n(-base.y, base.x);
		n = n / (abs(n));
		double h = sqrt(c1.r * c1.r - t * t * len);

		ret.push_back(c1.p + (base*t) + (n*h));
		ret.push_back(c1.p + (base*t) - (n*h));
	} else {
		ret.push_back(c1.p + (base*t));
	}

	return ret;
}

int main() {
	Circle c1, c2;
	cin >> c1.p.x >> c1.p.y >> c1.r;
	cin >> c2.p.x >> c2.p.y >> c2.r;

	vector<Point> ret = crossPointCC(c1, c2);

	cout << fixed;
	cout.precision(20);

	if(ret.size() == 1) {
		cout << ret[0].x << " " << ret[0].y << " " << ret[0].x << " " << ret[0].y << endl;
	} else {
		sort(ret.begin(), ret.end());
		cout << ret[0].x << " " << ret[0].y << " " << ret[1].x << " " << ret[1].y << endl;
	}
	return 0;
}