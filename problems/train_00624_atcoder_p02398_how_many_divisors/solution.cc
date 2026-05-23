#include <iostream>
using namespace std;
int main(void){
	int a,b,c,i,cnt=0;
	cin>>a>>b>>c;
	for(i=a;i<=b;i++)
		if(!(c%i))cnt++;
	cout<<cnt<<endl;
	return 0;
}