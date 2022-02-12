#include<iostream>
#include<cstring>
#include<string>

using namespace std;
int n=0,m=0,u=0,v=0;
int ms[59][59],mp[109][109];
//unsigned long long map[109][109];
// void hash(int a,int b,int c,int d){
    
// }
int main(){
    cin>>n>>m;
    string s;
    for(int i=1;i<=n;i++){
        getline(cin,s);
        cout<<s<<endl;
        for(int j=1;j<=m;j++){
            ms[i][j]=s[j-1]-'!';
            cout<<'!'+ms[i][j]<<" ";
        }
        cout<<endl;
    }
    cin>>u>>v;
    for(int i=1;i<=u;i++){
        getline(cin,s);
        cout<<s<<endl;
        for(int j=1;j<=v;j++){
            mp[i][j]=s[j-1]-'!';
        }
    }
    int a=0,b=0;
    //cout<<1723457823645987263495872;
    bool ck=false;
    for(int i=1;i<=u-n+1;i++){
        cout<<i<<" ";
        for(int j=1;j<=v-m+1;j++){
            cout<<j<<endl;
            if(ms[1][1]!=mp[i][j])continue;
            for(int i1=1;i1<=n;i1++){
                bool a1=false;
                for(int j1=1;j1<=m;j1++){
                    if(ck)break;
                    if(ms[i1][j1]!=mp[i+i1-1][j+j1-1]){a1=true;break;}
                    else if(i1==n && j1==m ){
                        a=i,b=j;
                        ck=true;
                    }
                }
                if(a1 || ck)break;
            }
        }
    }
    //out:
    cout<<a<<" "<<b;
    //cout<<ms[2][2]<<" "<<mp[2][2];
    return 0;
}
