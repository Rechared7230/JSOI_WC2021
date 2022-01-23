#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;
int n,k;
int a[10000009];
int main(){
    cin>>n>>k;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        a[i]=s[i]-'0';
    }
    for(int i=0;i<n;i++){
        a[i]=k-a[i];
        a[i]%=k;
    }
    bool c=false;
    int ans,mx;
    for(int i=0;i<n;i++){
        if(c==true&&a[i]==0){
            ans+=mx;
            mx=0;
        }
        if(a[i]!=0)c=true;
        else c=false;
        if(c){
            mx=max(mx,a[i]);
        }
        else continue;
    }
    cout<<ans;
    return 0;
}
