#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
int main(){
	cin>>n>>m>>k;
	bool ans=false;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if ((i*j+(n-i)*(m-j))==k) {
				puts("Yes");
				return 0;
			}
		}
	}
	puts("No");

}
