#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s){
    int n = s.size();
    vector<int> pi(n,0);
    for(int i=1;i<n;i++){
        int j = pi[i-1];
        while(j>0 and s[i]!=s[j])
            j = pi[j-1];
        if(s[i]==s[j]){
            j++;
        }
        pi[i] = j;
    }
}
int main(){
    string s = "abc";
    vector<int> res = prefix_function(s);
    string s1 = "dfabcabcabc";
    int pos = -1;
    int i =0;
    int j =0;
    while(i<s1.size()){
        if(s1[i] ==s[j]){
            j++;
            i++;
        }
        else{
            if(j!=0){
                j = res[j-1];
            }
            else
                i++;
        }
        if(j==s.size()){
            pos = i-s.size();
            break;
        }
    }
    cout<<pos;
}