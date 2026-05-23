#include <iostream>

using namespace std;
int main() {
	int n;
	cin >> n;
	int mini;
	int a[n], b[n];
	char A[n], B[n];
	bool stable;
	for(int i = 0; i < n; i++){
		cin >> A[i] >> a[i];
		B[i] = A[i];
		b[i] = a[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = n-1; j > i; j--){
			if(a[j] < a[j-1]){
				swap(A[j], A[j-1]);
				swap(a[j], a[j-1]);
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(i) cout << " ";
		cout << A[i] << a[i];
	}
	cout << endl;
	cout << "Stable" << endl;
	for(int i = 0; i < n; i++){
		mini = i;
		for(int j = i; j < n; j++){
			if(b[j] < b[mini])
			{
				mini = j;
			}
		}
		swap(b[i], b[mini]);
		swap(B[i], B[mini]);
	}
	for(int i = 0; i < n; i++){
		if(i) cout << " ";
		cout << B[i] << b[i];
	}
	cout << endl;
	for(int i = 0; i < n; i++){
		if(A[i] == B[i] && a[i] == b[i]){
			stable = true;
		}else{
			stable = false;
			break;
		}
	}
	if(stable == true) cout << "Stable" << endl;
	else cout << "Not stable" << endl;
}
