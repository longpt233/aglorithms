
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >>n;
    //vector<pair<int, int >> a(2000000);
    vector<int > f(2000000,0),g(2000000,0);
    
    for(int i=0;i<n;i++){
        int s,t;
        cin >> s>>t;
       // a.push_back({t,s});
       f[t]=t-s;  // chot duoi t co do dai luon 
       g[s]=t-s;

    }

    //sort(a.begin(),a.end()); 

    //int  f[2000000],g[2000000];
    
    
    //f[0]=a[0].first-a[0].second;// first khong co ngoac lol

    // for (int i=1;i<2000000;i++){
    //     f[i]=max(f[i-1],a[i].first-a[i].second);
    // }
    // for(int i=2000000-1;i>=0;i--){
    //     g[i]=max(g[i+1],a[i].first-a[i].second);
    // }

    for (int i=1;i<2000000;i++){
        f[i]=max(f[i-1],f[i]);
    }
    for(int i=2000000-2;i>=0;i--){
        g[i]=max(g[i+1],g[i]);
    }

    int res=-1;
    for(int i=0;i<2000000;i++){
        res=max(res,f[i]+g[i+1]);
    }

    cout<<res;



    
   
    
    return 0;
}