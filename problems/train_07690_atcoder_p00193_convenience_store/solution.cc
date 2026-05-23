#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
typedef pair<int, int> P;

int M, N, S, T;
vector<P> a;
vector<P> b;

bool input() {
  cin >> M >> N;
  if (!M && !N) {
    return false;
  }
  cin >> S;
  a.resize(S);
  for (int i = 0; i < S; ++i) {
    cin >> a[i].first >> a[i].second;
    --a[i].first;
    --a[i].second;
  }
  cin >> T;
  b.resize(T);
  for (int i = 0; i < T; ++i) {
    cin >> b[i].first >> b[i].second;
    --b[i].first;
    --b[i].second;
  }
  return true;
}

P conv1(P p) {
  int x = p.first - (p.second/2);
  int y = p.second;
  return P(x, y);
}

P conv2(P p) {
  P q = conv1(p);
  return P(-q.second, q.first + q.second);
}

P conv3(P p) {
  P q = conv1(p);
  return P(q.first + q.second, -q.first);
}

int dist_sub(P p, P q) {
  return abs(p.first - q.first) + abs(p.second - q.second);
}

int dist(P p, P q) {
  P p1 = conv1(p);
  P p2 = conv2(p);
  P p3 = conv3(p);
  P q1 = conv1(q);
  P q2 = conv2(q);
  P q3 = conv3(q);
  int d1 = dist_sub(p1, q1);
  int d2 = dist_sub(p2, q2);
  int d3 = dist_sub(p3, q3);
  if (d1 <= d2 && d1 <= d3) {
    return d1;
  }
  if (d2 <= d3) {
    return d2;
  }
  return d3;
}

int solve() {
  int ans = -1;
  vector<P> c;
  c.resize(S + 1);
  for (int i = 0; i < S; ++i) {
    c[i] = a[i];
  }
  vector<int> counter;
  counter.resize(S + 1);
  for (int i = 0; i < T; ++i) {
    c[S] = b[i];
    for (int j = 0; j <= S; ++j) {
      counter[j] = 0;
    }
    for (int j = 0; j < M; ++j) {
      for (int k = 0; k < N; ++k) {
        bool same_flag = false;
        int min_dist = INF;
        int min_id = -1;
        for (int l = 0; l <= S; ++l) {
          int d = dist(P(j, k), c[l]);
          if (min_dist == d) {
            same_flag = true;
          } else if (min_dist > d) {
            min_dist = d;
            min_id = l;
            same_flag = false;
          }
        }
        if (!same_flag) {
          ++counter[min_id];
        }
      }
    }
    if (ans < counter[S]) {
      ans = counter[S];
    }
  }

  return ans;
}

int main() {
  while (input()) {
    cout << solve() << endl;
  }
  return 0;
}