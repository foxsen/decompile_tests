//============================================================================
// Name        : JOI.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int A[5001],B[5001],C[5001],D[5001];
int N,M;
int S[101]={};
int main() {
	cin>>N;
	for(int i=0;i<(N*(N-1)/2);i++){
		cin>>A[i]>>B[i]>>C[i]>>D[i];
		if(C[i]>D[i])S[A[i]]+=3;
		if(C[i]<D[i])S[B[i]]+=3;
		if(C[i]==D[i])S[A[i]]+=1,S[B[i]]+=1;
	}

	int T=0;
	for(int i=1;i<N+1;i++){
		T=1;
		for(int j=1;j<N+1;j++){
			if(S[i]<S[j])T+=1;
		}
		cout<<T<<endl;

	}
	return 0;
}