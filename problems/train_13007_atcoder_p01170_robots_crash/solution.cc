#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

typedef complex<double> Point;
namespace std{
    bool operator < (const Point& p1, const Point& p2){
        if(p1.real() != p2.real()) return p1.real() < p2.real();
        return p1.imag() < p2.imag();
    }
};
struct Event{
    double y;
    Point p;
    int p_type;
    int e_type;
    Event(double y, Point p, int p_type, int e_type) : 
        y(y), p(p), p_type(p_type), e_type(e_type) {}
    bool operator < (const Event& e) const{
        if(y != e.y) return y < e.y;
        if(e_type != e.e_type) return e_type > e.e_type; // delete is first ???
        return p < e.p;
    }
};


double get_time(Point p, Point q, double R, double v){
    double dx = abs(p.real() - q.real());
    double dy = abs(p.imag() - q.imag());
    if(!(2 * R >= dy)) return 1e16;
    assert(2 * R >= dy);
    double b = sqrt(4 * R * R - dy * dy);
    assert(dx - b >= 0);
    return (dx - b) / v;
}

void update(double& ans, vector<Point>& pset, Point p, double R, double v, int t){
    int k = lower_bound(pset.begin(), pset.end(), p) - pset.begin();
    for(int dk = -1; dk <= 1; dk++) if(k + dk >= 0 && k + dk < pset.size()){
        if(t == 0 && p.real() < pset[k + dk].real()){
            ans = min(ans, get_time(p, pset[k + dk], R, v));
        }else if(t == 1 && p.real() > pset[k + dk].real()){
            ans = min(ans, get_time(p, pset[k + dk], R, v));
        }
    }
}

int main(){
    int N;
    while(cin >> N && N){
        double vx, vy;
        cin >> vx >> vy;
        vx *= 2; vy *= 2;
        double th = arg(Point(vx, vy));
        double v = sqrt(vx * vx + vy * vy);
        double R;
        cin >> R;

        vector<Event> events;

        REP(i, N){
            double x, y;
            int u;
            cin >> x >> y >> u;
            Point p(x, y);
            p = p * polar(1.0, -th);
            if(u == 1){
                events.push_back(Event(p.imag() - R, p, 0, 0));
                events.push_back(Event(p.imag() + R, p, 0, 1));
            }else{
                events.push_back(Event(p.imag() - R, p, 1, 0));
                events.push_back(Event(p.imag() + R, p, 1, 1));
            }
        }

        sort(events.begin(), events.end());

        vector<Point> point_set[2];
        double ans = 1e16;
        for(int i = 0; i < events.size(); i++){
            Event e = events[i];
            //cout << e.p << " " << e.e_type << " " << e.p_type << endl;
            vector<Point>& my_set = point_set[e.p_type];
            vector<Point>& you_set = point_set[e.p_type ^ 1];
            if(e.e_type == 0){
                my_set.insert(lower_bound(my_set.begin(), my_set.end(), e.p), e.p);
                update(ans, you_set, e.p, R, v, e.p_type);
            }else if(e.e_type == 1){
                my_set.erase(lower_bound(my_set.begin(), my_set.end(), e.p));
                int k = lower_bound(you_set.begin(), you_set.end(), e.p) - you_set.begin();
                for(int dk = -1; dk <= 1; dk ++) if(k + dk >= 0 && k + dk < you_set.size()){
                    update(ans, my_set, you_set[k], R, v, e.p_type ^ 1);
                }
            }
        }
        if(ans >= 1e16){
            puts("SAFE");
        }else{
            printf("%.6f\n", ans);
        }
    }
    return 0;
}