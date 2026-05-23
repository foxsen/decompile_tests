#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cassert>
#include<set>
#include<limits>

using namespace std;

const double EPS = 1e-8;
template<typename T> bool equals(T a, T b){ return (fabs(a - b)) < EPS;};

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

static const int NOTCROSS = 4;
static const int CIRCUMSCRIBED = 3; 
static const int INTERSECT = 2;
static const int INSCRIBED = 1;
static const int INCLUDE = 0;

const double PI = acos(-1);

class Point{
public:
	double x, y;
	
	Point(double x = 0, double y = 0): x(x), y(y) {}
	Point(const Point &p) { x = p.x; y = p.y;};
	
	Point operator + (const Point &p) { return Point(x + p.x, y + p.y); }
	Point operator - (const Point &p) { return Point(x - p.x, y - p.y); }
	Point operator * (const double &a) { return Point(x * a, y * a); }
	Point operator / (const double &a) { return Point(x / a, y / a); }
	
	Point & operator = (const Point& p) {x = p.x; y = p.y; return *this;};
	Point & operator += (const Point& p) {x += p.x; y += p.y; return *this;};
	Point & operator -= (const Point& p) {x -= p.x; y -= p.y; return *this;};
	Point & operator *= (const Point& p) {x *= p.x; y *= p.y; return *this;};
	Point & operator /= (const Point& p) {x /= p.x; y /= p.y; return *this;};
	
	bool operator < (const Point &p) const {
		return x != p.x ? x < p.x : y < p.y;
	}
	
	bool operator > (const Point &p) const {
		return x != p.x ? x > p.x : y > p.y;
	}
	
	bool operator == (const Point &p) const {
		return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
	}
	
	double abs() { return sqrt(norm()); };
	double norm() { return x * x + y * y;};
};

typedef Point Vector;


double norm(Vector a){
	return a.x * a.x + a.y * a.y;
}

double abs(Vector a){
	return sqrt(norm(a));
}

double dot(Vector a, Vector b){
	return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b){
	return a.x * b.y - a.y * b.x;
}

struct Segment{
	Point p1, p2;
};

typedef Segment Line;

class Circle {
public:
	Point c;
	double r;
	Circle(Point c = Point(), double r = 0.0): c(c), r(r) {}
};

typedef vector<Point> Polygon;



bool isOrthogonal(Vector a, Vector b){
	return equals(dot(a,b), 0.0);
}

bool isOrthogonal(Point a1, Point a2, Point b1, Point b2){
	return isOrthogonal(a1 - a2, b1 - b2);
}

bool isOrthogonal(Segment s1, Segment s2){
	return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}


bool isParallel(Vector a, Vector b){
	return equals(cross(a, b), 0.0);
}

bool isParallel(Point a1, Point a2, Point b1, Point b2){
	return isParallel(a1 - a2, b1 - b2);
}

