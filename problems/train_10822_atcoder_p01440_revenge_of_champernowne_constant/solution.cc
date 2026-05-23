#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <queue>
using namespace std;
#define MP(x,y) make_pair(x,y)
#define FI first
#define SE second
#define INF 1LL<<60

const int MAXN = 110;
int len;
char str[MAXN],st[MAXN];
long long ans,pos;

long long trans_stoi(int l,int r)
{
	long long res=0;
	for (int i=l;i<r;i++)
		res=res*10+str[i]-'0';
	return res;
}

void trans_itos(long long x)
{
	int num=0;
	int tmp[MAXN];
	while (x)
	{
		tmp[num++]=x%10;
		x/=10;
	}
	for (int i=0;i<num;i++)
		st[i]=tmp[num-i-1]+'0';
	st[num]='\0';
}

long long cal(long long ans)
{
    if (ans<=0) return 0;
	int num=1;
	long long mul=9,p=1,res=0;
	while (ans>p*10)
	{
		res+=num*mul;
		num++;
		mul*=10;
		p*=10;
	}
	res+=(ans-p)*num;
	return res;
}

void judge_0()
{
	long long p=1;
	for (int i=1;i<=len;i++)
	{
		if (str[i]!='0') return;
		p*=10;
	}
	ans=p;
	pos=2;
}

void judge_1()
{
	for (int i=1;i<min(17,len);i++)
	{
		for (int j=1;j<=i;j++) st[j]=str[j];
		st[i+1]='\0';
		int add=1,l=i;
		while (add&&l>0)
		{
			if (st[l]=='9') st[l]='0',add=1;
			else st[l]=st[l]+1,add=0;
			l--;
		}
		for (int j=max(1,2*i-len);j<=i;j++)
		{
			int flag=1;
			for (int p=len,q=i-j;q>=1;p--,q--)
				if (str[p]!=st[q])
				{
					flag=0;
					break;
				}
			if (flag)
			{
				long long tmp=0;
				if (str[i+1]=='0') continue;
				if (j+len-i>=18) continue;
				for (int k=i+1;k<=len;k++) tmp=tmp*10+str[k]-'0';
				for (int k=i-j+1;k<=i;k++) tmp=tmp*10+st[k]-'0';
				if (ans>tmp) ans=tmp,pos=1-i;
			}
		}
	}
}

int cal_len(long long x)
{
    int res=0;
    while (x)
    {
        x/=10;
        res++;
    }
    return res;
}

int main()
{
	int ca=0;
	while (scanf("%s",str+1)!=-1)
	{
		if (str[1]=='#') break;
		len=strlen(str+1);
		ans=INF;
		for (int s=1;s<=len;s++)
			for (int l=s;l<=17&&s+l-1<=len;l++)
			{
				if (str[s]=='0') continue;
				long long tt=trans_stoi(s,s+l);
				long long tmp=tt+1;
				trans_itos(tmp);
				int flag=1;
				int p=s+l,q=p+strlen(st)-1;
				while (flag)
				{
					if (q>len) break;
					for (int i=p,j=0;i<=q;i++,j++)
						if (str[i]!=st[j])
						{
							flag=0;
							break;
						}
					if (!flag) break;
					tmp++;
					trans_itos(tmp);
					p=q+1,q=p+strlen(st)-1;
				}
				if (!flag) continue;
				for (int i=p,j=0;i<=len;i++,j++)
					if (str[i]!=st[j])
					{
						flag=0;
						break;
					}
				trans_itos(tt-1);
				for (int i=s-1,j=strlen(st)-1;i>0;i--,j--)
					if (str[i]!=st[j])
					{
						flag=0;
						break;
					}
				if (flag)
				{
					if (ans>tt)
                        ans=tt-1,pos=cal_len(ans)-s+2;
				}
			}
		judge_1();
		judge_0();
		printf("%lld\n",cal(ans)+pos);
	}
	return 0;
}