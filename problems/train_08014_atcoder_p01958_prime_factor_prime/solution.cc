#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
#include<assert.h>
#include<bitset>
#include<stack>
#include<memory>
using namespace std;
using namespace std::chrono;
typedef long long int llint;
typedef double lldo;
#define mp make_pair
#define mt make_tuple
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define fir first
#define sec second
#define res resize
#define ins insert
#define era erase
/*cout<<fixed<<setprecision(20);cin.tie(0);ios::sync_with_stdio(false);*/
const llint mod=998244353;
const llint big=2.19e15+1;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-15;
template <class T,class U>bool mineq(T& a,U b){if(a>b){a=b;return true;}return false;}
template <class T,class U>bool maxeq(T& a,U b){if(a<b){a=b;return true;}return false;}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){if(a==0){return b;}return a/gcd(a,b)*b;}
template<class T> void SO(T& ve){sort(ve.begin(),ve.end());}
template<class T> void REV(T& ve){reverse(ve.begin(),ve.end());}
template<class T>llint LBI(vector<T>&ar,T in){return lower_bound(ar.begin(),ar.end(),in)-ar.begin();}
template<class T>llint UBI(vector<T>&ar,T in){return upper_bound(ar.begin(),ar.end(),in)-ar.begin();}
int main(void){
	llint L,R,i,j,ans=0;cin>>L>>R;
	static int soin[1000001]={0};
	static llint now[1000001];
	static bool sosu[35000]={};//1なら素数
	int A=max(50,(int)sqrt(R)+100);
	for(i=2;i<=A;i++){sosu[i]=1;}
	for(i=2;i<=A;i++){
		if(!sosu[i]){continue;}
		for(j=i+i;j<=A;j+=i){sosu[j]=false;}
	}
	for(j=0;j<=R-L;j++){now[j]=j+L;}
	for(i=2;i<=A;i++){
		//cerr<<"de"<<__LINE__<<endl;
		if(!sosu[i]){continue;}
		for(j=((L+i-1)/i)*i;j<=R;j+=i){
			
			while(now[j-L]%i==0){now[j-L]/=i;soin[j-L]++;}
		}
	}
	for(j=0;j<=R-L;j++){
		if(now[j]>1){soin[j]++;}
		if(sosu[soin[j]]){ans++;}
		
	}
	cout<<ans<<endl;
	return 0;
}
