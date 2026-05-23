#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n,a,b; cin>>n>>a>>b;
	int cnta=0, cntb=0, cntc=0;
	rep(i,n){
		int p; cin>>p;
		if(p<=a) cnta++;
		else if(p>a&&p<=b) cntb++;
		else cntc++;
	}
	cout<<min(cnta,min(cntb,cntc))<<endl;
}