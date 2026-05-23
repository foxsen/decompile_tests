#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <iomanip>

using namespace std;

// common
#define X real()
#define Y imag()

using Vector2 = complex<double>;
using Line = pair<Vector2, Vector2>;
using Segment = pair<Vector2, Vector2>;
const double EPS = 1e-10;
const double PI = 3.14159265359;

bool equals(double a, double b){
    if(abs(a - b) < EPS){
        return true;
    }
    else{
        return false;
    }
}

// struct

struct Circle{
    Vector2 c;
    double r;
    Circle(Vector2 c, double r){
        this->c = c;
        this->r = r;
    }
};

// Vector2
double abs(Vector2 v){
    return sqrt(norm(v));
}

double dot(Vector2 a, Vector2 b){
    return (a.X * b.X + a.Y * b.Y);
}

double cross(Vector2 a, Vector2 b){
    return (a.X * b.Y - a.Y * b.X);
}

Vector2 project(Line l, Vector2 p){
    Vector2 base = l.second - l.first;
    double r = dot(p - l.first, base) / norm(base);
    return l.first + base * r;
}

pair<Vector2, Vector2> crossPoints(Circle c, Line l){
    Vector2 pr = project(l, c.c);
    Vector2 e = (l.second - l.first) / abs(l.second - l.first);
    double base = sqrt(c.r * c.r - norm(pr - c.c));
    return make_pair(pr + e * base, pr - e * base);
}

int main(){

    int cx, cy, r;
    cin >> cx >> cy >> r;
    Circle c(Vector2(cx, cy), r);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int x0, y0, x1, y1;
        cin >> x0 >> y0 >> x1 >> y1;
        Line l(Vector2(x0, y0), Vector2(x1, y1));
        
        auto ans = crossPoints(c, l);
        Vector2 ansMin, ansMax;
        if(equals(ans.first.X, ans.second.X)){
            if(ans.first.Y < ans.second.Y){
                ansMin = ans.first;
                ansMax = ans.second;
            }
            else{
                ansMin = ans.second;
                ansMax = ans.first;
            }
        }
        else{
            if(ans.first.X < ans.second.X){
                ansMin = ans.first;
                ansMax = ans.second;
            }
            else{
                ansMin = ans.second;
                ansMax = ans.first;
            }
        }

        cout << fixed << setprecision(8) << ansMin.X << " " << ansMin.Y << " " << ansMax.X << " " << ansMax.Y << endl;
    }

    return 0;
}
