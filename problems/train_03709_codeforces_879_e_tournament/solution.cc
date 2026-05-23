#include <bits/stdc++.h>
using namespace std;
int N, K;
struct Node {
  int mx[10], mn[10];
  int sz;
  bool operator<(const Node &b) const {
    for (int i = 0; i < K; i++) {
      if (mn[i] < b.mx[i]) {
        return true;
      }
    }
    return false;
  }
  bool operator>(const Node &b) const {
    for (int i = 0; i < K; i++) {
      if (mx[i] > b.mn[i]) {
        return true;
      }
    }
    return false;
  }
};
int main() {
  cin >> N >> K;
  set<Node> st;
  for (int i = 0; i < N; i++) {
    Node tmp;
    tmp.sz = 1;
    for (int j = 0; j < K; j++) {
      cin >> tmp.mn[j];
      tmp.mx[j] = tmp.mn[j];
    }
    for (auto it = st.lower_bound(tmp); it != st.begin();
         it = st.lower_bound(tmp)) {
      it--;
      if ((*it) > tmp) {
        for (int j = 0; j < K; j++) {
          tmp.mn[j] = min(tmp.mn[j], it->mn[j]);
          tmp.mx[j] = max(tmp.mx[j], it->mx[j]);
        }
        tmp.sz += it->sz;
        st.erase(it);
      } else {
        break;
      }
    }
    st.insert(tmp);
    cout << (--st.end())->sz << endl;
  }
  return 0;
}
