#include <iostream>
#include <vector>
#include <algorithm>

#define IF 1300500010
#define lengthof(x) (sizeof(x) / sizeof(*(x)))

using namespace std;

int main(int argc, char const *argv[])
{
	int n,m;
	long long dp[1<<8][2];
	long long min_;

	while(1){
		cin>>n>>m;
		if(n+m==0) break;

		vector<long long> cb(m);
		vector<long long> x(n);
		for(int i1=0;i1<m;i1++){
			cin>>cb[i1];
		}

		for(int i1=0;i1<n;i1++){
			cin>>x[i1];
		}

		fill((long long*)dp,(long long *)(dp+lengthof(dp)),IF);

		dp[128][0]=0;
		for(int i1=0;i1<n;i1++){
			for(int i2=0;i2<(1<<8);i2++){
				if(dp[i2][i1%2]!=IF){

					for(int i3=0;i3<m;i3++){
						int temp=i2+cb[i3];
						if(temp<0) temp=0;
						if(temp>255) temp=255;
						dp[temp][(i1+1)%2]=min(dp[temp][(i1+1)%2],dp[i2][i1%2]+(temp-x[i1])*(temp-x[i1]));
					}
					dp[i2][i1%2]=IF;
				}

			}
		}

		min_=IF;
		for(int i1=0;i1<(1<<8);i1++){
			min_=min(min_,dp[i1][n%2]);
		}

		cout<<min_<<endl;
	}
	return 0;
}