#include<bits/stdc++.h>
using namespace std;

int main(){
	long long N , X , ans; cin >> N >> X; ans = N;
	long long P = X , Q = N - X;
	while(Q){ans += (P / Q * 2 - !(P % Q)) * Q; P %= Q; swap(P , Q);}
	cout << ans; return 0;
}
