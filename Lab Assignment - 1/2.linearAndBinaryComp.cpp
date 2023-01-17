#include<bits/stdc++.h>
using namespace std;
int bi(int arr[], int al,int x){
    int si = 0;
    int ei = al-1;
    int count=0;
    while(si<=ei){
        count++;
        int mid = (si+ei)/2;
        if(arr[mid]==x) break;
        else if(arr[mid]>x){
            si = mid+1;
        }
        else{
            ei = mid-1;
        }
    }
    return count;
}
int li(int arr[],int al,int x){
    int count = 0;
    for(int i=0;i<al;i++){
        count++;
        if(arr[i]==x) break;
    }
    return count;
}
int main(){
    int al,x;
    cout<<"Enter the array Length :\n";
    cin>>al;
    cout<<"Enter "<<al<<" Value\n";
    int arr[al];
    for(int i=0;i<al;i++){
        cin>>arr[i]; 
    }
    cout<<"Enter the finding Element in array \n";
    cin>>x;
    int bin = bi(arr,al,x);
    int lin = li(arr,al,x);
    if(lin==al){
        cout<< "lol it is not in array\n";
        return 0;
    }
    cout<<"Binary : "<<bin<<"\nLinear : "<<lin;
    return 0;
}