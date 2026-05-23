#include<iostream>
#include<string>
using namespace std;
int main(){
	string a;
	cin>>a;
	a.erase(a.size()-8,a.size()-1);
	cout<<a;
}