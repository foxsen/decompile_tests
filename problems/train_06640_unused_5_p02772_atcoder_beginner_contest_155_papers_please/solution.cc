#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	while (n--){
		int s;
		cin>>s;
		if (s%2==0)
			if (s%3!=0&&s%5!=0){
				cout<<"DENIED"<<endl;
				return 0;
			}
	}
	cout<<"APPROVED"<<endl;
	return 0;
}