bool isPrallel(Segment s1, Segment s2){
	return equals(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

Point project(Segment s, Point p){
	Vector base = s.p2 - s.p1;
	double r = dot(p - s.p1, base) / norm(base);
	return s.p1 + base * r;
}

Point reflect(Segment s, Point p){
	return p + (project(s, p) - p) * 2.0;
}

int ccw(Point p0, Point p1, Point p2){
	Vector a = p1 - p0;
	Vector b = p2 - p0;
	if(cross(a, b) > EPS) return COUNTER_CLOCKWISE;
	if(cross(a, b) < -EPS) return CLOCKWISE;
	if(dot(a, b) < - EPS) return ONLINE_BACK;
	if(a.norm() < b.norm()) return ONLINE_FRONT;
	
	return ON_SEGMENT;
}

bool intersect(Point p1, Point p2, Point p3, Point p4){
	return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

bool intersect(Segment s1, Segment s2){
	return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

int intersect(Circle c1, Circle c2){
	double dis = abs(c1.c - c2.c);
	
	if(dis > c1.r + c2.r + EPS) return NOTCROSS;
	if(fabs(dis - c1.r - c2.r) < EPS) return CIRCUMSCRIBED;
	if(dis > fabs(c1.r - c2.r) + EPS) return INTERSECT;
	if(fabs(dis - fabs(c1.r - c2.r)) < EPS) return INSCRIBED;
	return INCLUDE;
}

double getDistance(Point a, Point b){
	return abs(a - b);
}

double getDistanceLP(Line l, Point p){
	return abs(cross(l.p2 - l.p1, p - l.p1)) / abs(l.p2 - l.p1);
}

double getDistanceSP(Segment s, Point p){
	if(dot(s.p2 - s.p1, p - s.p1) < 0.0) return abs(p - s.p1);
	if(dot(s.p1 - s.p2, p - s.p2) < 0.0) return abs(p - s.p2);
	return getDistanceLP(s, p);
}

double getDistance(Segment s1, Segment s2){
	if(intersect(s1, s2)) return 0.0;
	return min(min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)), min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
}

Point getCrosPoint(Segment s1, Segment s2){
	Vector base = s2.p2 - s2.p1;
	double d1 = abs(cross(base, s1.p1 - s2.p1));
	double d2 = abs(cross(base, s1.p2 - s2.p1));
	double t = d1 / (d1 + d2);
	return s1.p1 + (s1.p2 - s1.p1) * t;
}

bool intersect(Circle c, Line l){
	return getDistanceLP(l, c.c) < c.r + EPS;
}

pair<Point, Point> getCrossPoint(Circle c, Line l){
	assert(intersect(c,l));
	Vector pr = project(l, c.c);
	Vector e = (l.p2 - l.p1) / abs(l.p2 - l.p1);
	double base = sqrt(c.r * c.r - norm(pr - c.c));
	return make_pair(pr + e * base, pr - e *base);
}

double arg(Vector p) {return atan2(p.y, p.x);}
Vector polar(double a, double r) { return Point(cos(r) * a, sin(r) * a);}


pair<Point, Point> getCrosPoint(Circle c1, Circle c2){
	Point res1, res2;
	int ins = intersect(c1, c2);
	if(ins == NOTCROSS || ins == INCLUDE) {
		assert(false); // 0
	}
	if(ins == INSCRIBED && equals(c1.r, c2.r)){
		assert(false); // infinity
	}
	double d = abs(c1.c - c2.c);
	double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
	double t = arg(c2.c - c1.c);
	res1 = c1.c + polar(c1.r, t + a);
	res2 = c1.c + polar(c1.r, t - a);
	return make_pair(res1, res2);
}


double getArea(Circle c){
	return c.r*c.r*PI;
}

double getArea(Polygon& p){
	double area = 0;
	
	for(int i = 0; i < p.size(); i++){
		area += (p[i].x * p[(i + 1) % p.size()].y - p[(i + 1) % p.size()].x * p[i].y);
	}
	
	return fabs(area)/2;
}

bool isConvex(Polygon& p){
	int b = 0;
	
	for(int i = 0; i < p.size(); i++){
		int j = (i + 1) % p.size(), k = (i + 2) % p.size();
		int c = ccw(p[i], p[j], p[k]);
		if(c == ON_SEGMENT || c == ONLINE_BACK || c == ONLINE_FRONT) continue;
		if(c*b < 0) return false;
		if(!b) b = c;
	}
	
	return 1;
}



signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	int N;
	
	cin>>N;
	
	for(int _ = 0; _ < N; _++) {
		int n;
		int ans = 0;
		Segment S;
		vector<pair<double,bool>> dis;
		
		// cin>>n;
		cin>>S.p1.x>>S.p1.y>>S.p2.x>>S.p2.y;
		
		cin>>n;
		for(int i = 0; i < n; i++){
			int o, l;
			bool X = true;
			Segment T;
			
			cin>>T.p1.x>>T.p1.y>>T.p2.x>>T.p2.y;
			
			cin>>o>>l;
			
			if(o == l) X = false;
			
			if(intersect(S, T)) {
				Point p = getCrosPoint(S, T);
				
				dis.push_back({getDistance(S.p1, p), X});
			}
		}
		
		sort(dis.begin(), dis.end());
		
		for(int i = 1; i < dis.size(); i++){
			if(dis[i].second != dis[i-1].second)  ans++;
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}

