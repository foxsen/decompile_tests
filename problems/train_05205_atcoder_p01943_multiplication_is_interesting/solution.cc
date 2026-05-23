#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 100005

int N;
double K,S[SIZE],ruiseki[SIZE],table[SIZE];

int main(){

	scanf("%d %lf",&N,&K);

	ruiseki[0] = 0.0;

	for(int i = 1; i <= N; i++){

		scanf("%lf",&S[i]);
		if(S[i] == 0.0){
			printf("%d\n",N);
			return 0;
		}
		S[i] = log(S[i]);
		ruiseki[i] = S[i];
		ruiseki[i] += ruiseki[i-1];
	}
	if(K == 0){

		printf("0\n");
		return 0;
	}

	K = log(K);

	table[N] = ruiseki[N];

	for(int i = N-1; i >= 1; i--){

		table[i] = min(ruiseki[i],table[i+1]);
	}

	int ans = 0;
	int left,right,mid,R;

	for(int i = 1; i <= N; i++){

		left = i,right = N,mid = (left+right)/2;
		R = -1;

		while(left <= right){

			if(table[mid]-ruiseki[i-1] <= K){

				R = mid;
				left = mid+1;
			}else{

				right = mid-1;
			}
			mid = (left+right)/2;
		}

		if(R == -1)continue;
		ans = max(ans,R-i+1);
	}

	printf("%d\n",ans);

	return 0;
}

