#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> add(vector<vector<int>> A, vector<vector<int>> B) {
  int n = A.size();
  vector<vector<int>> C(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
  return C;
}
vector<vector<int>> subtract(vector<vector<int>> A, vector<vector<int>> B) {
  int n = A.size();
  vector<vector<int>> C(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      C[i][j] = A[i][j] - B[i][j];
    }
  }
  return C;
}
vector<vector<int>> strassen(vector<vector<int>> &A, vector<vector<int>> &B) {
  int n = 2;
  vector<vector<int>> C(n, vector<int>(n));
  int p1 = A[0][0] * (B[0][1] - B[1][1]);
  int p2 = (A[0][0] + A[0][1]) * B[1][1];
  int p3 = (A[1][0] + A[1][1]) * B[0][0];
  int p4 = A[1][1] * (B[1][0] - B[0][0]);
  int p5 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
  int p6 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);
  int p7 = (A[0][0] - A[1][0]) * (B[0][0] + B[0][1]);
  C[0][0] = p5 + p4 - p2 + p6;
  C[0][1] = p1 + p2;
  C[1][0] = p3 + p4;
  C[1][1] = p5 + p1 - p3 - p7;
  return C;
}
int main(){
    vector<vector<int>> A(2,vector<int>(2));
    for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                A[i][j] = 1;
            }
        }
    vector<vector<int>> B(2,vector<int>(2));
    for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                B[i][j] = 1;
            }
        }
    A = strassen(A,B);
    for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                cout<<A[i][j]<<" ";
            }
            cout<<endl;
        }
}