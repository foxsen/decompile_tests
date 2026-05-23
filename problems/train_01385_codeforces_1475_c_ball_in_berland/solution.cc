#include<bits/stdc++.h>

using namespace std;
#define int long long 

signed main()
{
      int t;
    cin >> t;
    while(t--)
    {
        int a,b,k;
        cin >> a >> b >>k;
        //cout <<a; 
         pair<int,int> s[k];
        int boy[a];
        int girl[b];
        for(int i=0;i<a;i++)
        boy[i]=0;
          for(int i=0;i<b;i++)
        girl[i]=0;
        for(int i=0;i<k;i++)
        {
            cin >> s[i].first;
            boy[s[i].first-1]++;
        }
         for(int i=0;i<k;i++)
        {
            cin >> s[i].second;
            girl[s[i].second-1]++;
        }
        //for(int i=0;i<a;i++)
        //cout << boy[i]<<" ";
        int bs=0;
        for(int i=0;i<a;i++)
        {
            bs=bs+((boy[i]*(boy[i]-1))/2);
        }
        //cout <<bs<<endl;
        int gs=0;
        for(int i=0;i<b;i++)
        {
             gs=gs+((girl[i]*(girl[i]-1))/2);
        }
        int k1=((k)*(k-1))/2;
        cout << (k1-gs-bs)<<endl;
    }
}