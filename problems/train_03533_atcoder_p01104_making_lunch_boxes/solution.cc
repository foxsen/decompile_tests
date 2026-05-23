#include <bits/stdc++.h>
using Int = int64_t;
const Int inf = 1LL << 53;

int main() {
   for(;;) {
      Int n, m;
      std::cin >> n >> m;
      if( n == 0 && m == 0 ) {
         break;
      }
      auto xss = std::vector<std::string>(n);
      for(Int i = 0; i < n; ++i) {
         std::string ss;
         std::cin >> ss;
         xss[i] = ss;
      }
      if( n <= 20 ) {
         Int res = 0;
         for(Int i = 0; i < (1<<n); ++i) {
            std::string ss(m, '0');
            Int num = 0;
            for(Int k = 0; k < n; ++k) {
               if( (i & (1 << k)) != 0 ) {
                  num += 1;
                  for(Int j = 0; j < m; ++j) {
                     ss[j] = ss[j] == xss[k][j] ? '0' : '1';
                  }
               }
            }
            bool valid = true;
            for(Int j = 0; j < m; ++j) {
               if( ss[j] != '0' ) {
                  valid = false;
               }
            }
            if( valid ) {
               res = std::max(res, num);
            }
         }
         std::cout << res << std::endl;
      }
      else {
         auto ys = std::vector<Int>(n);
         for(Int i = 0; i < n; ++i) {
            Int t = 0;
            for(Int k = 0; k < m; ++k) {
               if( xss[i][k] == '1' ) {
                  t |= 1 << k;
               }
            }
            ys[i] = t;
         }
         std::vector<Int> dp(1<<m, -inf);
         std::vector<Int> dp2(1<<m, -inf);
         dp[0] = 0;
         for(Int i = 0; i < n; ++i) {
            for(Int k = 0; k < 1<<m; ++k) {
               dp2[k] = std::max(dp[k], dp[k^ys[i]]+1);
            }
            std::swap(dp, dp2);
         }
         std::cout << dp[0] << std::endl;
      }
   }
}

