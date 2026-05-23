#include <cstdio>

int n;
int A[21];

constexpr int mod = 1000000007;

int dp[1<<21];

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      int x;
      scanf("%d", &x);
      if(x) A[i] |= 1 << j;
    }
  }

  dp[0] = 1;
  for(int x = 1; x < (1<<n); x++){
    int i = __builtin_popcount(x);
    long long int r = 0;
    for(int y = x & A[i-1]; y; y &= y-1){
      int j = y & -y;
      r += dp[x & ~j];
    }
    dp[x] = r % mod;
  }
  printf("%d\n", dp[(1<<n)-1]);
  return 0;
}
