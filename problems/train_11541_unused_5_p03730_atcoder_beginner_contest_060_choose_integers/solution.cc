#include<stdio.h>
int main()
{
	int a,b,c,i,d=0,cnt=0;
	scanf("%d %d %d",&a,&b,&c);
	for(i=1;i<=b;i++){
		d=i*a;
		//printf("%d\n",d);
		if(d%b==c) cnt=1;
	}
	if(cnt==1) printf("YES\n");
	else printf("NO\n");
}