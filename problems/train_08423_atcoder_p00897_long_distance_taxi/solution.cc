#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>

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

struct Edge {
  int dest;
  int cost;
  Edge(int dest, int cost) : dest(dest), cost(cost) {;}
  bool operator<(const Edge &rhs) const { return cost > rhs.cost; }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

Graph g;
int n;
int e, m, cap;
bool lgp[6010];
char str1[1000];
char str2[1000];
map<string, int> mapto;

bool visit[2001][6001];
//int dist[2010][6010];

int Push(const char* str) {
  if (!mapto.count(str)) {
    mapto[str] = n++;
    g.push_back(Edges());
  }
  return mapto[str];
}

int main() {
  while (scanf("%d %d %d", &e, &m, &cap), e|m|cap) {
    n = 0;
    cap *= 10;
    g.clear();
    MEMSET(lgp, false);
    mapto.clear();
    scanf("%s %s", str1, str2);
    int start = Push(str1);
    int end = Push(str2);
    REP(i, e) {
      int d;
      scanf("%s %s %d", str1, str2, &d);
      int l = Push(str1);
      int r = Push(str2);
      g[l].push_back(Edge(r, d));
      g[r].push_back(Edge(l, d));
    }
    REP(i, m) {
      scanf("%s", str1);
      int v = Push(str1);
      lgp[v] = true;
    }

    MEMSET(visit, false);
    //MEMSET(dist, 0x0f);
    priority_queue<pair<Edge, int> > que;
    que.push(make_pair(Edge(start, 0), cap));
    while (!que.empty()) {
      Edge e = que.top().first;
      int rest = que.top().second;
      que.pop();
      int from = e.dest;
      if (lgp[from]) { rest = cap; }
      if (visit[rest][from]) { continue; }
      visit[rest][from] = true;
      if (from == end) {
        printf("%d\n", e.cost);
        goto next;
      }
      FORIT(it, g[from]) {
        int to = it->dest;
        int ncost = e.cost + it->cost;
        int nrest = rest - it->cost;
        if (nrest < 0 || visit[nrest][to]/* || ncost >= dist[nrest][to]*/) { continue; }
        //dist[nrest][to] = ncost;
        que.push(make_pair(Edge(to, ncost), nrest));
      }
    }
    puts("-1");
next:;
  }
}