#include <iostream>
using namespace std;
int gcd(int a,int b){
	return (b==0 ? a : gcd(b,a%b));
}
int main(void){
    int x,y;
    cin>>x>>y;
    int g=gcd(x,y);
    cout<<x+y-g+1<<endl;
}

