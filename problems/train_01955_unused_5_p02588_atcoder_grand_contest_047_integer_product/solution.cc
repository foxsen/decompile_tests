#include<bits/stdc++.h>
using namespace std;
int cnt[65][65],cnt2,cnt5;
long long ans,tmp;
int main(){
	double x;int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>x;
		tmp=llround(x*1e9);
		//cout<<tmp<<endl;
		cnt2=cnt5=0;
		while(tmp%2==0) ++cnt2,tmp/=2;
		while(tmp%5==0) ++cnt5,tmp/=5;
		for(int j=0;j<=64;++j)
			for(int k=0;k<=64;++k)
				if(cnt2+j>=18 && cnt5+k>=18)ans+=cnt[j][k];
		cnt[cnt2][cnt5]++;
	}
	cout<<ans;
	return 0;
} 