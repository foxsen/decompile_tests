#include <bits/stdc++.h>
using namespace std;

bool dp[100010] ; 
int a[1001] ; 

int main() {
	int n , k ; 
	scanf("%d %d" , &n , &k) ; 
	for (int i =0 ; i<n ; ++i)
		scanf("%d" , &a[i]) ; 
		
	for (int i =0 ; i<=k ; ++i){
		for(int j =0 ; j<n ; ++j) {
			if (i >= a[j] && !dp[i-a[j]])
				dp[i] = 1 ; 
		}
	}
	if (dp[k])
		puts("First");
	else 
		puts("Second") ; 
	return 0;
}