#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
typedef long long int ll;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000001
using namespace std;

struct Info{
	int cost,vocal,dance,looks;
};

int main(){

	int N,M,dp[301][301],maximum;
	char buf[32];
	Info info[301];

	while(true){
		if(scanf("%d %d",&N,&M) == EOF){
			break;
		}

		getchar();
		for(int i = 1; i <= N; i++){
			fgets(buf,31,stdin);
			scanf("%d %d %d %d",&info[i].cost,&info[i].vocal,&info[i].dance,&info[i].looks);
			getchar();
		}

		maximum = 0;

		for(int i = 0; i <= 2; i++){ //0.vocal 1.dance 2.looks

			for(int k = 0; k <= N; k++){
				for(int p = 0; p <= M; p++)dp[k][p] = 0;
			}

			for(int bydol = 1; bydol <= N; bydol++){

				for(int cost = M; cost >= 0; cost--){
					dp[bydol][cost] = dp[bydol-1][cost];
				}

				for(int cost = M; cost >= 0; cost--){
					for(int num = 1; info[bydol].cost*num <= cost; num++){
						switch(i){
						case 0:
							dp[bydol][cost] = max(dp[bydol][cost],dp[bydol][cost-info[bydol].cost*num]+info[bydol].vocal*num);
							break;
						case 1:
							dp[bydol][cost] = max(dp[bydol][cost],dp[bydol][cost-info[bydol].cost*num]+info[bydol].dance*num);
							break;
						case 2:
							dp[bydol][cost] = max(dp[bydol][cost],dp[bydol][cost-info[bydol].cost*num]+info[bydol].looks*num);
							break;
						}
					}
				}
			}

			for(int cost = M; cost >= 0; cost--){
				maximum = max(maximum,dp[N][cost]);
			}
		}

		printf("%d\n",maximum);
	}

	return 0;
}