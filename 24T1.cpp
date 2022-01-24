#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<queue>

using namespace std;
int n,m,s,t,k;
struct pt{
    int u,v,w;
}g[1009][1009];
int dist[1009][1009];
int main(){
    memset(dist,0x3f,sizeof(dist));
    cin>>n>>m>>s>>t>>k;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b].w=g[b][a].w=c;
    }
    queue <int> q;
    q.push(s);
    while(!q.empty()){
        int a=q.front();
        for(int i=0;i<n;i++){
            
        }
    }
    return 0;
}