#include<iostream>
#include<algorithm>
using namespace std;
const int B=250;
int N,Q;
long long A[100000];
long long L[100000/B],R[100000/B],mid[100000/B],S[100000/B];
void calc(int id)
{
	int l=id*B,r=min(id*B+B,N);
	long long Lmin=0,Lsum=0;
	L[id]=R[id]=mid[id]=0;
	for(int k=l;k<r;k++)
	{
		Lsum+=A[k];
		if(Lmin>Lsum)Lmin=Lsum;
		L[id]=max(L[id],Lsum);
		mid[id]=max(mid[id],Lsum-Lmin);
	}
	S[id]=Lsum;
	long long Rsum=0;
	for(int k=r-1;k>=l;k--)
	{
		Rsum+=A[k];
		R[id]=max(R[id],Rsum);
	}
}
long long get()
{
	long long ans=0;
	long long cummax=0;
	for(int i=0;i<=N/B;i++)
	{
		ans=max(ans,mid[i]);
		ans=max(ans,cummax+L[i]);
		cummax=max(cummax+S[i],R[i]);
	}
	return ans;
}
int main()
{
	cin>>N>>Q;
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
	}
	for(int i=0;i<=N/B;i++)
	{
		calc(i);
	}
	cout<<get()<<endl;
	for(;Q--;)
	{
		int k;long long x;cin>>k>>x;
		k--;
		A[k]=x;
		calc(k/B);
		cout<<get()<<endl;
	}
}

