#include<bits/stdc++.h>

using namespace std;

int n;
int d[20];
int day[20];


int main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>d[i];
        day[i]=0;   // so mon dang co ngay thu i 
    }
    sort(d+1,d+1+n);
    int res=1;
    for(int i=n;i>=1;i--){
        bool foud=false;
        int begin =1;
        while(!foud){
            if(day[begin]+d[i]<=6){
                day[begin]+=d[i];
                foud=true;
            }
            else begin++;
            if(begin>res) res=begin;
        }
    }

    cout <<res;
    

    return 0;
}