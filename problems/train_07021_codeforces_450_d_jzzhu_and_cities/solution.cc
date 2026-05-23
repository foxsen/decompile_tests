#include <bits/stdc++.h>
using namespace std;
int N, M, K;
int n1, n2, v;
vector<int> to[100002];
vector<long long> dist[100002];
bool vis[100002];
int main() {
  cin >> N >> M >> K;
  int count = 0;
  for (int i = 0; i < M; i++) {
    cin >> n1 >> n2 >> v;
    to[n1].push_back(n2);
    dist[n1].push_back(v);
    to[n2].push_back(n1);
    dist[n2].push_back(v);
  }
  for (int i = 0; i < K; i++) {
    cin >> n1 >> v;
    to[1].push_back(n1 - N);
    dist[1].push_back(v);
  }
  priority_queue<pair<long long, int>> pq;
  pq.push(make_pair(0, 1));
  int curNode = 1, nextNode = 1;
  long long curDist = 0, nextDist = 0;
  while (!pq.empty()) {
    pair<long long, int> cur = pq.top();
    pq.pop();
    curNode = cur.second;
    curDist = cur.first;
    if (curNode <= 0) {
      curNode += N;
      if (vis[curNode]) {
        count++;
      }
    }
    if (!vis[curNode]) {
      vis[curNode] = true;
      for (int i = 0; i < to[curNode].size(); i++) {
        nextNode = to[curNode][i];
        nextDist = dist[curNode][i];
        pq.push(make_pair(curDist - nextDist, nextNode));
      }
    }
  }
  cout << count << endl;
  return 0;
}
