#include<bits/stdc++.h>
using namespace std;

int n,m;   // lay >=m
int *h;

int H=0;// tim nhat cat
int hMAX=0;

long long Thetich(int H){  // tra ve the tich  >= H
    long long res=0;

    for (int i=0;i<n;i++){
        if(h[i]-H>0){
            res+=h[i]-H;
        
        }
    }
    return res;
}

/* int Cut(int low,int high){
    if(low==high) return low;
    int temp=(high+low)/2;
    if(Thetich(temp)>m){
        return Cut(temp,high);
    }else{
        return Cut(low,temp);
    }
}
 */
int main(){
    ios_base::sync_with_stdio(false);
    cin >> n>>m;
    h=new int[n];    // luu tru chieu cao cua cay tiu 1..n
    for(int i=0;i<n;i++){
        cin>> h[i];
        //if(h[i]>hMAX) hMAX=h[i];
    }
    sort(h,h+n);
     long long thetichtoi[h[n-1]+10]={0};
    /*  int i=0;
     int k=h[0];
    while(i<n-1){// thu tat ca cac chieu cao co the co 
        int hmax=h[i+1];
        k=h[i];
        while(k<=hmax){
            thetichtoi[k]=thetichtoi[k-1]+n-i+1;
            cout<< thetichtoi[k]<<endl;
            k++;
        }
        cout<<"======================"<<endl;
        i++;
    
    }  */
     thetichtoi[h[n-1]]=0;
    for(int i=n-1;i>=1;i--){
        for(int j=h[i]-1;j>=h[i-1];j--){
            thetichtoi[j]=thetichtoi[j+1]+n-i;
            if(thetichtoi[j]==<<endl;
        }
        //cout<<"==============="<<endl;
    }

    for(int j=h[0]-1;j>=0;j--){
            thetichtoi[j]=thetichtoi[j+1]+n;
            //cout<<thetichtoi[j]<<endl;
        }


    //cout<<low; 


}