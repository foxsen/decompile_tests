#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

int main(){

	int height,width,tmp;
	scanf("%d %d",&height,&width);

	int** table = new int*[height+1];
	table[0] = new int[width+1];
	for(int i=0; i < width+1; i++)table[0][i] = 0;

	for(int i=1; i <= height; i++){
		table[i] = new int[width+1];
		table[i][0] = 0;
		for(int k=1; k <= width; k++){
			scanf("%d",&tmp);
			table[i][k] = 1-tmp;
		}
	}

	int max_r = 0;

	for(int i=1; i <= height; i++){
		for(int k=1; k <= width; k++){
			if(table[i][k] != 0){
				table[i][k] = min(table[i-1][k-1],min(table[i][k-1],table[i-1][k]))+1;
				max_r = max(max_r,table[i][k]);
			}
		}
	}

	printf("%d\n",max_r*max_r);

    return 0;
}