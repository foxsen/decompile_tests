#include <iostream>
#include <string>
using namespace std;
int main()
{
    while(1)
    {
        string r,a;
        int hit=0;
        int blow=0;
        cin>>r>>a;if(r=="0")return 0;
        for(int i=0;i<4;++i){
            for(int j=0;j<4;++j){
                if(r[i]==a[j]){
                    if(i==j){
                        hit++;
                    }else{
                        blow++;
                    }
                }
            }
        }
        cout<<hit<<" "<<blow<<endl;
    }
    return 0;
}