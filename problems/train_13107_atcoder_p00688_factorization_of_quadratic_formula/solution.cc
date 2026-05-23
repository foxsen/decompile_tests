#include<iostream>
using namespace std;
int main(){
	int a,b,c,p,q,r,s;
	while(cin>>a>>b>>c,a)if(c){
		for(r=1;r*r<=a;r++)if(a%r==0){
			p=a/r;
			for(s=c>0?-c:c;s<=(c>0?c:-c);s++)if(s&&c%s==0){
				q=c/s;
				if(p*s+q*r==b){
					cout<<p<<" "<<q<<" "<<r<<" "<<s<<endl; goto END;
				}
			}
		}
		cout<<"Impossible"<<endl; END:;
	}
	else{
		if(a!=1)cout<<a<<" "<<b<<" "<<1<<" "<<0<<endl;
		else cout<<1<<" "<<(b>0?b:0)<<" "<<1<<" "<<(b>0?0:b)<<endl;
	}
	return 0;
}