#include<iostream>
#include<algorithm>

using namespace std;

int n,m,k;
int d[1000009],v[1000009];
int ml[1000006],tot=0;

int main(){
    cin>>n>>m>>k;
    for(int i=2;i<=n;i++){cin>>d[i];}
    for(int i=1;i<=n;i++){cin>>v[i];}
    unsigned long long a=0;
    for(int i=1;i<=n;i++)a+=v[i];
    if(2*k*m>=d[n]){cout<<a;return 0;}
    //Iterater
    int i=1,j=1,dist=0,val=0;
    unsigned long long ans=0;
    const int md=2*k;

    while(dist<=md){
        dist+=d[j];
        val+=v[j];
        j++;   
    }
    //tot--;
    dist-=d[j];
    val-=v[j];
    j--;
    ml[tot]=val;
    while(!(i==j&&i==n)){
        while(dist+d[j+1]<=md){
            j++;
            dist+=d[j];
            val+=v[j];
        }
        
        tot++;
        ml[tot]=val;
        // dist-=d[i];
        // val-=v[i];
        // i++;
        while(dist+d[j+1]>md){
            dist-=d[i];
            val-=v[i];
            i++;
        }
    }
    sort(ml,ml+tot+1);
    cout<<ml[tot];
    return 0;
}