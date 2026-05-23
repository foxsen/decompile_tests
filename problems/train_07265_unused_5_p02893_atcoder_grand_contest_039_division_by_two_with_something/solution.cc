#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
const int mod = 998244353;
inline int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
inline int sub(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return 1ll*a*b%mod;}
int n;
char s[N],tt[N];
int ret;
int ans[N];
int T = 0;
void chk(int d){
	for(int i=0;i<n;i++){
		
		if(s[i]>tt[i]+'0')break;
		if(s[i]<tt[i]+'0')return;
	}
	ans[d]=add(ans[d],1);
}
int nxt[N];
int CNT=0;
int main()
{
	cin >> n;
	scanf("%s",s);
	for(int i=0;i<n;i++)T=T*2+s[i]-'0',T%=mod;
	for(int i=n-1;~i;i--)nxt[i]=s[i]=='1'?nxt[i+1]+1:0;
	for(int i=0;i<n;i++)if(nxt[i])nxt[i+1]=0x3f3f3f3f;
	T=add(T,1);T%=mod;
	// for(int i=0;i<=T;i++){
	// 	int d = i, time = 0;
	// 	while(time==0||d!=i){
	// 		++time;
	// 		int dd = ((d&1)^1)<<29;
	// 		d=dd+(d>>1);
	// 	}
	// 	if(time==20)cout << i << endl,CNT++;
	// }
	// cout << CNT << endl;
	for(int i=3;i<=n;i+=2){
		if(n%i==0){
			int d = n/i;
			// cout << d << endl;
			int t2=0;
			for(int i=0;i<d;i++){
				t2=mul(t2,2);t2=add(t2,s[i]-'0');
				tt[i]=s[i]-'0';
			}
			ans[d]=add(ans[d],t2);
			for(int i=d;i<n;i++)tt[i]=tt[i-d]^1;
			chk(d);
			// cout << ans[d] << endl;
		}
	}
	for(int i=1;i<=n;i++)if(n%i==0&&n/i%2){
		for(int j=i*2;j<=n;j+=i){
			ans[j]=sub(ans[j],ans[i]);
		}
		T=sub(T,ans[i]);
		ret=add(ret,mul(ans[i],i*2));
		// cout << ans[i] << endl;
	}
	// cout << T << endl; 
	ret=add(ret,mul(T,n*2));
	cout << ret << endl;
}