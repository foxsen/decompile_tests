#include<stdio.h>
int main()
{
	int a,b,c;
	long long int s;
	scanf("%d%d%d",&a,&b,&c);
	s=a+b+c;
	if(s>=22)
	printf("bust\n");
	else
	printf("win\n");
}