#include <iostream>
#include<string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <cmath>
#include <iomanip> 
#include <stack>
#include <queue>
#include <cstdarg>
using namespace std;
#define mod 1000000007
#define ll long long 
#define endl '\n'

void sumST(vector<ll int> &tree,vector<ll int>&arr, int node, int arrL, int arrR ){
    if(arrL > arrR){
        return;
    }
    else if(arrL ==  arrR){
        tree[node] = arr[arrL] ;
        return;
    }


    int mid = (arrR+arrL)/2;
    sumST(tree,arr, 2*node, arrL, mid);
    sumST(tree,arr, 2*node+1, mid+1, arrR);
    tree[node] = tree[2*node] + tree[2*node+1];
    return ;
    
}
ll int getSum(vector<ll int> &tree,int tL, int tR, int node, int arrL, int arrR ){
    if(arrL > arrR){
        return 0 ;
    }
    else if(tL ==  arrL && tR ==  arrR){
        return tree[node];
    }
    int mid = (tL + tR)/2;
    return getSum(tree, tL, mid, 2*node, arrL, min(arrR, mid)) + getSum(tree, mid+1, tR, 2*node+1, max(arrL, mid+1), arrR);
}
bool comp(pair<int, int> &l, pair<int, int> &r){
    return l.second<r.second;
}
void coutWithPrecision(double n, int precision, bool nextLine)
{
    int data = (int)n;
    int len = 0;
    if (data == 0)
    {
        len = 1;
    }
    else {
        while (data != 0) {
            data = data / 10;
            len++;
        }
    }
    std::cout << std::setprecision(len + precision) << n;
    if (nextLine)
    {
        cout << '\n';
    }
}
bool compFirst(pair<int, int> &l, pair<int, int> &r){
    return l.first <=r.first;
}

bool compSecond(pair<int, int> &l, pair<int, int> &r){
    return l.second <= r.second;
}
pair <int, int> BSFirst(vector<pair<int, int>>&arr, int value, int s, int e){
    if(s > e) return {-1, -1};
    
    int mid = s +(e-s)/2;
    if(arr[mid].first == value) return arr[mid];
    else if(arr[mid].first > value){
        return BSFirst(arr, value, s, mid-1);
    } else {
        return BSFirst(arr, value, mid+1, e);
    }
}


int main()
{
    int n, Q;
    cin>>n>>Q;
    vector<int> arr(n);
    int zeros= 0;
    int ones = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==0) zeros++;
        else ones++;
    }
    for(int q=0;q<Q;q++){
        int a, b;
        cin>>a>>b;
        if(a == 1){
            b--;
            if(arr[b]==1){
                arr[b] =0;
                ones--;
                zeros++;
            }
            else if(arr[b]==0){
                arr[b] =1;
                ones++;
                zeros--;
            }
            //cout<<arr[b]<<endl;
        }
        else if(a == 2){
            if(ones>=b){
                cout<<1<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
    }
    

}

/*
    5
    92 31
    0 7
    31 9
    7 141
    141 0
    
    1. 
    2. 7 
    3. 
    4. 141
    5.
*/
