#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=12e4;

int a[N],n,k;
int cal(int l,int r){
	if(l+n-r>k)return 0;
	vector<int>v;
	for(int i=0;i<l;i++)
		v.push_back(a[i]);
	for(int i=r;i<n;i++)
		v.push_back(a[i]);
	sort(v.begin(),v.end(),greater<int>());
	int t=min(int(v.size()),k-l-n+r);
	for(int i=0;i<t;i++)
		if(v.back()<0)v.pop_back();
	int ans=0;
	for(int x:v)ans+=x;
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int l=0;l<=n;l++)
		for(int r=l;r<=n;r++)
			ans=max(ans,cal(l,r));
	cout<<ans;
	return 0;
}