
#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

typedef long long int ll;

ll max( ll p, ll q ) {
	if( p > q ) return p;
	return q;
}
ll solve(ll N);

int main(void) {

	ll N = 1;
	while(true) {
		cin >> N;
		if( N == 0 ) { break; }
		cout << solve(N) << endl;
	}

	return 0;
}

ll solve( ll N ) {

	ll ans = 0;
	map<int,ll> mp;	//mp[ID]=??\??£?????????
	map<int,ll> sum;
		mp[0] = -1;
		sum[0] = 0;

	for( int i = 0; i < N; i++ ) {

		int M, D, h, m, p;
		char e;

		scanf("%d/%d %d:%d %c %d", &M,&D,&h,&m,&e,&p);

		if( e == 'I' ) {
			mp[p] = m+60*h;
			if( mp.find(p) == mp.end() ) {
				//?????????ID
				sum[p] = 0;
			}
		} else {
			//??????
			//??°????????????????????§??´?????????
			if( p == 0 ) {
				//?\??\??????????
				for(auto it = mp.begin();it!=mp.end();++it){
					if( (*it).first == 0 || mp[(*it).first] < 0 ) { continue; }
					sum[(*it).first] += m+60*h - max( mp[p], mp[(*it).first] );
				}
			} else {
				//????????°???????????????
				if( mp[0] >= 0 ) {
					sum[p] += m+60*h - max( mp[p], mp[0] );
				}
			}
			mp[p] = -1;
		}

	}

	sum[0] = 0;
	for( auto it = sum.begin(); it != sum.end(); ++it ) {
		ans = max( (*it).second, ans );
	}

	return ans;

}