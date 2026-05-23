#include <bits/stdc++.h>
const uint32_t MAX_K = 5;
int32_t k;
int64_t mod(int64_t a) {
  a = a % k;
  if (a < 0) {
    a += k;
  }
  return a;
}
struct Vertex {
  std::vector<Vertex *> edges;
  Vertex *par;
  uint64_t upCnt[MAX_K];
  uint64_t upDist;
  uint64_t downCnt[MAX_K];
  uint64_t downDist;
  Vertex() : par(nullptr) {}
  void root_tree() {
    for (Vertex *v : edges) {
      if (v != par) {
        v->par = this;
        v->root_tree();
      }
    }
  }
  void calc_down_dist() {
    for (int32_t i = 0; i < k; i++) {
      downCnt[i] = 0;
    }
    downDist = 0;
    for (Vertex *v : edges) {
      if (v == par) {
        continue;
      }
      v->calc_down_dist();
      for (int32_t i = 1; i < k; i++) {
        downCnt[i] += v->downCnt[i - 1];
      }
      downCnt[0] += v->downCnt[k - 1];
      downCnt[1 % k]++;
      downDist++;
      downDist += v->downDist;
      downDist += v->downCnt[0];
    }
  }
  void calc_up_dist() {
    upDist = 0;
    for (int32_t i = 0; i < k; i++) {
      upCnt[i] = 0;
    }
    if (par != nullptr) {
      upDist = par->upDist + par->downDist;
      upDist -= downDist;
      upDist -= downCnt[0];
      upDist -= downCnt[mod(-1)];
      upDist += par->upCnt[0] + par->downCnt[0];
      if (k == 1) {
        upDist--;
      }
      for (int32_t i = 0; i < k; i++) {
        upCnt[i] = par->upCnt[mod(i - 1)] + par->downCnt[mod(i - 1)];
        upCnt[i] -= downCnt[mod(i - 2)];
      }
      upCnt[1 % k]++;
      upCnt[2 % k]--;
    }
    for (Vertex *v : edges) {
      if (v != par) {
        v->calc_up_dist();
      }
    }
  }
};
std::vector<Vertex> graph;
Vertex *root;
void input() {
  uint32_t vertCnt;
  scanf("%u %i", &vertCnt, &k);
  graph.resize(vertCnt);
  for (uint32_t i = 1; i < vertCnt; i++) {
    uint32_t a, b;
    scanf("%u %u", &a, &b);
    a--;
    b--;
    graph[a].edges.push_back(&graph[b]);
    graph[b].edges.push_back(&graph[a]);
  }
}
int main() {
  input();
  root = &graph[0];
  root->root_tree();
  root->calc_down_dist();
  root->calc_up_dist();
  uint64_t ans = 0;
  for (Vertex &v : graph) {
    for (int32_t i = 0; i < k; i++) {
    }
    for (int32_t i = 0; i < k; i++) {
    }
    ans += v.upDist + v.downDist;
  }
  printf("%llu\n", ans / 2);
}
