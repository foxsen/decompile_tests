#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    int time=0;
    for(int i=0; i<60; i++){
        while(time < (i+1)*60){
            if(time%60 <= c && c <= time%60+a){
                time += c - time%60;
                cout << time << endl;
                return 0;
            }else{
                time += a+b;
            }
        }
    }
    cout << -1 << endl;
    
    return 0;
}