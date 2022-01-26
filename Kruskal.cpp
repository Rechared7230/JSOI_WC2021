#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;

//Make a graphic
struct rec {
    int x,y,z;
}edge[1000005];
int fa[1000005],n,m,ans;

bool operator < (rec a,rec b){
    return a.z<b.z;
}

bool operator > (rec a,rec b){
    return a.z>b.z;
}

//Disjoint-Set
int get(int x){
    if(x==fa[x])return x;
    return fa[x]=get(fa[x]);
}

int main(){
    //Get a graphic
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>edge[i].x>>edge[i].y>>edge[i].z;
    }
    //Sort out all the edges in order from min to max.
    sort(edge+1,edge+1+m);
    for(int i=1;i<n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        int x=get(edge[i].x);
        int y=get(edge[i].y);
        if(x==y)continue;//If x and y are in the same set
        fa[x]=y;//Union
        ans+=edge[i].z;
    }
    cout<<ans<<endl;
    return 0;
}