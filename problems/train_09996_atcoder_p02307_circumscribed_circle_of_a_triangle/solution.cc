#include <bits/stdc++.h>
using namespace std;
#pragma region Geometry
const double EPS=1e-8,PI=acos(-1);
inline bool EQ(double a,double b){return fabs(b-a)<EPS;}

static const int COUNTER_CLOCKWISE=1;
static const int CLOCKWISE=-1;
static const int ONLINE_BACK=2;
static const int ONLINE_FRONT=-2;
static const int ON_SEGMENT=0;

struct Point{
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}
    Point operator+(Point p) const {return Point{x+p.x,y+p.y};}
    Point operator-(Point p) const {return Point{x-p.x,y-p.y};}
    Point operator*(double t) const {return Point{x*t,y*t};}
    Point operator*(Point p) const {return Point{x*p.x-y*p.y,x*p.y+y*p.x};}
    Point operator/(double t) const {return Point{x/t,y/t};}
    bool operator<(const Point &p) const {
        return x!=p.x?x<p.x:y<p.y;
    }
    bool operator==(const Point &p) const {
        return fabs(x-p.x)<EPS&&fabs(y-p.y)<EPS;
    }
    friend istream &operator>>(istream &is,Point &p){
        is >> p.x >> p.y;
        return is;
    }
    friend ostream &operator<<(ostream &os,Point p){
        os << fixed << setprecision(10) << p.x << ' ' << p.y;
        return os;
    }
};

struct Line{
    Point a,b;
    Line(){}
    Line(Point a,Point b):a(a),b(b){}
    friend istream &operator>>(istream &is,Line &l){
        is >> l.a >> l.b;
        return is;
    }
    friend ostream &operator<<(ostream &os,Line l){
        os << l.a << " to " << l.b;
        return os;
    }
};

struct Segment:Line{
    Segment(){}
    Segment(Point a,Point b):Line(a,b){}
};

struct Circle{
    Point c;
    double r;
    Circle(){}
    Circle(Point c,double r):c(c),r(r){}
    friend istream &operator>> (istream &is,Circle &c){
        is >> c.c >> c.r;
        return is;
    }
    friend ostream &operator<<(ostream &os,Circle &c){
        os << c.c << ' ' << c.r;
        return os;
    }
};

typedef vector<Point> Polygon;
istream &operator>>(istream &is,Polygon &p){
    for (int i=0;i<p.size();++i) is >> p[i];
    return is;
}

double dot(const Point &a,const Point &b){
    return a.x*b.x+a.y*b.y;
}
double cross(const Point &a,const Point &b){
    return a.x*b.y-a.y*b.x;
}
double norm(const Point &a){
    return a.x*a.x+a.y*a.y;
}
double abs(const Point &a){
    return sqrt(norm(a));
}

// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A
Point proj(const Line &l,const Point &p){
    double t=dot(p-l.a,l.b-l.a)/norm(l.b-l.a);
    return l.a+(l.b-l.a)*t;
}
// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B
Point refl(const Line &l,const Point &p){
    return p+(proj(l,p)-p)*2.0;
}

Point rotate(const Point &p,double theta){
    return Point(cos(theta)*p.x-sin(theta)*p.y,sin(theta)*p.x+cos(theta)*p.y);
}
double arg(const Point &p){
    return atan2(p.y,p.x);
}
double get_angle(const Point &a,const Point &b,const Point &c){
    const Point v=b-a,w=c-b;
    double alpha=arg(v),beta=arg(w);
    if (alpha>beta) swap(alpha,beta);
    double theta=beta-alpha;
    return min(theta,2*PI-theta);
}

// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C
int ccw(const Point &a,Point b,Point c){
    b=b-a,c=c-a;
    if (cross(b,c)>EPS) return COUNTER_CLOCKWISE;
    if (cross(b,c)<-EPS) return CLOCKWISE;
    if (dot(b,c)<-EPS) return ONLINE_BACK;
    if (norm(b)<norm(c)) return ONLINE_FRONT;
    return ON_SEGMENT;
}

// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A
bool orthogonal(const Point &a,const Point &b){
    return EQ(dot(a,b),0.0);
}
bool orthogonal(const Point &a,const Point &b,const Point &c,const Point &d){
    return orthogonal(b-a,d-c);
}
bool orthogonal(const Line &l,const Line &m){
    return EQ(dot(l.b-l.a,m.b-m.a),0.0);
}
// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A
bool parallel(const Point &a,const Point &b){
    return EQ(cross(a,b),0.0);
}
bool parallel(const Point &a,const Point &b,const Point &c,const Point &d){
    return parallel(b-a,d-c);
}
bool parallel(const Line &l,const Line &m){
    return EQ(cross(l.b-l.a,m.b-m.a),0.0);
}

