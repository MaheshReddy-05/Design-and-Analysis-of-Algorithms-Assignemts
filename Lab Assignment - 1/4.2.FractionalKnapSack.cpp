#include<bits/stdc++.h>
using namespace std;
class s
{
    public:
    int v;
    int w;
    float d;
};
bool cmp(s A,s B){
    if(A.d>B.d){
        return true;
    }
    return false;
}
int main(){
    cout<<"Enter the array size \n";
    int al;
    cin>> al;
    int w[al];
    cout<<"Enter the weights \n";
    for(int i=0;i<al;i++){
        cin>>w[i];
    }
    cout<<"Enter the value \n";
    int v[al];
    for(int i=0;i<al;i++){
        cin>>v[i];
    } 
    s Iteams[al];
    for(int i=0;i<al;i++){
        s p1;
        p1.v = v[i];
        p1.w = w[i];
        p1.d = p1.v/p1.w*1.0;
        Iteams[i] = p1;
    }
    sort(Iteams,Iteams + al,cmp);
    int bucket;
    cout<<"Enter the Bucket Weight \n";
    cin>>bucket;
    int ans=0;
    for(int i=0;i<al;i++){
        if(Iteams[i].w<=bucket){
            ans += Iteams[i].v;
            bucket -=Iteams[i].w;
        }
        else if(bucket==0) break;
        else{
            ans+= Iteams[i].d* bucket;
            bucket = 0;
        }
    }
    cout<<ans;
    return 0;
}