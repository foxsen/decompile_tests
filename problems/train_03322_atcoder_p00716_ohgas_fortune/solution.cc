#include <cstdio>
#include <cstdlib>

int main(){
  int m;
  scanf( "%d", &m );
  for( int i = 0; i < m; i++ ) {
    int ini_fund;
    int y, n;
    int max_fund = 0;
    scanf( "%d%d%d", &ini_fund, &y, &n );
    for( int j = 0; j < n; j++ ) {
      int type;
      int a, b, cost;
      int sum = 0;
      double alpha;
      scanf( "%d%lf%d", &type, &alpha, &cost );
      a = ini_fund;
      for( int k = 0; k < y; k++ ){
        b = ( int )( a * alpha );
        if( type ) {
          a = a + b - cost;
        }else{
          sum += b;
          a -= cost;
        }
      }
      if( !type ){ a += sum; }
      max_fund = a > max_fund ? a : max_fund;
    }
    printf( "%d\n", max_fund );
  }
  return EXIT_SUCCESS;
}