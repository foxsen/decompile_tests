#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

struct LineInfo{
  double a, b, c;
};

struct Point{
  double x, y;
};

vector<Point> Input(int, double, char);
Point InputInner(double, double, char);

vector<LineInfo> GetAllLine(const vector<Point>&, const vector<Point>&);
LineInfo GetLine(const Point&, const Point&);

vector< vector<Point> > GetAllPoint(const vector<LineInfo>&,  const vector<LineInfo>&);
Point GetPoint(const LineInfo&, const LineInfo&);

double GetMaxArea(const vector< vector<Point> >&);
double GetArea(const Point&, const Point&, const Point&);
double GetDistance(const Point&, const Point&);

int main(){
  int n;
  vector<Point> bottom, top, left, right;
  vector<LineInfo> vertical, horizontal;
  vector< vector<Point> > data;

  while(1){
    cin >> n;
    if(n == 0) break;

    bottom = Input(n, 0, 'y');
    top = Input(n, 1, 'y');
    left = Input(n, 0, 'x');
    right = Input(n, 1, 'x');

    vertical = GetAllLine(bottom, top);
    horizontal = GetAllLine(left, right);
    data = GetAllPoint(vertical, horizontal);

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(6);
    cout << GetMaxArea(data) << endl;
  }
  return 0;
}

vector<Point> Input(int n, double a, char c){
  int i;
  double b;
  vector<Point> data;
  data.push_back(InputInner(a, 0, c));
  for(i=0; i<n; ++i){
    cin >> b;
    data.push_back(InputInner(a, b, c));
  }
  data.push_back(InputInner(a, 1, c));
  return data;
}

Point InputInner(double a, double b, char c){
  Point p;
  if(c == 'x'){
      p.x = a;
      p.y = b;
  }else if(c == 'y'){
      p.x = b;
      p.y = a;
  }
  return p;
}

vector<LineInfo> GetAllLine(const vector<Point>& data1,
			    const vector<Point>& data2){
  int i;
  double a, b, c;
  vector<LineInfo> data;
  for(i=0; i<data1.size(); ++i)
    data.push_back(GetLine(data1[i], data2[i]));
  return data;
}

LineInfo GetLine(const Point& p1, const Point& p2){
  double x, y;
  LineInfo line;
  x = p1.x - p2.x;
  y = p1.y - p2.y;
  line.a = y;
  line.b = -x;
  line.c = x*p1.y - y*p1.x;
  return line;
}

vector< vector<Point> > GetAllPoint(const vector<LineInfo>& data1,
				    const vector<LineInfo>& data2){
  int i, j;
  Point p;
  vector<Point> _data;
  vector< vector<Point> > data;
  for(i=0; i<data1.size(); ++i){
    for(j=0; j<data2.size(); ++j){
      p = GetPoint(data1[i], data2[j]);
      _data.push_back(p);
    }
    data.push_back(_data);
    _data.clear();
  }
  return data;
}

Point GetPoint(const LineInfo& l1, const LineInfo& l2){
  Point p;
  if(l1.b == 0 && l2.a == 0){
    p.x = -l1.c/l1.a;
    p.y = -l2.c/l2.b;
  }else if(l1.b == 0){
    p.x = -l1.c/l1.a;
    p.y = -(l2.a*p.x + l2.c)/l2.b;
  }else if(l2.a == 0){
    p.y = -l2.c/l2.b;
    p.x = -(l1.b*p.y + l1.c)/l1.a;
  }else{
    p.x = (l1.b*l2.c - l2.b*l1.c)/(l1.a*l2.b - l2.a*l1.b);
    p.y = -(l1.a*p.x + l1.c)/l1.b;
  }
  return p;
}

double GetMaxArea(const vector< vector<Point> >& data){
  int i, j;
  double s, _s;
  for(i=0, s=0; i<data.size()-1; ++i){
    for(j=0; j<data[i].size()-1; ++j){
      _s = GetArea(data[i][j], data[i+1][j], data[i+1][j+1])
	+ GetArea(data[i][j], data[i][j+1], data[i+1][j+1]);
      if(s < _s) s = _s;
    }
  }
  return s;
}

double GetArea(const Point& p1, const Point& p2, const Point& p3){
  double a, b, c;
  a = GetDistance(p1, p2);
  b = GetDistance(p1, p3);
  c = GetDistance(p2, p3);
  return a * b * sin(acos((a*a + b*b - c*c)/(2*a*b))) /2;
}

double GetDistance(const Point& p1, const Point& p2){
  double x, y;
  x = p1.x - p2.x;
  y = p1.y - p2.y;
  return sqrt(x*x + y*y);
}