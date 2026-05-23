#include <stdio.h>

int main()
{
	long long a,b;
	scanf ("%lld %lld",&a,&b);
	if (a == 1 && b == 1) puts("1");
	else if (a == 1) printf ("%lld\n",b-2);
	else if (b == 1) printf ("%lld\n",a-2);
	else{
		printf ("%lld\n",(a-2)*(b-2));
	}
	return 0;
}