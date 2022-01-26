#include<iostream>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;
long long a[200005];
int n,m;
struct di{
    int x,y;
}d[200005];
int main(){
    memset(a,0,sizeof(a));
    memset(d,0,sizeof(d));
    int n,m;
    cin>>n>>m;
    //Get qzh
    for(int i=0;i<n;i++){
        long long x=0;
        cin>>x;
        if(i==0)a[i]=x;
        else a[i]=a[i-1]+x;
    }
    for(int i=0;i<m;i++)cin>>d[i].x>>d[i].y;
    long long ans=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            int l1=0,l2=0,r1=0,r2=0;
            l1=min(d[i].x,d[j].x);
            l2=max(d[i].x,d[j].x);
            r1=min(d[i].y,d[j].y);
            r2=max(d[i].y,d[j].y);
            ans=max(ans,a[r1]-a[l1]+a[r2]-a[l2]);
            cout<<ans<<endl;
        }
        cout<<ans;
    }
    return 0;
}