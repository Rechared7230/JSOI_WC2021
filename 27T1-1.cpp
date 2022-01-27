#include<iostream>

using namespace std;
int d[1000009],v[1000009];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    const unsigned long long l=2*k;
    for(int i=2;i<=n;i++){cin>>d[i];}
    for(int i=1;i<=n;i++){cin>>v[i];}
    unsigned long long a=0;
    for(int i=1;i<=n;i++)a+=v[i];
    if(2*k*m>=d[n]){cout<<a;return 0;}
    return 0;
}