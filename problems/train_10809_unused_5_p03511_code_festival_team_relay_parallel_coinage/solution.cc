#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<queue>
using namespace std;
#define f(i,n) for(int i=0;i<(int)n;i++)
#define MOD 1000000009

int main(void){
	char a[200001];
	char b[200001];
	f(i, 200001){
		a[i] = 0;
		b[i] = 0;
	}
	int n, k;
	int p, q;
	int x, y;
	int z = 0;
	scanf("%d", &n);
	scanf("%s", a);
	scanf("%s", b);
	p = strlen(a);
	q = strlen(b);
	f(i, n){
		x = i % p;
		y = i % q;
		if (a[x] != b[y]){
			if (a[x] > b[y])z = 1;
			break;
		}
	}
	k = n;
	if (z == 0){
		while (z == 0){
			if (k%p == 0){
				z = 2;
				for (int i = 0; i < k / p; i++){
					for (int j = 0; j<p; j++)printf("%c", a[j]);
				}
				for (int i = 0; i < (n - k) / q; i++){
					for (int j = 0; j<q; j++)printf("%c", b[j]);
				}
			}
			k -= q;
		}
	}
	else{
		while (z == 1){
			if (k%q == 0){
				z = 2;
				for (int i = 0; i < k / q; i++){
					for (int j = 0; j<q; j++)printf("%c", b[j]);
				}
				for (int i = 0; i < (n - k) / p; i++){
					for (int j = 0; j<p; j++)printf("%c", a[j]);
				}
			}
			k -= p;
		}
	}

	return 0;
}