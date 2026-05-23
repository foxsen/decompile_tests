#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll print(string s,char a, char b, char c)
{
	ll pos=0;
	ll n=s.size();
	for(ll i=0;i<n;i++)
	{
		if(s[i]==a)
		{
			pos++;
		}
		else if(s[i]==b)
		{
			pos--;
		}
		else{
			pos++;
		}
		if(pos<0)
		{
			return -1;
		}
	}
	if(pos>0)
	{
		return -1;
	}
	return 1;
	
}


ll print1(string s,char a, char b, char c)
{
	ll pos=0;
	ll n=s.size();
	for(ll i=0;i<n;i++)
	{
		if(s[i]==a)
		{
			pos++;
		}
		else if(s[i]==b)
		{
			pos++;
		}
		else{
			pos--;
		}
		if(pos<0)
		{
			return -1;
		}
	}
	if(pos>0)
	{
		return -1;
	}
	return 1;
	
}

ll print2(string s,char a, char b, char c)
{
	ll pos=0;
	ll n=s.size();
	for(ll i=0;i<n;i++)
	{
		if(s[i]==a)
		{
			pos++;
		}
		else if(s[i]==b)
		{
			pos--;
		}
		else{
			pos--;
		}
		if(pos<0)
		{
			return -1;
		}
	}
	if(pos>0)
	{
		return -1;
	}
	return 1;
	
}
int main(){
   ll t;
   cin>>t;
   while(t--)
   {
   	
   string s;
   cin>>ws;
   cin>>s;
   ll n;
   n=s.size();
   ll a=0,b=0,c=0;
   for(ll i=0;i<n;i++)
   {
   	if(s[i]=='A')
   	{
   		a++;
	   }
	else if(s[i]=='B')
	{
		b++;
	   }
	else
	{
		c++;
		  }      
   }
   if((a==0 && b==0 && c!=0) || (a!=0 && b==0 && c==0) || (a==0 && b!=0 && c==0) )
   {
   	cout<<"NO"<<"\n";
	} 
    else {
    	if(s[0]=='A')
    	{
    		ll p=print(s,'A','B','C');
    		ll p1=print1(s,'A','B','C');
    		ll p2=print2(s,'A','B','C');
    		p1=max(p1,p2);
    		if(max(p,p1)==1)
    		{
    			cout<<"YES"<<"\n";
			}
			else{
				cout<<"NO"<<"\n";
			}
		}
		else if(s[0]=='B')
		{
			ll p=print(s,'B','A','C');
    		ll p1=print1(s,'B','A','C');
    		ll p2=print2(s,'B','A','C');
    		p1=max(p1,p2);
    		if(max(p,p1)==1)
    		{
    			cout<<"YES"<<"\n";
			}
			else{
				cout<<"NO"<<"\n";
			}
		}
		else{
			ll p=print(s,'C','B','A');
    		ll p1=print1(s,'C','B','A');
    		ll p2=print2(s,'C','B','A');
    		p1=max(p1,p2);
    		if(max(p,p1)==1)
    		{
    			cout<<"YES"<<"\n";
			}
			else{
				cout<<"NO"<<"\n";
			}
		}
	}	

   
   }
	return 0;
}


