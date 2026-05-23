#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
	if(a < b)
		swap(a, b);
		
	if(b == 0)
		return a;
		
	return gcd(b, a % b);
}

int lcm(int a, int b)
{
	int div = gcd(a, b);
	
	return a / div * b;
}

struct mobile {

	int p, q, r, b;
	mobile() {}
	mobile(int p, int q, int r, int b) : p(p), q(q), r(r), b(b) {}
};

int calc(int k, vector<mobile> &m) {

	if(k == -1)
		return 1;

	mobile x = m[k];
	
	int lw, rw;
	
	lw = calc(x.r - 1, m);
	rw = calc(x.b - 1, m);
	
	int div = gcd(x.p, x.q);
	x.p = x.p / div;
	x.q = x.q / div;
	
	//x.p * lw * a = x.q * rw * b
	int sum = lcm(x.p * lw, x.q * rw);
	int ans = sum / x.p + sum / x.q;
	
	//printf("[debug] %d -> %d\n", k, ans);
	
	return ans;
}

int main()
{
	while(true) {
	
		int n;
		
		scanf("%d", &n);
		if(n == 0)
			break;
			
		vector<mobile> m;
		
		m.resize(n);
		
		for(int i = 0; i < n; ++i)
			scanf("%d%d%d%d", &m[i].p, &m[i].q, &m[i].r, &m[i].b);
		
		bool middle[128] = {false};
		int top = -1;
		
		for(int i = 0; i < n; ++i)
			middle[m[i].r] = middle[m[i].b] = true;
		middle[0] = true;
		for(int i = 0; i <= n; ++i) {
			if(!middle[i]) {
				top = i - 1;
				break;
			}	
		}
		
		int ans = calc(top, m);
		
		printf("%d\n", ans);
	}

	return 0;
}