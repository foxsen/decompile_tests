#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;

int main(){
	double d;
	while(cin>>d,d){
		for(int i = 1; i < 1000000; i++){
			int x = M_PI * i;
			double y = (double) x / i;
			if(abs(y - M_PI) < d){
				printf("%d/%d\n",x,i);
				break;
			}
			y = (double)(x+1)/i;
			if(abs(y - M_PI) < d){
				printf("%d/%d\n",x+1,i);
				break;
			}
		}
	}

	return 0;
}