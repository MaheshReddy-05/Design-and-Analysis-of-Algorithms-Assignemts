#include<bits/stdc++.h>
using namespace std;
void helper(int arr[],int k,int al){
    priority_queue<int> pqh;  
    priority_queue<int> pqs;  
    for(int i=0;i<al;i++){
        pqh.push(arr[i]);
    }
    for(int i=0;i<al;i++){
        pqs.push(-arr[i]);
    }
    while(k>1){
        k--;
        pqh.pop();
        pqs.pop();
    }
    cout<< pqh.top() << " Highest" <<endl;
    cout<< -pqs.top()<< " Smallest" <<endl;
}
int main(){
    cout<<"Enter the Array Size"<<endl;
    int al;
    cin>>al;
    int arr[al];
    for(int i=0;i<al;i++){
        cin >> arr[i];
    }
    cout<< "Enter the Kth Number : "<<endl;
    int k;
    cin>>k;
    helper(arr,k,al);
    return 0;
}