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

int main(){

	int N,M;
	scanf("%d %d",&N,&M);

	char* buf = new char[N+1];

	set<ull> S;

	scanf("%s",buf);

	ull* P1 = new ull[N+1];

	P1[0] = 1;

	for(int i = 1; i <= N; i++){
		P1[i] = P1[i-1]*MOD;
	}

	ull* HASH = new ull[N+1];

	HASH[0] = 0;

	for(int i = 1; i <= N; i++){
		HASH[i] = buf[i-1]+HASH[i-1]*MOD;
	}

	int L = 1,R = 1;
	ull hashValue;
	char order[10];

	for(int loop = 0; loop < M; loop++){
		scanf("%s",order);

		if(order[0] == 'L' && order[1] == '+'){
			L++;
		}else if(order[0] == 'L' && order[1] == '-'){
			L--;
		}else if(order[0] == 'R' && order[1] == '+'){
			R++;
		}else{ //order[0] == 'R' && order[1] == '-';
			R--;
		}

		hashValue = HASH[R] - HASH[L-1]*P1[R-(L-1)];

		S.insert(hashValue);
	}

	printf("%d\n",S.size());

	return 0;
}