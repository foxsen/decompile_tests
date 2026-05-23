#include<stdio.h>
int main(void)
{
	int a,s,d,f,g,i;
	f=-1;
	g=0;
	scanf("%d",&a);
	for(i=1;i<=a;i++){
		scanf("%d %d",&s,&d);
		if(f==d){
			if(g>s){
				g=s;
			}
		}
		else if(f<d){
			f=d;
			g=s;
		}
	}
	printf("%d %d\n",g,f);
	return 0;
}