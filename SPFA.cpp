#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;

int n,m,tot;
const int N=100010,M=100010;//Max num of edges and points
int head[N],ver[M],Next[M],d[N],edge[M];//Use list to build a graphic
queue <int> q;
bool v[N];//Whether the point is int the queue

void spfa(){
    //Pre-process
    memset(v,false,sizeof(v));
    memset(d,0x3f,sizeof(d));
    d[1]=0;v[1]=true;
    q.push(1);
    //Process
    while(!q.empty()){
        int x=q.front();q.pop();
        v[x]=0;
        //Enum all the out-edge of x
        for(int i=head[x];i;i=Next[i]){
            int y=ver[i],z=edge[i];
            if(d[y]>d[x]+z){
                d[y]=d[x]+z;
            }//d[y]=min(d[y],d[x]+z);
            if(!v[y])q.push(y),v[y]=true;//If t isn't in the queue,q.push(y)
        }
    }
}

int main(){
    //Make a graphic
    cin>>n>>m;
    //memset(d,0x3f,sizeof(d));
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        ver[++tot]=y,edge[tot]=z,Next[tot]=head[x],head[x]=tot;
    }
    spfa();
    //Output
    for(int i=1;i<=n;i++)cout<<d[i]<<" ";
    return 0;
}