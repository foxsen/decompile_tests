#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MaxN = 2e5;
typedef long long LL;

int n, l, r;
int a[MaxN + 5], lsk[MaxN + 5], rsk[MaxN + 5];

int main()
{
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d %d %d", &n, &l, &r);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1; i <= l; i++) lsk[a[i]]++;
		for(int i = l + 1; i <= n; i++) rsk[a[i]]++;
		int cost = 0;
		// match left and right socks with same color; no cost.
		for(int i = 1; i <= n; i++) {
			int tmp = min(lsk[i], rsk[i]);
			lsk[i] -= tmp;
			rsk[i] -= tmp;
			l -= tmp;
			r -= tmp;
		}
		// make l larger than r
		if(l < r) {
			swap(l, r);
			swap(lsk, rsk);
		}
		// match same type of socks with same color;
		// always need to turn (l-r) left to right;
		// turn the same color is optimal; 1 cost.
		for(int i = 1; i <= n; i++) {
			int gap = (l - r); 
			int ltor = min(lsk[i] / 2, gap / 2);
			lsk[i] -= ltor * 2;
			cost += ltor;
			l -= ltor * 2;
		}
		// printf("l = %d r = %d\n", l, r);
		// match rest of socks; 1 cost.
		int lsk_sum = 0, rsk_sum = 0;
		for(int i = 1; i <= n; i++) {
			lsk_sum += lsk[i];
			rsk_sum += rsk[i];
		}
		// printf("lsk_sum = %d rsk_sum = %d\n", lsk_sum, rsk_sum);
		// turn left socks color to match right socks, now right socks is 0.
		cost += rsk_sum;
		// change type ans turn color of left socks to match themself.
		cost += (lsk_sum - rsk_sum) / 2 * 2;
		printf("%d\n", cost);
		// clear
		for(int i = 1; i <= n; i++) {
			lsk[i] = 0;
			rsk[i] = 0;
		}
	}
	return 0;
}