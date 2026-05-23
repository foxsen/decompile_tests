#include<iostream>

using namespace std;

int main(){
	int n,q;
	long long s=0;
	cin>>n;

	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];

	cin>>q;

	int p[100005]={0};

	for(int i=0;i<n;i++){
		s+=a[i];
		p[a[i]]++;
	}
	for(int i=0;i<q;i++){
		int b,c;
		cin>>b>>c;

		s+=(c-b)*p[b];
		p[c]+=p[b];
		p[b]=0;

		cout<<s<<endl;
	}
	return 0;
}

	