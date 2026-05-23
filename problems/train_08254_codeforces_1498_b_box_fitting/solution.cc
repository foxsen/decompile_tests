#include <bits/stdc++.h>
using namespace std;

int main() {
	long t;
	cin>>t;
	while(t--){
		long n,w;
		cin>>n>>w;
		long tmp;
		long count[20]={0};
		for(long i=0;i<n;i++){
			cin>>tmp;
			count[long(log2(tmp))]++;
		}
		// for(long i=19;i>=0;i--)
			// cout<<count[i]<<" ";
		long space_left=w,largest=-1;
		long height=1;
		for(long i=0;i<n;i++){
			for(long i=19;i>=0;i--){
				if(count[i] && space_left>=(1<<i)){
					largest=i;
					break;
				}
			}
			// cout<<largest<<" ";
			if(largest==-1){
				height++;
				space_left=w;
				for(long i=19;i>=0;i--){
					if(count[i]>0 && space_left>=(1<<i)){
						largest=i;
						break;
					}
				}	
			}
			count[largest]-=1;
			space_left-=(1<<largest);
			// cout<<space_left<<" ";
			largest=-1;
		}
		cout<<height<<endl;
	}
	return 0;
}