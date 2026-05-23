#include <bits/stdc++.h>
using namespace std;
inline int rei() {
  int x;
  cin >> x;
  return x;
}
inline long long rel() {
  long long x;
  cin >> x;
  return x;
}
inline string res() {
  string x;
  cin >> x;
  return x;
}
int A[500000];
int need[500001];
int needneed[500001];
void Calc() {
  int N = rei();
  int K = rei();
  int n = rei() - 1;
  int S = rei();
  int kind = 0;
  for (int i = 0; i < N; i++) {
    A[i] = rei();
  }
  for (int i = 0; i < S; i++) {
    int x = rei();
    if (need[x] == 0) {
      kind++;
    }
    need[x]++;
    needneed[x]++;
  }
  int p = 0;
  while (p < N && (kind > 0 || p < K)) {
    need[A[p]]--;
    if (need[A[p]] == 0) {
      kind--;
    }
    p++;
  }
  if (p == N && (kind > 0 || p < K)) {
    cout << -1 << endl;
    return;
  }
  if (N - p >= n * K) {
    cout << p - K << endl;
    int discard = p - K;
    if (discard == 0) {
      cout << endl;
      return;
    }
    for (int i = 0; i < p; i++) {
      if (needneed[A[i]] == 0) {
        cout << i + 1;
        discard--;
        if (discard == 0) {
          cout << endl;
          return;
        }
        cout << " ";
      } else {
        needneed[A[i]]--;
      }
    }
    return;
  }
  for (int i = 0; i < N; i++) {
    need[A[i]]++;
    if (need[A[i]] == 1) {
      kind++;
    }
    while (p < N && (kind > 0 || p - i - 1 < K)) {
      need[A[p]]--;
      if (need[A[p]] == 0) {
        kind--;
      }
      p++;
    }
    if (p == N && (kind > 0 || p - i - 1 < K)) {
      cout << -1 << endl;
      return;
    }
    if (i % K == K - 1) {
      if (N - p >= n * K - (i + 1)) {
        cout << p - K - (i + 1) << endl;
        int discard = p - K - (i + 1);
        if (discard == 0) {
          cout << endl;
          return;
        }
        for (int j = i + 1; j < p; j++) {
          if (needneed[A[j]] == 0) {
            cout << j + 1;
            discard--;
            if (discard == 0) {
              cout << endl;
              return;
            }
            cout << " ";
          } else {
            needneed[A[j]]--;
          }
        }
        return;
      }
    }
  }
  cout << -1 << endl;
}
int main(int argc, char** argv) {
  ios::sync_with_stdio(false), cin.tie(0);
  cout.tie(0);
  Calc();
  return 0;
}
