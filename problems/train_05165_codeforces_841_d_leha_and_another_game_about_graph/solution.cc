#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
vector<int> parent;
vector<int> parEdge;
vector<vector<int> > children;
vector<vector<int> > childEdge;
vector<pair<int, int> > edges;
vector<vector<int> > adj;
vector<vector<int> > adjEdge;
vector<int> edgeColor;
vector<int> vertexVal;
int n, m;
bitset<500000> vis;
void buildTree(int n) {
  vis[n] = true;
  for (int i = 0; i < adj[n].size(); i++) {
    int k = adj[n][i];
    int e = adjEdge[n][i];
    if (!vis[k]) {
      children[n].push_back(k);
      childEdge[n].push_back(e);
      parent[k] = n;
      parEdge[k] = e;
      buildTree(k);
    }
  }
}
void printTree(int n) {
  for (auto k : children[n]) {
    printTree(k);
  }
}
bool connecting = false;
void colorEdges(int n) {
  if (vertexVal[n]) connecting = !connecting;
  for (int i = 0; i < children[n].size(); i++) {
    int k = children[n][i];
    if (connecting) {
      edgeColor[childEdge[n][i]] = 1 - edgeColor[childEdge[n][i]];
    }
    colorEdges(k);
  }
  if (n != 1)
    if (connecting) {
      edgeColor[parEdge[n]] = 1 - edgeColor[parEdge[n]];
    }
}
int main() {
  cin >> n >> m;
  vector<int> t;
  vis.reset();
  adj.assign(n + 1, t);
  parent.assign(n + 1, 0);
  parEdge.assign(n + 1, 0);
  children.assign(n + 1, t);
  childEdge.assign(n + 1, t);
  edges.assign(m + 1, {0, 0});
  edgeColor.assign(m + 1, 0);
  vertexVal.assign(n + 1, 0);
  adjEdge.assign(n + 1, t);
  int tot = 0;
  bool neg = false;
  for (int i = 1; i <= n; i++) {
    cin >> vertexVal[i];
    if (vertexVal[i] == -1)
      neg = true;
    else
      tot = (tot + vertexVal[i]) % 2;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    edges[i] = {a, b};
    adj[a].push_back(b);
    adjEdge[a].push_back(i);
    adj[b].push_back(a);
    adjEdge[b].push_back(i);
  }
  if (tot == 1 && !neg) {
    cout << -1 << endl;
    exit(0);
  } else if (tot == 1) {
    for (int i = 1; i <= n; i++) {
      if (vertexVal[i] == -1) {
        vertexVal[i] = 1;
        break;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (vertexVal[i] == -1) {
      vertexVal[i] = 0;
    }
  }
  buildTree(1);
  colorEdges(1);
  int ne = 0;
  for (int i = 0; i < m; i++) {
    ne += edgeColor[i];
  }
  cout << ne << endl;
  for (int i = 0; i < m; i++) {
    if (edgeColor[i]) {
      cout << i + 1 << endl;
    }
  }
}
