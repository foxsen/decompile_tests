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

int* uniformity,*partial;
int N = 1;

void init(int first_N){
	while(N < first_N)N *= 2;
}

void add_and_updateNodes(int left,int right,int value,int node_id,int node_left,int node_right){

	if(right < node_left || left > node_right)return;
	else if(left <= node_left && right >= node_right){
		uniformity[node_id] += value;
	}else{
		partial[node_id] += (min(right,node_right)-max(left,node_left)+1)*value;
		add_and_updateNodes(left,right,value,2*node_id+1,node_left,(node_left+node_right)/2);
		add_and_updateNodes(left,right,value,2*node_id+2,(node_left+node_right)/2+1,node_right);
	}
}

int getSum(int left,int right,int node_id,int node_left,int node_right){
	if(right < node_left || left > node_right)return 0;
	else if(left <= node_left && right >= node_right){
		return (node_right-node_left+1)*uniformity[node_id]+partial[node_id];

	}else{
		int sum = (min(right,node_right)-max(left,node_left)+1)*uniformity[node_id];

		sum += getSum(left,right,2*node_id+1,node_left,(node_left+node_right)/2);
		sum += getSum(left,right,2*node_id+2,(node_left+node_right)/2+1,node_right);
		return sum;
	}
}

int main(){

	int first_N,Q,command,left,right,value,loc;
	scanf("%d %d",&first_N,&Q);

	init(first_N);

	uniformity = new int[270000];
	partial = new int[270000];

	for(int i = 0; i <= 2*N-2; i++){
		uniformity[i] = 0;
		partial[i] = 0;
	}

	for(int i = 0; i < Q; i++){
		scanf("%d",&command);

		if(command == 0){
			scanf("%d %d %d",&left,&right,&value);
			left--;
			right--;
			add_and_updateNodes(left,right,value,0,0,N-1);
		}else{
			scanf("%d",&loc);
			loc--;
			printf("%d\n",getSum(loc,loc,0,0,N-1));
		}
	}

	return 0;
}