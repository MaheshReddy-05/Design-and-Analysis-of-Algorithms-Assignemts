#include<bits/stdc++.h>
using namespace std;
int helper(int *v,int *w,int al,int b,int si){
    if(si>=al) return 0;
    int ans = 0;
    if(w[si]<=b){
        ans = v[si]+max(ans,helper(v,w,al,b-w[si],si+1));
    }
    ans = max(ans,helper(v,w,al,b,si+1));
    return ans;
}
int main(){
    cout<<"Enter the array Length: \n";
    int al;
    cin>>al;
    int v[al];
    int w[al];
    cout<<"Enter Values \n";
    for(int i=0;i<al;i++){
        cin>>v[i];
    }
    cout<<"Enter Weights \n";
    for(int i=0;i<al;i++){
        cin>>w[i];
    }
    int b;
    cout<<"Enter the bucket Size\n";
    cin>>b;
    int ans = helper(v,w,al,b,0);
    cout<<ans;
    return 0;
}