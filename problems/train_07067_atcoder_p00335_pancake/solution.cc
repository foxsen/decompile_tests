#include <iostream>
#include<string.h>
using namespace std;

int main(void){
    int N; cin >> N;
    int P[N];
    int min = 20000;
    
    for(int i = 0;i < N;i++) cin >> P[i];
    
    for(int i = 0;i < 4;i++){
        int count = 0;
        int Q[N];
        for(int x = 0;x < N;x++)Q[x] = P[x];
       
        for(int j = 0;j <= N - 2;j++){
            
            if(j == 0){
                count += i;
                Q[j] -= i;
            }
            
            while(Q[j] > 0){
                Q[j] -= 1; 
                Q[j+1] -= 1;
                count += 2;
            }
        
        }
        
        if(Q[N - 1] > 0)count += Q[N-1];
        
        min = min > count ? count : min;
        
    }
    
    cout << min << endl;
    
    return 0;
    
}
        
        
    
