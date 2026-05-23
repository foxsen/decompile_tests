#include <bits/stdc++.h>
using namespace std;
struct Node {
  string a, b;
};
bool operator<(Node a, Node b) {
  if (a.a != b.a) return a.a < b.a;
  return a.b < b.b;
}
set<Node> S;
int main() {
  Node N;
  int n;
  cin >> n;
  string a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    N.a = a;
    N.b = b;
    S.insert(N);
  }
  cout << S.size() << endl;
  return 0;
}
