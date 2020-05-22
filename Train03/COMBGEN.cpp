#include<iostream>

using namespace std;

int n,m;
//int in[10000]={0};// luu chu cau hinh 

int x[10000]={0};

/* bool ok =false;

void Try(int i,int j){    // try toi so n , truyen vao so so 1 dc viet 
    int max=0;
    if(j<=0) max=0;
    else max=1;

   for(int k=max;k>=0;k--){

        
         //   int a=in[i];
             if(j<=0) in[i]=0;
            else 
            in[i]=k;
            if(k==1) j--;
            if(i==n){
                if(j<=0){// du cau hinh 
                      for(int p=1;p<=n;p++){
                        if(in[p]==1) cout<<p<<" ";
                    }
                    cout<<endl;  
                    if(ok==true){
                        for(int p=1;p<=n;p++){
                            if(in[p]==1) cout<<p<<" ";
                        }
                    }

                    ok =true;
                    //if(dem==k1){
                        for(int p=1;p<=n;p++){
                            if(in[p]==1) if(p!=goal[p]) ok=false;
                        }

                    //} 
                }
            }else if(){
                Try(i+1,j);
            }
        //    in[i]=a;
        if(k==1) j++;
        
 //   }

}


} */

void Sinh(){
    int i=m;
    while (i>0&&(x[i]==n-m+i)) i--;  // tim motj vi tri ma taij co chua max
    if(i>0){
        x[i]++;
        for(int k=i+1;k<=m;k++){
            x[k]=x[k-1]+1;
        }
        for(int k=1;k<=m;k++){
            cout<< x[k]<<" ";
        }
    }else{
        cout<<-1;
    }
}



int main(){
    cin >>n>>m;
    for(int p=1;p<=m;p++){
        cin>>x[p];
    }
    Sinh();

 //   Try(1,m);
  // if(ok==false) cout<< -1;
   

    return 0;
}