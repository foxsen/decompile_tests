#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	int n;
	while(~scanf("%d", &n)) {
		const int K = 3;
		vector<int> v[K];
		rep(i, n) {
			int a;
			scanf("%d", &a);
			v[a % 3].push_back(a);
		}
		rep(k, 3)
			sort(v[k].begin(), v[k].end());
		int ans = 0;
		rer(first, 1, 2) if(!v[first].empty()) {
			vector<int> rem[3];
			rer(k, 1, 2) rem[k] = v[k];
			int sum = 1;
			rem[first].pop_back();
			sum += v[0].size();
			int r = first;
			while(!rem[r].empty()) {
				++ sum;
				rem[r].pop_back();
				(r += r) %= K;
			}
			if(!rem[3 - r].empty())
				++ sum;
			amax(ans, sum);
		}
		if(!v[0].empty())
			amax(ans, 1);
		printf("%d\n", ans);
	}
	return 0;
}