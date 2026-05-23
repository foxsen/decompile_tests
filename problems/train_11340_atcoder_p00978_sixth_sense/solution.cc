#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 10005

int N;
int P[5005],F[5005];
vector<int> V;
int P_table[NUM],F_table[NUM];
int P_TMP[NUM],F_TMP[NUM];

int calc(){

	for(int i = 0; i < NUM; i++){

		P_TMP[i] = P_table[i];
		F_TMP[i] = F_table[i];
	}

	int P_num = 1,F_num = 2;
	int ret = 0;

	while(true){

		while(P_num < NUM && P_TMP[P_num] == 0)P_num++;
		while(F_num < NUM && (P_num >= F_num || F_TMP[F_num] == 0))F_num++;

		if(F_num == NUM)break;

		while(F_TMP[F_num] > 0 && P_TMP[P_num] > 0){
			F_TMP[F_num]--;
			P_TMP[P_num]--;
			ret++;
		}
	}

	return ret;
}

int main(){

	for(int i = 0; i < NUM; i++){

		P_table[i] = 0;
		F_table[i] = 0;
	}

	scanf("%d",&N);

	for(int i = 0; i < N; i++){

		scanf("%d",&P[i]);
		P_table[P[i]] += 1;
	}

	for(int i = 0; i < N; i++){

		scanf("%d",&F[i]);
		F_table[F[i]] += 1;
		V.push_back(F[i]);
	}

	int max_num = calc();

	sort(V.begin(),V.end());

	queue<int> ANS;
	int num_larger = 0;
	int left,right,mid,this_value,tmp_larger,index;

	for(int i = 0; i < N; i++){

		this_value = -1;
		left = 0,right = V.size()-1,mid = (left+right)/2;

		while(left <= right){

			F_table[V[mid]] -= 1;
			P_table[P[i]] -= 1;

			tmp_larger = calc();

			F_table[V[mid]] += 1;
			P_table[P[i]] += 1;

			if(V[mid] <= P[i]){

				if(num_larger+tmp_larger == max_num){

					this_value = V[mid];
					index = mid;

					left = mid+1;
				}else{

					if(V[V.size()-1] <= P[i]){

						right = mid-1;

					}else{

						left = mid+1;
					}
				}

			}else{

				if(num_larger+tmp_larger+1 == max_num){

					this_value = V[mid];
					index = mid;
					left = mid+1;

				}else{

					right = mid-1;
				}
			}
			mid = (left+right)/2;
		}

		ANS.push(this_value);

		if(this_value > P[i]){

			num_larger++;
		}
		F_table[this_value] -= 1;
		P_table[P[i]] -= 1;
		V.erase(V.begin()+index);
	}

	printf("%d",ANS.front());
	ANS.pop();

	while(!ANS.empty()){

		printf(" %d",ANS.front());
		ANS.pop();
	}
	printf("\n");

	return 0;
}

