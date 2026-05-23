#include<bits/stdc++.h>
using namespace std;
int f[100005][3];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>f[i][0]>>f[i][1]>>f[i][2];
	}
	for(int i=2;i<=n;i++){
	    f[i][0]+=max(f[i-1][1],f[i-1][2]);
	    f[i][1]+=max(f[i-1][2],f[i-1][0]);
	    f[i][2]+=max(f[i-1][1],f[i-1][0]);
	}
	cout<<max({f[n][0],f[n][1],f[n][2]});
}
