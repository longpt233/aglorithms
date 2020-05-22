#include<iostream>

using namespace std;

int n,m,M;
int a[20001]={0};
long long tongtoi[20001]={0};

int dem=0;


int main(){
    cin >>n>>m>>M;
    for(int i=1;i<=n;i++){
        cin>> a[i];
        tongtoi[i]=tongtoi[i-1]+a[i];
         if(tongtoi[i]>=m&&tongtoi[i]<=M)//{
            dem++; 
            int temp=tongtoi[i];
            //if(i>1){
                for(int j=1;j<=i;j++){
                    temp-=a[j];
                    if(temp>=m&&temp<=M)
                        dem++;
                }
            //}
        //}
    }
    cout<< dem;

    
    return 0;
}