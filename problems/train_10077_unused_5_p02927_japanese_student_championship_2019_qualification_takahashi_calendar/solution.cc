#include <bits/stdc++.h>
using namespace std;
int main(){
	int M, D; cin >> M >> D; 
	int count = 0; 
	for(int i = 1; i <= D; i++){
		int a = i / 10; int b = i % 10; 
		if(a > 1 && b > 1 && M >= a * b && a * b > 0) count ++; 
	}
	cout << count << endl; 
}