#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;



int main(){

	int n,count;

	while(true){
		scanf("%d",&n);
		if(n == 0)break;

		count = 0;

		while(n != 1){
			if(n % 2 == 0)n /= 2;
			else{
				n = 3*n + 1;
			}
			count++;
		}

		printf("%d\n",count);
	}

    return 0;
}