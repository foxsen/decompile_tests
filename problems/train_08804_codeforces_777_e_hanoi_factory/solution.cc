#include <bits/stdc++.h>
using namespace std;
const int INFTY = 20000000;
const int MAX = 500100;
const int MOD = 10000000;
void coutTab(long long* tab, int n) {
  for (int i = 0; i < n; i++) {
    cout << tab[i] << " ";
  }
  cout << "\n";
}
struct el {
  long long a, b, h;
};
el me(long long a, long long b, long long h) {
  el e;
  e.a = a;
  e.b = b;
  e.h = h;
  return e;
}
bool sortEls(el a, el b) {
  if (a.b == b.b)
    return a.a > b.a;
  else
    return a.b > b.b;
}
bool sortElsByA(el a, el b) { return a.a < b.a; }
bool sortElsByB(el a, el b) { return a.b < b.b; }
el els[MAX];
long long dp[MAX];
int n;
int D;
long long tree[4 * MAX];
void renumber() {
  vector<long long> nums;
  for (int i = 0; i < n; i++) {
    nums.push_back(els[i].a);
    nums.push_back(els[i].b);
  }
  sort((nums).begin(), (nums).end());
  nums.erase(unique((nums).begin(), (nums).end()), nums.end());
  sort(els, els + n, sortElsByA);
  int j = 0;
  for (int i = 0; i < n; i++) {
    while (nums[j] < els[i].a) j++;
    els[i].a = j + 1;
  }
  sort(els, els + n, sortElsByB);
  j = 0;
  for (int i = 0; i < n; i++) {
    while (nums[j] < els[i].b) j++;
    els[i].b = j + 1;
  }
}
void countD() {
  D = 1;
  while (D <= els[0].b) D *= 2;
}
void update(int i, long long v) {
  i = i + D;
  tree[i] = max(tree[i], v);
  i = i / 2;
  while (i > 0) {
    tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    i = i / 2;
  }
}
long long read(int L, int R) {
  L += D;
  R += D;
  long long maxi = 0;
  while (L < R) {
    if (L % 2 == 1) maxi = max(maxi, tree[L]);
    if (R % 2 == 0) maxi = max(maxi, tree[R]);
    L = (L + 1) / 2;
    R = (R - 1) / 2;
  }
  maxi = max(maxi, tree[L]);
  return maxi;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> els[i].a >> els[i].b >> els[i].h;
  }
  renumber();
  sort(els, els + n, sortEls);
  countD();
  dp[0] = els[0].h;
  update(els[0].a, els[0].h);
  for (int i = 1; i < n; i++) {
    dp[i] = read(0, els[i].b - 1);
    dp[i] += els[i].h;
    update(els[i].a, dp[i]);
  }
  long long maxi = 0;
  for (int i = 0; i < n; i++) {
    maxi = max(maxi, dp[i]);
  }
  cout << maxi << "\n";
}
