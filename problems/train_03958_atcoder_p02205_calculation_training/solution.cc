#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long int ll;
map<int,pair<ll,ll>>mp;

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	ll n; cin >> n;
	ll a,b; cin >> a >> b;
	mp[0]=make_pair(a,b);
	for(int i=0;i<12;i++){
		if(i%2==0){
			a=a-b;
		}
		else{
			b=a+b;
		}
		mp[i+1]=make_pair(a,b);
	}
	cout << mp[n%12].first << " " << mp[n%12].second << endl;
}
