#include <bits/stdc++.h>
using namespace std;
struct seg {
  long long l, r, id;
  bool operator<(const seg &t) const {
    if (r != t.r) return r < t.r;
    return l < t.l;
  }
};
struct my_pair {
  long long first;
  int second;
  bool operator==(const my_pair &t) const { return (first == t.first); }
  bool operator<(const my_pair &t) const { return first < t.first; }
};
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  n--;
  vector<seg> segs;
  long long last_l, last_r;
  scanf("%lld %lld", &last_l, &last_r);
  vector<int> answer(n);
  for (int i = 0; i < n; ++i) {
    long long l, r;
    scanf("%lld %lld", &l, &r);
    seg add = {l - last_r, r - last_l, i};
    segs.push_back(add);
    last_l = l, last_r = r;
  }
  sort(segs.begin(), segs.end());
  multiset<my_pair> bridges;
  multiset<my_pair>::iterator it;
  for (int i = 0; i < m; ++i) {
    my_pair add;
    scanf("%lld", &add.first);
    add.second = i + 1;
    bridges.insert(add);
  }
  for (int i = 0; i < n; ++i) {
    my_pair check = {segs[i].l, 0};
    it = bridges.lower_bound(check);
    if (it == bridges.end() || (*it).first > segs[i].r) {
      printf("No\n");
      return 0;
    }
    answer[segs[i].id] = (*it).second;
    bridges.erase(it);
  }
  printf("Yes\n");
  for (int i = 0; i < answer.size(); ++i)
    printf("%d%c", answer[i], " \n"[i == answer.size() - 1]);
}
