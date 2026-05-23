#include <stdio.h>
int main(void){
	int n,i,x,y,b,p;
	int q,w;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&x,&y,&b,&p);
		
		
		
		q=x*b+y*p;
		if(b<5)b=5;
		if(p<2)p=2;
		w=(x*b+y*p)*0.8;
		
		if(q<w){
			printf("%d\n",q);
		}else{
			printf("%d\n",w);
		}
	}
	return 0;
}