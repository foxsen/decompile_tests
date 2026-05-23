#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e6 + 5 ; 
const int P = 1e9 + 7 ; 
int a, b, c, n, m, Ans, fac[N], inv[N] ; 
int fpow( int x, int k ) {
	int ans = 1, base = x ;
	while(k) {
		if( k & 1 ) ans = ans * base % P ; 
		base = base * base % P, k >>= 1 ; 
	} return ans % P ; 
}
int C( int x, int y ) {
	if( y > x || x < 0 || y < 0 ) return 0 ; 
	return fac[x] * inv[y] % P * inv[x - y] % P ; 
}
signed main()
{
	a = gi(), b = gi(), c = gi() ; 
	n = a + b + c, fac[0] = inv[0] = 1 ; 
	rep( i, 1, n ) fac[i] = fac[i - 1] * i % P, inv[i] = fpow( fac[i], P - 2 ) ;
	int f = 1, l = - c ; -- a ; 
	for( re int i = a; i < n; ++ i ) {
		int x = i - a ; 
		if( l > b ) break ; 
		Ans = ( Ans + f * C( i, a ) % P * fpow( 3, n - i - 1 ) % P ) % P ;
		f = ( f * 2 + P - C( x, b ) + P - C( x, l ) ) % P, ++ l ; 
	}
	printf("%lld\n", Ans % P ) ;
	return 0 ;
}