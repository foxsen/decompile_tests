#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    int ans=0;
    for(int i=0; i<n; i++){
        while(a[i]==a[i+1]) i++;
        if(a[i]<a[i+1]){
            while(a[i]<=a[i+1]) i++;
        }
        else if(a[i]>a[i+1]){
            while(a[i]>=a[i+1]) i++;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}
