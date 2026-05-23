#include <iostream>
using namespace std;
int x[100005],y[100005],a[100005],ans;
int main(void){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        a[i]=(i+num)%n;
    }
    for(int i=0;i<n;y[i]=-1,i++)x[i]=-1;
    for(int i=0;i<n;i++){
        int p=i,c=0;
        while(x[p]==-1){
            x[p]=c++;
            y[p]=i;
           p=a[p];
            
        }
        if(y[p]==i)ans+=c-x[p];
    }
    cout<<ans<<endl;
}