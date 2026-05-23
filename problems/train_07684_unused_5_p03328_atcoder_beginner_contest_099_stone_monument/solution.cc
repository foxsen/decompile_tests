#include<iostream>
using namespace std;

int a,b;

int main(){
	cin>>a>>b;
	printf("%d\n",(b-a)*(b-a-1)/2-a);
	return 0;
}
