#include <iostream>
using namespace std;
int main(void){
    string s,t[3]={"KIH", "B", "R"};
    cin>>s;
    for(int i=0;i<16;i++){
        string u="";
        for(int j=0;j<4;j++){
            if(((i>>j)&1)==1){
                u+="A";
            }
            if(j<3){
                u+=t[j];
            }
        }
        //cout<<u<<endl;
        if(s==u){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
