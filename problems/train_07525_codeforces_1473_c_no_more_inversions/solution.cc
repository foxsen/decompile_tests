/*
�ټ�ͷ�ļ�������������
DP��Ч�ԣ�����������
�ļ����������������
�ļ���д������������
���겻���룬����������
���۲�֤��������������
����û����������������
ll�� int������������
 dp û��ֵ������������
����û�߽磬����������
���������ӣ�����������
ģ��û���壬����������
Խ�粻���У�����������
��ⲻ��գ�����������
�ռ���ҿ�������������
��������򣬱���������
������ɾ��������������
�ļ������棬����������
��Ŀ�ύ������������
*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
void solve(){
	int n,k;
	cin>>n>>k;
	int t=2*n-2*k+1;
	FOR(i,1,n-t)cout<<i<<' ';
	for(int i=k;i>n-t;i--)cout<<i<<' ';
	cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	while(n--)solve();
	RE 0;
}





