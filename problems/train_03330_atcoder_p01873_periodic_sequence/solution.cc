#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, S[200000];

  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d", &S[i]);
  }

  for(int i = 1; i <= N; i++) {
    if(N % i == 0) {
      bool match = true;
      for(int j = i; j < N; j += i) {
        for(int k = 0; k < i; k++) match &= S[k] == S[j + k];
      }
      if(match) {
        printf("%d\n", N / i);
        return (0);
      }
    }
  }
}