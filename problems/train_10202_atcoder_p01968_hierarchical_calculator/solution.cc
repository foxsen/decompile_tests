#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define int long long
#define rep(i,n) for(int i = 0; i < (n); i++)
#define INF ((long long)1e18)
#define MOD ((int)1e9+7)
#define endl "\n"

#define yn(f) ((f)?"Yes":"No")
#define YN(f) ((f)?"YES":"NO")

#define MAX 100

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	int N, a[MAX], used[MAX] = {};
	int num = 1, con = 0;
	
	cin>>N;
	
	for(int i = 1; i <= N; i++){
		cin>>a[i];
		if(a[i] == 2 || a[i] == -2) used[i] = true, con++;
		if(a[i] == -2) num *= -1;
	}
	
	if(num == -1){
		bool flag = false;
		
		for(int i = 1; i <= N; i++){
			if(a[i] == -1){
				used[i] = true;
				flag = true;
				con++;
				break;
			}
		}
		
		if(flag == false){
			
			for(int i = N; i; i--){
				if(a[i] == -2){
					used[i] = false;
					con--;
					break;
				}
			}
			
		}
	}
	
	cout<<con<<endl;
	
	for(int i = 1; i <= N; i++){
		if(used[i])cout<<i<<endl;
	}
	
	return 0;
}
