#include<iostream>
using namespace std;

void maxHeapify(int a[], int n, int i){
	int l=i*2;
	int r=l+1;
	int larg=i;
	if (l<=n && a[l]>a[larg]){
		larg = l;
	}
	if (r<=n && a[r]>a[larg]){
		larg = r;
	}
	if (larg!=i){
		int t=a[larg];
		a[larg]=a[i];
		a[i]=t;
		maxHeapify(a,n,larg);
	}
}

void buildMaxHeap(int n, int a[]){
	for (int i=n/2;i>=1;i--){
		maxHeapify(a,n,i);
	}
}

int main(){
	int n,i;
	cin >> n;
	int a[n+1];
	for(i=1;i<=n;i++) cin >> a[i];
	buildMaxHeap(n,a);
	for(i=1;i<=n;i++) cout << " " << a[i];
	cout << endl;
	return 0;
}

