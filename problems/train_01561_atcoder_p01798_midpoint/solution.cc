#include <bits/stdc++.h>
using namespace std;
using lld = int64_t;
using I128 = __int128;
typedef long long ll;
using pII = pair<I128,I128>;
using pll = pair<ll,ll>;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef complex<double> cplex;
const double pi=acos(-1);
const int INF = 500000;
const int N = 100000 + 5;

int l, m, n;

pair< int, int > a[ N ], b[ N ], c[ N ];

void init() {
	cin >> l >> m >> n;
	for ( int i = 0 ; i < l ; ++ i )
		cin >> a[ i ].first >> a[ i ].second;
	for ( int i = 0 ; i < m ; ++ i )
		cin >> b[ i ].first >> b[ i ].second;
	for ( int i = 0 ; i < n ; ++ i )
		cin >> c[ i ].first >> c[ i ].second;
}

void solve_brute() {
	map< pair< int, int >, lld > cntA, cntB;
	for ( int i = 0 ; i < l ; ++ i )
		cntA[ a[ i ] ] ++;
	for ( int i = 0 ; i < m ; ++ i )
		cntB[ b[ i ] ] ++;

	lld ans = 0;

	lld a0x = a[ 0 ].first, a0y = a[ 0 ].second;
	lld b0x = b[ 0 ].first, b0y = b[ 0 ].second;
	lld dax = a[ 1 ].first - a[ 0 ].first;
	lld day = a[ 1 ].second - a[ 0 ].second;
	lld dbx = b[ 1 ].first - b[ 0 ].first;
	lld dby = b[ 1 ].second - b[ 0 ].second;

	for ( int i = 0 ; i < n ; ++ i ) {
		lld cx = 2 * c[ i ].first, cy = 2 * c[ i ].second;
		cx -= a0x + b0x;
		cy -= a0y + b0y;

		lld det = dax * dby - dbx * day;
		lld ma = cx * dby - cy * dbx;
		lld mb = cy * dax - cx * day; 

		// cout << "MA = " << ma << '\n';
		// cout << "MB = " << mb << '\n';
		// cout << "DAX = " << dax <<'\n';
		// cout << "DAY = " << day << '\n';
		// cout << "DBX = " << dbx << '\n';
		// cout << "DBY = " << dby << '\n';
		// cout << "DET = " << det << '\n';

		if ( ( ma * dax ) % det != 0 ) continue;
		if ( ( ma * day ) % det != 0 ) continue;
		if ( ( mb * dbx ) % det != 0 ) continue;
		if ( ( mb * dby ) % det != 0 ) continue;

		// cout << "JIZZ\n";

		lld ax = a0x + ma * dax / det, ay = a0y + ma * day / det;
		lld bx = b0x + mb * dbx / det, by = b0y + mb * dby / det;

		ans += cntA[ { ax, ay } ] * cntB[ { bx, by } ];
	}
	cout << ans << '\n';
}

map<pair<int,int>,int> adic,bdic,cdic;
inline ll cross(pll o,pll a,pll b){
	return (a.first-o.first)*(b.second-o.second)-(a.second-o.second)*(b.first-o.first);
}
inline ll cross(pll v1,pll v2,pll v3,pll v4){
	return (v2.first-v1.first)*(v4.second-v3.second)-(v2.second-v1.second)*(v4.first-v3.first);
}

using wtf = pair< pII, pII >;

