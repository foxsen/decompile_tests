#include<bits/stdc++.h>

#define ll long long
using namespace std; 
ll f[64][2][2][2][2];ll l,r;ll ans1=0;int l1[64],r1[64];ll mod=1e9+7;
ll dfs(int pos,int tl,int tr,int ts,int th){
	if(pos<0) return 1;ll &ans=f[pos][tl][tr][ts][th];
	if(ans) return ans;
	
	for(int i=0;i<=1;i++){
		for(int j=0;j<=1;j++){int fs=ts,fl=tl,fr=tr,fh=th;
			if(!th&&i)if(i!=j)continue;
			if((j&i)!=j) continue;
			if(!tl&&l1[pos]>j) continue;
			if(!tr&&r1[pos]<i) continue;
			if(!ts&&j>i) continue;
			if(j<i) fs=1;if(j>l1[pos])fl=1;if(i<r1[pos])fr=1;if(j) fh=1;
			ans+=dfs(pos-1,fl,fr,fs,fh);
		}
	}ans%=mod;
	return ans;
}
int main(){
	cin>>l>>r;
	for(int i=63;i>=0;i--)
	{
		l1[i]=(bool)((1ll<<i)&l);r1[i]=(bool((1ll<<i)&r));
	}
cout<<dfs(63,0,0,0,0);
}