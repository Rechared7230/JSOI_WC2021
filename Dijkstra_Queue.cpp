#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
#include<algorithm>

using namespace std;

const int N=3009,M=300009;
int head[N],ver[M],edge[M],Next[M],d[N];
bool v[N];
int n,m,tot;//n:the number of points    m:the number of edges.  tot:a iterator while input the graphic.
priority_queue < pair<int,int> > q;

void Dijkstra(){
    memset(d,0x3f,sizeof(d));
    memset(v,false,sizeof(v));
    d[1]=0;
    q.push(make_pair(0,1));
    while(q.size()){
        int x=q.top().second;q.pop();
        if(v[x])continue;
        v[x]=1;
        for(int i=head[x];i;i=Next[i]){
            int y=ver[i],z=edge[i];
            if(d[y]>d[x]+z){
                d[y]=d[x]+z;
                q.push(make_pair(-d[y],y));
            }
        }
    }
}
void add(int x,int y,int z){
    ver[++tot]=y,edge[tot]=z,Next[tot]=head[x],head[x]=tot;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y,z;//x->y length is z
        cin>>x>>y>>z;
        add(x,y,z);
    }
    Dijkstra();
    for(int i=1;i<=n;i++)cout<<d[i]<<endl;
    return 0;
}