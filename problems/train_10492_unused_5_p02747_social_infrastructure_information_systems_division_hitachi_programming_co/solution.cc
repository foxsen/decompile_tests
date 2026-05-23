#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    cin>>s;
    if (s.length()%2) return 0*puts("No");
    for (int i=0;i<(int)s.length();i+=2)
        if (s[i]!='h'||s[i+1]!='i')
            return 0*puts("No");
    return 0*puts("Yes");
}
