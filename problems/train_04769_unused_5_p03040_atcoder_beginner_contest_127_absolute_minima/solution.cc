#include<iostream>
#include<queue>
using namespace std;
long B,l,r;
int Q;
priority_queue<int>L,R;
int main()
{
	cin>>Q;
	for(;Q--;)
	{
		int id;cin>>id;
		if(id==1)
		{
			int a,b;cin>>a>>b;
			B+=b;
			if(R.size()<L.size())
			{
				L.push(a);
				l+=a;
				a=L.top();
				l-=a;
				r+=a;
				L.pop();
				R.push(-a);
			}
			else
			{
				R.push(-a);
				r+=a;
				a=-R.top();
				r-=a;
				l+=a;
				R.pop();
				L.push(a);
			}
		}
		else
		{
			long w=L.top();
			cout<<w<<" "<<B+r-l+w*((int)L.size()-(int)R.size())<<endl;
		}
	}
}