#include <cstdio>
int min(int a, int b) {
	return a<=b?a:b;
}
int main() {
	int a,b,c,d,e;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	printf("%d\n",min(a,min(b,c))+min(d,e)-50);
}