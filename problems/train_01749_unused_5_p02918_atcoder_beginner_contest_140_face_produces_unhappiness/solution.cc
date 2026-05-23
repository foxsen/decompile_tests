#include<iostream>
#include<algorithm>
using lint=int64_t;
using namespace std;

int main()
{
	int N,K;
	string S;

	cin >> N >> K;
	cin >> S;

	int cnt=0;
	for(int i=0;i<S.size()-1;i++)
	{
		if(S[i]==S[i+1])
			cnt++;
	}

	cout << min(cnt+2*K,N-1) << endl;
	return 0;
}

