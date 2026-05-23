#include <stdio.h>

int main()
{
int n,d;
while(scanf("%d%d",&n,&d)!=EOF)
{
printf("%d\n",n*n-d);
return 0;
}
}