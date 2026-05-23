
#include <bits/stdc++.h>

#define PB          push_back
#define PF          push_front
#define MP          make_pair
#define FI          first
#define SE          second
#define SIZE( A )   int( ( A ).size( ) )
#define ALL( A )    ( A ).begin( ), ( A ).end( )
#define ALLR( A )   ( A ).rbegin( ), ( A ).rend( )

using namespace std;

typedef long long           ll;
typedef unsigned long long  ull;
typedef long double         lf;
typedef pair< int, int >    pii;
typedef pair< ll, ll >      pll;
typedef vector< bool >      vb;
typedef vector< lf >        vd;
typedef vector< ll >        vll;
typedef vector< int >       vi;
typedef vector< pii >       vpii;

const int MAXN = int( 1e5 )+10;
const int MOD  = int( 360 );
const int oo   = INT_MAX;
const lf EPS = 1e-9;

struct pt {
  lf x, y;
  pt( ) { }
  pt( lf x, lf y ) : x( x ), y ( y ) { }
};

inline lf x( pt P ) { return P.x; }
inline lf y( pt P ) { return P.y; }

istream& operator >> ( istream& in, pt& p ) {
  lf x,y; in >> x >> y;
  p = pt(x,y); return in;
}

ostream& operator << ( ostream& out, const pt& p ) {
  out << double(p.x) << " " << double(p.y);
  return out;
}

pt operator + ( const pt& A, const pt& B ) {
  return pt( x(A)+x(B), y(A)+y(B) );
}

pt operator - ( const pt& A, const pt& B ) {
  return pt( x(A)-x(B), y(A)-y(B) );
}

pt operator * ( const lf& B, const pt& A ) {
  return pt( x(A)*B, y(A)*B );
}

pt operator * ( const pt& A, const lf& B ) {
  return pt( x(A)*B, y(A)*B  );
}

inline lf norm( pt A ) {
  return x(A)*x(A) + y(A)*y(A);
}

inline lf abs( pt A ) {
  return sqrt( norm(A) );
}

inline bool same ( lf a, lf b ) {
  return a+EPS > b && b+EPS > a;
}

inline lf dist ( pt A, pt B ) { return norm( B - A ); }

int n;
pt P[ MAXN ], extra[ MAXN ];

bool cmpX( const pt &A, const pt &B ) {
  return A.x < B.x;
}

lf sqr( lf x ) {
  return x*x;
}

void merge( int f, int m, int t ){
	int total = t - f + 1;
	for( int i = 0, l = f, r = m+1; i < total; ++i ){
		if( l == m+1 ){
      extra[ i ] = P[ r++ ];
		}
		else if( r == t+1 ){
		  extra[ i ] = P[ l++ ];
		}
		else if( P[l].y < P[r].y ){
		  extra[ i ] = P[ l++ ];
		}
		else{
		  extra[ i ] = P[ r++ ];
		}
	}
	for( int i = 0; i < total; ++i ){
    P[ f+i ] = extra[ i ];
	}
}

lf solve( int f, int t ) {
  if( f == t ) return oo;
	int mi = (f + t)/2;
	lf mx = P[ mi ].x;
	lf d = min( solve( f, mi ), solve( mi+1, t ) );
	merge( f, mi, t );
	vector< int > idxs;
	for( int i = f; i <= t; ++i ){
		if( sqr(mx - P[i].x) < d ) idxs.push_back( i );
	}
	for( int i = 0; i < idxs.size(); ++i ){
		for( int j = i+1; j < idxs.size() && sqr(P[ idxs[i] ].y - P[ idxs[j] ].y) < d; ++j ){
			d = min( d, dist( P[ idxs[i] ], P[ idxs[j] ] ) );
		}
	}
	return d;
}

int main( ) {

  #ifdef LOCAL
    freopen( "CGL_5_A-in25.txt", "r", stdin );
    //freopen( "output", "w", stdout );
  #else
    //freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
  #endif
  cout << fixed << setprecision( 10 );
  cin >> n;
  for( int i = 0; i < n; ++i ) {
    cin >> P[i];
  }
  sort( P, P+n, cmpX );
  cout << double( sqrt(solve( 0, n-1 )) ) << '\n';
  return 0;
}