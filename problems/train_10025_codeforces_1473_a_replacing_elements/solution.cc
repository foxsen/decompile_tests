#include<bits/stdc++.h>
using namespace std;
int t,n,x,y,d,z,p;
int main(){
	for(scanf("%d",&t);t;t--){
		scanf("%d%d",&n,&d);
		x=y=1e9;p=0;
		for(int i=0;i<n;i++){
			scanf("%d",&z);
			if(z>d)p=1;
			if(x>z)y=x,x=z;
			else if(y>z)y=z;
		}
		puts(x+y<=d||!p?"YES":"NO");
	}
	return 0;
}
