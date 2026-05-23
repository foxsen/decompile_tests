#include <bits/stdc++.h>
using namespace std;
int main(){
    char c;
    string s;
    while(~scanf("%c",&c)){
        if(c=='B'){
            if(!s.empty())
                s.pop_back();
        }
        else s+=c;
    }
    cout<<s<<endl;
    return 0;
}
