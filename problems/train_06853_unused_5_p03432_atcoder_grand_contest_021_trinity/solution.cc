#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast<t>(x)
#define AR(t) vector < t >
#define PII pair < int, int >
#define PLL pair < LL, LL >
#define PIL pair < int, LL >
#define PLI pair < LL, int >
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define PRF first
#define PRS second
#define INIT(ar,val) memset ( ar, val, sizeof ( ar ) )
#define lp(loop,start,end) for ( int loop = start; loop < end; ++loop )
#define lpd(loop,start,end) for ( int loop = start; loop > end; --loop )
#define lpi(loop,start,end) for ( int loop = start; loop <= end; ++loop )
#define lpdi(loop,start,end) for ( int loop = start; loop >= end; --loop )
#define qmax(a,b) (((a)>(b))?(a):(b))
#define qmin(a,b) (((a)<(b))?(a):(b))
#define qabs(a) (((a)>=0)?(a):(-(a)))

const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 8007;
const int MAXM = 207;
const int MOD = 998244353;
const int RT = 3;
const int MAXS = MAXN * 4;

int n, m;
int dp[MAXM][MAXN];
int a[MAXN], b[MAXN], ans[MAXN];
int ca[MAXS], cb[MAXS], cans[MAXS], rt[MAXS];
LL frac[MAXN], rf[MAXN];

void init ();
void input ();
void work ();

void mul ( int a[], int b[], int ans[] );
void fft ( LL ar[], int tn );



int add ( int x, int y )
{
	x += y;
	if ( x >= MOD ) x -= MOD;
	return x;
}

void addv ( int &x, int y )
{
	x += y;
	if ( x >= MOD ) x -= MOD;
}

int dec ( int x, int y )
{
	x -= y;
	if ( x < 0 ) x += MOD;
	return x;
}

void decv ( int &x, int y )
{
	x -= y;
	if ( x < 0 ) x += MOD;
}

int qpow ( int a, int b )
{
	LL base = a, ans = 1;
	while ( b ){
		if ( b & 1 ) ( ans *= base ) %= MOD;
		( base *= base ) %= MOD;
		b >>= 1;
	}
	return SC ( int, ans );
}

int C ( int n, int m )
{
	return SC ( int, frac[n] * rf[m] % MOD * rf[n-m] % MOD );
}



int main()
{
	init();
	input();
	work();
}



void init ()
{
	// Init Everything Here
	
	ios::sync_with_stdio ( false );
	
	frac[0] = 1;
	lp ( i, 1, MAXN ) frac[i] = frac[i-1] * i % MOD;
	rf[MAXN-1] = qpow ( frac[MAXN-1], MOD-2 ); 
	lpdi ( i, MAXN-2, 0 ) rf[i] = rf[i+1] * ( i + 1 ) % MOD;
}

void input ()
{
	// input method
	
	scanf ( "%d%d", &n, &m );
}

void work ()
{
	// main work
	
	dp[0][0] = 1;
	lpi ( i, 1, m ){
		lpi ( j, 0, n ) a[j] = dp[i-1][j] * rf[j] % MOD;
		lpi ( j, 1, n ) b[j] = rf[j+2];
		mul ( a, b, ans );
		lpi ( j, 0, n ) dp[i][j] = ans[j] * frac[j+2] % MOD;
		lpi ( j, 0, n ) addv ( dp[i][j], SC ( LL, dp[i-1][j] ) * add ( C ( j + 1, 2 ), 1 ) % MOD );
	}
	
	int ans = 0;
	lpi ( i, 0, n ) addv ( ans, SC ( LL, dp[m][i] ) * C ( n, i ) % MOD );
	
	cout << ans << endl;
}



void fft ( int ar[], int tn )
{
	for ( int i = 0, j = 0; i < tn; ++i ){
		if ( i > j ) swap ( ar[i], ar[j] );
		for ( int bt = tn >> 1; bt && ( ! ( ( j ^= bt ) & bt ) ); bt >>= 1 );
	}
	
	int m, x, y;
	for ( int i = 2; i <= tn; i <<= 1 ){
		m = i >> 1;
		for ( int j = 0; j < tn; j += i ){
			lp ( k, 0, m ){
				x = ar[j+k], y = SC ( LL, ar[j+k+m] ) * rt[tn/i*k] % MOD;
				ar[j+k] = add ( x, y );
				ar[j+k+m] = dec ( x, y );
			}
		}
	}
}

void mul ( int a[], int b[], int ans[] )
{
	int nn = n << 1;
	int tn = 1;
	while ( tn <= nn ) tn <<= 1;
	
	lpi ( i, 0, n ) ca[i] = a[i], cb[i] = b[i];
	lp ( i, n+1, tn ) ca[i] = cb[i] = 0;
	int nrt = qpow ( RT, ( MOD - 1 ) / tn );
	rt[0] = 1;
	lp ( i, 1, tn ) rt[i] = SC ( LL, rt[i-1] ) * nrt % MOD;
	fft ( ca, tn );
	fft ( cb, tn );
	lp ( i, 0, tn ) cans[i] = SC ( LL, ca[i] ) * cb[i] % MOD;
	nrt = qpow ( nrt, MOD-2 );
	rt[0] = 1;
	lp ( i, 1, tn ) rt[i] = SC ( LL, rt[i-1] ) * nrt % MOD;
	fft ( cans, tn );
	int rn = qpow ( tn, MOD-2 );
	lpi ( i, 0, n ) ans[i] = SC ( int, SC ( LL, cans[i] ) * rn % MOD );
}