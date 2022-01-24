#include<iostream>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

const int N=3009;
int n;//The number of points in this graphic is n.
int m;//The number of edges in this graphic is m.
int a[N][N];//
int d[N];//d[i] is the length of the path from point 1 to point i.
bool v[N];//Whether the point i is visited;If visited v[i]==true.Else v[i]==false.

void Dijkstra(){
    //Pre-Process
    memset(d,0x3f,sizeof(d));//the length of the path from 1 to i is 0x3f3f3f3f.
    memset(v,false,sizeof(v));//Every points haven't been visited.
    d[1]=0;//the length of the pat from 1 to 1 is 0.
    //Process
    for(int i=1;i<n;i++){//it circles for n-1 times.
        //Find the point which has the miniest length to point 1,and it hasn't been marked visited.
        int x=0;
        for(int j=1;j<=n;j++){
            if(!v[j]&&(x==0||d[x]>d[j]))x=j;
        }
        v[x]=1;//Mark point x is visited
        for(int y=1;y<=n;y++)d[y]=min(d[y],d[x]+a[x][y]);//Use point x to get other points' miniest path length.
    }
}

int main(){
    cin>>n>>m;
    //Pre-Process
    memset(a,0x3f,sizeof(a));
    for(int i=1;i<=n;i++)a[i][i]=0;//The length of the path from i to i is 0.
    //Read the graphic
    for(int i=1;i<=n;i++){
        int x,y,z;//x->y value is z.
        cin>>x>>y>>z;
        a[x][y]=min(a[x][y],z);//maybe the inputs have same pathes.
    }
    //Process
    Dijkstra();
    //Ouput the length from 1 to i
    for(int i=1;i<=n;i++)cout<<d[i]<<endl;
    return 0;
}