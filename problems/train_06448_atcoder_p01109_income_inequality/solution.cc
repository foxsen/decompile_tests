#include <iostream>
using namespace std;
int main(void){
    int n, a[100000], sum; //sumはn人の平均値の合計
    int num;  //numは平均値以下の所得者数
    
    while(true){
        cin >> n;
        if(n == 0) break;
        
        sum = 0;
        num = 0;

        for(int i = 0; i < n; i++){  
            cin >> a[i];
            sum += a[i];
        }
        int mean = sum / n;
        for(int i = 0; i < n; i++){
            if(a[i] <= mean) num++;
        }
        cout << num << endl;
    }
}
