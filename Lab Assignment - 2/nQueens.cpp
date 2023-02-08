#include<iostream>
#include<vector>
using namespace std;
bool checkPosition(vector<vector<int>> &data,int row,int col,int n){
    for(int i=0;i<col;i++){
        if(data[row][i]==1) return false;
    }
    for(int i=0;i<row;i++){
        if(data[i][col]==1) return false;
    }
    int r = row;
    int c = col;
    while(r>=0 && c>=0){
        if(data[r--][c--]==1) return false;
    }
    r = row;
    c = col;
    while(r>=0 && c<=n-1){
        if(data[r--][c++]==1) return false;
    }
    return true;
}
void printMatrix(vector<vector<int>> &data,int curr,int n){
    if(curr==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<data[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"\n";
        return;
    }
    for(int i=0;i<n;i++){
        if(checkPosition(data,curr,i,n)){
            data[curr][i] = 1;
            printMatrix(data,curr+1,n);
            data[curr][i]=0;
        }
        
    }
    return;
}
int main(){
    cout<<"Enter the n value";
    int n;
    cin>>n;
    vector<vector<int>> data(n,vector<int>(n));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            data[i][j]==0;
        }
    }
    printMatrix(data,0,n);
}