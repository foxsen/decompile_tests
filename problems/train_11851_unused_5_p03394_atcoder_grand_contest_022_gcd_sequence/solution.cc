#include "bits/stdc++.h"
using namespace std;

int main(){
	int n;
	cin>>n;
	
	if(n==3){
		cout<<"2 5 63"<<endl;
		return 0;
	}
	
	if(n==4){
		cout<<"2 5 20 63"<<endl;
		return 0;
	}
	
	if(n==5){
		cout<<"2 5 20 30 63"<<endl;
		return 0;
	}
	
	long long int sum=0;
	
	vector<int> ans;
	int cnt=0;
	for(int i=2;cnt<n;i++){
		if(i%2==0||i%3==0){
			sum+=i;
			ans.push_back(i);
			cnt++;
		}
	}
	
	if(sum%6==2){
		ans[4]=30000;
	}
	if(sum%6==3){
		ans[5]=30000;
	}
	if(sum%6==5){
		ans[4]=29997;
	}
	
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	
	cout<<endl;
}