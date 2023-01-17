#include<bits/stdc++.h>
using namespace std;
void bubbleSort(int *arr,int al){
    for(int i=0;i<al;i++){
        for(int j=i+1;j<al;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
}
int main(){
    int al;
    cout<<"Enter Array Length\n";
    cin>>al;
    cout<<"Enter Array Elements\n";
    int arr[al];
    for(int i =0;i<al;i++){
        cin>>arr[i];
    }
    bubbleSort(arr,al);
    cout<<"Sorted Array: \n";
    for(int i=0;i<al;i++){
        cout<<arr[i]<<" ";
    }
}