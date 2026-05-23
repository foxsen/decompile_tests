#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
float sum;
int n,m,a[11][11],sumn;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
			cin>>a[i][l];
	for(int i=1;i<=n-1;i++)
		for(int l=i+1;l<=n;l++){
			for(int j=1;j<=m;j++)
				sum+=abs(a[i][j]-a[l][j])*abs(a[i][j]-a[l][j]);
			if(int(sqrt(sum))==sqrt(sum))
				sumn++;
			sum=0;
		}
	cout<<sumn;
	return 0;
}