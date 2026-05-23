#include<bits/stdc++.h>
using namespace std;

long long int gcd(long long int x,long long int y){
	while((x%=y)&&(y%=x));
	return x^y;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		long long int A,B,C,D;
		cin>>A>>B>>C>>D;
		if(A<B||D<B){
			cout<<"No\n";
			continue;
		}
		long long int g = gcd(B,D);
		A = A - (C-B+1);
		long long int d = (A%g+g)%g;
			A = C-B+1+d;
		if(A<0)
			cout<<"No\n";
		else
			cout<<"Yes\n";
	}
}
