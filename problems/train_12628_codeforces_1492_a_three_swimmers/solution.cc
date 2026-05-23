#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        long long int a,b,c,p,m,a1,a2,a3;
        cin >> p >> a >> b >> c;

        a1=((p+a-1)/a)*a;
        a2=((p+b-1)/b)*b;
        a3=((p+c-1)/c)*c;

        if(a1<=a2 && a1<=a3){
            m=a1-p;
        }
        else if(a2<=a1 && a2<=a3){
             m=a2-p;
        }
        else{
            m=a3-p;
        }
        cout << m << endl;
    }

    return 0;
}
