#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
int n, a, c = 1;
int main(){
	scanf("%d", &n);
	rep(i,n){
		scanf("%d", &a);
		if(a == c) c++;
	}
	printf("%d\n", c == 1 ? -1 : n-c+1);
}