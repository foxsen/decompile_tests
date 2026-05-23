#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
};
struct segment {
  point a, b;
};
double G[1002][1002];
vector<segment> S;
int a, b;
int N;
double mins[1002];
bool used[1002];
double getLength(point a, point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool someDirection(segment a, segment b) {
  return (a.a.x == a.b.x && b.a.x == b.b.x) ||
         (a.a.y == a.b.y && b.a.y == b.b.y);
}
bool isVertical(segment a) { return a.a.x == a.b.x; }
bool Inside(int f, int k, int l) {
  return (f <= k && f >= l) || (f >= k && f <= l);
}
double minLength(segment a, segment b) {
  if (someDirection(a, b)) {
    int k, l;
    if (isVertical(b) && isVertical(a)) {
      k = abs(a.a.x - b.a.x);
      if (Inside(a.a.y, b.a.y, b.b.y) || Inside(a.b.y, b.a.y, b.b.y) ||
          Inside(b.a.y, a.a.y, a.b.y) || Inside(b.b.y, a.a.y, a.b.y))
        l = 0;
      else
        l = min(abs(a.a.y - b.a.y),
                min(abs(a.a.y - b.b.y),
                    min(abs(a.b.y - b.a.y), abs(a.b.y - b.b.y))));
    } else {
      k = abs(a.a.y - b.a.y);
      if (Inside(a.a.x, b.a.x, b.b.x) || Inside(a.b.x, b.a.x, b.b.x) ||
          Inside(b.a.x, a.a.x, a.b.x) || Inside(b.b.x, a.a.x, a.b.x))
        l = 0;
      else
        l = min(abs(a.a.x - b.a.x),
                min(abs(a.a.x - b.b.x),
                    min(abs(a.b.x - b.a.x), abs(a.b.x - b.b.x))));
    }
    return sqrt(k * k + l * l);
  } else {
    if (isVertical(b)) swap(a, b);
    int k, l;
    if (abs(a.a.x - b.a.x) + abs(a.a.x - b.b.x) == abs(b.a.x - b.b.x))
      k = 0;
    else
      k = min(abs(a.a.x - b.a.x), abs(a.a.x - b.b.x));
    if (abs(b.a.y - a.a.y) + abs(b.a.y - a.b.y) == abs(a.a.y - a.b.y))
      l = 0;
    else
      l = min(abs(b.a.y - a.a.y), abs(b.a.y - a.b.y));
    return sqrt(k * k + l * l);
  }
}
void FormMatrix() {
  for (int i = 0; i < S.size(); i++)
    for (int j = 0; j < S.size(); j++) {
      G[i][j] = minLength(S[i], S[j]);
    }
}
void Dijkstra() {
  for (int i = 0; i < N + 2; i++) {
    mins[i] = 4294967296;
    used[i] = false;
  }
  mins[0] = 0;
  for (int i = 0; i < N + 2; i++) {
    int v = -1;
    for (int j = 0; j < N + 2; j++)
      if (!used[j] && (v == -1 || mins[j] < mins[v])) v = j;
    used[v] = true;
    for (int j = 0; j < N + 2; j++) {
      if (mins[j] > (ceil(mins[v] / (a + b))) * (a + b) + G[v][j] &&
          G[v][j] <= a)
        mins[j] = ceil(mins[v] / (a + b)) * (a + b) + G[v][j];
    }
  }
}
int main() {
  cin >> a >> b;
  segment alpha, beta;
  cin >> alpha.a.x >> alpha.a.y;
  alpha.b.x = alpha.a.x;
  alpha.b.y = alpha.a.y;
  cin >> beta.a.x >> beta.a.y;
  beta.b.x = beta.a.x;
  beta.b.y = beta.a.y;
  S.push_back(alpha);
  S.push_back(beta);
  cin >> N;
  for (int i = 0; i < N; i++) {
    segment gamma;
    cin >> gamma.a.x >> gamma.a.y >> gamma.b.x >> gamma.b.y;
    S.push_back(gamma);
  }
  FormMatrix();
  Dijkstra();
  cout.setf(ios::fixed);
  cout.precision(5);
  if (mins[1] == 4294967296)
    cout << -1 << endl;
  else
    cout << mins[1] << endl;
  return 0;
}