inline wtf get_point(pll v1,pll v2,pll v3,pll v4){
	ll a1=cross(v3,v1,v4),a2=cross(v3,v4,v2);
	// cout<<"a1="<<a1<<",a2="<<a2<<'\n';
	// double x=(double)(v1.first*a2+v2.first*a1)/(a1+a2);
	// double y=(double)(v1.second*a2+v2.second*a1)/(a1+a2);
	return wtf( {(v1.first*a2+v2.first*a1), (a1+a2)}, {(v1.second*a2+v2.second*a1),(a1+a2)} );
}
inline double dist(pii v1,pii v2){
	return sqrt((ll)(v1.first-v2.first)*(v1.first-v2.first)+(ll)(v1.second-v2.second)*(v1.second-v2.second));
}
inline int rev_bit(int bit,int len){
	int rev=0;
	for(int i=0;(1<<i)<len;i++){
		rev<<=1;
		if((1<<i)&bit) rev|=1;
	}
	return rev;
}
bool fin[1200040];
void exec_fft(cplex* f,int len,int o){
	for(int i=0;i<len;i++) fin[i]=false;
	for(int i=0;i<len;i++){
		if(!fin[i]){
			int rev=rev_bit(i,len);
			fin[rev]=fin[i]=true;
			swap(f[rev],f[i]);
		}
	}
	for(int s=2;s<=len;s<<=1){
		cplex mul=cplex(cos(2*pi*o/s),sin(2*pi*o/s));
		for(int j=0;j<len;j+=s){
			cplex e=cplex(1,0);
			for(int k=0;k<(s>>1);k++){
				cplex t=f[j+k+(s>>1)]*e;
				cplex u=f[j+k];
				f[j+k]=u+t;
				f[j+k+(s>>1)]=u-t;
				e*=mul;
			}
		}
	}
	if(o==-1){
		for(int i=0;i<len;i++)
			f[i]/=(double)len;
	}
}
cplex f[1200040],g[1200040];
ll solve_pp(){

	if(cross(a[0],a[1],c[0],c[1])==0){
		// cout<<"WTFFF\n";
		double d1=abs(cross(a[0],c[0],c[1]))/dist(c[0],c[1]);
		double d2=abs(cross(b[0],c[0],c[1]))/dist(c[0],c[1]);
		if(abs(d1-d2)<1e-10){
			// cout << "JIZZ\n";

			if ( a[ 0 ].first != a[ 1 ].first ) {

				for(int i=0;i<l;i++)
					f[a[i].first+100000]=cplex(f[a[i].first+100000].real()+1,0);
				for(int i=0;i<m;i++)
					g[b[i].first+100000]=cplex(g[b[i].first+100000].real()+1,0);
				int sz=1;
				while(sz<=(400005)) sz<<=1;
				exec_fft(f,sz,1);
				exec_fft(g,sz,1);
				for(int i=0;i<sz;i++)
					f[i]*=g[i];
				exec_fft(f,sz,-1);
				ll ret=0;

				// for ( int i = 0 ; i < sz ; ++ i ) {
				// 	if ( static_cast< int >( floor(f[i].real()+0.3) ) ) {
				// 		cout << i << " meow\n";
				// 	}
				// }

				for(int i=0;i<n;i++){
					ret+=floor(f[c[i].first*2+200000].real()+0.3);
				}
				return ret;
			} else {
				for(int i=0;i<l;i++)
					f[a[i].second+100000]=cplex(f[a[i].second+100000].real()+1,0);
				for(int i=0;i<m;i++)
					g[b[i].second+100000]=cplex(g[b[i].second+100000].real()+1,0);
				int sz=1;
				while(sz<=(400005)) sz<<=1;
				exec_fft(f,sz,1);
				exec_fft(g,sz,1);
				for(int i=0;i<sz;i++)
					f[i]*=g[i];
				exec_fft(f,sz,-1);
				ll ret=0;

				// for ( int i = 0 ; i < sz ; ++ i ) {
				// 	if ( static_cast< int >( floor(f[i].real()+0.3) ) ) {
				// 		cout << i << " meow\n";
				// 	}
				// }

				for(int i=0;i<n;i++){
					ret+=floor(f[c[i].second*2+200000].real()+0.3);
				}
				return ret;
			}
		}else{
			return 0;
		}
	}else{
		// cout << "Obov\n";
		wtf x=get_point(a[0],a[1],c[0],c[1]);
		wtf y=get_point(b[0],b[1],c[0],c[1]);

		// cout << "("<<x.first.first<<"/"<<x.first.second<<","<<x.second.first<<"/"<<x.second.second<<")\n";
		// cout << "("<<y.first.first<<"/"<<y.first.second<<","<<y.second.first<<"/"<<y.second.second<<")\n";

		wtf z = wtf(
		{
			x.first.first*y.first.second+y.first.first*x.first.second,
			x.first.second*y.first.second
		},
		{
			x.second.first*y.second.second+x.second.second*y.second.first,
			x.second.second*y.second.second
		} );

		// pdd z=pdd((x.first+y.first),(x.second+y.second));
		for(int i=0;i<l;i++)
			adic[a[i]]++;
		for(int i=0;i<m;i++)
			bdic[b[i]]++;
		for(int i=0;i<n;i++)
			cdic[c[i]]++;
		ll ret=0;
		for(auto it=adic.begin();it!=adic.end();it++) {

			if ( ( z.first.first - it->first.first * z.first.second ) % z.first.second )
				continue;
			if ( ( z.second.first - it->first.second * z.second.second ) % z.second.second )
				continue;

			ret+=(ll)it->second*bdic[{ static_cast<lld>( z.first.first - it->first.first * z.first.second ) / z.first.second, static_cast<lld>( z.second.first - it->first.second * z.second.second ) / z.second.second }];
		}
		return ret;
	}
}

