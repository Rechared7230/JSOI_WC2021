#include<iostream>
#include<cstring>
#include<string>

using namespace std;
int as[1000009];
int hs[1000009];
int main(){
    string s;
    cin>>s;
    string a;
    bool ck=false;
    int it=0;
    for(int i=0;i<s.length();i++){
        if(ck==false&&s[i]=='a')ck=true;
        if(ck){
            if(s[i]=='a'||s[i]=='h')a+=s[i];
        }
    }
    cout<<a;
    int x=0;
    int ite=0;
    while(x<a.length()){
        int an=0;
        while(a[x]=='a'){
            x++;
            an++;
        }
        int hn=0;
        while(a[x]=='h'){
            x++;
            hn++;
        }
        if(as==0||hs==0)break;
        as[ite]=an;
        hs[ite]=hn;
        ite++;
    }
    for(int i=0;i<ite;i++)
        cout<<as[i]<<" "<<hs[i]<<endl;
    int ans;
    for(int i=0;i<ite;i++){
        //ans+=(as[i]*hs[i]*(hs[i]-1));
        int t=0;
        for(int j=i;j<ite;j++)
            t+=hs[j];
        cout<<t<<endl;
        ans+=(as[i]*t*(t-1))/2;
        cout<<ans<<endl;
    }
    cout<<ans;
    return 0;
}