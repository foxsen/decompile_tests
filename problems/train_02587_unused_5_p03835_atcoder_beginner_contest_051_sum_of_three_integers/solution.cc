#include "iostream"
using namespace std;
int main(){
	int ans=0,k,s,x,y,z;
	cin>>k>>s;
	for(x=0;x<=k;x++)
		for(y=0;y<=k;y++)
			if(s-x-y>=0&&s-x-y<=k)
					ans++;
				
	cout<<ans<<endl;
}