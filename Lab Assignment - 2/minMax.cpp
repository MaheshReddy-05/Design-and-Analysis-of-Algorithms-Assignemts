#include<bits/stdc++.h>
using namespace std;
class s{
    public:
    int min = INT_MAX;
    int max = INT_MIN;
};
s getMinMax(int arr[],int al, int si,int ei){
    if(si==ei){
        s obj;
        obj.min = arr[si];
        obj.max = arr[si];
        return obj;
    }
    int mid = (si+ei)/2;
    s first = getMinMax(arr,al,si,mid);
    s second = getMinMax(arr,al,mid+1,ei);
    s ans;
    ans.min = min(first.min,second.min);
    ans.max = max(first.max,second.max);
    return ans;
}
int main(){
    int al;
    cout<<"Enter array size"<< endl;
    cin>>al;
    int arr[al];
    cout<<"Enter array elements"<<endl;
    for(int i=0;i<al;i++){
        cin>>arr[i];
    }
    s ans = getMinMax(arr,al,0,al-1);
    cout<<"Min: "<<ans.min<<endl;
    cout<<"Max: "<<ans.max<<endl;
}

