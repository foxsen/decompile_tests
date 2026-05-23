#include <bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b){
	if(b == 0){
		return a;
	}
	else{
		return gcd(b, a % b);
	}
}

int lcm(int a, int b){
	return (a / gcd(a, b)) * b;
}

signed main(){
	int N, M, i;
	scanf("%lld%lld", &N, &M);
	vector<int> a(N);
	for(i = 0; i < N; i++){
		scanf("%lld", &a[i]);
		a[i] /= 2;
	}
	int L = 1;
	for(i = 0; i < N; i++){
		L = lcm(L, a[i]);
		if(L > M){
			printf("0\n");
			return 0;
		}
	}
	for(i = 0; i < N; i++){
		if((L / a[i]) % 2 == 0){
			printf("0\n");
			return 0;
		}
	}
	printf("%lld\n", (M + L) / (2 * L));
	return 0;
}