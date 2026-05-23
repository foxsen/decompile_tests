#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,k;
	cin>>n>>k;
	long long rez=0;
	for(long long i = k ; i <= n+1 ; i ++){
		rez+=1+(n-i+1)*i%int(1e9+7);
	}
	cout<<rez%int(1e9+7);
}