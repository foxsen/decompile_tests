#include <bits/stdc++.h>
using namespace std;
using LD = long double;
const LD PI = atan2(0, -1);
struct Point {
  LD x, y;
};
struct Circle {
  Point center;
  LD radius;
};
LD square(LD x) { return x * x; }
LD square_distance(Point p, Point q) {
  return square(p.x - q.x) + square(p.y - q.y);
}
LD distance(Point p, Point q) { return sqrt(square_distance(p, q)); }
pair<LD, LD> intersect_angles(Circle& C, Circle& D) {
  LD a = C.radius;
  LD b = distance(C.center, D.center);
  LD c = D.radius;
  assert(a + c > b);
  LD delta = acos((square(a) + square(b) - square(c)) / (2 * a * b));
  LD theta = atan2(D.center.y - C.center.y, D.center.x - C.center.x);
  return {theta - delta, theta + delta};
}
pair<LD, LD> tangent_angles(Point p, Circle& D) {
  LD b = distance(p, D.center);
  LD c = D.radius;
  LD delta = asin(c / b);
  LD theta = atan2(D.center.y - p.y, D.center.x - p.x);
  return {theta - delta, theta + delta};
}
pair<LD, LD> safe_angles(Circle& C, Circle& D) {
  double tangent = sqrt(square_distance(C.center, D.center) - square(D.radius));
  if (tangent <= C.radius)
    return tangent_angles(C.center, D);
  else
    return intersect_angles(C, D);
}
struct Event {
  bool begin;
  LD angle;
};
bool operator<(const Event& a, const Event& b) { return a.angle < b.angle; }
LD solve(LD x0, LD y0, LD v, LD T, int n, vector<Circle>& plates) {
  Circle cockroach{x0, y0, v * T};
  vector<Event> sweep;
  for (auto& plate : plates) {
    if (square(plate.radius) >= square_distance(cockroach.center, plate.center))
      return 1;
    if (plate.radius == 0) continue;
    if (distance(cockroach.center, plate.center) >=
        cockroach.radius + plate.radius)
      continue;
    LD left, right;
    tie(left, right) = safe_angles(cockroach, plate);
    if (left < 0) {
      left += 2 * PI;
      right += 2 * PI;
    }
    assert(0 <= left && right <= 4 * PI);
    if (right < 2 * PI) {
      sweep.push_back({true, left});
      sweep.push_back({false, right});
    } else {
      sweep.push_back({true, left});
      sweep.push_back({false, 2 * PI});
      sweep.push_back({true, 0});
      sweep.push_back({false, right - 2 * PI});
    }
  }
  sort(begin(sweep), end(sweep));
  LD cover = 0;
  int layers = 0;
  LD start = 0;
  for (auto& event : sweep) {
    assert(0 <= event.angle && event.angle <= 2 * PI);
    if (event.begin) {
      layers++;
      if (layers == 1) start = event.angle;
    } else {
      layers--;
      assert(layers >= 0);
      if (layers == 0) cover += event.angle - start;
    }
  }
  return cover / (2 * PI);
}
int main() {
  int x0, y0, v, T;
  cin >> x0 >> y0 >> v >> T;
  int n;
  cin >> n;
  auto plates = vector<Circle>(n);
  for (int i = 0; i < n; i++) {
    int x, y, r;
    cin >> x >> y >> r;
    plates[i] = {{(LD)x, (LD)y}, (LD)r};
  }
  cout << solve(x0, y0, v, T, n, plates) << endl;
}
