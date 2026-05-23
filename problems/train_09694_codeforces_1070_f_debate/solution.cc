#include <bits/stdc++.h>
using namespace std;
bool compare(const long long& a, const long long& b) { return a > b; }
int main() {
  int n;
  cin >> n;
  vector<long long> A;
  vector<long long> B;
  vector<long long> AB;
  vector<long long> NN;
  ;
  string str;
  long long pt;
  for (int i = 0; i < n; ++i) {
    cin >> str >> pt;
    if (str == "00") NN.push_back(pt);
    if (str == "01") B.push_back(pt);
    if (str == "10") A.push_back(pt);
    if (str == "11") AB.push_back(pt);
  }
  sort(NN.begin(), NN.end(), compare);
  sort(B.begin(), B.end(), compare);
  sort(A.begin(), A.end(), compare);
  if (A.size() < B.size() and (A.size() + AB.size()) * 2 < n) {
    while ((A.size() + AB.size()) * 2 < n and A.size() < B.size()) {
      if (!NN.empty()) {
        if (B[B.size() - 1] < NN[NN.size() - 1] and A.size() < B.size()) {
          B.pop_back();
        } else {
          NN.pop_back();
        }
      } else {
        B.pop_back();
      }
      --n;
    }
  } else if (B.size() < A.size() and (B.size() + AB.size()) * 2 < n) {
    while (B.size() < A.size() and (B.size() + AB.size()) * 2 < n) {
      if (!NN.empty()) {
        if (A[A.size() - 1] < NN[NN.size() - 1] and B.size() < A.size()) {
          A.pop_back();
        } else {
          NN.pop_back();
        }
      } else {
        A.pop_back();
      }
      --n;
    }
  }
  while (((B.size() + AB.size()) * 2 < n or (A.size() + AB.size()) * 2 < n) and
         !NN.empty()) {
    NN.pop_back();
    --n;
  }
  if ((A.size() + AB.size()) * 2 < n or (B.size() + AB.size()) * 2 < n) {
    cout << 0 << endl;
  } else {
    long long ans = 0;
    for (auto i : A) ans += i;
    for (auto i : B) ans += i;
    for (auto i : AB) ans += i;
    for (auto i : NN) ans += i;
    cout << ans << endl;
  }
  return 0;
}
