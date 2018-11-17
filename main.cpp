#include <iostream>

using namespace std;
int table[1005];//I am assuming that the biggest size of the array will be 1000
int arr[1005];
int n;
/*
function dp(i) returns the minimum cost if we are in cell i
and table[i] contains those minimum values
*/
int dp(int i){
    if(table[i] != -1){
        return table[i];
    }
    if(i>=n){
        return 0;
    }
    if(i == n-1){
        return table[i]=arr[i];//if we are at the last cell then return its value
    }
    if(i == n-2){
        return table[i]=arr[i]+arr[i+1];//if we are at the cell before the last then we return its value and the last cell value
    }
    int mn=min(dp(i+1),dp(i+2)) + arr[i];//decide which decision is better
    return table[i]=mn;
}
int main(){
    cin>>n;
    /*
    the array without the leading 0
    */
    for(int i=0 ; i<n ; i++){
        table[i]=-1;
        cin>>arr[i];
    }
    int mn=min(dp(0),dp(1));//we see whats best for us going to 0 or 1
    cout<<mn<<endl;
}
