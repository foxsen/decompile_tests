#include <iostream>
#include <cmath>
#include <utility>
#define EPS 1e-10
using namespace std;

int main(void){

    pair<double, double> p0, p1, p2, p3;
    int n;
    cin >> n;

    while(n--){

        cin >> p0.first >> p0.second;
        cin >> p1.first >> p1.second;
        cin >> p2.first >> p2.second;
        cin >> p3.first >> p3.second;

        double innerProduct = (p1.first - p0.first)*(p3.first - p2.first)
            + (p1.second - p0.second)*(p3.second - p2.second);
        double crossProduct = (p1.first - p0.first)*(p3.second - p2.second)
            - (p1.second - p0.second)*(p3.first - p2.first);

        if(crossProduct == 0){
            cout << "2" << endl;
        }else if(innerProduct == 0 ){
            cout << "1" << endl;
        }else{
            cout << "0" << endl;
        }
    }
    return 0;
}