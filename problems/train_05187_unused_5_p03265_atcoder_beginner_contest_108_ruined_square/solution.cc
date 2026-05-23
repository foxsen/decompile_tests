#include<stdio.h>

int main(){
	int a,b,c,d,e,f;
  	scanf("%d%d%d%d",&a,&b,&c,&d);
    e = c - a;
    f = d - b;
    printf("%d %d %d %d\n",c - f,d + e,a - f,b + e);
}