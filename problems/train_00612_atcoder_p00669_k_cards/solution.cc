#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define PRIME1 99999883
#define PRIME2 99999893
#define EPS 0.00000001
using namespace std;

int N,K;

void func(){

	int baseTable[N],baseValue = 0;
	for(int i = 0; i < N; i++){
		scanf("%d",&baseTable[i]);
	}

	int tmp = 1,pre;
	for(int p = 0; p < K; p++){
		tmp *= baseTable[p];
	}
	baseValue = tmp;
	pre = tmp;

	for(int i = 1; i <= N-K; i++){
		tmp = (pre/baseTable[i-1])*baseTable[i+K-1];
		baseValue = max(baseValue,tmp);
		pre = tmp;
	}

	int nextValue = 0,tmpValue;
	//???????????§??§??????????????§????????????????????£???????????§?????????????????¨?????????????????¨??¢?´¢
	for(int a = 0; a < N-1; a++){
		for(int b = a+1; b < N; b++){
			swap(baseTable[a],baseTable[b]);

			tmp = 1;
			for(int p = 0; p < K; p++){
				tmp *= baseTable[p];
			}
			tmpValue = tmp;
			pre = tmp;

			for(int i = 1; i <= N-K; i++){
				tmp = (pre/baseTable[i-1])*baseTable[i+K-1];
				tmpValue = max(tmpValue,tmp);
				pre = tmp;
			}

			nextValue = max(nextValue,tmpValue);
			swap(baseTable[a],baseTable[b]); //????????????
		}
	}

	if(nextValue < baseValue){
		printf("NO GAME\n");
	}else{
		printf("%d\n",nextValue - baseValue);
	}
}


int main(){

	while(true){
		scanf("%d %d",&N,&K);
		if(N == 0 && K == 0)break;

		func();
	}

    return 0;
}