#include<iostream>

using namespace std;

int n,m,k1;
int in[10000]={0};// luu chu cau hinh 

int dem=0;

void Try(int i,int j){    // try toi so n , truyen vao so so 1 dc viet 

    int max=0;
    if(j<=0) max=0;
    else max=1;

   for(int k=max;k>=0;k--){

        
         //   int a=in[i];
            /* if(j<=0) in[i]=0;
            else */
            in[i]=k;
            if(k==1) j--;
            if(i==n){
                if(j<=0){// du cau hinh 
                      for(int p=1;p<=n;p++){
                        if(in[p]==1) cout<<p<<" ";
                    }
                    cout<<endl;  
                    dem++;
                    if(dem==k1){
                        for(int p=1;p<=n;p++){
                            if(in[p]==1) cout<<p<<" ";
                        }
                    } 
                }
            }else if(dem<k1){
                Try(i+1,j);
            }
        //    in[i]=a;
        if(k==1) j++;
        
 //   }

}


}



int main(){
    cin >>n>>m>>k1;

    Try(1,m);
   if(dem!=k1) cout<< -1;
   

    return 0;
}