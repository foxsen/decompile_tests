#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

enum EventKind {
  Fire,
  ElevetorEnd
};

struct Event {
  EventKind kind;
  double t;
  int floor;
  int index;
  Event() {;}
  Event(EventKind kind, double t, int floor, int index)
    : kind(kind), t(t), floor(floor), index(index) {;}
  bool operator<(const Event &rhs) const {
    if (t != rhs.t) { return t > rhs.t; }
    return floor < rhs.floor;;
  }
};

int n, m, k, tfloor, tup, tlower;
double d;
int device[50];
int capacity[50];
double v[50];
int tstop[50];
double elevetorFrom[50];
double elevetorStart[50];
double elevetorWait[50];
int elevetorDir[50];
int elevetorTo[50];
int elevetorRide[50];

void dfsFire(priority_queue<Event> &que, int floor, int parent, int t) {
  if (floor <= -1 || floor >= n) { return; }
  que.push(Event(Fire, t + tfloor, floor, 0));
  int nfloor = floor + 1;
  if (nfloor != parent) {
    dfsFire(que, nfloor, floor, t + tup);
  }
  nfloor = floor - 1;
  if (nfloor != parent) {
    dfsFire(que, nfloor, floor, t + tlower);
  }
}

void SetElevetor(priority_queue<Event> &que, int index, double t) {
  double pos = elevetorFrom[index] + v[index] * elevetorDir[index] * max(0.0, (t - elevetorStart[index] - elevetorWait[index]));
  assert(pos >= -EPS);
  elevetorFrom[index] = pos;
  elevetorWait[index] = max(0.0, elevetorWait[index] + elevetorStart[index] - t);
  elevetorStart[index] = t;
  if (elevetorRide[index] != capacity[index]) {
    for (int y = n - 1; y >= 0; y--) {
      if (device[y] == 0) { continue; }
      if (elevetorTo[index] == y) { return; }
      //cout << index << " " << elevetorTo[index] << " " << y << endl;
      elevetorDir[index] = y * d > pos ? 1 : -1;
      elevetorTo[index] = y;
      double nt = fabs(pos - elevetorTo[index] * d) / v[index] + t + elevetorWait[index];;
      //cout << index << " " << nt << " " << y << endl;
      que.push(Event(ElevetorEnd, nt, elevetorTo[index], index));
      return;
    }
  }
  if (elevetorTo[index] == 0) {
    elevetorDir[index] = 0;
    return;
  }
  elevetorDir[index] = -1;
  elevetorTo[index] = 0;
  double nt = fabs(pos - elevetorTo[index] * d) / v[index] + t + elevetorWait[index];
  //cout << index << " " << nt << " " << 0 << endl;
  que.push(Event(ElevetorEnd, nt, elevetorTo[index], index));
  return;
}

int main() {
  while (scanf("%d %d", &n, &m),n|m) {
    int ans = 0;
    double anst = 0.0;
    priority_queue<Event> que;
    scanf("%lf", &d);
    REP(i, n) { scanf("%d", &device[i]); }
    ans += device[0];
    device[0] = 0;
    REP(i, m) {
      int y;
      scanf("%d %lf %d %d", &capacity[i], &v[i], &tstop[i], &y);
      y--;
      elevetorFrom[i] = y * d;
      elevetorStart[i] = 0;
      elevetorWait[i] = 0;
      elevetorDir[i] = 1;
      elevetorTo[i] = -1;
      elevetorRide[i] = 0;
      SetElevetor(que, i, 0);
    }
    scanf("%d %d %d %d", &k, &tfloor, &tup, &tlower);
    k--;
    dfsFire(que, k, k, 0);
    while (!que.empty()) {
      Event event = que.top();
      que.pop();
      if (event.kind == ElevetorEnd && event.floor != elevetorTo[event.index]) {
        continue;
      }
      //cout << event.kind << " " << event.t << " " << event.floor << " " << event.index << endl;
      if (event.kind == Fire) {
        //cout << event.t << endl;
        device[event.floor] = 0;
      } else if (event.kind == ElevetorEnd) {
        if (event.floor == 0) {
          ans += elevetorRide[event.index];
          if (elevetorRide[event.index] != 0) {
            anst = max(anst, event.t + tstop[event.index]);
          }
          elevetorFrom[event.index] = event.floor * d;
          elevetorStart[event.index] = event.t;
          elevetorRide[event.index] = 0;
          elevetorWait[event.index] = tstop[event.index];
        } else {
          //cout << event.kind << " " << event.t << " " << event.floor << " " << event.index << endl;
          int ride = min(capacity[event.index] - elevetorRide[event.index], device[event.floor]);
          device[event.floor] -= ride;
          elevetorFrom[event.index] = event.floor * d;
          elevetorStart[event.index] = event.t;
          elevetorRide[event.index] += ride;
          elevetorWait[event.index] = tstop[event.index];
        }
      } else {
        assert(false);
      }
      REP(i, m) { SetElevetor(que, i, event.t); }
    }
    printf("%d %.3lf\n", ans, anst);
  }
}