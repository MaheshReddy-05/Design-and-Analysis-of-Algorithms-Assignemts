#include<bits/stdc++.h>
using namespace std;
int helper(vector<vector<int>> &data,int current,int bitm,int n){
    if( bitm == (1<<n)-1) return data[current][0];
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        if((bitm & 1<<i) == 0){
            ans = min(ans,data[current][i]+helper(data,i,(bitm|1<<i),n));
        }
    } 
    return ans;
}
int main(){
    vector<vector<int>> data = {{0,10,15,20},{10,0,35,25},{15,35,0,30},{20,25,30,0}};
    int ans = helper(data,0,1,4);
    cout<<ans;
    return 0;
}