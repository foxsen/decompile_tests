#include<iostream>
#include<string>
#define MAX 64
using namespace std;
int main()
{
  while(true){
    long long int N;
    long long int K;
    bool tile[MAX+2][MAX+2];
    cin >> N >> K;
    if( N == 0 && K == 0 ) break;
    if( K>(1LL<<(N/2)) || N%2==1 ){ cout << "No\n" << endl; continue; }
    --K;
    for(long long int j = N-1; j >= 0; --j){
      tile[1][j+1]=(K&(1LL<<((N-1-j)/2)));
      tile[0][j+1]=!tile[1][j+1];
    }
    tile[1][0]=!tile[1][1];
    tile[1][N+1]=!tile[1][N];

    for(int i = 1; i < N; ++i){
      for(int j = 0; j < N; ++j){
	bool L=tile[i][j],C=tile[i][j+1],R=tile[i][j+2],T=tile[i-1][j+1];
	tile[i+1][j+1]=( (!T && !L && !C &&  R) ||
			 (!T && !L &&  C && !R) ||
			 (!T && !L &&  C &&  R) ||
			 (!T &&  L && !C && !R) ||
			 (!T &&  L &&  C && !R) ||
			 ( T && !L && !C && !R) ||
			 ( T && !L &&  C && !R) );
	//  0
	// 001 = 1

	//  0
	// 010 = 1

	//  0
	// 011 = 1

	//  0
	// 100 = 1

	//  0
	// 101 = 0
	
	//  0
	// 110 = 1
	
	//  0
	// 111 = 0
	
	//  1
	// 000 = 1

	//  1
	// 001 = 0

	//  1
	// 010 = 1

	//  1
	// 011 = 0
	
	//  1
	// 100 = 0

	//  1
	// 110 = 0
      }
      tile[i+1][0]=!tile[i+1][1];
      tile[i+1][N+1]=!tile[i+1][N];
    }
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < N; ++j){
	cout << (tile[i+1][j+1]?'E':'.');
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}