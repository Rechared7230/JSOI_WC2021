#include<iostream>
#include<cstring>
#include<string>

using namespace std;
int n,m;
struct tree{int v;bool used=false;int dep=-1;} tre[3000009];//tre[i]  point i son
int c[3000009];//friend c[i];
unsigned long long ans=0;
void getdep(int n){
    

}
int main(){
    //memset(tre,0,sizeof(tre));
    cin>>n>>m;
    tre[0].dep=0;
    for(int i=1;i<n;i++){cin>>tre[i].v;}
    if(m==0){cout<<0;return 0;}
    for(int i=0;i<m;i++)cin>>c[i];
    
    return 0;
}