#include <bits/stdc++.h>
using namespace std;

int d[100010];

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", d+i);
	sort(d, d+n);
	printf("%d\n", d[n/2] - d[n/2-1]);
}
