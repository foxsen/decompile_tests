#include <cstdio>
using namespace std;

int ans;
bool f[100001];

void check(int k, int t, int u){
	if((t <= k && k <= u) || ((t + k - 1) / k < u / k)){
		if(!f[k]){
			f[k] = true;
			++ans;
		}
	}
	else if(f[k]){
		f[k] = false;
		--ans;
	}
}

int main(){
	int n, w;
	scanf("%d%d", &n, &w);
	
	for(int i = 1; i <= w; ++i){
		f[i] = true;
	}
	ans = w;
	
	for(int i = 1; i <= n - w + 1; ++i){
		printf("%d%c", ans, i == n - w + 1 ? '\n' : ' ');
		
		for(int j = 1; j * j <= i; ++j){
			if(i % j == 0){
				check(j, i + 1, i + w);
				check(i / j, i + 1, i + w);
			}
		}
		for(int j = 1; j * j <= i + w; ++j){
			if((i + w) % j == 0){
				check(j, i + 1, i + w);
				check((i + w) / j, i + 1, i + w);
			}
		}
	}
}