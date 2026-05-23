#include <bits/stdc++.h>

int main(){

	double ans = 0, sum = 0;
	int n, x, d;
	scanf("%d%d%d", &n, &x, &d);
	
	sum = x * 2 * n + 1.0 * n * (2 * n - 1) * d;
	while(n){
		ans += sum * 0.5 / n;
		sum -= sum / n / n;
		--n;
	}
	printf("%.10lf\n", ans);

	return 0;
}