bool intersect(const Line &l,const Point &p){
    return abs(ccw(l.a,l.b,p))!=1;
}
bool intersect(const Line &l,const Line &m){
    return abs(cross(l.b-l.a,m.b-m.a)>EPS||abs(cross(l.b-l.a,m.b-m.a))<EPS);
}
bool intersect(const Line &l,const Segment &s){
    return cross(l.b-l.a,s.a-l.a)*cross(l.b-l.a,s.b-l.a)<EPS;
}
bool intersect(const Segment &s,const Point &p){
    return ccw(s.a,s.b,p)==0;
}
// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B
bool intersect(const Segment &s,const Segment &t){
    return ccw(s.a,s.b,t.a)*ccw(s.a,s.b,t.b)<=0&&ccw(t.a,t.b,s.a)*ccw(t.a,t.b,s.b)<=0;
}
bool intersect(const Circle &c,const Line &l){
    return (norm(proj(l,c.c)-c.c)-c.r*c.r)<=EPS;
}
int intersect(const Circle &c,const Segment &s){
    if (norm(proj(s,c.c)-c.c)-c.r*c.r>EPS) return 0;
    double d1=abs(c.c-s.a),d2=abs(c.c-s.b);
    if (d1<c.r+EPS&&d2<c.r+EPS) return 0;
    if (d1<c.r-EPS&&d2>c.r+EPS||d1>c.r+EPS&&d2<c.r-EPS) return 1;
    const Point h=proj(s,c.c);
    if (dot(s.a-h,s.b-h)<0) return 2;
    return 0;
}
// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_A
int intersect(Circle c,Circle d){
    if (c.r<d.r) swap(c,d);
    double dist=abs(c.c-d.c);
    if (c.r+d.r<dist) return 4;
    if (EQ(c.r+d.r,dist)) return 3;
    if (c.r-d.r<dist) return 2;
    if (EQ(c.r-d.r,dist)) return 1;
    return 0;
}

double distance(const Point &a,const Point &b){
    return abs(b-a);
}
double distance(const Line &l,const Point &p){
    return abs(p-proj(l,p));
}
double distance(const Line &l,const Line &m){
    return intersect(l,m)?0:distance(l,m.a);
}
double distance(const Segment &s,const Point &p){
    Point h=proj(s,p);
    return intersect(s,h)?abs(h-p):min(abs(s.a-p),abs(s.b-p));
}
// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D
double distance(const Segment &s,const Segment &t){
    if (intersect(s,t)) return 0;
    return min({distance(s,t.a),distance(s,t.b),distance(t,s.a),distance(t,s.b)});
}
double distance(const Line &l,const Segment &s){
    return intersect(l,s)?0:min(distance(l,s.a),distance(l,s.b));
}

Point crosspoint(const Line &l,const Line &m){
    double d1=cross(l.b-l.a,m.b-m.a),d2=cross(l.b-l.a,l.b-m.a);
    if (EQ(abs(d1),0.0)&&EQ(abs(d2),0.0)) return m.a;
    return m.a+(m.b-m.a)*d2/d1;
}
// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_C
Point crosspoint(const Segment &s,const Segment &t){
    assert(intersect(s,t));
    return crosspoint(Line(s),Line(t));
}
vector<Point> crosspoint(const Circle &c,const Line &l){
    Point pr=proj(l,c.c);
    Point e=(l.b-l.a)/abs(l.b-l.a);
    if (EQ(distance(l,c.c),c.r)) return {pr};
    double base=sqrt(c.r*c.r-norm(pr-c.c));
    return {pr-e*base,pr+e*base};
}
vector<Point> crosspoint(const Circle &c,const Segment &s){
    Line l=Line(s);
    assert(intersect(c,l));
    auto res=crosspoint(c,l);
    if (intersect(c,l)==2) return res;
    if (dot(l.a-res[0],l.b-res[0])<0) res.emplace_back(res[0]);
    else res.pop_back();
    return res;
}
vector<Point> crosspoint(const Circle &c,const Circle &d){
    double dist=abs(c.c-d.c);
    double a=acos((c.r*c.r+dist*dist-d.r*d.r)/(2*c.r*dist));
    double t=arg(d.c-c.c);
    Point p1=c.c+Point(cos(t+a),sin(t+a))*c.r,p2=c.c+Point(cos(t-a),sin(t-a))*c.r;
    return {p1,p2};
}

Circle circumcenter(Point a,Point b,const Point &c){
    a=(a-c)*0.5;
    b=(b-c)*0.5;
    Point center=c+crosspoint(Line(a,a*Point{1,1}),Line{b,b*Point{1,1}});
    return Circle{center,abs(c-center)};
}
vector<Point> center_given_radius(const Point &a,const Point &b,const double &r){
    Point m=(b-a)*0.5;
    double d1=abs(m);
    vector<Point> res;
    if (EQ(d1,0.0)||d1>r) return res;
    double d2=sqrt(r*r-d1*d1);
    Point n=m*Point{0.0,1.0}*d2/d1;
    res.emplace_back(a+m+n);
    if (d2>EPS) res.emplace_back(a+m-n);
    return res;
}

bool convex(const Polygon &p){
    int n=p.size();
    for (int i=0;i<n;++i){
        if (ccw(p[(i+n-1)%n],p[i],p[(i+1)%n])==-1){
            return false;
        }
    }
    return true;
}

Polygon convex_hull(Polygon p){
    int n=p.size(),k=0;
    if (n<=2) return p;
    sort(p.begin(),p.end());
    Polygon ch(2*n);
    for (int i=0;i<n;ch[k++]=p[i++]){
        while(k>=2&&cross(ch[k-1]-ch[k-2],p[i]-ch[k-1])<EPS) --k;
    }
    for (int i=n-2,t=k+1;i>=0;ch[k++]=p[i--]){
        while(k>=t&&cross(ch[k-1]-ch[k-2],p[i]-ch[k-1])<EPS) --k;
    }
    ch.resize(k-1);
    return ch;
}

#pragma endregion

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    Point a,b,c; cin >> a >> b >> c;
    Circle ans=circumcenter(a,b,c);
    cout << ans << '\n';
}
