#include<bits/stdc++.h>
using namespace std;
typedef vector<int>V;
int n,i,j,ans=1<<30,x;
V L,R,S,T;
string s,t;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>s>>t;
	if(n<3){for(i=0;i<n;++i)x+=s[i]!=t[i];cout<<x<<endl;return 0;}
	for(i=0;i+1<n;++i){
		if(s[i]!=s[i+1])S.push_back(i+1);
		if(t[i]!=t[i+1])T.push_back(i+1);
	}
	L=V(n);R=V(n,n);
	if((s[S[0]-1]!=t[T[0]-1])!=(n&1))L.push_back(0);
	L.insert(L.end(),S.begin(),S.end());
	L.insert(L.end(),R.begin(),R.end());
	for(i=0;i+T.size()<=L.size();i+=2){
		x=0;
		for(j=0;j<T.size();++j)x+=abs(L[i+j]-T[j]);
		for(j+=i;j<L.size();++j)x+=n-L[j];
		for(j=0;j<i;++j)x+=L[j];
		ans=min(ans,x);
	}
	cout<<ans<<endl;
	return 0;
}