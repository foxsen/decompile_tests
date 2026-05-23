#include <stdio.h>

int main(void)
{
	int n;
	
	while(scanf("%d", &n) != EOF){
	
	bool *d = new bool [n+1];
	int count = 0;

	for(int i = 0; i <= n; i++)
		d[i] = true;

	for(int i = 2; i <= n; i++){
		if(d[i]){
			count++;
			for(int j = i*2; j <= n; j+=i)
				d[j] = false;
		}
	}
	printf("%d\n", count);
	}


	return 0;
}