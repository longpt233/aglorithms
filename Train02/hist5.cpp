// duyet tuyen tinh 

#include<iostream>

using namespace std;

const int MAXTEST =100000;

int GetMax(int *arr,int n){
    int count=1;
    int max;
    int  temp=-1,k,i,j;
    for( i=0;i<n;i++){
        int val=arr[i];
      int cl1=1,cl=1;
        for( j=i-1,k=i+1;j>=0 || k<n;j--,k++){
            if(j>=0 && arr[j]>=val && cl1==1){
                count++;
            }else cl1=0;
            if(k<n && arr[k]>=val && cl==1){
                count++;
            }else cl=0;
            if(cl==0 && cl1==0)
                break;
        }
        max=val*count;
        if(max>temp){
            temp=max;
        }
        count=1;
        
    }
    return temp;
}



int main(){
    int n; 
    int kq[MAXTEST];
    int dem=0;
    while(1){
        cin>>n;
        if (0==n) break;
        int
     hist[n];
        for(int
     i=0;i<n;i++){
            cin >>hist[i];
        }
        kq[dem]=GetMax(hist,n);
        dem++;
    }
    for(int
 i=0;i<dem;i++){
        cout<< kq[i]<<endl;
    }
    return 0;
}