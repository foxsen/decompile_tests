#include<bits/stdc++.h>
using namespace std;
int a,b,c,x,m,n;
int main() {
	cin>>a>>b>>c>>x;
	for(int i=0; i<=a; i++) {
		for(int j=0; j<=b; j++) {
			for(int v=0; v<=c; v++) {
				m=500*i+100*j+50*v;
				if(m==x)n++;
			}
		}
	}
	cout<<n;
	return 0;
}