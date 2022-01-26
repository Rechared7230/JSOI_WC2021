#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int d[1009][1009],n,m;
int main(){
    //Make a graphic
    memset(d,0x3f,sizeof(d));
    cin>>n>>m;
    for(int i=1;i<=n;i++)d[i][i]=0;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        d[x][y]=d[y][x]=z;
    }
    //Floyd algorithm
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);//cdbb d[i][j] |= d[i][k] & d[k][j];
            }
        }
    }
    //Output
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
           cout<<d[i][j]<<" "; 
        }
        cout<<endl;
    }
    return 0;
}