#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> myodd, myeven;
bool cmp(int a, int b) { return a > b; }
int main() {
  scanf("%d", &n);
  int tmp;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &tmp);
    sum += tmp;
    if (tmp % 2 == 0) {
      myeven.push_back(tmp);
    } else {
      myodd.push_back(tmp);
    }
  }
  sort(myeven.begin(), myeven.end(), cmp);
  sort(myodd.begin(), myodd.end(), cmp);
  int ans1 = 0;
  int len1 = myeven.size(), len2 = myodd.size();
  int i = 0, j = 0;
  for (; i < len1 && j < len2; ++i, ++j) {
    ans1 += myeven[i];
    ans1 += myodd[j];
  }
  if (i < len1) {
    ans1 += myeven[i];
  }
  if (j < len2) {
    ans1 += myodd[j];
  }
  int ans2 = 0;
  i = 0;
  j = 0;
  for (; i < len1 && j < len2; ++i, ++j) {
    ans2 += myodd[j];
    ans2 += myeven[i];
  }
  if (j < len2) {
    ans2 += myodd[j];
  }
  if (i < len1) {
    ans2 += myeven[i];
  }
  printf("%d\n", sum - max(ans1, ans2));
  return 0;
}