void solve_pin() {
	// cout << "MEOW\n";
	cout << solve_pp() << '\n';
}

void solve() {

	sort( a, a + l );
	sort( b, b + m );
	sort( c, c + m );

	if ( a[ l - 1 ] == a[ 0 ] and b[ m - 1 ] == b[ 0 ] ) {
		map< pair< int, int >, int > cnt;
		for ( int i = 0 ; i < n ; ++ i )
			cnt[ c[ i ] ]++;
		int dx = ( a[ 0 ].first + b[ 0 ].first );
		int dy = ( a[ 0 ].second + b[ 0 ].second );
		if ( ( dx & 1 ) or ( dy & 1 ) ) {
			cout << 0 << '\n';
		} else {
			dx >>= 1, dy >>= 1;
			cout << static_cast< lld >( cnt[ { dx, dy } ] ) * l * m << '\n';
		}
		return;
	} else if ( b[ m - 1 ] == b[ 0 ] and c[ n - 1 ] == c[ 0 ] ) {
		map< pair< int, int >, int > cnt;
		for ( int i = 0 ; i < l ; ++ i )
			cnt[ a[ i ] ]++;
		int dx = 2 * c[ 0 ].first - b[ 0 ].first;
		int dy = 2 * c[ 0 ].second - b[ 0 ].second;
		cout << static_cast< int >( cnt[ { dx, dy } ] ) * m * n << '\n';
		return;
	} else if ( c[ n - 1 ] == c[ 0 ] and a[ l - 1 ] == a[ 0 ] ) {
		map< pair< int, int >, int > cnt;
		for ( int i = 0 ; i < m ; ++ i )
			cnt[ b[ i ] ]++;
		int dx = 2 * c[ 0 ].first - a[ 0 ].first;
		int dy = 2 * c[ 0 ].second - a[ 0 ].second;
		cout << static_cast< int >( cnt[ { dx, dy } ] ) * n * l << '\n';
		return;
	}

	if ( a[ l - 1 ] == a[ 0 ] ) {
		a[ l ++ ] = { INF, INF };
	} else if ( b[ m - 1 ] == b[ 0 ] ) {
		b[ m ++ ] = { INF, INF };
	} else if ( c[ n - 1 ] == c[ 0 ] ) {
		c[ n ++ ] = { INF, INF };
	}

	swap( a[ 1 ], a[ l - 1 ] );
	swap( b[ 1 ], b[ m - 1 ] );
	swap( c[ 1 ], c[ n - 1 ] );


	const lld ax = ( a[ 0 ].first - a[ 1 ].first );
	const lld ay = ( a[ 0 ].second - a[ 1 ].second );

	const lld bx = ( b[ 0 ].first - b[ 1 ].first );
	const lld by = ( b[ 0 ].second - b[ 1 ].second );

	if ( ax * by - bx * ay == 0 ) {
		solve_pin();
	} else {
		solve_brute();
	}
}

int main() {
	ios_base::sync_with_stdio( false );
	cin.tie( nullptr );
	init(); solve();
	return 0;
}
