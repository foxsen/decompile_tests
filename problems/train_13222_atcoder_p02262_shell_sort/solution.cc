#include<bits/stdc++.h>
using namespace std;
#define int long long

int cnt, a[1000100];

void insertionSort(int a[],int n, int g){
	int v,j;
	for(int i = g; i < n; i++){
		v = a[i];
		j = i-g;
		while(j >= 0 && a[j] > v){
			a[j+g]=a[j];
			j-=g;
			cnt++;
		}
		a[j+g] = v;
	}
}

void shellSort(int a[], int n){
	int m=0,temp=n,j=1, G[100] = {};
	for(int i = 1; ; i++){
		G[i] = 3*G[i-1]+1;
		//cout<<i<<"== "<<G[i]<<endl;
		if(G[i] > n)break;
		j++;
	}
	j--;
	cout<<j<<endl;
	for(int i = j,k=0; i; i--){
		if(k++)cout<<" ";
		cout<<G[i];
	}cout<<endl;
	for(int i = j; i; i--){
		insertionSort(a,n, G[i]);
	}
}

signed main(){
	int n;
	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>a[i];
	shellSort(a,n);
	cout<<cnt<<endl;
	for(int i = 0; i < n; i++)
		cout<<a[i]<<endl;
	
	
	return 0;
}
