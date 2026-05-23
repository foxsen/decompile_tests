#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<fstream>
using namespace std;
const int mod=1000000007;
int n,m;
int f[3003][3003][2];
int dp(int tur,int num,int sta){
	int &ret=f[tur][num][sta];
	if(ret!=-1){
		return ret;
	}
	if(tur==m){
		if(sta==1){
			return ret=1;
		}
		return ret=0;
	}
	ret=0;
	if(num){
		ret=(ret+dp(tur+1,num-1,sta|(num==1)))%mod;//-1 red,+1 red,+1 blue,-1 red
	}
	if(num){
		ret=(ret+dp(tur+1,num,sta|(num==1)))%mod;//-1 red,+1 red,+1 blue,-1 blue
	}
	if(n-num){
		ret=(ret+dp(tur+1,num,sta))%mod;//-1 blue,+1 red,+1 blue,-1 red
	}
	if(n-num){
		ret=(ret+dp(tur+1,num+1,sta))%mod;//-1 blue,+1 red,+1 blue,-1 blue
	}
	return ret;
}
int main(){
	memset(f,-1,sizeof(f));
	cin>>n>>m;
	long long ans=0;
	ans=(ans+dp(0,0,1))%mod;
	for(int i=1;i<=n;i++){
		ans=(ans+dp(0,i,0))%mod;
	}
	cout<<ans<<endl;
	return 0;
}
/*

in:
2 3

out:
56

in:
1000 10

out:
1048576

*/