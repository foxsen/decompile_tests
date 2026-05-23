#include <bits/stdc++.h>
using namespace std;
const int NMax = 101000;
struct node {
  vector<int> s;
} T[NMax * 8];
int N, nn, L;
pair<int, int> B[NMax];
vector<long long> LSH;
map<long long, int> ID;
vector<pair<int, pair<long long, long long> > > Q;
void insert(int a, int b, int c, int first, int second, int p) {
  if (a > b) return;
  if (a == first && b == second) {
    T[p].s.push_back(c);
    return;
  }
  int mid = (first + second) >> 1;
  if (mid >= b)
    insert(a, b, c, first, mid, p * 2);
  else if (mid < a)
    insert(a, b, c, mid + 1, second, p * 2 + 1);
  else {
    insert(a, mid, c, first, mid, p * 2);
    insert(mid + 1, b, c, mid + 1, second, p * 2 + 1);
  }
}
vector<int> calc(int a, int first, int second, int p) {
  if (first == second) {
    vector<int> ret = T[p].s;
    while (!T[p].s.empty()) T[p].s.pop_back();
    return ret;
  }
  int mid = (first + second) >> 1;
  if (a <= mid) {
    vector<int> ret = calc(a, first, mid, p * 2);
    for (int i = 0; i < (int)T[p].s.size(); i++) ret.push_back(T[p].s[i]);
    while (!T[p].s.empty()) T[p].s.pop_back();
    return ret;
  } else {
    vector<int> ret = calc(a, mid + 1, second, p * 2 + 1);
    for (int i = 0; i < (int)T[p].s.size(); i++) ret.push_back(T[p].s[i]);
    while (!T[p].s.empty()) T[p].s.pop_back();
    return ret;
  }
}
int father[NMax * 4];
int Find(int a) {
  int R;
  for (R = a; father[R] != -1; R = father[R])
    ;
  int tmp;
  while (father[a] != -1) {
    tmp = father[a];
    father[a] = R;
    a = tmp;
  }
  return R;
}
void Union(int a, int b) {
  int first = Find(a), second = Find(b);
  if (first == second) return;
  father[first] = second;
}
pair<long long, long long> A[NMax * 4];
int main() {
  memset(father, -1, sizeof(father));
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    int t;
    long long first, second;
    scanf("%d%lld%lld", &t, &first, &second);
    if (t == 1) {
      Q.push_back(make_pair(t, make_pair(first, second)));
      LSH.push_back(first);
      LSH.push_back(second);
    } else
      Q.push_back(make_pair(t, make_pair(first, second)));
  }
  sort(LSH.begin(), LSH.end());
  for (int i = 0; i < LSH.size(); i++)
    if (i == 0 || LSH[i] != LSH[i - 1]) ID[LSH[i]] = ++L;
  nn = 0;
  for (int i = 0; i < N; i++) {
    if (Q[i].first == 1) {
      Q[i].second.first = (long long)ID[Q[i].second.first];
      Q[i].second.second = (long long)ID[Q[i].second.second];
      nn++;
      A[nn] = make_pair(Q[i].second.first, Q[i].second.second);
    }
  }
  nn = 0;
  int j1 = 0;
  for (int i = 0; i < N; i++) {
    int first = (int)Q[i].second.first, second = (int)Q[i].second.second;
    int t = Q[i].first;
    if (t == 1) {
      nn++;
      vector<int> t1 = calc(first, 1, L, 1), t2 = calc(second, 1, L, 1);
      int leftmost = first, rightmost = second;
      for (int j = 0; j < (int)t1.size(); j++) {
        int x1 = t1[j], r1 = Find(x1);
        leftmost = min(leftmost, B[r1].first);
        rightmost = max(rightmost, B[r1].second);
        Union(nn, x1);
      }
      for (int j = 0; j < (int)t2.size(); j++) {
        int x1 = t2[j], r1 = Find(x1);
        leftmost = min(leftmost, B[r1].first);
        rightmost = max(rightmost, B[r1].second);
        Union(nn, x1);
      }
      int R = Find(nn);
      B[R] = make_pair(leftmost, rightmost);
      insert(leftmost + 1, rightmost - 1, R, 1, L, 1);
    } else {
      j1++;
      if (Find(first) == Find(second))
        puts("YES");
      else {
        int a = A[first].first, b = A[first].second, R = Find(second);
        if (B[R].first < a && B[R].second > a ||
            B[R].first < b && B[R].second > b)
          puts("YES");
        else
          puts("NO");
      }
    }
  }
  getchar();
  getchar();
  return 0;
}
