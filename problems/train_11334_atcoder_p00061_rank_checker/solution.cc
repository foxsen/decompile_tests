#include <stdio.h>
#include <functional>
#include <algorithm>
using namespace std;

int main(){
	int res[100],rankt[100],i,rank = 0,point,a,b;
	for(i = 0;i <100;i++) {
		res[i] = 0;
		rankt[i] = 0;
	}
	while(1){
		scanf("%d,%d",&a,&b);
		if(!a && !b) break;
		res[a] = b * 1000 + a;
	}
	sort(res,res + 100,greater<int>());
	point = res[0] / 1000;
	for(i = 0;i < 100;i++){
		if(!res[i]) break;
		if(res[i] / 1000 != point) {
			point = res[i] / 1000;
			rank++;
		}
		rankt[res[i] % 1000] = rank + 1;
	}
	while(scanf("%d",&i) != EOF) printf("%d\n",rankt[i]);
	return 0;
}