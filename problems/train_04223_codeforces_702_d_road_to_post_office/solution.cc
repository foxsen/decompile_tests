#include <bits/stdc++.h>
using namespace std;
long long D;
long long K;
long long CAR_TIME;
long long WALK_TIME;
long long FIX_TIME;
int main() {
  scanf("%lld %lld %lld %lld %lld", &D, &K, &CAR_TIME, &WALK_TIME, &FIX_TIME);
  long long time = min(K, D) * CAR_TIME + max(0LL, D - K) * WALK_TIME;
  long long blocks = D / K;
  long long rem = D % K;
  if (blocks == 0) {
    time = min(time, D * CAR_TIME);
  } else if (rem == 0) {
    time = min(time, (blocks - 1) * (FIX_TIME + K * CAR_TIME) + K * CAR_TIME);
  } else {
    time = min(time, (blocks - 1) * (FIX_TIME + K * CAR_TIME) + K * CAR_TIME +
                         rem * WALK_TIME);
    time = min(time, (blocks) * (FIX_TIME + K * CAR_TIME) + rem * CAR_TIME);
  }
  printf("%lld", time);
}
