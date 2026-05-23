#include<stdio.h>

int main(){
	int n,ni[7],i,to;
	while(0<=scanf("%d",&n)){
		if(n==0)break;
		
		for(i=0;i<7;i++)ni[i]=0;
		
		for(i=0;i<n;i++){
			scanf("%d",&to);
			if(to<10){
				++ni[0];
			}else if(to<20){
				++ni[1];
			}else if(to<30){
				++ni[2];
			}else if(to<40){
				++ni[3];
			}else if(to<50){
				++ni[4];
			}else if(to<60){
				++ni[5];
			}else{
				++ni[6];
			}
		}
		for(i=0;i<7;i++)printf("%d\n",ni[i]);
	}
	return 0;
}